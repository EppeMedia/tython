#include "../../include/visitor/SourceFileVisitor.h"
#include <string>
#include "../../include/exception/CompileException.h"
#include "../../include/exception/NotImplemented.h"
#include <regex>

std::any SourceFileVisitor::visitImport_statement(TythonParser::Import_statementContext *ctx) {

    const auto identifier = ctx->import_path()->getText();

    // check the object table if we have found an object of the specified name
    if (this->external_object_symbol_table.count(identifier)) {

        this->imports.insert(identifier);

    } else {

        throw CompileException("Attempt to import unknown object " + identifier + ". Did you check the order of inclusion?");
    }

    return nullptr;
}

std::any SourceFileVisitor::visitAssign_statement(TythonParser::Assign_statementContext *ctx) {


    auto rhs = any_cast<llvm::Value*>(visit(ctx->expression()));

    // todo: this identifier resolution should be implemented in the specialized branches of lval.
    // todo: Note that, unlike most other uses, assignment is a defining operation (identifiers that do not exist are created)
    string identifier = ctx->IDENTIFIER()->getText();

    // resolve identifier
    auto lhs = this->builder->current_namespace->findVariable(identifier);

    // if a variable of this identifier is unknown, we create one on the fly
    if (!lhs) {
        lhs = this->builder->CreateVariable(identifier);
    }

    this->builder->CreateStore(rhs, lhs);

    return lhs;
}

std::any SourceFileVisitor::visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) {

    auto identifier = ctx->IDENTIFIER()->getText();

    // check if the identifier exists, otherwise throw an exception

    if (auto variable = this->builder->current_namespace->findVariable(identifier)) {
        // this is a pointer to the variable. We load it to get a pointer to the object.
        const auto ptr_type = llvm::PointerType::get(this->builder->getContext(), 0);
        return (llvm::Value*)this->builder->CreateLoad(ptr_type, variable);
    }

    throw CompileException("Unknown symbol " + identifier);
}

std::any SourceFileVisitor::visitConstant(TythonParser::ConstantContext *ctx) {

    if (ctx->INT_LIT()) {

        auto raw = stoi(ctx->INT_LIT()->getText());
        auto int64_t = llvm::IntegerType::getInt64Ty(this->module->getContext());
        auto v = llvm::ConstantInt::get(int64_t, raw, true);

        return this->builder->CreateFloatObject(v);

    } else if (ctx->FLOAT_LIT()) {

        auto raw = stod(ctx->FLOAT_LIT()->getText());
        auto double_t = llvm::Type::getDoubleTy(this->module->getContext());
        auto v = llvm::ConstantFP::get(double_t, raw);

        return this->builder->CreateFloatObject(v);

    } else if (ctx->STR_LIT()) {

        // create string literal character array
        auto raw = ctx->STR_LIT()->getText();
        // trim double quotes
        auto trim = raw.substr(1, raw.size() - 2);

        // todo: a more rigorous way of achieving this and other escapable characters...
        auto clean = std::regex_replace(trim, std::regex("\\\\n"), "\n");

        auto str = this->builder->CreateGlobalString(clean, "string_literal");

        auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
        auto length = llvm::ConstantInt::get(int32_t, clean.length());

        return this->builder->CreateStringObject(str, length);
    }

    throw NotImplemented("Encountered unknown literal type. Language implementation and specification have probably diverged. Please contact the project maintainer.");
}

