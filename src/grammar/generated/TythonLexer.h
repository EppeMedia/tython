
#include "../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/src/grammar/TythonLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonLexer : public TythonLexerBase {
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

