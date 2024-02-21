
#include "../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/src/grammar/TythonLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonLexer : public TythonLexerBase {
public:
  enum {
    INDENT = 1, DEDENT = 2, KW_DEF = 3, KW_RETURN = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_FOR = 7, KW_IN = 8, KW_WHILE = 9, KW_EXTERN = 10, KW_IMPORT = 11, 
    KW_SELF = 12, SYM_LPAR = 13, SYM_RPAR = 14, SYM_LSQ = 15, SYM_RSQ = 16, 
    SYM_LBR = 17, SYM_RBR = 18, SYM_COL = 19, SYM_SEMCOL = 20, SYM_COMMA = 21, 
    SYM_STMNT_DELIMITER = 22, SYM_ASSIGN = 23, SYM_NEQ = 24, SYM_LTE = 25, 
    SYM_LT = 26, SYM_EQ = 27, SYM_GT = 28, SYM_GTE = 29, SYM_AND = 30, SYM_OR = 31, 
    SYM_PLUS = 32, SYM_MINUS = 33, SYM_MULT = 34, SYM_DIV = 35, SYM_EXP = 36, 
    SYM_DOT = 37, SYM_ELLIPS = 38, SYM_COMMENT = 39, SYM_COMMENT_START = 40, 
    IDENTIFIER = 41, INT_LIT = 42, FLOAT_LIT = 43, STR_LIT = 44, TRUE_LIT = 45, 
    FALSE_LIT = 46, NEWLINE = 47, WS = 48, SYM_COMMENT_END = 49, COMMENT_CONTENT = 50
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

