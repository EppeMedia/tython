#include "../../include/visitor/SourceFileVisitor.h"
#include <string>
#include "../../include/exception/CompileException.h"
#include "../../include/exception/NotImplemented.h"
#include <regex>
#include "type.h"
#include "exception/UnkownSymbolException.h"
#include "utils/Utils.h"
#include <spdlog/spdlog.h>

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

std::any SourceFileVisitor::visitLbl_assign_statement(TythonParser::Lbl_assign_statementContext *ctx) {

    llvm::Value* lhs;

    try {

        lhs = any_cast<llvm::Value*>(visit(ctx->lval()));

    } catch (UnknownSymbolException& e) {

        // Note that, unlike most other uses, assignment is a defining operation (identifiers that do not exist are created)
        // if a variable of this identifier is unknown, we try to create one on the fly

        auto identifierContext = dynamic_cast<TythonParser::Lbl_identifierContext*>(ctx->lval()->expression());

        if (identifierContext) {

            string identifier = identifierContext->getText();
            lhs = this->builder->CreateVariable(identifier);

        } else {
            // we can only create new object here if they are simple identifier names (i.e. not dictionary access or sequence access)
            throw CompileException("Illegal left-hand identifier for implicit declaration \"" + ctx->lval()->expression()->getText() + "\"");
        }
    }

    auto rhs = any_cast<llvm::Value*>(visit(ctx->expression()));

    this->builder->CreateGrabObject(rhs); // increment RHS reference counter
    this->builder->CreateReleaseObject(lhs); // decrement LHS ref count

    // todo: fill lhs struct
    auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());

    const auto lhs_type_ref = this->builder->CreateStructGEP(this->builder->specialization_type, lhs, 0);
    const auto lhs_content_ref = this->builder->CreateStructGEP(this->builder->specialization_type, lhs, 1);

    const auto rhs_type_ref = this->builder->CreateStructGEP(this->builder->specialization_type, rhs, 0);
    const auto rhs_type = this->builder->CreateLoad(int32_t, rhs_type_ref);
    const auto rhs_content_ref = this->builder->CreateStructGEP(this->builder->specialization_type, rhs, 1);
    const auto rhs_content = this->builder->CreateLoad(int64_t, rhs_content_ref);

    this->builder->CreateStore(rhs_type, lhs_type_ref);
    this->builder->CreateStore(rhs_content, lhs_content_ref);

    return lhs;
}

std::any SourceFileVisitor::visitLval(TythonParser::LvalContext *ctx) {

    this->builder->nestContext(TYTHON_CONTEXT_FLAG_ASSIGN);

    llvm::Value* ref;

    try {

        ref = any_cast<llvm::Value*>(visit(ctx->expression()));

    } catch (UnknownSymbolException& e) {

        this->builder->popContext();

        throw e;

    } catch (CompileException& e) {

        this->builder->popContext();

        throw e;
    }

    this->builder->popContext();

    return ref;
}

std::any SourceFileVisitor::visitLbl_assign_plus_eq(TythonParser::Lbl_assign_plus_eqContext *ctx) {

    const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lval()));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->expression()));

    auto lhs_deref = this->builder->CreateLoad(ptr_t, lhs);


    auto sum = this->builder->CreateTythonAdd(lhs_deref, rhs);

    this->builder->CreateReleaseObject(lhs_deref); // decrement LHS ref count
    this->builder->CreateGrabObject(sum);

    this->builder->CreateStore(sum, lhs);

    return lhs;
}

std::any SourceFileVisitor::visitLbl_assign_minus_eq(TythonParser::Lbl_assign_minus_eqContext *ctx) {

    const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lval()));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->expression()));

    auto lhs_deref = this->builder->CreateLoad(ptr_t, lhs);

    auto res = this->builder->CreateTythonSub(lhs_deref, rhs);

    this->builder->CreateReleaseObject(lhs_deref); // decrement LHS ref count
    this->builder->CreateGrabObject(res);

    this->builder->CreateStore(res, lhs);

    return lhs;
}

