
// Generated from /home/manzi/repos/tython/src/grammar/TythonParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "TythonParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TythonParser.
 */
class  TythonParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TythonParser.
   */
    virtual std::any visitProgram(TythonParser::ProgramContext *context) = 0;

    virtual std::any visitImport_statement(TythonParser::Import_statementContext *context) = 0;

    virtual std::any visitImport_path(TythonParser::Import_pathContext *context) = 0;

    virtual std::any visitFunction_def(TythonParser::Function_defContext *context) = 0;

    virtual std::any visitBlock(TythonParser::BlockContext *context) = 0;

    virtual std::any visitStatement(TythonParser::StatementContext *context) = 0;

    virtual std::any visitSimple_statement(TythonParser::Simple_statementContext *context) = 0;

    virtual std::any visitSimple_statements(TythonParser::Simple_statementsContext *context) = 0;

    virtual std::any visitCompound_statement(TythonParser::Compound_statementContext *context) = 0;

    virtual std::any visitLbl_assign_statement(TythonParser::Lbl_assign_statementContext *context) = 0;

    virtual std::any visitLbl_assign_plus_eq(TythonParser::Lbl_assign_plus_eqContext *context) = 0;

    virtual std::any visitLbl_assign_minus_eq(TythonParser::Lbl_assign_minus_eqContext *context) = 0;

    virtual std::any visitBreak_statement(TythonParser::Break_statementContext *context) = 0;

    virtual std::any visitReturn_statement(TythonParser::Return_statementContext *context) = 0;

    virtual std::any visitIf_statement(TythonParser::If_statementContext *context) = 0;

    virtual std::any visitFor_loop(TythonParser::For_loopContext *context) = 0;

    virtual std::any visitWhile_loop(TythonParser::While_loopContext *context) = 0;

    virtual std::any visitArguments(TythonParser::ArgumentsContext *context) = 0;

    virtual std::any visitParameters(TythonParser::ParametersContext *context) = 0;

    virtual std::any visitCall_expression(TythonParser::Call_expressionContext *context) = 0;

    virtual std::any visitLbl_identifier(TythonParser::Lbl_identifierContext *context) = 0;

    virtual std::any visitLbl_literal(TythonParser::Lbl_literalContext *context) = 0;

    virtual std::any visitLbl_div_expr(TythonParser::Lbl_div_exprContext *context) = 0;

    virtual std::any visitLbl_or_expr(TythonParser::Lbl_or_exprContext *context) = 0;

    virtual std::any visitLbl_eq_expr(TythonParser::Lbl_eq_exprContext *context) = 0;

    virtual std::any visitLbl_lt_expr(TythonParser::Lbl_lt_exprContext *context) = 0;

    virtual std::any visitLbl_inc_suffix(TythonParser::Lbl_inc_suffixContext *context) = 0;

    virtual std::any visitLbl_call_expression(TythonParser::Lbl_call_expressionContext *context) = 0;

    virtual std::any visitLbl_dec_prefix(TythonParser::Lbl_dec_prefixContext *context) = 0;

    virtual std::any visitLbl_and_expr(TythonParser::Lbl_and_exprContext *context) = 0;

    virtual std::any visitLbl_gte_expr(TythonParser::Lbl_gte_exprContext *context) = 0;

    virtual std::any visitLbl_dec_suffix(TythonParser::Lbl_dec_suffixContext *context) = 0;

    virtual std::any visitLbl_key_access(TythonParser::Lbl_key_accessContext *context) = 0;

    virtual std::any visitLbl_neq_expr(TythonParser::Lbl_neq_exprContext *context) = 0;

    virtual std::any visitLbl_method_call(TythonParser::Lbl_method_callContext *context) = 0;

    virtual std::any visitLbl_add_expr(TythonParser::Lbl_add_exprContext *context) = 0;

    virtual std::any visitLbl_lte_expr(TythonParser::Lbl_lte_exprContext *context) = 0;

    virtual std::any visitLbl_inc_prefix(TythonParser::Lbl_inc_prefixContext *context) = 0;

    virtual std::any visitLbl_mult_expr(TythonParser::Lbl_mult_exprContext *context) = 0;

    virtual std::any visitLbl_exponent_expr(TythonParser::Lbl_exponent_exprContext *context) = 0;

    virtual std::any visitLbl_sub_expr(TythonParser::Lbl_sub_exprContext *context) = 0;

    virtual std::any visitLbl_gt_expr(TythonParser::Lbl_gt_exprContext *context) = 0;

    virtual std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *context) = 0;

    virtual std::any visitLbl_slice_access(TythonParser::Lbl_slice_accessContext *context) = 0;

    virtual std::any visitLval(TythonParser::LvalContext *context) = 0;

    virtual std::any visitKey_value_pair(TythonParser::Key_value_pairContext *context) = 0;

    virtual std::any visitDict_lit(TythonParser::Dict_litContext *context) = 0;

    virtual std::any visitList_lit(TythonParser::List_litContext *context) = 0;

    virtual std::any visitTuple_lit(TythonParser::Tuple_litContext *context) = 0;

    virtual std::any visitSlice_lit(TythonParser::Slice_litContext *context) = 0;

    virtual std::any visitLiteral(TythonParser::LiteralContext *context) = 0;


};

