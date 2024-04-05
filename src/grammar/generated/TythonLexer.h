
#include "../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/src/grammar/TythonLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonLexer : public TythonLexerBase {
public:
  enum {
    INDENT = 1, DEDENT = 2, KW_DEF = 3, KW_RETURN = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_FOR = 7, KW_IN = 8, KW_WHILE = 9, KW_BREAK = 10, KW_EXTERN = 11, 
    KW_IMPORT = 12, KW_SELF = 13, SYM_LPAR = 14, SYM_RPAR = 15, SYM_LSQ = 16, 
    SYM_RSQ = 17, SYM_LBR = 18, SYM_RBR = 19, SYM_COL = 20, SYM_SEMCOL = 21, 
    SYM_COMMA = 22, SYM_STMNT_DELIMITER = 23, SYM_ASSIGN = 24, SYM_PLUS_EQ = 25, 
    SYM_MINUS_EQ = 26, SYM_NEQ = 27, SYM_LTE = 28, SYM_LT = 29, SYM_EQ = 30, 
    SYM_GT = 31, SYM_GTE = 32, SYM_AND = 33, SYM_OR = 34, SYM_PLUS = 35, 
    SYM_MINUS = 36, SYM_MULT = 37, SYM_DIV = 38, SYM_EXP = 39, SYM_INC = 40, 
    SYM_DEC = 41, SYM_DOT = 42, SYM_ELLIPS = 43, SYM_COMMENT = 44, SYM_COMMENT_START = 45, 
    TRUE_LIT = 46, FALSE_LIT = 47, NONE_LIT = 48, IDENTIFIER = 49, INT_LIT = 50, 
    FLOAT_LIT = 51, STR_LIT = 52, NEWLINE = 53, WS = 54, SYM_COMMENT_END = 55, 
    COMMENT_CONTENT = 56
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

