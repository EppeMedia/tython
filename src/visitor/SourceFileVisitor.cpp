#include "../../include/visitor/SourceFileVisitor.h"
#include <string>
#include "../../include/exception/CompileException.h"
#include "../../include/exception/NotImplemented.h"
#include <regex>
#include "type.h"
#include "api/api.h"
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

    std::function<void (llvm::Value*)> rhs_handler;

    try {

        this->builder->nestContext(TYTHON_CONTEXT_FLAG_ASSIGN);

        try {

            rhs_handler = any_cast<std::function<void (llvm::Value*)>>(visit(ctx->lval()));

        } catch (UnknownSymbolException& e) {

            this->builder->popContext();

            throw e;

        } catch (CompileException& e) {

            this->builder->popContext();

            throw e;
        }

        this->builder->popContext();

    } catch (UnknownSymbolException& e) {

        // Note that, unlike most other uses, assignment is a defining operation (identifiers that do not exist are created)
        // if a variable of this identifier is unknown, we try to create one on the fly

        auto identifierContext = dynamic_cast<TythonParser::Lbl_lval_identifierContext*>(ctx->lval());

        if (identifierContext) {

            string identifier = identifierContext->getText();
            const auto variable = this->builder->CreateVariable(identifier);

            rhs_handler = [this, variable](llvm::Value* rhs) -> void {
                this->builder->CreateAssign(variable, rhs);
            };

        } else {

            // we can only create new object here if they are simple identifier names (i.e. not dictionary access or sequence access)
            throw CompileException("Illegal left-hand identifier for implicit declaration \"" + ctx->lval()->getText() + "\"");
        }
    }

    auto rhs = any_cast<llvm::Value*>(visit(ctx->expression()));

    rhs_handler(rhs);

    return rhs;
}

std::any SourceFileVisitor::visitLbl_lval_identifier(TythonParser::Lbl_lval_identifierContext *ctx) {

    const auto identifier = ctx->IDENTIFIER()->getText();

    // check if the identifier exists, otherwise throw an exception
    if (auto variable = this->builder->current_context->findVariable(identifier)) {

        std::function<void (llvm::Value*)> rhs_handler = [this, variable](llvm::Value* rhs) -> void {

            this->builder->CreateGrabObject(rhs); // increment RHS reference counter
            this->builder->CreateReleaseObject(rhs); // decrement LHS ref count

            this->builder->CreateAssign(variable, rhs);
        };

        return rhs_handler;
    }

    throw UnknownSymbolException("Unknown symbol " + identifier);
}

std::any SourceFileVisitor::visitLbl_lval_key_access(TythonParser::Lbl_lval_key_accessContext *ctx) {

    auto instance = any_cast<llvm::Value*>(visit(ctx->obj));

    auto key = any_cast<llvm::Value*>(visit(ctx->key));

    std::function<void (llvm::Value*)> rval_handler = [this, instance, key](llvm::Value* rhs) -> void {

        auto f = this->module->tython__set__func;

        this->builder->CreateCall(*f, { instance, key, rhs });
    };

    return rval_handler;
}

std::any SourceFileVisitor::visitLbl_assign_plus_eq(TythonParser::Lbl_assign_plus_eqContext *ctx) {

    auto operand = any_cast<llvm::Value*>(visit(ctx->expression()));
    llvm::Value* assign_value;

    if (auto key_ctx = dynamic_cast<TythonParser::Lbl_lval_key_accessContext*>(ctx->lval())) {

        // get the object and do the subtraction, then set assign value to that result
        auto instance = any_cast<llvm::Value*>(visit(key_ctx->obj));
        auto key = any_cast<llvm::Value*>(visit(key_ctx->key));

        auto e_ref_spec = this->builder->CreateSubscript(instance, key);
        auto e_ref = this->builder->CreateGetObjectPrimitive(e_ref_spec);
        const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);
        auto e = this->builder->CreateLoad(ptr_t, e_ref);
        auto e_spec = this->builder->CreateSpecInstance(SPEC_OBJECT, e);

        assign_value = this->builder->CreateTythonAdd(e_spec, operand);

    } else if (auto id_ctx = dynamic_cast<TythonParser::Lbl_lval_identifierContext*>(ctx->lval())) {

        const auto identifier = id_ctx->IDENTIFIER()->getText();

        if (auto variable = this->builder->current_context->findVariable(identifier)) {

            const auto variable_value = this->builder->CreateLoad(this->module->specialization_type, variable);

            assign_value = this->builder->CreateTythonAdd(variable_value, operand);

        } else {

            throw UnknownSymbolException("Unknown symbol " + identifier);
        }
    }

