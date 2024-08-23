
// Generated from /home/manzi/repos/tython/src/grammar/TythonParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonParser : public antlr4::Parser {
public:
  enum {
    INDENT = 1, DEDENT = 2, KW_DEF = 3, KW_RETURN = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_FOR = 7, KW_IN = 8, KW_WHILE = 9, KW_BREAK = 10, KW_EXTERN = 11, 
    KW_IMPORT = 12, KW_SELF = 13, KW_EWOUT = 14, SYM_LPAR = 15, SYM_RPAR = 16, 
    SYM_LSQ = 17, SYM_RSQ = 18, SYM_LBR = 19, SYM_RBR = 20, SYM_COL = 21, 
    SYM_SEMCOL = 22, SYM_COMMA = 23, SYM_STMNT_DELIMITER = 24, SYM_ASSIGN = 25, 
    SYM_PLUS_EQ = 26, SYM_MINUS_EQ = 27, SYM_NEQ = 28, SYM_LTE = 29, SYM_LT = 30, 
    SYM_EQ = 31, SYM_GT = 32, SYM_GTE = 33, SYM_AND = 34, SYM_OR = 35, SYM_PLUS = 36, 
    SYM_MINUS = 37, SYM_MULT = 38, SYM_DIV = 39, SYM_FLOOR_DIV = 40, SYM_EXP = 41, 
    SYM_MOD = 42, SYM_INC = 43, SYM_DEC = 44, SYM_DOT = 45, SYM_ELLIPS = 46, 
    SYM_COMMENT = 47, SYM_COMMENT_START = 48, TRUE_LIT = 49, FALSE_LIT = 50, 
    NONE_LIT = 51, IDENTIFIER = 52, INT_LIT = 53, FLOAT_LIT = 54, STR_LIT = 55, 
    NEWLINE = 56, WS = 57, SYM_COMMENT_END = 58, COMMENT_CONTENT = 59
  };

  enum {
    RuleProgram = 0, RuleImport_statement = 1, RuleImport_path = 2, RuleFunction_def = 3, 
    RuleBlock = 4, RuleStatement = 5, RuleSimple_statement = 6, RuleSimple_statements = 7, 
    RuleCompound_statement = 8, RuleAssign_statement = 9, RuleBreak_statement = 10, 
    RuleReturn_statement = 11, RuleEwout_statement = 12, RuleIf_statement = 13, 
    RuleFor_loop = 14, RuleWhile_loop = 15, RuleArguments = 16, RuleParameters = 17, 
    RuleCall_expression = 18, RuleExpression = 19, RuleLval = 20, RuleKey_value_pair = 21, 
    RuleDict_lit = 22, RuleList_lit = 23, RuleTuple_lit = 24, RuleSlice_lit = 25, 
    RuleLiteral = 26
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
  class Break_statementContext;
  class Return_statementContext;
  class Ewout_statementContext;
  class If_statementContext;
  class For_loopContext;
  class While_loopContext;
  class ArgumentsContext;
  class ParametersContext;
  class Call_expressionContext;
  class ExpressionContext;
  class LvalContext;
  class Key_value_pairContext;
  class Dict_litContext;
  class List_litContext;
  class Tuple_litContext;
  class Slice_litContext;
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
    Break_statementContext *break_statement();
    Return_statementContext *return_statement();
    Ewout_statementContext *ewout_statement();


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
    For_loopContext *for_loop();
    While_loopContext *while_loop();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Assign_statementContext : public antlr4::ParserRuleContext {
  public:
    Assign_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Assign_statementContext() = default;
    void copyFrom(Assign_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Lbl_assign_minus_eqContext : public Assign_statementContext {
  public:
    Lbl_assign_minus_eqContext(Assign_statementContext *ctx);

    LvalContext *lval();
    antlr4::tree::TerminalNode *SYM_MINUS_EQ();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_assign_statementContext : public Assign_statementContext {
  public:
    Lbl_assign_statementContext(Assign_statementContext *ctx);

    LvalContext *lval();
    antlr4::tree::TerminalNode *SYM_ASSIGN();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_assign_plus_eqContext : public Assign_statementContext {
  public:
    Lbl_assign_plus_eqContext(Assign_statementContext *ctx);

    LvalContext *lval();
    antlr4::tree::TerminalNode *SYM_PLUS_EQ();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Assign_statementContext* assign_statement();

  class  Break_statementContext : public antlr4::ParserRuleContext {
  public:
    Break_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_BREAK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_statementContext* break_statement();

  class  Return_statementContext : public antlr4::ParserRuleContext {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_RETURN();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_statementContext* return_statement();

  class  Ewout_statementContext : public antlr4::ParserRuleContext {
  public:
    Ewout_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_EWOUT();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ewout_statementContext* ewout_statement();

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

  class  For_loopContext : public antlr4::ParserRuleContext {
  public:
    For_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_FOR();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_COL();
    BlockContext *block();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *KW_IN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_loopContext* for_loop();

  class  While_loopContext : public antlr4::ParserRuleContext {
  public:
    While_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KW_WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_COL();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_loopContext* while_loop();

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

  class  Lbl_identifierContext : public ExpressionContext {
  public:
    Lbl_identifierContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_literalContext : public ExpressionContext {
  public:
    Lbl_literalContext(ExpressionContext *ctx);

    LiteralContext *literal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_div_exprContext : public ExpressionContext {
  public:
    Lbl_div_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_DIV();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_or_exprContext : public ExpressionContext {
  public:
    Lbl_or_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_OR();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_eq_exprContext : public ExpressionContext {
  public:
    Lbl_eq_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_EQ();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_lt_exprContext : public ExpressionContext {
  public:
    Lbl_lt_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_LT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_inc_suffixContext : public ExpressionContext {
  public:
    Lbl_inc_suffixContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_INC();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_dec_prefixContext : public ExpressionContext {
  public:
    Lbl_dec_prefixContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *SYM_DEC();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_dec_suffixContext : public ExpressionContext {
  public:
    Lbl_dec_suffixContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_DEC();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_neq_exprContext : public ExpressionContext {
  public:
    Lbl_neq_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_NEQ();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_method_callContext : public ExpressionContext {
  public:
    Lbl_method_callContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_DOT();
    Call_expressionContext *call_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_add_exprContext : public ExpressionContext {
  public:
    Lbl_add_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_PLUS();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_inc_prefixContext : public ExpressionContext {
  public:
    Lbl_inc_prefixContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *SYM_INC();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_mult_exprContext : public ExpressionContext {
  public:
    Lbl_mult_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_MULT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_sub_exprContext : public ExpressionContext {
  public:
    Lbl_sub_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_MINUS();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_mod_exprContext : public ExpressionContext {
  public:
    Lbl_mod_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_MOD();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_slice_accessContext : public ExpressionContext {
  public:
    Lbl_slice_accessContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SYM_LSQ();
    Slice_litContext *slice_lit();
    antlr4::tree::TerminalNode *SYM_RSQ();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_call_expressionContext : public ExpressionContext {
  public:
    Lbl_call_expressionContext(ExpressionContext *ctx);

    Call_expressionContext *call_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_and_exprContext : public ExpressionContext {
  public:
    Lbl_and_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_AND();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_gte_exprContext : public ExpressionContext {
  public:
    Lbl_gte_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_GTE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_key_accessContext : public ExpressionContext {
  public:
    Lbl_key_accessContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *obj = nullptr;
    TythonParser::ExpressionContext *key = nullptr;
    antlr4::tree::TerminalNode *SYM_LSQ();
    antlr4::tree::TerminalNode *SYM_RSQ();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_lte_exprContext : public ExpressionContext {
  public:
    Lbl_lte_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_LTE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_exponent_exprContext : public ExpressionContext {
  public:
    Lbl_exponent_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_EXP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_gt_exprContext : public ExpressionContext {
  public:
    Lbl_gt_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_GT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

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

  class  Lbl_floor_div_exprContext : public ExpressionContext {
  public:
    Lbl_floor_div_exprContext(ExpressionContext *ctx);

    TythonParser::ExpressionContext *lhs = nullptr;
    TythonParser::ExpressionContext *rhs = nullptr;
    antlr4::tree::TerminalNode *SYM_FLOOR_DIV();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  LvalContext : public antlr4::ParserRuleContext {
  public:
    LvalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LvalContext() = default;
    void copyFrom(LvalContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Lbl_lval_identifierContext : public LvalContext {
  public:
    Lbl_lval_identifierContext(LvalContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lbl_lval_key_accessContext : public LvalContext {
  public:
    Lbl_lval_key_accessContext(LvalContext *ctx);

    TythonParser::ExpressionContext *obj = nullptr;
    TythonParser::ExpressionContext *key = nullptr;
    antlr4::tree::TerminalNode *SYM_LSQ();
    antlr4::tree::TerminalNode *SYM_RSQ();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

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
    std::vector<antlr4::tree::TerminalNode *> SYM_COMMA();
    antlr4::tree::TerminalNode* SYM_COMMA(size_t i);
    std::vector<Key_value_pairContext *> key_value_pair();
    Key_value_pairContext* key_value_pair(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dict_litContext* dict_lit();

  class  List_litContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> elements;
    List_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_LSQ();
    antlr4::tree::TerminalNode *SYM_RSQ();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SYM_COMMA();
    antlr4::tree::TerminalNode* SYM_COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_litContext* list_lit();

  class  Tuple_litContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> elements;
    Tuple_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYM_LPAR();
    antlr4::tree::TerminalNode *SYM_RPAR();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SYM_COMMA();
    antlr4::tree::TerminalNode* SYM_COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tuple_litContext* tuple_lit();

  class  Slice_litContext : public antlr4::ParserRuleContext {
  public:
    TythonParser::ExpressionContext *start = nullptr;
    TythonParser::ExpressionContext *end = nullptr;
    TythonParser::ExpressionContext *step = nullptr;
    Slice_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SYM_COL();
    antlr4::tree::TerminalNode* SYM_COL(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Slice_litContext* slice_lit();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LIT();
    antlr4::tree::TerminalNode *FLOAT_LIT();
    antlr4::tree::TerminalNode *STR_LIT();
    antlr4::tree::TerminalNode *NONE_LIT();
    antlr4::tree::TerminalNode *TRUE_LIT();
    antlr4::tree::TerminalNode *FALSE_LIT();
    Dict_litContext *dict_lit();
    List_litContext *list_lit();
    Tuple_litContext *tuple_lit();


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