std::any SourceFileVisitor::visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) {
    return any_cast<llvm::Value*>(visit(ctx->expression()));
}

std::any SourceFileVisitor::visitSlice_lit(TythonParser::Slice_litContext *ctx) {

    llvm::Value* start = this->builder->none_object_instance;

    if (ctx->start) {
        start = any_cast<llvm::Value*>(visit(ctx->start));
    }

    llvm::Value* end = this->builder->none_object_instance;

    if (ctx->end) {
        end = any_cast<llvm::Value*>(visit(ctx->end));
    }

    llvm::Value* step = this->builder->none_object_instance;

    if (ctx->step) {
        step = any_cast<llvm::Value*>(visit(ctx->step));
    }

    // create the slice object
    auto f = this->module->findProcedure("slice");

    return (llvm::Value*)this->builder->CreateCall(f, { start, end, step }, "slice_construct");
}

std::any SourceFileVisitor::visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) {

    const auto identifier = ctx->IDENTIFIER()->getText();

    // check if the identifier exists, otherwise throw an exception
    if (auto variable = this->builder->current_context->findVariable(identifier)) {
        return variable;
    }

    throw UnknownSymbolException("Unknown symbol " + identifier);
}

std::any SourceFileVisitor::visitLbl_key_access(TythonParser::Lbl_key_accessContext *ctx) {

    // avoid not loading the mapping object if we are in an assign context
    // (in an assign context we want a reference to the result of this WHOLE key access expression)
    this->builder->nestContext();
    auto mapping_object = any_cast<llvm::Value*>(visit(ctx->obj));
    this->builder->popContext();

    this->builder->nestContext();
    auto key = any_cast<llvm::Value*>(visit(ctx->key));
    this->builder->popContext();

    auto object_ptr = this->builder->CreateSubscript(mapping_object, key);

    if (this->builder->current_context->isAssign()) {
        return object_ptr;
    }

    const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);
    return (llvm::Value*)this->builder->CreateLoad(ptr_t, object_ptr);
}

std::any SourceFileVisitor::visitLbl_slice_access(TythonParser::Lbl_slice_accessContext *ctx) {

    auto sequence_object = any_cast<llvm::Value*>(visit(ctx->expression()));

    auto slice = any_cast<llvm::Value*>(visit(ctx->slice_lit()));

    return this->builder->CreateTakeSlice(sequence_object, slice);
}

std::any SourceFileVisitor::visitLiteral(TythonParser::LiteralContext *ctx) {

    if (ctx->INT_LIT()) {

        auto raw = stoi(ctx->INT_LIT()->getText());
        auto int64_t = llvm::IntegerType::getInt64Ty(this->module->getContext());
        auto v = llvm::ConstantInt::get(int64_t, raw, true);

        return this->builder->CreateSpecInstance(SPEC_INT, v);

    } else if (ctx->FLOAT_LIT()) {

        auto raw = stod(ctx->FLOAT_LIT()->getText());
        auto double_t = llvm::Type::getDoubleTy(this->module->getContext());
        auto v = llvm::ConstantFP::get(double_t, raw);

        return this->builder->CreateSpecInstance(SPEC_FLOAT, v);

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

    } else if (ctx->NONE_LIT()) {

        return this->builder->none_object_instance;

    } else if (ctx->dict_lit()) {

        // delegate to the dictionary literal handler
        return any_cast<llvm::Value*>(visit(ctx->dict_lit()));

    } else if (ctx->list_lit()) {

        // delegate to the list literal handler
        return any_cast<llvm::Value*>(visit(ctx->list_lit()));

    } else if (ctx->tuple_lit()) {

        // delegate to the tuple literal handler
        return any_cast<llvm::Value*>(visit(ctx->tuple_lit()));
    }

    throw NotImplemented("Encountered unknown literal type. Language implementation and specification have probably diverged. Please contact the project maintainer.");
}