//    this->builder->CreateReleaseObject(lhs_deref); // decrement LHS ref count
//    this->builder->CreateGrabObject(assign_value);

    const auto rhs_handler = any_cast<std::function<void (llvm::Value*)>>(visit(ctx->lval()));

    rhs_handler(assign_value);

    return assign_value;
}

std::any SourceFileVisitor::visitLbl_assign_minus_eq(TythonParser::Lbl_assign_minus_eqContext *ctx) {

    auto operand = any_cast<llvm::Value*>(visit(ctx->expression()));
    llvm::Value* assign_value;

    if (auto key_ctx = dynamic_cast<TythonParser::Lbl_lval_key_accessContext*>(ctx->lval())) {

        // get the object and do the subtraction, then set assign value to that result
        auto instance = any_cast<llvm::Value*>(visit(key_ctx->obj));
        auto key = any_cast<llvm::Value*>(visit(key_ctx->key));

        auto e_ref_spec = this->builder->CreateSubscript(instance, key);
        auto e_ref = this->builder->CreateGetObjectPrimitive(e_ref_spec);
        const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);
        auto e = this->builder->CreateLoad(ptr_t, e_ref);
        auto e_spec = this->builder->CreateSpecInstance(SPEC_OBJECT, e);

        assign_value = this->builder->CreateTythonSub(e_spec, operand);

    } else if (auto id_ctx = dynamic_cast<TythonParser::Lbl_lval_identifierContext*>(ctx->lval())) {

        const auto identifier = id_ctx->IDENTIFIER()->getText();

        if (auto variable = this->builder->current_context->findVariable(identifier)) {

            const auto variable_value = this->builder->CreateLoad(this->module->specialization_type, variable);

            assign_value = this->builder->CreateTythonSub(variable_value, operand);

        } else {

            throw UnknownSymbolException("Unknown symbol " + identifier);
        }
    }

//    this->builder->CreateReleaseObject(lhs_deref); // decrement LHS ref count
//    this->builder->CreateGrabObject(assign_value);

    const auto rhs_handler = any_cast<std::function<void (llvm::Value*)>>(visit(ctx->lval()));

    rhs_handler(assign_value);

    return assign_value;
}

std::any SourceFileVisitor::visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) {
    return any_cast<llvm::Value*>(visit(ctx->expression()));
}

std::any SourceFileVisitor::visitSlice_lit(TythonParser::Slice_litContext *ctx) {

    llvm::Value* start = this->builder->CreateNoneSpec();

    if (ctx->start) {
        start = any_cast<llvm::Value*>(visit(ctx->start));
    }

    llvm::Value* end = this->builder->CreateNoneSpec();

    if (ctx->end) {
        end = any_cast<llvm::Value*>(visit(ctx->end));
    }

    llvm::Value* step = this->builder->CreateNoneSpec();

    if (ctx->step) {
        step = any_cast<llvm::Value*>(visit(ctx->step));
    }

    // create the slice object
    auto f = this->module->tython_slice_func;

    return (llvm::Value*)this->builder->CreateCall((llvm::Function*)f->getCallee(), { start, end, step }, "slice_construct");
}

std::any SourceFileVisitor::visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) {

    const auto identifier = ctx->IDENTIFIER()->getText();

    // check if the identifier exists, otherwise throw an exception
    if (auto variable = this->builder->current_context->findVariable(identifier)) {
        return (llvm::Value*)this->builder->CreateLoad(this->module->specialization_type, variable, identifier);
    }

    utils::log_warn(this->module, ctx, "Unknown symbol " + identifier);
    throw UnknownSymbolException("Unknown symbol " + identifier);
}

