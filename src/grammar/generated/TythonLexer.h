
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
    SYM_COMMA = 22, SYM_STMNT_DELIMITER = 23, SYM_ASSIGN = 24, SYM_NEQ = 25, 
    SYM_LTE = 26, SYM_LT = 27, SYM_EQ = 28, SYM_GT = 29, SYM_GTE = 30, SYM_AND = 31, 
    SYM_OR = 32, SYM_PLUS = 33, SYM_MINUS = 34, SYM_MULT = 35, SYM_DIV = 36, 
    SYM_EXP = 37, SYM_INC = 38, SYM_DEC = 39, SYM_DOT = 40, SYM_ELLIPS = 41, 
    SYM_COMMENT = 42, SYM_COMMENT_START = 43, TRUE_LIT = 44, FALSE_LIT = 45, 
    NONE_LIT = 46, IDENTIFIER = 47, INT_LIT = 48, FLOAT_LIT = 49, STR_LIT = 50, 
    NEWLINE = 51, WS = 52, SYM_COMMENT_END = 53, COMMENT_CONTENT = 54
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

