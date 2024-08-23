//
// Created by bruh on 21-9-22.
//

#ifndef CROSSOVER_PROCEDUREVISITOR_H
#define CROSSOVER_PROCEDUREVISITOR_H

#include "../../src/grammar/generated/TythonParserBaseVisitor.h"
#include "../ir/TythonModule.h"
#include "../../include/ir/TythonBuilder.h"
#include <any>

#define ASSERT_LEXICAL_BLOCK_CONTEXT \
    do {                           \
        assert(this->builder->current_context); \
        assert(this->builder->current_context->isLexicalBlock()); \
    } while (0);


using namespace std;

class SourceFileVisitor : public TythonParserBaseVisitor {

private:

    TythonModule* module;
    TythonBuilder* builder;
    const std::map<std::string, const std::map<std::string, llvm::Function*>*>& external_object_symbol_table;
    std::set<std::string> imports;

public:

    SourceFileVisitor(TythonModule* tythonModule, TythonBuilder* builder, const std::map<std::string, const std::map<std::string, llvm::Function*>*>& object_symbol_table) :
            module(tythonModule),
            builder(builder),
            external_object_symbol_table(object_symbol_table),
            imports() {}

    std::any visitImport_statement(TythonParser::Import_statementContext *ctx) override;

    std::any visitLbl_assign_statement(TythonParser::Lbl_assign_statementContext *ctx) override;
    std::any visitLbl_assign_plus_eq(TythonParser::Lbl_assign_plus_eqContext *ctx) override;
    std::any visitLbl_assign_minus_eq(TythonParser::Lbl_assign_minus_eqContext *ctx) override;

    std::any visitLbl_lval_key_access(TythonParser::Lbl_lval_key_accessContext *ctx) override;
    std::any visitLbl_lval_identifier(TythonParser::Lbl_lval_identifierContext *ctx) override;

    std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) override;

    std::any visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) override;
    std::any visitLbl_key_access(TythonParser::Lbl_key_accessContext *ctx) override;
    std::any visitLbl_slice_access(TythonParser::Lbl_slice_accessContext *ctx) override;

    std::any visitLiteral(TythonParser::LiteralContext *ctx) override;
    std::any visitDict_lit(TythonParser::Dict_litContext *ctx) override;
    std::any visitList_lit(TythonParser::List_litContext *ctx) override;
    std::any visitTuple_lit(TythonParser::Tuple_litContext *ctx) override;

    std::any visitSlice_lit(TythonParser::Slice_litContext *ctx) override;

    std::any visitBlock(TythonParser::BlockContext *ctx) override;
    std::any visitSimple_statement(TythonParser::Simple_statementContext *ctx) override;
    std::any visitCompound_statement(TythonParser::Compound_statementContext *ctx) override;

    std::any visitIf_statement(TythonParser::If_statementContext *ctx) override;

    std::any visitFor_loop(TythonParser::For_loopContext *ctx) override;
    std::any visitWhile_loop(TythonParser::While_loopContext *ctx) override;
    std::any visitBreak_statement(TythonParser::Break_statementContext *ctx) override;

    std::any visitFunction_def(TythonParser::Function_defContext *ctx) override;
    std::any visitReturn_statement(TythonParser::Return_statementContext *ctx) override;

    std::any visitEwout_statement(TythonParser::Ewout_statementContext *ctx) override;

    std::any visitCall_expression(TythonParser::Call_expressionContext *ctx) override;
    std::any visitArguments(TythonParser::ArgumentsContext *ctx) override;

    llvm::Value* visitExternCallExpression(TythonParser::Call_expressionContext *ctx);
    llvm::Value* visitInternalCallExpression(TythonParser::Call_expressionContext *ctx);
    std::vector<llvm::Value*> visitExternCallParameters(TythonParser::ParametersContext *ctx);
    std::vector<llvm::Value*> visitInternalCallParameters(TythonParser::ParametersContext *ctx);

    std::any visitLbl_method_call(TythonParser::Lbl_method_callContext *ctx) override;

    // Expression overrides

    std::any visitLbl_exponent_expr(TythonParser::Lbl_exponent_exprContext *ctx) override;
    std::any visitLbl_mult_expr(TythonParser::Lbl_mult_exprContext *ctx) override;
    std::any visitLbl_div_expr(TythonParser::Lbl_div_exprContext *ctx) override;
    std::any visitLbl_floor_div_expr(TythonParser::Lbl_floor_div_exprContext *ctx) override;
    std::any visitLbl_add_expr(TythonParser::Lbl_add_exprContext *ctx) override;
    std::any visitLbl_sub_expr(TythonParser::Lbl_sub_exprContext *ctx) override;
    std::any visitLbl_mod_expr(TythonParser::Lbl_mod_exprContext *ctx) override;

    std::any visitLbl_and_expr(TythonParser::Lbl_and_exprContext *ctx) override;
    std::any visitLbl_or_expr(TythonParser::Lbl_or_exprContext *ctx) override;

    std::any visitLbl_neq_expr(TythonParser::Lbl_neq_exprContext *ctx) override;
    std::any visitLbl_lt_expr(TythonParser::Lbl_lt_exprContext *ctx) override;
    std::any visitLbl_lte_expr(TythonParser::Lbl_lte_exprContext *ctx) override;
    std::any visitLbl_eq_expr(TythonParser::Lbl_eq_exprContext *ctx) override;
    std::any visitLbl_gt_expr(TythonParser::Lbl_gt_exprContext *ctx) override;
    std::any visitLbl_gte_expr(TythonParser::Lbl_gte_exprContext *ctx) override;

    std::any visitLbl_inc_prefix(TythonParser::Lbl_inc_prefixContext *ctx) override;
    std::any visitLbl_inc_suffix(TythonParser::Lbl_inc_suffixContext *ctx) override;
    std::any visitLbl_dec_prefix(TythonParser::Lbl_dec_prefixContext *ctx) override;
    std::any visitLbl_dec_suffix(TythonParser::Lbl_dec_suffixContext *ctx) override;

};

#endif //CROSSOVER_PROCEDUREVISITOR_H