std::any SourceFileVisitor::visitLbl_key_access(TythonParser::Lbl_key_accessContext *ctx) {

    // avoid not loading the mapping object if we are in an assign context
    // (in an assign context we want a reference to the result of this WHOLE key access expression)
    auto mapping_object = any_cast<llvm::Value*>(visit(ctx->obj));
    auto key = any_cast<llvm::Value*>(visit(ctx->key));

    auto object_ptr_ptr_spec = this->builder->CreateSubscript(mapping_object, key);

    auto object_ptr_ptr_int = this->builder->getContent(object_ptr_ptr_spec);

    const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);

    const auto object_ptr_ptr = this->builder->CreateIntToPtr(object_ptr_ptr_int, ptr_t);
    const auto object_ptr = (llvm::Value*)this->builder->CreateLoad(ptr_t, object_ptr_ptr);

    return this->builder->CreateSpecInstance(SPEC_OBJECT, object_ptr);
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

        if (builder->config->no_specialize.has_value()) {

            const auto integer_object = this->builder->CreateIntObject(v);

            return this->builder->CreateSpecInstance(SPEC_OBJECT, integer_object);
        }

        return this->builder->CreateSpecInstance(SPEC_INT, v);

    } else if (ctx->FLOAT_LIT()) {

        auto raw = stod(ctx->FLOAT_LIT()->getText());
        auto double_t = llvm::Type::getDoubleTy(this->module->getContext());
        auto v = llvm::ConstantFP::get(double_t, raw);

        if (builder->config->no_specialize.has_value()) {

            const auto float_object = this->builder->CreateFloatObject(v);

            return this->builder->CreateSpecInstance(SPEC_OBJECT, float_object);
        }

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

        const auto content = this->builder->CreateStringObject(str, length);

        return this->builder->CreateSpecInstance(SPEC_OBJECT, content);

    } else if (ctx->NONE_LIT()) {

        return this->builder->CreateNoneSpec();

    } else if (ctx->TRUE_LIT()) {


        if (builder->config->no_specialize.has_value()) {

            const auto bool_obj = this->builder->CreateBoolObject(true);

            return this->builder->CreateSpecInstance(SPEC_OBJECT, bool_obj);
        }

        auto int64_t = llvm::IntegerType::getInt64Ty(this->module->getContext());
        auto v = llvm::ConstantInt::get(int64_t, 1, true);

        return this->builder->CreateSpecInstance(SPEC_INT, v);

    } else if (ctx->FALSE_LIT()) {

        if (builder->config->no_specialize.has_value()) {

            const auto bool_obj = this->builder->CreateBoolObject(false);

            return this->builder->CreateSpecInstance(SPEC_OBJECT, bool_obj);
        }

        auto int64_t = llvm::IntegerType::getInt64Ty(this->module->getContext());
        auto v = llvm::ConstantInt::get(int64_t, 0, true);

        return this->builder->CreateSpecInstance(SPEC_INT, v);

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

    auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    auto entry_count = llvm::ConstantInt::get(int64_t, entries.size());

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

    auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    auto entry_count = llvm::ConstantInt::get(int64_t, elements.size());

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

    auto int64_t = llvm::IntegerType::getInt64Ty(this->builder->getContext());
    auto entry_count = llvm::ConstantInt::get(int64_t, elements.size());

    return this->builder->CreateTupleLiteral(entry_count, elements);
}

