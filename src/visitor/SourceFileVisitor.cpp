#include "../../include/visitor/SourceFileVisitor.h"
#include <string>
#include "../../include/exception/CompileException.h"
#include "../../include/exception/NotImplemented.h"

std::any SourceFileVisitor::visitAssign_statement(TythonParser::Assign_statementContext *ctx) {

    string identifier = ctx->IDENTIFIER()->getText();
    auto value = any_cast<Value*>(visitAtomic(ctx->atomic()));

    // resolve identifier
    auto dataEntry = this->builder->current_scope->findDataEntry(identifier);

    // if a variable of this identifier is unknown, we create one on the fly
    if (!dataEntry) {
        dataEntry = this->builder->CreateVariable(identifier);
    }

    // get reference to target content field
    auto content = builder->getContent(dataEntry);

    this->builder->CreateStore(value->content, content);
    // update shadow
    dataEntry->value = value;

    return nullptr;
}

std::any SourceFileVisitor::visitAtomic(TythonParser::AtomicContext *ctx) {

    if (auto identifier = ctx->IDENTIFIER()) {

        // fetch the identifier if it exists, otherwise throw exception
        if (auto dataEntry = this->builder->current_scope->findDataEntry(identifier->getText())) {
//            return dataEntry->value; // todo: we can do this iff we know that the variable's value was declared in this same (function-level) scope! Note: it's a bit hard to distinguish a function level at the moment, we can restrict it to stricly "his scope" first.
            return new Value(dataEntry->value->type, this->builder->getValueContent(dataEntry));
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

        return this->builder->CreateValue(tython::Type::STRING, bytes);
    }

    throw NotImplemented("Encountered unknown literal type. Language implementation and specification have probably diverged. Please contact the project maintainer.");
}

std::any SourceFileVisitor::visitIf_statement(TythonParser::If_statementContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_true = llvm::BasicBlock::Create(this->builder->getContext(), "if_true", f, nullptr);
    llvm::BasicBlock* br_else = llvm::BasicBlock::Create(this->builder->getContext(), "if_else", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "if_end", f, nullptr);

    auto expression_value = any_cast<Value*>(visitExpression(ctx->expression()));
    auto condition = this->builder->getContent(expression_value);
    auto load = this->builder->CreateLoad(this->builder->getLLVMType(expression_value->type), condition);

    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto zero = llvm::ConstantInt::get(int64_t, 0, true);

    auto check = this->builder->CreateICmpSLT(load, zero);

    this->builder->CreateCondBr(check, br_true, br_else);

    { // true

        this->builder->SetInsertPoint(br_true);

        visit(ctx->br_true);

        this->builder->CreateBr(br_end);
    }

    { // false

        this->builder->SetInsertPoint(br_else);

        if (ctx->KW_ELSE()) {
            visit(ctx->br_else);
        }

        this->builder->CreateBr(br_end);
    }

    this->builder->SetInsertPoint(br_end);

    return nullptr;
}

std::any SourceFileVisitor::visitBlock(TythonParser::BlockContext *ctx) {

    auto block_scope = new Scope(this->builder->current_scope);
    this->builder->current_scope = block_scope;

    for (auto s : ctx->statement()) {
        TythonBaseVisitor::visitStatement(s);
    }

    this->builder->current_scope = this->builder->current_scope->parent;

    return nullptr;
}

std::any SourceFileVisitor::visitFunction(TythonParser::FunctionContext *ctx) {

    auto identifier = ctx->IDENTIFIER()->getText();

    // create a new scope for this function's arguments. The body scope of the function will be nested in this.
    this->builder->current_scope = new Scope(this->builder->current_scope);

    // function declarations are fully opaque; we only know that it may return something, and that it takes n variable arguments
    // todo: check if there is any returns, then return (variable) ptr type, otherwise return void.
    auto void_type = llvm::Type::getVoidTy(this->builder->getContext());
    auto ptr_type = llvm::PointerType::get(this->builder->getContext(), 0);

    std::vector<llvm::Type*> arg_types;

    for (int i = 0; i < ctx->arguments()->args.size(); ++i) {
        arg_types.push_back(ptr_type);
    }

    llvm::FunctionType* ft = llvm::FunctionType::get(void_type, arg_types, false);
    auto fn = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage, identifier, this->module);

    this->module->registerProcedure(fn, identifier);

    auto old_bb = this->builder->GetInsertBlock();

    auto prologue = llvm::BasicBlock::Create(this->builder->getContext(), "prologue", fn);
    this->builder->SetInsertPoint(prologue);

    visit(ctx->arguments());

    auto body = llvm::BasicBlock::Create(this->builder->getContext(), "body", fn);
    this->builder->CreateBr(body);
    this->builder->SetInsertPoint(body);

    visit(ctx->block());

    auto epilogue = llvm::BasicBlock::Create(this->builder->getContext(), "epilogue", fn);
    this->builder->CreateBr(epilogue);
    this->builder->SetInsertPoint(epilogue);

    // todo: currently, the block is always "epilogue", and that block has no content a all (the check below is trivially true)
    // check if we have a return statement
    if (!this->builder->GetInsertBlock()->getTerminator()) {
        this->builder->CreateRetVoid();
    }

    // pop scope
    this->builder->current_scope = this->builder->current_scope->parent;

    this->builder->SetInsertPoint(old_bb);

    return nullptr;
}

std::any SourceFileVisitor::visitCall_expression(TythonParser::Call_expressionContext *ctx) {

    auto f = this->module->findProcedure(ctx->IDENTIFIER()->getText());

    if (!f) {
        throw CompileException("Undefined reference to function \"" + ctx->IDENTIFIER()->getText() + "\".");
    }

    auto params = any_cast<std::vector<llvm::Value*>>(visit(ctx->parameters()));

    return this->builder->CreateCall(f, params);
}

std::any SourceFileVisitor::visitParameters(TythonParser::ParametersContext *ctx) {

    std::vector<Value*> values;
    values.reserve(ctx->params.size());

    for (auto p : ctx->params) {
        values.push_back(any_cast<Value*>(TythonBaseVisitor::visitExpression(p)));
    }

//
//    std::transform(ctx->params.begin(), ctx->params.end(), values.begin(),
//                   [this](auto p){ return any_cast<Value*>(TythonBaseVisitor::visitExpression(p)); });

    std::vector<llvm::Value*> params;
    params.reserve(values.size());
//
//    std::transform(values.begin(), values.end(), params.begin(),
//                   [this](Value* v){ return builder->getContent(v); });

    for (auto v : values) {
        params.push_back(builder->getContent(v));
    }

    return params;
}

std::any SourceFileVisitor::visitArguments(TythonParser::ArgumentsContext *ctx) {

    std::vector<Variable*> vars(ctx->args.size());

    for (int i = 0; i < ctx->args.size(); ++i) {

        auto identifier = ctx->args.at(i)->getText();
        auto v = this->builder->GetInsertBlock()->getParent()->getArg(i); // todo: seems like a stack member to me, it will probably be deleted wih the call frame. What would then if we assign it to a global variable?

        // resolve identifier
        auto dataEntry = this->builder->current_scope->findDataEntry(identifier);

        // if a variable of this identifier is unknown, we create one on the fly
        if (!dataEntry) {
            dataEntry = this->builder->CreateVariable(identifier);
        }

        // assign the passed argument value to the new variable
        auto target = this->builder->getContent(dataEntry);
        this->builder->CreateStore(v, target);
        dataEntry->value = new Value(tython::Type::UNKNOWN, v);

        vars.push_back(dataEntry);
    }

    return vars;
}
