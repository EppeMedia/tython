
#include "../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/src/grammar/TythonLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonLexer : public TythonLexerBase {
public:
  enum {
    INDENT = 1, DEDENT = 2, KW_DEF = 3, KW_RETURN = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_FOR = 7, KW_WHILE = 8, KW_EXTERN = 9, KW_IMPORT = 10, KW_SELF = 11, 
    SYM_LPAR = 12, SYM_RPAR = 13, SYM_LSQ = 14, SYM_RSQ = 15, SYM_LBR = 16, 
    SYM_RBR = 17, SYM_COL = 18, SYM_SEMCOL = 19, SYM_COMMA = 20, SYM_STMNT_DELIMITER = 21, 
    SYM_ASSIGN = 22, SYM_NEQ = 23, SYM_LTE = 24, SYM_LT = 25, SYM_EQ = 26, 
    SYM_GT = 27, SYM_GTE = 28, SYM_AND = 29, SYM_OR = 30, SYM_PLUS = 31, 
    SYM_MINUS = 32, SYM_MULT = 33, SYM_DIV = 34, SYM_EXP = 35, SYM_DOT = 36, 
    SYM_ELLIPS = 37, SYM_COMMENT = 38, SYM_COMMENT_START = 39, IDENTIFIER = 40, 
    INT_LIT = 41, FLOAT_LIT = 42, STR_LIT = 43, TRUE_LIT = 44, FALSE_LIT = 45, 
    NEWLINE = 46, WS = 47, SYM_COMMENT_END = 48, COMMENT_CONTENT = 49
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

