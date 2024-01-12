
// Generated from /home/manzi/repos/tython/grammar/TythonParser.g4 by ANTLR 4.12.0

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

    virtual std::any visitReturn_statement(TythonParser::Return_statementContext *context) = 0;

    virtual std::any visitIf_statement(TythonParser::If_statementContext *context) = 0;

    virtual std::any visitArguments(TythonParser::ArgumentsContext *context) = 0;

    virtual std::any visitParameters(TythonParser::ParametersContext *context) = 0;

    virtual std::any visitCall_expression(TythonParser::Call_expressionContext *context) = 0;

    virtual std::any visitBinary_expression(TythonParser::Binary_expressionContext *context) = 0;

    virtual std::any visitLbl_call_expression(TythonParser::Lbl_call_expressionContext *context) = 0;

    virtual std::any visitLbl_expression_parentheses(TythonParser::Lbl_expression_parenthesesContext *context) = 0;

    virtual std::any visitLbl_atomic(TythonParser::Lbl_atomicContext *context) = 0;

    virtual std::any visitBinary_operator(TythonParser::Binary_operatorContext *context) = 0;

    virtual std::any visitInequality_operator(TythonParser::Inequality_operatorContext *context) = 0;

    virtual std::any visitLogic_operator(TythonParser::Logic_operatorContext *context) = 0;

    virtual std::any visitArithmetic_operator(TythonParser::Arithmetic_operatorContext *context) = 0;

    virtual std::any visitAtomic(TythonParser::AtomicContext *context) = 0;

    virtual std::any visitConstant(TythonParser::ConstantContext *context) = 0;


};

