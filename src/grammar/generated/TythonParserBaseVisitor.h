
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

  virtual std::any visitAssign_statement(TythonParser::Assign_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak_statement(TythonParser::Break_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_statement(TythonParser::Return_statementContext *ctx) override {
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

  virtual std::any visitBinary_expression(TythonParser::Binary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_rval(TythonParser::Lbl_rvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_call_expression(TythonParser::Lbl_call_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinary_operator(TythonParser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInequality_operator(TythonParser::Inequality_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_operator(TythonParser::Logic_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_operator(TythonParser::Arithmetic_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRval(TythonParser::RvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_identifier(TythonParser::Lbl_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLbl_key_access(TythonParser::Lbl_key_accessContext *ctx) override {
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

  virtual std::any visitLiteral(TythonParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