std::any SourceFileVisitor::visitDict_lit(TythonParser::Dict_litContext *ctx) {

    // todo: adapt to specialization struct here and in all literals

    std::vector<std::pair<llvm::Value*, llvm::Value*>> entries;
    entries.reserve(ctx->entries.size());

    for (auto& entry : ctx->entries) {

        auto key = any_cast<llvm::Value*>(visit(entry->key));
        auto value = any_cast<llvm::Value*>(visit(entry->value));

        // grab both key and value (the dictionary references them of course)
        this->builder->CreateGrabObject(key);
        this->builder->CreateGrabObject(value);

        entries.emplace_back(key, value);
    }

    auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    auto entry_count = llvm::ConstantInt::get(int32_t, entries.size());

    return this->builder->CreateDictLiteral(entry_count, entries);
}

std::any SourceFileVisitor::visitList_lit(TythonParser::List_litContext *ctx) {

    std::vector<llvm::Value*> elements;
    elements.reserve(ctx->elements.size());

    for (auto& element : ctx->elements) {

        auto v = any_cast<llvm::Value*>(visit(element));

        // grab a reference to the value (the list references it)
        this->builder->CreateGrabObject(v);

        elements.push_back(v);
    }

    auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    auto entry_count = llvm::ConstantInt::get(int32_t, elements.size());

    return this->builder->CreateListLiteral(entry_count, elements);
}

std::any SourceFileVisitor::visitTuple_lit(TythonParser::Tuple_litContext *ctx) {

    std::vector<llvm::Value*> elements;
    elements.reserve(ctx->elements.size());

    for (auto& element : ctx->elements) {

        auto v = any_cast<llvm::Value*>(visit(element));

        // grab a reference to the value (the tuple references it)
        this->builder->CreateGrabObject(v);

        elements.push_back(v);
    }

    auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    auto entry_count = llvm::ConstantInt::get(int32_t, elements.size());

    return this->builder->CreateTupleLiteral(entry_count, elements);
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

        if (!br_true->getTerminator()) {
            this->builder->CreateBr(br_end);
        }
    }

    { // if_else

        this->builder->SetInsertPoint(br_else_if);

        if (ctx->br_else_if) {
            visit(ctx->br_else_if);
        }

        if (!br_else_if->getTerminator()) {
            this->builder->CreateBr(br_end);
        }
    }

    { // else

        this->builder->SetInsertPoint(br_else);

        if (ctx->br_else) {
            visit(ctx->br_else);
        }

        if (!br_else->getTerminator()) {
            this->builder->CreateBr(br_end);
        }
    }

    this->builder->SetInsertPoint(br_end);

    return nullptr;
}

