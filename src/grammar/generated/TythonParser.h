
// Generated from /home/manzi/repos/tython/src/grammar/TythonParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonParser : public antlr4::Parser {
public:
  enum {
    INDENT = 1, DEDENT = 2, KW_DEF = 3, KW_RETURN = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_EXTERN = 8, KW_IMPORT = 9, KW_SELF = 10, SYM_LPAR = 11, 
    SYM_RPAR = 12, SYM_LSQ = 13, SYM_RSQ = 14, SYM_LBR = 15, SYM_RBR = 16, 
    SYM_COL = 17, SYM_SEMCOL = 18, SYM_COMMA = 19, SYM_STMNT_DELIMITER = 20, 
    SYM_ASSIGN = 21, SYM_NEQ = 22, SYM_LTE = 23, SYM_LT = 24, SYM_EQ = 25, 
    SYM_GT = 26, SYM_GTE = 27, SYM_AND = 28, SYM_OR = 29, SYM_PLUS = 30, 
    SYM_MINUS = 31, SYM_MULT = 32, SYM_DIV = 33, SYM_EXP = 34, SYM_DOT = 35, 
    SYM_ELLIPS = 36, SYM_COMMENT = 37, SYM_COMMENT_START = 38, IDENTIFIER = 39, 
    INT_LIT = 40, FLOAT_LIT = 41, STR_LIT = 42, TRUE_LIT = 43, FALSE_LIT = 44, 
    NEWLINE = 45, WS = 46, SYM_COMMENT_END = 47, COMMENT_CONTENT = 48
  };

  enum {
    RuleProgram = 0, RuleImport_statement = 1, RuleImport_path = 2, RuleFunction_def = 3, 
    RuleBlock = 4, RuleStatement = 5, RuleSimple_statement = 6, RuleSimple_statements = 7, 
    RuleCompound_statement = 8, RuleAssign_statement = 9, RuleReturn_statement = 10, 
    RuleIf_statement = 11, RuleArguments = 12, RuleParameters = 13, RuleCall_expression = 14, 
    RuleExpression = 15, RuleBinary_operator = 16, RuleInequality_operator = 17, 
    RuleLogic_operator = 18, RuleArithmetic_operator = 19, RuleRval = 20, 
    RuleLval = 21, RuleKey_value_pair = 22, RuleDict_lit = 23, RuleLiteral = 24
  };

  explicit TythonParser(antlr4::TokenStream *input);

  TythonParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~TythonParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class Import_statementContext;
  class Import_pathContext;
  class Function_defContext;
  class BlockContext;
  class StatementContext;
  class Simple_statementContext;
  class Simple_statementsContext;
  class Compound_statementContext;
  class Assign_statementContext;
  class Return_statementContext;
  class If_statementContext;
  class ArgumentsContext;
  class ParametersContext;
  class Call_expressionContext;
  class ExpressionContext;
  class Binary_operatorContext;
  class Inequality_operatorContext;
  class Logic_operatorContext;
  class Arithmetic_operatorContext;
  class RvalContext;
  class LvalContext;
  class Key_value_pairContext;
  class Dict_litContext;
  class LiteralContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Import_statementContext *> import_statement();
    Import_statementContext* import_statement(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Import_statementContext : public antlr4::ParserRuleContext {
  public:
    Import_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IMPORT();
    Import_pathContext *import_path();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *SYM_SEMCOL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_statementContext* import_statement();

  class  Import_pathContext : public antlr4::ParserRuleContext {
  public:
    Import_pathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SYM_DOT();
    antlr4::tree::TerminalNode* SYM_DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_pathContext* import_path();

  class  Function_defContext : public antlr4::ParserRuleContext {
  public:
    Function_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_DEF();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SYM_LPAR();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *SYM_RPAR();
    antlr4::tree::TerminalNode *SYM_COL();
    BlockContext *block();
    antlr4::tree::TerminalNode *KW_EXTERN();
    antlr4::tree::TerminalNode *SYM_ELLIPS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_defContext* function_def();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::StatementContext *indent_statements = nullptr;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_statementsContext *simple_statements();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *INDENT();
    antlr4::tree::TerminalNode *DEDENT();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_statementsContext *simple_statements();
    Compound_statementContext *compound_statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Simple_statementContext : public antlr4::ParserRuleContext {
  public:
    Simple_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Assign_statementContext *assign_statement();
    Return_statementContext *return_statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_statementContext* simple_statement();

  class  Simple_statementsContext : public antlr4::ParserRuleContext {
  public:
    Simple_statementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_statementContext *> simple_statement();
    Simple_statementContext* simple_statement(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> SYM_SEMCOL();
    antlr4::tree::TerminalNode* SYM_SEMCOL(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_statementsContext* simple_statements();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_statementContext *if_statement();
    Function_defContext *function_def();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Assign_statementContext : public antlr4::ParserRuleContext {
  public:
    Assign_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LvalContext *lval();
    antlr4::tree::TerminalNode *SYM_ASSIGN();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_statementContext* assign_statement();

  class  Return_statementContext : public antlr4::ParserRuleContext {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_statementContext* return_statement();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::BlockContext *br_if = nullptr;
    TythonParser::If_statementContext *br_else_if = nullptr;
    TythonParser::BlockContext *br_else = nullptr;
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_IF();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> SYM_COL();
    antlr4::tree::TerminalNode* SYM_COL(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    antlr4::tree::TerminalNode *KW_ELSE();
    If_statementContext *if_statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *identifierToken = nullptr;
    std::vector<antlr4::Token *> args;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SYM_COMMA();
    antlr4::tree::TerminalNode* SYM_COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> params;
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SYM_COMMA();
    antlr4::tree::TerminalNode* SYM_COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  Call_expressionContext : public antlr4::ParserRuleContext {
  public:
    Call_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SYM_LPAR();
    ParametersContext *parameters();
    antlr4::tree::TerminalNode *SYM_RPAR();
    antlr4::tree::TerminalNode *KW_EXTERN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_expressionContext* call_expression();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Binary_expressionContext : public ExpressionContext {
  public:
    Binary_expressionContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    Binary_operatorContext *binary_operator();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_rvalContext : public ExpressionContext {
  public:
    Lbl_rvalContext(ExpressionContext *ctx);

    RvalContext *rval();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_call_expressionContext : public ExpressionContext {
  public:
    Lbl_call_expressionContext(ExpressionContext *ctx);

    Call_expressionContext *call_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_expression_parenthesesContext : public ExpressionContext {
  public:
    Lbl_expression_parenthesesContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *SYM_LPAR();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Inequality_operatorContext *inequality_operator();
    Logic_operatorContext *logic_operator();
    Arithmetic_operatorContext *arithmetic_operator();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Inequality_operatorContext : public antlr4::ParserRuleContext {
  public:
    Inequality_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_NEQ();
    antlr4::tree::TerminalNode *SYM_LT();
    antlr4::tree::TerminalNode *SYM_LTE();
    antlr4::tree::TerminalNode *SYM_EQ();
    antlr4::tree::TerminalNode *SYM_GT();
    antlr4::tree::TerminalNode *SYM_GTE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inequality_operatorContext* inequality_operator();

  class  Logic_operatorContext : public antlr4::ParserRuleContext {
  public:
    Logic_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_AND();
    antlr4::tree::TerminalNode *SYM_OR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_operatorContext* logic_operator();

  class  Arithmetic_operatorContext : public antlr4::ParserRuleContext {
  public:
    Arithmetic_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_PLUS();
    antlr4::tree::TerminalNode *SYM_MINUS();
    antlr4::tree::TerminalNode *SYM_MULT();
    antlr4::tree::TerminalNode *SYM_DIV();
    antlr4::tree::TerminalNode *SYM_EXP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arithmetic_operatorContext* arithmetic_operator();

  class  RvalContext : public antlr4::ParserRuleContext {
  public:
    RvalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    LvalContext *lval();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RvalContext* rval();

  class  LvalContext : public antlr4::ParserRuleContext {
  public:
    LvalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LvalContext() = default;
    void copyFrom(LvalContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Lbl_identifierContext : public LvalContext {
  public:
    Lbl_identifierContext(LvalContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_key_accessContext : public LvalContext {
  public:
    Lbl_key_accessContext(LvalContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SYM_LSQ();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_RSQ();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LvalContext* lval();

  class  Key_value_pairContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::ExpressionContext *key = nullptr;
    TythonParser::ExpressionContext *value = nullptr;
    Key_value_pairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_COL();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Key_value_pairContext* key_value_pair();

  class  Dict_litContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::Key_value_pairContext *key_value_pairContext = nullptr;
    std::vector<Key_value_pairContext *> entries;
    Dict_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_LBR();
    antlr4::tree::TerminalNode *SYM_RBR();
    std::vector<Key_value_pairContext *> key_value_pair();
    Key_value_pairContext* key_value_pair(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SYM_COMMA();
    antlr4::tree::TerminalNode* SYM_COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dict_litContext* dict_lit();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *FLOAT_LIT();
    antlr4::tree::TerminalNode *STR_LIT();
    Dict_litContext *dict_lit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