std::any SourceFileVisitor::visitIf_statement(TythonParser::If_statementContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_true = llvm::BasicBlock::Create(this->builder->getContext(), "if", f, nullptr);
    llvm::BasicBlock* br_else_if = llvm::BasicBlock::Create(this->builder->getContext(), "else_if", f, nullptr);
    llvm::BasicBlock* br_else = llvm::BasicBlock::Create(this->builder->getContext(), "else", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_if", f, nullptr);

    auto expression_value = any_cast<llvm::Value*>(visit(ctx->expression()));
    auto test = this->builder->CreateObjectIsTruthy(expression_value); // todo: this should happen as a comparison (magic method) between the result of the expression and the True (or False) unique objects instead!

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    const auto zero = llvm::ConstantInt::get(int32_t, 0, true);

    auto check = this->builder->CreateICmpSGT(test, zero);

    llvm::BasicBlock* br_false;

    if (ctx->br_else_if) {
        br_false = br_else_if;
    } else if (ctx->br_else) {
        br_false = br_else;
    } else {
        br_false = br_end;
    }

    this->builder->CreateCondBr(check, br_true, br_false);

    { // if

        this->builder->SetInsertPoint(br_true);

        visit(ctx->br_if);

        this->builder->CreateBr(br_end);
    }

    { // if_else
        this->builder->SetInsertPoint(br_else_if);

        if (ctx->br_else_if) {
            visit(ctx->br_else_if);
        }

        this->builder->CreateBr(br_end);
    }

    { // else

        this->builder->SetInsertPoint(br_else);

        if (ctx->br_else) {
            visit(ctx->br_else);
        }

        this->builder->CreateBr(br_end);
    }

    this->builder->SetInsertPoint(br_end);

    return nullptr;
}

std::any SourceFileVisitor::visitBlock(TythonParser::BlockContext *ctx) {

    this->builder->nestNamespace();

    TythonParserBaseVisitor::visitBlock(ctx);

    this->builder->popNamespace();

    return nullptr;
}

std::any SourceFileVisitor::visitFunction_def(TythonParser::Function_defContext *ctx) {

    auto identifier = ctx->IDENTIFIER()->getText();

    // create a new scope for this function's arguments. The body scope of the function will be nested in this.
    this->builder->nestNamespace();

    // function declarations are fully opaque; we only know that it may return something, and that it takes n variable arguments
    // todo: check if there is any returns, then return (variable) ptr type, otherwise return void.
    auto return_type = llvm::Type::getVoidTy(this->builder->getContext());
    auto ptr_type = llvm::PointerType::get(this->builder->getContext(), 0);

    std::vector<llvm::Type*> arg_types;

    for (int i = 0; i < ctx->arguments()->args.size(); ++i) {
        arg_types.push_back(ptr_type);
    }

    const bool isVarArgs = ctx->SYM_ELLIPS();

    llvm::FunctionType* ft = llvm::FunctionType::get(return_type, arg_types, isVarArgs);
    auto fn = llvm::Function::Create(ft, llvm::GlobalValue::CommonLinkage, identifier, this->module);

    // todo: this return type should depend on any return statements in the content of the body
    this->module->registerProcedure(fn, identifier);

    auto old_bb = this->builder->GetInsertBlock();

    auto prologue = llvm::BasicBlock::Create(this->builder->getContext(), "prologue", fn);
    this->builder->SetInsertPoint(prologue);

    visit(ctx->arguments());

    auto body = llvm::BasicBlock::Create(this->builder->getContext(), "body", fn);
    this->builder->CreateBr(body);
    this->builder->SetInsertPoint(body);

    visitBlock(ctx->block());

    auto epilogue = llvm::BasicBlock::Create(this->builder->getContext(), "epilogue", fn);
    this->builder->CreateBr(epilogue);
    this->builder->SetInsertPoint(epilogue);

    // todo: currently, the block is always "epilogue", and that block has no content a all (the check below is trivially true)
    // check if we have a return statement
    if (!this->builder->GetInsertBlock()->getTerminator()) {
        this->builder->CreateRetVoid();
    }

    this->builder->popNamespace();

    this->builder->SetInsertPoint(old_bb);

    return nullptr;
}

std::any SourceFileVisitor::visitCall_expression(TythonParser::Call_expressionContext *ctx) {

    if (ctx->KW_EXTERN()) {
        return visitExternCallExpression(ctx);
    }

    return visitInternalCallExpression(ctx);
}

llvm::Value* SourceFileVisitor::visitExternCallExpression(TythonParser::Call_expressionContext *ctx) {

    if (!ctx->KW_EXTERN()) {
        throw CompileException("Syntactical mismatch: interpreting an unmarked function call as an <extern> function call!");
    }

    const auto function_name = ctx->IDENTIFIER()->getText();

    auto f = this->module->findProcedure(function_name);

    if (!f) {
        throw CompileException("Undefined reference to function \"" + function_name + "\".");
    }

    auto params = any_cast<std::vector<llvm::Value*>>(visitExternCallParameters(ctx->parameters()));

    auto return_value = this->builder->CreateCall(f, params);

    return return_value;
}

std::vector<llvm::Value*> SourceFileVisitor::visitExternCallParameters(TythonParser::ParametersContext *ctx) {

    std::vector<llvm::Value*> values;
    values.reserve(ctx->params.size());

    for (auto p : ctx->params) {
        values.push_back(any_cast<llvm::Value*>(visit(p)));
    }

    return values;
}

llvm::Value *SourceFileVisitor::visitInternalCallExpression(TythonParser::Call_expressionContext *ctx) {

    if (ctx->KW_EXTERN()) {
        throw CompileException("Syntactical mismatch: interpreting a marked <extern> function call as an internal function call!");
    }

    const auto function_name = ctx->IDENTIFIER()->getText();
    auto f = this->module->findProcedure(function_name);

    if (!f) {

        // check other processed objects so far
        for (auto &entry : this->external_object_symbol_table) {
            // check if the object is imported in this source file
            if (this->imports.count(entry.first)) {
                // check if that object contains the function
                if (entry.second->count(function_name)) {
                    f = entry.second->find(function_name)->second;
                }
            }
        }

        if (!f) {
            throw CompileException("Undefined reference to function \"" + function_name + "\".");
        }
    }

    auto params = any_cast<std::vector<llvm::Value*>>(visitInternalCallParameters(ctx->parameters()));

    auto return_value = this->builder->CreateCall(f, params);

    return return_value;
}

std::vector<llvm::Value*> SourceFileVisitor::visitInternalCallParameters(TythonParser::ParametersContext *ctx) {

    std::vector<llvm::Value*> values;
    values.reserve(ctx->params.size());

    for (auto p : ctx->params) {
        values.push_back(any_cast<llvm::Value*>(visit(p)));
    }

    return values;
}

std::any SourceFileVisitor::visitArguments(TythonParser::ArgumentsContext *ctx) {

    std::vector<llvm::Value*> vars(ctx->args.size());

    for (int i = 0; i < ctx->args.size(); ++i) {

        auto identifier = ctx->args.at(i)->getText();
        auto v = this->builder->GetInsertBlock()->getParent()->getArg(i); // todo: seems like a stack member to me, it will probably be deleted wih the call frame. What would then if we assign it to a global variable?

        auto dataEntry = this->builder->CreateVariable(identifier);

        /*
         * todo:
         * First-class data arguments are passed by value, other types are passed by reference.
         * Implementation-wise, this is probably already partly achieved by our setup (i.e. a value pass of a sequence is a new sequence referencing the same elements as the original)
         * We'll have to have another look when we implement objects (class instances)
         */

        // assign the passed argument value to the new variable
        this->builder->CreateStore(v, dataEntry);

        vars.push_back(dataEntry);
    }

    return vars;
}

std::any SourceFileVisitor::visitBinary_expression(TythonParser::Binary_expressionContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    // obtain the magic function
    auto binop_function_ptr = visitBinaryOperator(ctx->binary_operator(), lhs, rhs);

    auto function_type = llvm::FunctionType::get(this->builder->object_type, { this->builder->object_type, this->builder->object_type }, false);

    // the result of a binary expression is always an integer
    return this->builder->CreateCall(function_type, binop_function_ptr, { lhs, rhs }, "binop");
}

llvm::Value* SourceFileVisitor::visitBinaryOperator(TythonParser::Binary_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs) {

    if (ctx->inequality_operator()) {
        return visitInequalityOperator(ctx->inequality_operator(), lhs, rhs);
    }

    throw NotImplemented("Unimplemented binary operator \"" + ctx->getText() + "\"!");
}

llvm::Value* SourceFileVisitor::visitInequalityOperator(TythonParser::Inequality_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs) {

    // look up the corresponding magic methods struct on the LHS object
    const auto typeobject = this->builder->CreateGetTypeObject(lhs);
    auto number_methods_struct = this->builder->CreateGetNumberFunctions(typeobject);

    // determine which operation we should perform, and
    // return a function pointer to that magic function (it is always a binary function)
    if (ctx->SYM_EQ()) {
        return this->builder->CreateGetNumberCmpEq(number_methods_struct);
    } else if (ctx->SYM_NEQ()) {
//        return this->builder->CreateICmpNE(lhs, rhs);
    } else if (ctx->SYM_GT()) {
//        return this->builder->CreateICmpSGT(lhs, rhs);
    } else if (ctx->SYM_GTE()) {
//        return this->builder->CreateICmpSGE(lhs, rhs);
    } else if (ctx->SYM_LTE()) {
//        return this->builder->CreateICmpSLE(lhs, rhs);
    } else if (ctx->SYM_LT()) {
//        return this->builder->CreateICmpSLT(lhs, rhs);
    }

    throw NotImplemented("Unimplemented inequality operator \"" + ctx->getText() + "\"!");
}