std::any SourceFileVisitor::visitIf_statement(TythonParser::If_statementContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_true = llvm::BasicBlock::Create(this->builder->getContext(), "if", f, nullptr);
    llvm::BasicBlock* br_else_if = llvm::BasicBlock::Create(this->builder->getContext(), "else_if", f, nullptr);
    llvm::BasicBlock* br_else = llvm::BasicBlock::Create(this->builder->getContext(), "else", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_if", f, nullptr);

    auto expression_value = any_cast<llvm::Value*>(visit(ctx->expression()));
    auto test = this->builder->CreateObjectIsTruthy(expression_value);

    llvm::BasicBlock* br_false;

    if (ctx->br_else_if) {
        br_false = br_else_if;
    } else if (ctx->br_else) {
        br_false = br_else;
    } else {
        br_false = br_end;
    }

    this->builder->CreateCondBr(test, br_true, br_false);

    // if

    this->builder->SetInsertPoint(br_true);

    this->builder->nestContext();
    visit(ctx->br_if);
    const auto if_is_complete = this->builder->current_context->isComplete();
    this->builder->popContext();

    if (!if_is_complete) {
        this->builder->CreateBr(br_end);
    }

    // else_if

    this->builder->SetInsertPoint(br_else_if);

    auto else_if_is_complete = false;

    if (ctx->br_else_if) {
        this->builder->nestContext();
        visit(ctx->br_else_if);
        else_if_is_complete = this->builder->current_context->isComplete();
        this->builder->popContext();
    }

    if (!else_if_is_complete) {
        this->builder->CreateBr(br_end);
    }

    // else

    this->builder->SetInsertPoint(br_else);

    auto else_is_complete = false;

    if (ctx->br_else) {
        this->builder->nestContext();
        visit(ctx->br_else);
        else_is_complete = this->builder->current_context->isComplete();
        this->builder->popContext();
    }

    if (!else_is_complete) {
        this->builder->CreateBr(br_end);
    }

    this->builder->SetInsertPoint(br_end);

    // if these branches we cover all CFG paths, and all branches are completing, the encompassing context is also completing
    if (if_is_complete && else_if_is_complete && else_is_complete) {
        this->builder->current_context->setComplete();
    }

    return nullptr;
}

std::any SourceFileVisitor::visitFor_loop(TythonParser::For_loopContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_pre = llvm::BasicBlock::Create(this->builder->getContext(), "pre_for", f, nullptr);
    llvm::BasicBlock* br_head = llvm::BasicBlock::Create(this->builder->getContext(), "head_for", f, nullptr);
    llvm::BasicBlock* br_for = llvm::BasicBlock::Create(this->builder->getContext(), "for", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_for", f, nullptr);

    this->builder->nestContext(TYTHON_CONTEXT_FLAG_LOOP | TYTHON_CONTEXT_FLAG_LEX_BLOCK);
    this->builder->current_context->entry = br_pre;
    this->builder->current_context->exit = br_end;

    this->builder->CreateBr(br_pre);
    this->builder->SetInsertPoint(br_pre);

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
        this->builder->CreateBr(br_head);
        this->builder->SetInsertPoint(br_head);

        // test the iterator state, not the iterator value (which often starts at zero, which would be falsy)
        auto test = this->builder->CreateObjectIsTruthy(it);

        // increment iterator, obtains stale value
        auto it_value = this->builder->CallIteratorNext(it);

        // grab a reference to the iterator value
        this->builder->CreateGrabObject(it_value);

        // bind the stale iterator value to the induction variable
        this->builder->CreateAssign(it_var, it_value);

        this->builder->CreateCondBr(test, br_for, br_end);

    } else {

        this->builder->CreateBr(br_head);
        this->builder->SetInsertPoint(br_head);

        auto expression_value = any_cast<llvm::Value*>(visit(ctx->expression()));

        auto test = this->builder->CreateObjectIsTruthy(expression_value); // todo: this could happen as a comparison (magic method) between the result of the expression and the True (or False) unique objects instead

        this->builder->CreateCondBr(test, br_for, br_end);
    }

    this->builder->SetInsertPoint(br_for);
    visit(ctx->block());
    this->builder->CreateBr(br_head);

    this->builder->SetInsertPoint(br_end);

    this->builder->popContext();

    return nullptr;
}

std::any SourceFileVisitor::visitWhile_loop(TythonParser::While_loopContext *ctx) {

    llvm::Function* f = builder->GetInsertBlock()->getParent();

    llvm::BasicBlock* br_pre = llvm::BasicBlock::Create(this->builder->getContext(), "pre_while", f, nullptr);
    llvm::BasicBlock* br_head = llvm::BasicBlock::Create(this->builder->getContext(), "head_while", f, nullptr);
    llvm::BasicBlock* br_while = llvm::BasicBlock::Create(this->builder->getContext(), "while", f, nullptr);
    llvm::BasicBlock* br_end = llvm::BasicBlock::Create(this->builder->getContext(), "end_while", f, nullptr);

    this->builder->nestContext(TYTHON_CONTEXT_FLAG_LOOP | TYTHON_CONTEXT_FLAG_LEX_BLOCK);
    this->builder->current_context->entry = br_pre;
    this->builder->current_context->exit = br_end;

    this->builder->CreateBr(br_pre);
    this->builder->SetInsertPoint(br_pre);

    this->builder->CreateBr(br_head);
    this->builder->SetInsertPoint(br_head);

    auto expression_value = any_cast<llvm::Value*>(visit(ctx->expression()));

    auto test = this->builder->CreateObjectIsTruthy(expression_value);

    this->builder->CreateCondBr(test, br_while, br_end);

    this->builder->SetInsertPoint(br_while);
    visit(ctx->block());
    this->builder->CreateBr(br_head);

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

    if (this->builder->current_context->isComplete()) {
        // the parent context may be interested to know that this basic block terminates explicitly;
        if (auto parent = this->builder->current_context->parent) {
            parent->setComplete();
        }
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
    auto return_type = this->module->specialization_type;

    std::vector<llvm::Type*> arg_types;

    for (int i = 0; i < ctx->arguments()->args.size(); ++i) {
        arg_types.push_back(this->module->specialization_type);
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

        this->builder->CreateRet(this->builder->CreateNoneSpec());
    }

    this->builder->SetInsertPoint(old_bb);

    return nullptr;
}

std::any SourceFileVisitor::visitReturn_statement(TythonParser::Return_statementContext *ctx) {

    ASSERT_LEXICAL_BLOCK_CONTEXT

    llvm::Value* ret_val;

    if (ctx->expression()) {

        ret_val = any_cast<llvm::Value*>(visit(ctx->expression()));

    } else {

        ret_val = this->builder->CreateNoneSpec();
    }

    this->builder->current_context->setComplete();

    return this->builder->CreateRet(ret_val);
}

std::any SourceFileVisitor::visitEwout_statement(TythonParser::Ewout_statementContext *ctx) {

    const auto expression = any_cast<llvm::Value*>(visit(ctx->expression()));

    this->builder->CreateCall(*this->module->tython_ewout_func, { expression });

    return nullptr;
}

std::any SourceFileVisitor::visitCall_expression(TythonParser::Call_expressionContext *ctx) {

    if (ctx->KW_EXTERN()) {
        return visitExternCallExpression(ctx);
    }

    return visitInternalCallExpression(ctx);
}

llvm::Value* SourceFileVisitor::visitExternCallExpression(TythonParser::Call_expressionContext *ctx) {

    // todo: this is legacy

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

    auto params = any_cast<std::vector<llvm::Value*>>(visitInternalCallParameters(ctx->parameters()));

    const auto function_name = ctx->IDENTIFIER()->getText();
    auto f = this->module->findProcedure(function_name);

    if (f && f->arg_size() != params.size()) { // check if the number of parameters match

        const auto msg = std::format("Expected {} arguments for function {}, found {}.", f->arg_size(), function_name, ctx->parameters()->params.size());
        utils::log_warn(module, ctx, msg);

        if (params.size() > f->arg_size()) {

            utils::log_warn(module, ctx, std::format("Dropping last {} arguments.", params.size() - f->arg_size()));
            params.resize(f->arg_size());

        } else {

            utils::log_warn(module, ctx, "Padding argument list with None values.");

            for (int i = 0; i < f->arg_size() - params.size(); ++i) {
                params.push_back(this->builder->CreateNoneSpec());
            }
        }

    } else if (!f) {

        // check other processed objects so far
        for (auto &entry : this->external_object_symbol_table) {
            // check if the object is imported in this source file
            if (this->imports.count(entry.first)) {
                // check if that object contains the function
                if (entry.second->count(function_name)) {

                    f = entry.second->find(function_name)->second;

                    // create a local symbol for the linker, assume the caller's argument list:
                    std::vector<llvm::Type*> args;
                    for (auto p : params) {
                        args.push_back(this->module->specialization_type);
                    }
                    llvm::FunctionType* f_type = llvm::FunctionType::get(this->module->specialization_type, args, false);
                    auto f_local = this->module->getOrInsertFunction(function_name, f_type);
                    ((llvm::Function*)f_local.getCallee())->setLinkage(llvm::GlobalValue::ExternalWeakLinkage);
                }
            }
        }
    }

    if (!f) {
        throw CompileException("Undefined reference to function \"" + function_name + "\".");
    }

    // grab reference to parameters and mark them as pass-by-value
//    for (int i = 0; i < params.size(); ++i) {
//
////        this->builder->CreateGrabObject(v);
//
////        f->addParamAttr(i, llvm::Attribute::getWithByValType(this->builder->getContext(), this->module->specialization_type));
//    }

    llvm::Value* result = this->builder->CreateCall(f, params);

    if (result->getType()->isVoidTy()) {
        // return None implicitly
        return this->builder->CreateNoneSpec();
    }

    // release param objects
//    for (auto& v : params) {
//        this->builder->CreateReleaseObject(v);
//    }

    return result;
}

std::vector<llvm::Value*> SourceFileVisitor::visitInternalCallParameters(TythonParser::ParametersContext *ctx) {

    std::vector<llvm::Value*> values;
    values.reserve(ctx->params.size());

    for (auto p : ctx->params) {
        const auto param = any_cast<llvm::Value*>(visit(p));
        values.push_back(param);
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
        this->builder->CreateAssign(dataEntry, v);

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

std::any SourceFileVisitor::visitLbl_floor_div_expr(TythonParser::Lbl_floor_div_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonFloorDiv(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_mod_expr(TythonParser::Lbl_mod_exprContext *ctx) {

    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonMod(lhs, rhs);
}

std::any SourceFileVisitor::visitLbl_add_expr(TythonParser::Lbl_add_exprContext *ctx) {
    auto lhs = any_cast<llvm::Value*>(visit(ctx->lhs));
    auto rhs = any_cast<llvm::Value*>(visit(ctx->rhs));

    return this->builder->CreateTythonAdd(lhs, rhs);
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

    const auto instance = any_cast<llvm::Value*>(visit(ctx->expression()));

    const auto method_name_str = ctx->call_expression()->IDENTIFIER()->getText();
    const auto method_name = this->builder->CreateGlobalString(method_name_str, method_name_str, 0, this->module);

    auto spec_args = visitInternalCallParameters(ctx->call_expression()->parameters());

    std::vector<llvm::Value*> args;
    args.reserve(spec_args.size() + 1);

    for (const auto& spec_arg : spec_args) {
        const auto boxed = this->builder->CreateBox(spec_arg);
        const auto unpacked = this->builder->getContent(boxed);
        args.push_back(unpacked);
    }

    const auto object_handler = [this, args, method_name](llvm::Value* object_primitive) -> llvm::Value* {

        std::vector<llvm::Value*> m_args;
        for (const auto v : args) {
            m_args.push_back(v);
        }
        m_args.insert(m_args.begin(), object_primitive);

        // todo: implement non-builtin methods (class-member callables)
        auto f_ptr = this->builder->CreateResolveBuiltinMethod(object_primitive, method_name);

        const auto ptr_t = llvm::PointerType::get(this->builder->getContext(), 0);
        auto f_type = llvm::FunctionType::get(ptr_t, true);

        const auto result = (llvm::Value*)this->builder->CreateCall(f_type, f_ptr, m_args);

        return this->builder->CreateSpecInstance(SPEC_OBJECT, result);
    };

    const auto int_handler = [this, object_handler](llvm::Value* integer_primitive) -> llvm::Value* {

        const auto object_primitive = this->builder->CreateIntObject(integer_primitive);

        return object_handler(object_primitive);
    };

    const auto float_handler = [this, object_handler](llvm::Value* float_primitive) -> llvm::Value* {

        const auto object_primitive = this->builder->CreateFloatObject(float_primitive);

        return object_handler(object_primitive);
    };

    return this->builder->CreateTypeGuard(instance, int_handler, float_handler, object_handler);
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
