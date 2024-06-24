
// Generated from /home/manzi/repos/tython/src/grammar/TythonParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "TythonParserVisitor.h"


/**
 * This class provides an empty implementation of TythonParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TythonParserBaseVisitor : public TythonParserVisitor {
public:

  virtual std::any visitProgram(TythonParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_statement(TythonParser::Import_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_path(TythonParser::Import_pathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_def(TythonParser::Function_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(TythonParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(TythonParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_statement(TythonParser::Simple_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_statements(TythonParser::Simple_statementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_statement(TythonParser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_assign_statement(TythonParser::Lbl_assign_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_assign_plus_eq(TythonParser::Lbl_assign_plus_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_assign_minus_eq(TythonParser::Lbl_assign_minus_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak_statement(TythonParser::Break_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_statement(TythonParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEwout_statement(TythonParser::Ewout_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_statement(TythonParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_loop(TythonParser::For_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_loop(TythonParser::While_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(TythonParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(TythonParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_expression(TythonParser::Call_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_literal(TythonParser::Lbl_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_div_expr(TythonParser::Lbl_div_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_or_expr(TythonParser::Lbl_or_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_eq_expr(TythonParser::Lbl_eq_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_lt_expr(TythonParser::Lbl_lt_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_inc_suffix(TythonParser::Lbl_inc_suffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_dec_prefix(TythonParser::Lbl_dec_prefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_dec_suffix(TythonParser::Lbl_dec_suffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_neq_expr(TythonParser::Lbl_neq_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_method_call(TythonParser::Lbl_method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_add_expr(TythonParser::Lbl_add_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_inc_prefix(TythonParser::Lbl_inc_prefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_mult_expr(TythonParser::Lbl_mult_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_sub_expr(TythonParser::Lbl_sub_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_mod_expr(TythonParser::Lbl_mod_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_slice_access(TythonParser::Lbl_slice_accessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_call_expression(TythonParser::Lbl_call_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_and_expr(TythonParser::Lbl_and_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_gte_expr(TythonParser::Lbl_gte_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_key_access(TythonParser::Lbl_key_accessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_lte_expr(TythonParser::Lbl_lte_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_exponent_expr(TythonParser::Lbl_exponent_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_gt_expr(TythonParser::Lbl_gt_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_floor_div_expr(TythonParser::Lbl_floor_div_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_lval_key_access(TythonParser::Lbl_lval_key_accessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_lval_identifier(TythonParser::Lbl_lval_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKey_value_pair(TythonParser::Key_value_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict_lit(TythonParser::Dict_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList_lit(TythonParser::List_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTuple_lit(TythonParser::Tuple_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlice_lit(TythonParser::Slice_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(TythonParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

