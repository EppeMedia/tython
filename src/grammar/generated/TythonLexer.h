
#include "../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/src/grammar/TythonLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonLexer : public TythonLexerBase {
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
    comment_block = 1
  };

  explicit TythonLexer(antlr4::CharStream *input);

  ~TythonLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void SYM_LPARAction(antlr4::RuleContext *context, size_t actionIndex);
  void SYM_RPARAction(antlr4::RuleContext *context, size_t actionIndex);
  void SYM_LSQAction(antlr4::RuleContext *context, size_t actionIndex);
  void SYM_RSQAction(antlr4::RuleContext *context, size_t actionIndex);
  void SYM_LBRAction(antlr4::RuleContext *context, size_t actionIndex);
  void SYM_RBRAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

