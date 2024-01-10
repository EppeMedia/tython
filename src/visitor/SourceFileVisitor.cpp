#include "../../include/visitor/SourceFileVisitor.h"
#include <string>
#include "../../include/exception/CompileException.h"
#include "../../include/exception/NotImplemented.h"

std::any SourceFileVisitor::visitAssign_statement(TythonParser::Assign_statementContext *ctx) {

    string identifier = ctx->IDENTIFIER()->getText();
    auto value = any_cast<Value*>(visit(ctx->expression()));

    // resolve identifier
    auto dataEntry = this->builder->current_scope->findDataEntry(identifier);

    // if a variable of this identifier is unknown, we create one on the fly
    if (!dataEntry) {
        dataEntry = this->builder->CreateVariable(identifier);
    }

    // get reference to target content field
    auto gep = builder->CreateGetValuePtr(dataEntry);

    this->builder->CreateStore(value->content, gep);
    // update shadow
    dataEntry->value = value;

    return nullptr;
}

std::any SourceFileVisitor::visitAtomic(TythonParser::AtomicContext *ctx) {

    if (auto identifier = ctx->IDENTIFIER()) {

        // fetch the identifier if it exists, otherwise throw exception
        if (auto dataEntry = this->builder->current_scope->findDataEntry(identifier->getText())) {
//            return dataEntry->value; // todo: we can do this iff we know that the variable's value was declared in this same (function-level) scope! Note: it's a bit hard to distinguish a function level at the moment, we can restrict it to stricly "his scope" first.

            auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);
            auto load = this->builder->CreateLoad(ptr_t, this->builder->CreateGetValuePtr(dataEntry));
            return new Value(dataEntry->value->type, load);
        }

        throw CompileException("Unknown symbol " + identifier->getText());
    }

    // this is a constant atomic
    return visitConstant(ctx->constant());
}

std::any SourceFileVisitor::visitConstant(TythonParser::ConstantContext *ctx) {

    if (ctx->INT_LIT()) {

        auto raw = stoi(ctx->INT_LIT()->getText());
        auto int64_t = llvm::IntegerType::getInt64Ty(this->module->getContext());
        auto v = llvm::ConstantInt::get(int64_t, raw, true);

        return this->builder->CreateValue(tython::Type::INTEGER, v);

    } else if (ctx->FLOAT_LIT()) {

        auto raw = stod(ctx->FLOAT_LIT()->getText());
        auto double_t = llvm::Type::getDoubleTy(this->module->getContext());
        auto v = llvm::ConstantFP::get(double_t, raw);

        return this->builder->CreateValue(tython::Type::FP, v);

    } else if (ctx->STR_LIT()) {

        // create string literal character array
        auto raw = ctx->STR_LIT()->getText();
        // trim double quotes
        auto trim = raw.substr(1, raw.size() - 2);
        auto charVector = std::vector<char>(trim.begin(), trim.end());
        charVector.push_back('\0'); // null-terminator
        // populate allocated char*
        auto bytes = llvm::ConstantDataArray::get(this->builder->getContext(), charVector);

        auto int8_t = llvm::IntegerType::getInt8Ty(this->builder->getContext());
        auto malloc = this->builder->CreateMalloc(int8_t, charVector.size());

        this->builder->CreateStore(bytes, malloc);

        return this->builder->CreateValue(tython::Type::STRING, malloc);
    }

    throw NotImplemented("Encountered unknown literal type. Language implementation and specification have probably diverged. Please contact the project maintainer.");
}

std::any SourceFileVisitor::visitIf_statement(TythonParser::If_statementContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_true = llvm::BasicBlock::Create(this->builder->getContext(), "if", f, nullptr);
    llvm::BasicBlock* br_else_if = llvm::BasicBlock::Create(this->builder->getContext(), "else_if", f, nullptr);
    llvm::BasicBlock* br_else = llvm::BasicBlock::Create(this->builder->getContext(), "else", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_if", f, nullptr);

    auto expression_value = any_cast<Value*>(visit(ctx->expression()));
    auto load = this->builder->CreateGetContent(expression_value);

    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto zero = llvm::ConstantInt::get(int64_t, 0, true);

    auto check = this->builder->CreateICmpSGT(load, zero);

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

    this->builder->nestScope();

    TythonParserBaseVisitor::visitBlock(ctx);

    this->builder->popScope();

    return nullptr;
}

std::any SourceFileVisitor::visitFunction_def(TythonParser::Function_defContext *ctx) {

    auto identifier = ctx->IDENTIFIER()->getText();

    // create a new scope for this function's arguments. The body scope of the function will be nested in this.
    this->builder->nestScope();

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
    auto fn = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage, identifier, this->module);

    // todo: this return type should depend on any return statements in the content of the body
    this->module->registerProcedure(fn, tython::UNKNOWN, identifier);

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

    this->builder->popScope();

    this->builder->SetInsertPoint(old_bb);

    return nullptr;
}

std::any SourceFileVisitor::visitCall_expression(TythonParser::Call_expressionContext *ctx) {

    if (ctx->KW_EXTERN()) {
        return visitExternCallExpression(ctx);
    }

    return visitInternalCallExpression(ctx);
}