std::any SourceFileVisitor::visitFor_loop(TythonParser::For_loopContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_pre = llvm::BasicBlock::Create(this->builder->getContext(), "pre_for", f, nullptr);
    llvm::BasicBlock* br_for = llvm::BasicBlock::Create(this->builder->getContext(), "for", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_for", f, nullptr);

    this->builder->nestContext(TYTHON_CONTEXT_FLAG_LOOP | TYTHON_CONTEXT_FLAG_LEX_BLOCK)->exit = br_end;

    if (ctx->KW_IN()) {

        // create or obtain the induction variable
        const auto it_name = ctx->IDENTIFIER()->getText();
        llvm::Value* it_var;

        if (!(it_var = this->builder->current_context->findVariable(it_name))) {
            it_var = this->builder->CreateVariable(it_name);
        }

        // obtain an iterator for the iterable
        const auto iterable = any_cast<llvm::Value*>(visit(ctx->expression()));
        const auto it = this->builder->CreateGetIterator(iterable);

        // grab a reference to the iterator
        this->builder->CreateGrabObject(it);

        // start pre header
        this->builder->CreateBr(br_pre);
        this->builder->SetInsertPoint(br_pre);

        // test the iterator state, not the iterator value (which often starts at zero, which would be falsy)
        auto test = this->builder->CreateObjectIsTruthy(it); // todo: this could happen as a comparison (magic method) between the result of the expression and the True (or False) unique objects instead

        // increment iterator, obtains stale value
        auto it_value = this->builder->CallIteratorNext(it);

        // grab a reference to the iterator value
        this->builder->CreateGrabObject(it_value);

        // bind the stale iterator value to the induction variable
        this->builder->CreateStore(it_value, it_var);

        const auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
        const auto zero = llvm::ConstantInt::get(int32_t, 0, true);

        const auto check = this->builder->CreateICmpSGT(test, zero);

        this->builder->CreateCondBr(check, br_for, br_end);

    } else {

        this->builder->CreateBr(br_pre);
        this->builder->SetInsertPoint(br_pre);

        auto expression_value = any_cast<llvm::Value*>(visit(ctx->expression()));

        auto test = this->builder->CreateObjectIsTruthy(expression_value); // todo: this could happen as a comparison (magic method) between the result of the expression and the True (or False) unique objects instead

        const auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
        const auto zero = llvm::ConstantInt::get(int32_t, 0, true);

        const auto check = this->builder->CreateICmpSGT(test, zero);

        this->builder->CreateCondBr(check, br_for, br_end);
    }

    this->builder->SetInsertPoint(br_for);
    visit(ctx->block());
    this->builder->CreateBr(br_pre);

    this->builder->SetInsertPoint(br_end);

    this->builder->popContext();

    return nullptr;
}

std::any SourceFileVisitor::visitWhile_loop(TythonParser::While_loopContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_pre = llvm::BasicBlock::Create(this->builder->getContext(), "pre_while", f, nullptr);
    llvm::BasicBlock* br_while = llvm::BasicBlock::Create(this->builder->getContext(), "while", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_while", f, nullptr);

    this->builder->nestContext(TYTHON_CONTEXT_FLAG_LOOP | TYTHON_CONTEXT_FLAG_LEX_BLOCK)->exit = br_end;

    this->builder->CreateBr(br_pre);
    this->builder->SetInsertPoint(br_pre);

    auto expression_value = any_cast<llvm::Value*>(visit(ctx->expression()));

    auto test = this->builder->CreateObjectIsTruthy(expression_value); // todo: this could happen as a comparison (magic method) between the result of the expression and the True (or False) unique objects instead

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    const auto zero = llvm::ConstantInt::get(int32_t, 0, true);

    const auto check = this->builder->CreateICmpSGT(test, zero);

    this->builder->CreateCondBr(check, br_while, br_end);

    this->builder->SetInsertPoint(br_while);
    visit(ctx->block());
    this->builder->CreateBr(br_pre);

    this->builder->SetInsertPoint(br_end);

    this->builder->popContext();

    return nullptr;
}

std::any SourceFileVisitor::visitBlock(TythonParser::BlockContext *ctx) {

    this->builder->nestContext(TYTHON_CONTEXT_FLAG_LEX_BLOCK);

    TythonParserBaseVisitor::visitBlock(ctx);

    /*
     * The following avoids inserting GC code after a terminating instruction.
     */

    // if this block is terminated explicitly (i.e. by a return statement), insert the cleanup code just before that terminator.
    llvm::Instruction* terminator;
    if ((terminator = this->builder->GetInsertBlock()->getTerminator())) {
        this->builder->SetInsertPoint(terminator);
    }

    this->builder->popContext();

    if (terminator) {
        // resume at the end of the block (at the terminating instruction)
        this->builder->SetInsertPoint(this->builder->GetInsertBlock());
    }

    return nullptr;
}

std::any SourceFileVisitor::visitSimple_statement(TythonParser::Simple_statementContext *ctx) {

    if (this->builder->current_context->isComplete()) {
        throw CompileException("Unreachable statement at line " + std::to_string(ctx->getStart()->getLine()) + "!");
    }

    return TythonParserBaseVisitor::visitSimple_statement(ctx);
}

std::any SourceFileVisitor::visitCompound_statement(TythonParser::Compound_statementContext *ctx) {

    if (this->builder->current_context->isComplete()) {
        throw CompileException("Unreachable statement at line " + std::to_string(ctx->getStart()->getLine()) + "!");
    }

    return TythonParserBaseVisitor::visitCompound_statement(ctx);
}

std::any SourceFileVisitor::visitBreak_statement(TythonParser::Break_statementContext *ctx) {

    ASSERT_LEXICAL_BLOCK_CONTEXT

    // identify parent loop
    Context* context = this->builder->current_context;
    while (context && !context->isLoop()) {
        context = context->parent;
    }

    if (context) {
        // check if this loop has a valid exit block
        if (!context->exit) {
            throw CompileException("Illegal state: break in a loop with no exit!");
        }

        if (!context->isLexicalBlock()) {
            throw CompileException("Illegal state: break in a loop outside a lexical block!");
        }

        this->builder->current_context->setComplete();

        return this->builder->CreateBr(context->exit);
    }

    throw CompileException("Break statement outside loop definition.");
}

std::any SourceFileVisitor::visitFunction_def(TythonParser::Function_defContext *ctx) {

    auto identifier = ctx->IDENTIFIER()->getText();

    // create a new scope for this function's arguments. The body scope of the function will be nested in this.
    this->builder->nestContext();

    // function declarations are fully opaque; we only know that it will return an object (may be None), and that it takes either at most n, or a variable number of arguments
    auto return_type = llvm::PointerType::get(this->builder->object_type, 0);
    auto ptr_type = llvm::PointerType::get(this->builder->getContext(), 0);

    std::vector<llvm::Type*> arg_types;

    for (int i = 0; i < ctx->arguments()->args.size(); ++i) {
        arg_types.push_back(ptr_type);
    }

    const bool isVarArgs = ctx->SYM_ELLIPS();

    llvm::FunctionType* ft = llvm::FunctionType::get(return_type, arg_types, isVarArgs);
    auto fn = llvm::Function::Create(ft, llvm::GlobalValue::ExternalLinkage, identifier, this->module);

    this->module->registerProcedure(fn, identifier);

    auto old_bb = this->builder->GetInsertBlock();

    auto prologue = llvm::BasicBlock::Create(this->builder->getContext(), "prologue", fn);
    this->builder->SetInsertPoint(prologue);

    visit(ctx->arguments());

    auto body = llvm::BasicBlock::Create(this->builder->getContext(), "body", fn);
    this->builder->CreateBr(body);
    this->builder->SetInsertPoint(body);

    visitBlock(ctx->block());

    /*
     * The following avoids inserting GC code after a terminating instruction.
     */
    llvm::Instruction* terminator;
    if ((terminator = this->builder->GetInsertBlock()->getTerminator())) {
        this->builder->SetInsertPoint(terminator);
    }

    this->builder->popContext();

    if (terminator) {

        // resume at the end of the block (at the terminating instruction)
        this->builder->SetInsertPoint(this->builder->GetInsertBlock());

    } else {

        // create implicit return None

        auto epilogue = llvm::BasicBlock::Create(this->builder->getContext(), "epilogue", fn);
        this->builder->CreateBr(epilogue);
        this->builder->SetInsertPoint(epilogue);

        this->builder->CreateRet(this->builder->none_object_instance);
    }

    this->builder->SetInsertPoint(old_bb);

    return nullptr;
}

std::any SourceFileVisitor::visitReturn_statement(TythonParser::Return_statementContext *ctx) {

    ASSERT_LEXICAL_BLOCK_CONTEXT

    const auto ret_val = any_cast<llvm::Value*>(visit(ctx->expression()));

    this->builder->CreateGrabObject(ret_val);

    this->builder->current_context->setComplete();

    // todo: this should only return specialized types!! This is just for testing
    // load the content of the return value, and return that
    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto ref = this->builder->CreateStructGEP(this->builder->specialization_type, ret_val, 1);
    const auto content = this->builder->CreateLoad(int64_t, ref);
    return this->builder->CreateRet(content);

    // todo: that's the old way:
//    return this->builder->CreateRet(ret_val);
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

    if (f) {

        // check if the number of parameters match
        if (f->arg_size() != ctx->parameters()->params.size()) {
            const auto msg = std::format("Expected {} arguments, found {}.", f->arg_size(), ctx->parameters()->params.size());
            utils::log_warn(module, ctx, msg);
        }

    } else {

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

    // grab reference to parameters
    for (auto& v : params) {
        this->builder->CreateGrabObject(v);
    }

    llvm::Value* result = this->builder->CreateCall(f, params);

    // release param objects
    for (auto& v : params) {
        this->builder->CreateReleaseObject(v);
    }

    return result;
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
        auto v = this->builder->GetInsertBlock()->getParent()->getArg(i);

        auto dataEntry = this->builder->CreateVariable(identifier);

        /*
         * todo:
         * First-class data arguments are passed by value, other types are passed by reference.
         * Implementation-wise, this is probably already partly achieved by our setup (i.e. a value pass of a sequence is a new sequence referencing the same elements as the original)
         * We'll have to have another look when we implement objects (class instances)
         */

        // grab a reference to the argument value
        this->builder->CreateGrabObject(v);

        // assign the passed argument value to the new variable
        this->builder->CreateStore(v, dataEntry);

        vars.push_back(dataEntry);
    }

    return vars;
}

std::any SourceFileVisitor::visitLbl_exponent_expr(TythonParser::Lbl_exponent_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonExp(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_mult_expr(TythonParser::Lbl_mult_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonMult(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_div_expr(TythonParser::Lbl_div_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonDiv(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_add_expr(TythonParser::Lbl_add_exprContext *ctx) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->builder->getContext());
    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());

    // todo: assume everything is in spec-form
    const auto lhs_spec = this->builder->current_context->findVariable(ctx->lhs->getText());
    const auto rhs_spec = this->builder->current_context->findVariable(ctx->rhs->getText());

    const auto lhs_type_enum_ref= this->builder->CreateStructGEP(this->builder->specialization_type, lhs_spec, 0);
    const auto lhs_type_enum = this->builder->CreateLoad(int32_t, lhs_type_enum_ref, "lhs_type_enum");

    llvm::Value* result_spec = this->builder->CreateAlloca(this->builder->specialization_type); // todo: why on stack? Can leak garbage if used in function return...

    // todo: do a specialization guard here

    // SWITCH on lhs type enumerator
    const auto exit_block = llvm::BasicBlock::Create(this->builder->getContext(), "switch_exit_block", this->builder->GetInsertBlock()->getParent());
    const auto catchall_block = llvm::BasicBlock::Create(this->builder->getContext(), "catchall_block", this->builder->GetInsertBlock()->getParent(), exit_block);
    const auto switch_value = this->builder->CreateSwitch(lhs_type_enum, catchall_block, 2); // todo: 1 case...

    const auto obj_type_enum_value = llvm::ConstantInt::get(int32_t, SPEC_OBJ);
    switch_value->addCase(obj_type_enum_value, catchall_block);

    // CASE lhs is INT
    {
        const auto int_spec_block = llvm::BasicBlock::Create(this->builder->getContext(), "int_spec_block",
                                                             this->builder->GetInsertBlock()->getParent(), exit_block);

        this->builder->SetInsertPoint(int_spec_block);

        // if rhs is also INT, do simple add, else delegate to catchall function
        const auto int_type_enum_value = llvm::ConstantInt::get(int32_t, SPEC_INT);
        const auto rhs_type_enum_ref = this->builder->CreateStructGEP(this->builder->specialization_type, rhs_spec, 0, "rhs_type_enum");
        const auto rhs_type_enum = this->builder->CreateLoad(int32_t, rhs_type_enum_ref);

        const auto rhs_is_int = this->builder->CreateICmpEQ( rhs_type_enum, int_type_enum_value, "rhs_type_check");

        const auto simple_block = llvm::BasicBlock::Create(this->builder->getContext(), "simple_block",
                                                           this->builder->GetInsertBlock()->getParent());

        this->builder->CreateCondBr(rhs_is_int, simple_block, catchall_block);

        this->builder->SetInsertPoint(simple_block);

        // we know both lhs and rhs are integer values, so let's do a simple 'add' instruction on their contents
        const auto lhs_value_ref = this->builder->CreateStructGEP(this->builder->specialization_type, lhs_spec, 1);
        const auto rhs_value_ref = this->builder->CreateStructGEP(this->builder->specialization_type, rhs_spec, 1);

        const auto lhs_value = this->builder->CreateLoad(int64_t, lhs_value_ref, "lhs_value");
        const auto rhs_value = this->builder->CreateLoad(int64_t, rhs_value_ref, "rhs_value");

        const auto sum = this->builder->CreateAdd(lhs_value, rhs_value, "sum");

        // initialize the result spec struct
        const auto int_type_enum_value2 = llvm::ConstantInt::get(int64_t, SPEC_INT);

        this->builder->CreateStore(int_type_enum_value2, result_spec);
        const auto ref = this->builder->CreateStructGEP(this->builder->specialization_type, result_spec, 1);
//        const auto sum_bitcast = this->builder->CreateBitCast(sum, int64_t);
        this->builder->CreateStore(sum, ref);

        const auto int_type_enum_value3 = llvm::ConstantInt::get(int32_t, SPEC_INT);
        switch_value->addCase(int_type_enum_value3, int_spec_block);

        this->builder->CreateBr(exit_block);
    }

    // todo: populate catchall block
    this->builder->SetInsertPoint(catchall_block);

    // delegate to some external API function that takes two spec structs as input

    this->builder->CreateBr(exit_block);

    this->builder->SetInsertPoint(exit_block);

    return result_spec;

//    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
//    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));
//
//    return this->builder->CreateTythonAdd(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_sub_expr(TythonParser::Lbl_sub_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonSub(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_and_expr(TythonParser::Lbl_and_exprContext *ctx) {

    // todo: implement
    throw NotImplemented("Logical binary operators are not yet implemented!");
}

std::any SourceFileVisitor::visitLbl_or_expr(TythonParser::Lbl_or_exprContext *ctx) {

    // todo: implement
    throw NotImplemented("Logical binary operators are not yet implemented!");
}

std::any SourceFileVisitor::visitLbl_neq_expr(TythonParser::Lbl_neq_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateRichCmp(lhs, rhs, TYTHON_CMP_OP_NEQ);
}

std::any SourceFileVisitor::visitLbl_lt_expr(TythonParser::Lbl_lt_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateRichCmp(lhs, rhs, TYTHON_CMP_OP_LT);
}

std::any SourceFileVisitor::visitLbl_lte_expr(TythonParser::Lbl_lte_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateRichCmp(lhs, rhs, TYTHON_CMP_OP_LTE);
}

std::any SourceFileVisitor::visitLbl_eq_expr(TythonParser::Lbl_eq_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateRichCmp(lhs, rhs, TYTHON_CMP_OP_EQ);
}

std::any SourceFileVisitor::visitLbl_gt_expr(TythonParser::Lbl_gt_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateRichCmp(lhs, rhs, TYTHON_CMP_OP_GT);
}

std::any SourceFileVisitor::visitLbl_gte_expr(TythonParser::Lbl_gte_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateRichCmp(lhs, rhs, TYTHON_CMP_OP_GTE);
}

std::any SourceFileVisitor::visitLbl_method_call(TythonParser::Lbl_method_callContext *ctx) {

    const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);

    auto method_name_str = ctx->call_expression()->IDENTIFIER()->getText();
    auto object_ref = any_cast<llvm::Value*>(visit(ctx->expression()));
    auto object = this->builder->CreateLoad(ptr_t, object_ref);

    auto method_name = this->builder->CreateGlobalString(method_name_str, method_name_str, 0, this->module);

    // todo: implement non-builtin methods (class-member callables)
    auto f_ptr = this->builder->CreateResolveBuiltinMethod(object, method_name);

    auto args = visitInternalCallParameters(ctx->call_expression()->parameters());
    args.insert(args.begin(), object);

    auto f_type = llvm::FunctionType::get(ptr_t, true); // todo: we can determine the number of arguments and just pretend/assume they're all opaque pointers

    return (llvm::Value*)this->builder->CreateCall(f_type, f_ptr, args);
}

std::any SourceFileVisitor::visitLbl_inc_prefix(TythonParser::Lbl_inc_prefixContext *ctx) {

    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto ptr_t = llvm::PointerType::get(this->builder->object_type, 0);

    // get lval
    this->builder->nestContext(TYTHON_CONTEXT_FLAG_ASSIGN);
    const auto lval_ref = any_cast<llvm::Value*>(visit(ctx->expression()));
    this->builder->popContext();
    const auto lval = this->builder->CreateLoad(ptr_t, lval_ref);

    const auto one = llvm::ConstantInt::get(int64_t, 1, true);

    const auto one_val = this->builder->CreateIntObject(one);

    // add and return the sum
    auto const sum = this->builder->CreateTythonAdd(lval, one_val);
    this->builder->CreateStore(sum, lval_ref);

    return sum;
}

std::any SourceFileVisitor::visitLbl_inc_suffix(TythonParser::Lbl_inc_suffixContext *ctx) {

    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto ptr_t = llvm::PointerType::get(this->builder->object_type, 0);

    // get lval
    this->builder->nestContext(TYTHON_CONTEXT_FLAG_ASSIGN);
    const auto lval_ref = any_cast<llvm::Value*>(visit(ctx->expression()));
    this->builder->popContext();
    const auto lval = this->builder->CreateLoad(ptr_t, lval_ref);

    const auto zero = llvm::ConstantInt::get(int64_t, 0, true);
    const auto one = llvm::ConstantInt::get(int64_t, 1, true);

    const auto zero_val = this->builder->CreateIntObject(zero);
    const auto one_val = this->builder->CreateIntObject(one);

    // keep a copy of the old value
    auto const old = this->builder->CreateTythonAdd(lval, zero_val); // handy trick

    // add and return the sum
    auto const sum = this->builder->CreateTythonAdd(lval, one_val);
    this->builder->CreateStore(sum, lval_ref);

    return old;
}

std::any SourceFileVisitor::visitLbl_dec_prefix(TythonParser::Lbl_dec_prefixContext *ctx) {

    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto ptr_t = llvm::PointerType::get(this->builder->object_type, 0);

    // get lval
    this->builder->nestContext(TYTHON_CONTEXT_FLAG_ASSIGN);
    const auto lval_ref = any_cast<llvm::Value*>(visit(ctx->expression()));
    this->builder->popContext();
    const auto lval = this->builder->CreateLoad(ptr_t, lval_ref);

    const auto one = llvm::ConstantInt::get(int64_t, 1, true);

    const auto one_val = this->builder->CreateIntObject(one);

    // add and return the diff
    auto const dif = this->builder->CreateTythonSub(lval, one_val);
    this->builder->CreateStore(dif, lval_ref);

    return dif;
}

std::any SourceFileVisitor::visitLbl_dec_suffix(TythonParser::Lbl_dec_suffixContext *ctx) {

    const auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    const auto ptr_t = llvm::PointerType::get(this->builder->object_type, 0);

    // get lval
    this->builder->nestContext(TYTHON_CONTEXT_FLAG_ASSIGN);
    const auto lval_ref = any_cast<llvm::Value*>(visit(ctx->expression()));
    this->builder->popContext();
    const auto lval = this->builder->CreateLoad(ptr_t, lval_ref);

    const auto zero = llvm::ConstantInt::get(int64_t, 0, true);
    const auto one = llvm::ConstantInt::get(int64_t, 1, true);

    const auto zero_val = this->builder->CreateIntObject(zero);
    const auto one_val = this->builder->CreateIntObject(one);

    // keep a copy of the old value
    auto const old = this->builder->CreateTythonAdd(lval, zero_val); // handy trick

    // add and return the diff
    auto const dif = this->builder->CreateTythonSub(lval, one_val);
    this->builder->CreateStore(dif, lval_ref);

    return old;
}
