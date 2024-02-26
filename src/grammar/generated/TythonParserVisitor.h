
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

    virtual std::any visitAssign_statement(TythonParser::Assign_statementContext *context) = 0;

    virtual std::any visitBreak_statement(TythonParser::Break_statementContext *context) = 0;

    virtual std::any visitReturn_statement(TythonParser::Return_statementContext *context) = 0;

    virtual std::any visitIf_statement(TythonParser::If_statementContext *context) = 0;

    virtual std::any visitFor_loop(TythonParser::For_loopContext *context) = 0;

    virtual std::any visitWhile_loop(TythonParser::While_loopContext *context) = 0;

    virtual std::any visitArguments(TythonParser::ArgumentsContext *context) = 0;

    virtual std::any visitParameters(TythonParser::ParametersContext *context) = 0;

    virtual std::any visitCall_expression(TythonParser::Call_expressionContext *context) = 0;

    virtual std::any visitBinary_expression(TythonParser::Binary_expressionContext *context) = 0;

    virtual std::any visitLbl_rval(TythonParser::Lbl_rvalContext *context) = 0;

    virtual std::any visitLbl_inc_prefix(TythonParser::Lbl_inc_prefixContext *context) = 0;

    virtual std::any visitLcl_dec_suffix(TythonParser::Lcl_dec_suffixContext *context) = 0;

    virtual std::any visitLbl_inc_suffix(TythonParser::Lbl_inc_suffixContext *context) = 0;

    virtual std::any visitLbl_call_expression(TythonParser::Lbl_call_expressionContext *context) = 0;

    virtual std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *context) = 0;

    virtual std::any visitLcl_dec_prefix(TythonParser::Lcl_dec_prefixContext *context) = 0;

    virtual std::any visitBinary_operator(TythonParser::Binary_operatorContext *context) = 0;

    virtual std::any visitInequality_operator(TythonParser::Inequality_operatorContext *context) = 0;

    virtual std::any visitLogic_operator(TythonParser::Logic_operatorContext *context) = 0;

    virtual std::any visitArithmetic_operator(TythonParser::Arithmetic_operatorContext *context) = 0;

    virtual std::any visitRval(TythonParser::RvalContext *context) = 0;

    virtual std::any visitLbl_identifier(TythonParser::Lbl_identifierContext *context) = 0;

    virtual std::any visitLbl_key_access(TythonParser::Lbl_key_accessContext *context) = 0;

    virtual std::any visitKey_value_pair(TythonParser::Key_value_pairContext *context) = 0;

    virtual std::any visitDict_lit(TythonParser::Dict_litContext *context) = 0;

    virtual std::any visitList_lit(TythonParser::List_litContext *context) = 0;

    virtual std::any visitTuple_lit(TythonParser::Tuple_litContext *context) = 0;

    virtual std::any visitLiteral(TythonParser::LiteralContext *context) = 0;


};