Value* SourceFileVisitor::visitExternCallExpression(TythonParser::Call_expressionContext *ctx) {

    if (!ctx->KW_EXTERN()) {
        throw CompileException("Syntactical mismatch: interpreting an unmarked function call as an <extern> function call!");
    }

    auto f = this->module->findProcedure(ctx->IDENTIFIER()->getText());

    if (!f) {
        throw CompileException("Undefined reference to function \"" + ctx->IDENTIFIER()->getText() + "\".");
    }

    auto params = any_cast<std::vector<llvm::Value*>>(visitExternCallParameters(ctx->parameters()));

    auto return_value = this->builder->CreateCall((llvm::Function*)f->content, params);

    // create a typed value wrapper for the return value
    return this->builder->CreateValue(tython::UNKNOWN, return_value);
}

std::vector<llvm::Value*> SourceFileVisitor::visitExternCallParameters(TythonParser::ParametersContext *ctx) {

    std::vector<Value*> values;
    values.reserve(ctx->params.size());

    for (auto p : ctx->params) {
        values.push_back(any_cast<Value*>(visit(p)));
    }

    std::vector<llvm::Value*> params;
    params.reserve(values.size());

    for (auto v : values) {
        params.push_back(this->builder->CreateGetContent(v));
    }

    return params;
}

Value *SourceFileVisitor::visitInternalCallExpression(TythonParser::Call_expressionContext *ctx) {

    if (ctx->KW_EXTERN()) {
        throw CompileException("Syntactical mismatch: interpreting a marked <extern> function call as an internal function call!");
    }

    auto f = this->module->findProcedure(ctx->IDENTIFIER()->getText());

    if (!f) {
        throw CompileException("Undefined reference to function \"" + ctx->IDENTIFIER()->getText() + "\".");
    }

    auto params = any_cast<std::vector<llvm::Value*>>(visitInternalCallParameters(ctx->parameters()));

    auto return_value = this->builder->CreateCall((llvm::Function*)f->content, params);

    return new Value(f->type, return_value);
}

std::vector<llvm::Value*> SourceFileVisitor::visitInternalCallParameters(TythonParser::ParametersContext *ctx) {

    std::vector<Value*> values;
    values.reserve(ctx->params.size());

    for (auto p : ctx->params) {
        values.push_back(any_cast<Value*>(visit(p)));
    }

    std::vector<llvm::Value*> params;
    params.reserve(values.size());

    for (auto v : values) {
        params.push_back(v->content);
    }

    return params;
}

std::any SourceFileVisitor::visitArguments(TythonParser::ArgumentsContext *ctx) {

    std::vector<Variable*> vars(ctx->args.size());

    for (int i = 0; i < ctx->args.size(); ++i) {

        auto identifier = ctx->args.at(i)->getText();
        auto v = this->builder->GetInsertBlock()->getParent()->getArg(i); // todo: seems like a stack member to me, it will probably be deleted wih the call frame. What would then if we assign it to a global variable?

        auto dataEntry = this->builder->CreateVariable(identifier);

        // assign the passed argument value to the new variable
        auto target = this->builder->CreateGetValuePtr(dataEntry);
        this->builder->CreateStore(v, target);
        dataEntry->value = new Value(tython::Type::UNKNOWN, v);

        vars.push_back(dataEntry);
    }

    return vars;
}

std::any SourceFileVisitor::visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) {
    return visit(ctx->expression());
}

std::any SourceFileVisitor::visitBinary_expression(TythonParser::Binary_expressionContext *ctx) {

    auto lhs_value = any_cast<Value*>(visit(ctx->lhs));
    auto rhs_value = any_cast<Value*>(visit(ctx->rhs));

    // obtain the contents of the expression values
    auto lhs_content = this->builder->CreateGetContent(lhs_value);
    auto rhs_content = this->builder->CreateGetContent(rhs_value);

    auto result = visitBinaryOperator(ctx->binary_operator(), lhs_content, rhs_content);

    // the result of a binary expression is always an integer
    return this->builder->CreateValue(tython::INTEGER, result);
}

llvm::Value* SourceFileVisitor::visitBinaryOperator(TythonParser::Binary_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs) {

    if (ctx->inequality_operator()) {
        return visitInequalityOperator(ctx->inequality_operator(), lhs, rhs);
    }

    throw NotImplemented("Unimplemented binary operator \"" + ctx->getText() + "\"!");
}

llvm::Value* SourceFileVisitor::visitInequalityOperator(TythonParser::Inequality_operatorContext *ctx, llvm::Value* lhs, llvm::Value* rhs) {

    if (ctx->SYM_EQ()) {
        return this->builder->CreateICmpEQ(lhs, rhs);
    } else if (ctx->SYM_NEQ()) {
        return this->builder->CreateICmpNE(lhs, rhs);
    } else if (ctx->SYM_GT()) {
        return this->builder->CreateICmpSGT(lhs, rhs);
    } else if (ctx->SYM_GTE()) {
        return this->builder->CreateICmpSGE(lhs, rhs);
    } else if (ctx->SYM_LTE()) {
        return this->builder->CreateICmpSLE(lhs, rhs);
    } else if (ctx->SYM_LT()) {
        return this->builder->CreateICmpSLT(lhs, rhs);
    }

    throw NotImplemented("Unimplemented inequality operator \"" + ctx->getText() + "\"!");
}
