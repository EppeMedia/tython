
#include "../../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/grammar/TythonLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  TythonLexer : public TythonLexerBase {
public:
  enum {
    INDENT = 1, DEDENT = 2, KW_DEF = 3, KW_RETURN = 4, KW_IF = 5, KW_ELSE = 6, 
    KW_WHILE = 7, KW_EXTERN = 8, KW_IMPORT = 9, SYM_LPAR = 10, SYM_RPAR = 11, 
    SYM_BLOCK_START = 12, SYM_ARG_SEPARATOR = 13, SYM_STMNT_DELIMITER = 14, 
    SYM_ASSIGN = 15, SYM_NEQ = 16, SYM_LTE = 17, SYM_LT = 18, SYM_EQ = 19, 
    SYM_GT = 20, SYM_GTE = 21, SYM_AND = 22, SYM_OR = 23, SYM_PLUS = 24, 
    SYM_MINUS = 25, SYM_MULT = 26, SYM_DIV = 27, SYM_EXP = 28, SYM_DOT = 29, 
    SYM_ELLIPS = 30, SYM_COMMENT = 31, SYM_COMMENT_START = 32, IDENTIFIER = 33, 
    INT_LIT = 34, FLOAT_LIT = 35, STR_LIT = 36, TRUE_LIT = 37, FALSE_LIT = 38, 
    NEWLINE = 39, WS = 40, SYM_COMMENT_END = 41, COMMENT_CONTENT = 42
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
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

