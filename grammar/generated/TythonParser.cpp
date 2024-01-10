
// Generated from /home/manzi/repos/tython/grammar/TythonParser.g4 by ANTLR 4.12.0


#include "TythonParserVisitor.h"

#include "TythonParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TythonParserStaticData final {
  TythonParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TythonParserStaticData(const TythonParserStaticData&) = delete;
  TythonParserStaticData(TythonParserStaticData&&) = delete;
  TythonParserStaticData& operator=(const TythonParserStaticData&) = delete;
  TythonParserStaticData& operator=(TythonParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tythonparserParserOnceFlag;
TythonParserStaticData *tythonparserParserStaticData = nullptr;

void tythonparserParserInitialize() {
  assert(tythonparserParserStaticData == nullptr);
  auto staticData = std::make_unique<TythonParserStaticData>(
    std::vector<std::string>{
      "program", "globalStatement", "function_def", "block", "statement", 
      "simple_statement", "simple_statements", "compound_statement", "assign_statement", 
      "return_statement", "if_statement", "arguments", "parameters", "call_expression", 
      "expression", "binary_operator", "inequality_operator", "logic_operator", 
      "arithmetic_operator", "atomic", "constant"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'while'", "'extern'", 
      "'('", "')'", "':'", "','", "';'", "'='", "'!='", "'<='", "'<'", "'=='", 
      "'>'", "'>='", "'&&'", "'||'", "'+'", "'-'", "'*'", "'/'", "'**'", 
      "", "'/*'", "'...'", "", "", "", "", "'true'", "'false'", "", "", 
      "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_WHILE", "KW_EXTERN", "SYM_LPAR", "SYM_RPAR", "SYM_BLOCK_START", 
      "SYM_ARG_SEPARATOR", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", "SYM_NEQ", 
      "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", 
      "SYM_PLUS", "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", "SYM_COMMENT", 
      "SYM_COMMENT_START", "SYM_ELLIPS", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", 
      "STR_LIT", "TRUE_LIT", "FALSE_LIT", "NEWLINE", "WS", "SYM_COMMENT_END", 
      "ALL_ELSE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,189,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,4,
  	0,44,8,0,11,0,12,0,45,1,0,1,0,1,1,1,1,3,1,52,8,1,1,2,1,2,1,2,1,2,1,2,
  	3,2,59,8,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,4,3,69,8,3,11,3,12,3,70,1,
  	3,1,3,3,3,75,8,3,1,4,1,4,3,4,79,8,4,1,5,1,5,1,5,3,5,84,8,5,1,6,1,6,1,
  	6,5,6,89,8,6,10,6,12,6,92,9,6,1,6,3,6,95,8,6,1,6,1,6,1,7,1,7,3,7,101,
  	8,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	10,3,10,118,8,10,3,10,120,8,10,1,11,3,11,123,8,11,1,11,1,11,1,11,4,11,
  	128,8,11,11,11,12,11,129,3,11,132,8,11,1,12,3,12,135,8,12,1,12,1,12,1,
  	12,4,12,140,8,12,11,12,12,12,141,3,12,144,8,12,1,13,3,13,147,8,13,1,13,
  	1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,161,8,14,
  	1,14,1,14,1,14,1,14,5,14,167,8,14,10,14,12,14,170,9,14,1,15,1,15,1,15,
  	3,15,175,8,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,3,19,185,8,19,1,
  	20,1,20,1,20,0,1,28,21,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,0,4,1,0,15,20,1,0,21,22,1,0,23,27,1,0,32,34,193,0,43,1,0,
  	0,0,2,49,1,0,0,0,4,53,1,0,0,0,6,74,1,0,0,0,8,78,1,0,0,0,10,83,1,0,0,0,
  	12,85,1,0,0,0,14,100,1,0,0,0,16,102,1,0,0,0,18,106,1,0,0,0,20,109,1,0,
  	0,0,22,131,1,0,0,0,24,143,1,0,0,0,26,146,1,0,0,0,28,160,1,0,0,0,30,174,
  	1,0,0,0,32,176,1,0,0,0,34,178,1,0,0,0,36,180,1,0,0,0,38,184,1,0,0,0,40,
  	186,1,0,0,0,42,44,3,8,4,0,43,42,1,0,0,0,44,45,1,0,0,0,45,43,1,0,0,0,45,
  	46,1,0,0,0,46,47,1,0,0,0,47,48,5,0,0,1,48,1,1,0,0,0,49,51,3,16,8,0,50,
  	52,5,13,0,0,51,50,1,0,0,0,51,52,1,0,0,0,52,3,1,0,0,0,53,54,5,3,0,0,54,
  	55,5,31,0,0,55,56,5,9,0,0,56,58,3,22,11,0,57,59,5,30,0,0,58,57,1,0,0,
  	0,58,59,1,0,0,0,59,60,1,0,0,0,60,61,5,10,0,0,61,62,5,11,0,0,62,63,3,6,
  	3,0,63,5,1,0,0,0,64,75,3,12,6,0,65,66,5,37,0,0,66,68,5,1,0,0,67,69,3,
  	8,4,0,68,67,1,0,0,0,69,70,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,72,1,
  	0,0,0,72,73,5,2,0,0,73,75,1,0,0,0,74,64,1,0,0,0,74,65,1,0,0,0,75,7,1,
  	0,0,0,76,79,3,12,6,0,77,79,3,14,7,0,78,76,1,0,0,0,78,77,1,0,0,0,79,9,
  	1,0,0,0,80,84,3,28,14,0,81,84,3,16,8,0,82,84,3,18,9,0,83,80,1,0,0,0,83,
  	81,1,0,0,0,83,82,1,0,0,0,84,11,1,0,0,0,85,90,3,10,5,0,86,87,5,13,0,0,
  	87,89,3,10,5,0,88,86,1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,
  	0,91,94,1,0,0,0,92,90,1,0,0,0,93,95,5,13,0,0,94,93,1,0,0,0,94,95,1,0,
  	0,0,95,96,1,0,0,0,96,97,5,37,0,0,97,13,1,0,0,0,98,101,3,20,10,0,99,101,
  	3,4,2,0,100,98,1,0,0,0,100,99,1,0,0,0,101,15,1,0,0,0,102,103,5,31,0,0,
  	103,104,5,14,0,0,104,105,3,28,14,0,105,17,1,0,0,0,106,107,5,4,0,0,107,
  	108,3,28,14,0,108,19,1,0,0,0,109,110,5,5,0,0,110,111,3,28,14,0,111,112,
  	5,11,0,0,112,119,3,6,3,0,113,117,5,6,0,0,114,118,3,20,10,0,115,116,5,
  	11,0,0,116,118,3,6,3,0,117,114,1,0,0,0,117,115,1,0,0,0,118,120,1,0,0,
  	0,119,113,1,0,0,0,119,120,1,0,0,0,120,21,1,0,0,0,121,123,5,31,0,0,122,
  	121,1,0,0,0,122,123,1,0,0,0,123,132,1,0,0,0,124,127,5,31,0,0,125,126,
  	5,12,0,0,126,128,5,31,0,0,127,125,1,0,0,0,128,129,1,0,0,0,129,127,1,0,
  	0,0,129,130,1,0,0,0,130,132,1,0,0,0,131,122,1,0,0,0,131,124,1,0,0,0,132,
  	23,1,0,0,0,133,135,3,28,14,0,134,133,1,0,0,0,134,135,1,0,0,0,135,144,
  	1,0,0,0,136,139,3,28,14,0,137,138,5,12,0,0,138,140,3,28,14,0,139,137,
  	1,0,0,0,140,141,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,144,1,0,0,
  	0,143,134,1,0,0,0,143,136,1,0,0,0,144,25,1,0,0,0,145,147,5,8,0,0,146,
  	145,1,0,0,0,146,147,1,0,0,0,147,148,1,0,0,0,148,149,5,31,0,0,149,150,
  	5,9,0,0,150,151,3,24,12,0,151,152,5,10,0,0,152,27,1,0,0,0,153,154,6,14,
  	-1,0,154,161,3,26,13,0,155,156,5,9,0,0,156,157,3,28,14,0,157,158,5,10,
  	0,0,158,161,1,0,0,0,159,161,3,38,19,0,160,153,1,0,0,0,160,155,1,0,0,0,
  	160,159,1,0,0,0,161,168,1,0,0,0,162,163,10,4,0,0,163,164,3,30,15,0,164,
  	165,3,28,14,5,165,167,1,0,0,0,166,162,1,0,0,0,167,170,1,0,0,0,168,166,
  	1,0,0,0,168,169,1,0,0,0,169,29,1,0,0,0,170,168,1,0,0,0,171,175,3,32,16,
  	0,172,175,3,34,17,0,173,175,3,36,18,0,174,171,1,0,0,0,174,172,1,0,0,0,
  	174,173,1,0,0,0,175,31,1,0,0,0,176,177,7,0,0,0,177,33,1,0,0,0,178,179,
  	7,1,0,0,179,35,1,0,0,0,180,181,7,2,0,0,181,37,1,0,0,0,182,185,3,40,20,
  	0,183,185,5,31,0,0,184,182,1,0,0,0,184,183,1,0,0,0,185,39,1,0,0,0,186,
  	187,7,3,0,0,187,41,1,0,0,0,23,45,51,58,70,74,78,83,90,94,100,117,119,
  	122,129,131,134,141,143,146,160,168,174,184
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tythonparserParserStaticData = staticData.release();
}

}

TythonParser::TythonParser(TokenStream *input) : TythonParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TythonParser::TythonParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TythonParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *tythonparserParserStaticData->atn, tythonparserParserStaticData->decisionToDFA, tythonparserParserStaticData->sharedContextCache, options);
}

TythonParser::~TythonParser() {
  delete _interpreter;
}

const atn::ATN& TythonParser::getATN() const {
  return *tythonparserParserStaticData->atn;
}

std::string TythonParser::getGrammarFileName() const {
  return "TythonParser.g4";
}

const std::vector<std::string>& TythonParser::getRuleNames() const {
  return tythonparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& TythonParser::getVocabulary() const {
  return tythonparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TythonParser::getSerializedATN() const {
  return tythonparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

TythonParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::ProgramContext::EOF() {
  return getToken(TythonParser::EOF, 0);
}

std::vector<TythonParser::StatementContext *> TythonParser::ProgramContext::statement() {
  return getRuleContexts<TythonParser::StatementContext>();
}

TythonParser::StatementContext* TythonParser::ProgramContext::statement(size_t i) {
  return getRuleContext<TythonParser::StatementContext>(i);
}


size_t TythonParser::ProgramContext::getRuleIndex() const {
  return TythonParser::RuleProgram;
}


std::any TythonParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::ProgramContext* TythonParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, TythonParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(42);
      statement();
      setState(45); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32212255544) != 0));
    setState(47);
    match(TythonParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalStatementContext ------------------------------------------------------------------

TythonParser::GlobalStatementContext::GlobalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::Assign_statementContext* TythonParser::GlobalStatementContext::assign_statement() {
  return getRuleContext<TythonParser::Assign_statementContext>(0);
}

tree::TerminalNode* TythonParser::GlobalStatementContext::SYM_STMNT_DELIMITER() {
  return getToken(TythonParser::SYM_STMNT_DELIMITER, 0);
}


size_t TythonParser::GlobalStatementContext::getRuleIndex() const {
  return TythonParser::RuleGlobalStatement;
}


std::any TythonParser::GlobalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitGlobalStatement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::GlobalStatementContext* TythonParser::globalStatement() {
  GlobalStatementContext *_localctx = _tracker.createInstance<GlobalStatementContext>(_ctx, getState());
  enterRule(_localctx, 2, TythonParser::RuleGlobalStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    assign_statement();
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_STMNT_DELIMITER) {
      setState(50);
      match(TythonParser::SYM_STMNT_DELIMITER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_defContext ------------------------------------------------------------------

TythonParser::Function_defContext::Function_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Function_defContext::KW_DEF() {
  return getToken(TythonParser::KW_DEF, 0);
}

tree::TerminalNode* TythonParser::Function_defContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

tree::TerminalNode* TythonParser::Function_defContext::SYM_LPAR() {
  return getToken(TythonParser::SYM_LPAR, 0);
}

TythonParser::ArgumentsContext* TythonParser::Function_defContext::arguments() {
  return getRuleContext<TythonParser::ArgumentsContext>(0);
}

tree::TerminalNode* TythonParser::Function_defContext::SYM_RPAR() {
  return getToken(TythonParser::SYM_RPAR, 0);
}

tree::TerminalNode* TythonParser::Function_defContext::SYM_BLOCK_START() {
  return getToken(TythonParser::SYM_BLOCK_START, 0);
}

TythonParser::BlockContext* TythonParser::Function_defContext::block() {
  return getRuleContext<TythonParser::BlockContext>(0);
}

tree::TerminalNode* TythonParser::Function_defContext::SYM_ELLIPS() {
  return getToken(TythonParser::SYM_ELLIPS, 0);
}


size_t TythonParser::Function_defContext::getRuleIndex() const {
  return TythonParser::RuleFunction_def;
}


std::any TythonParser::Function_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitFunction_def(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Function_defContext* TythonParser::function_def() {
  Function_defContext *_localctx = _tracker.createInstance<Function_defContext>(_ctx, getState());
  enterRule(_localctx, 4, TythonParser::RuleFunction_def);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(TythonParser::KW_DEF);
    setState(54);
    match(TythonParser::IDENTIFIER);
    setState(55);
    match(TythonParser::SYM_LPAR);
    setState(56);
    arguments();
    setState(58);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_ELLIPS) {
      setState(57);
      match(TythonParser::SYM_ELLIPS);
    }
    setState(60);
    match(TythonParser::SYM_RPAR);
    setState(61);
    match(TythonParser::SYM_BLOCK_START);
    setState(62);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

TythonParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::Simple_statementsContext* TythonParser::BlockContext::simple_statements() {
  return getRuleContext<TythonParser::Simple_statementsContext>(0);
}

tree::TerminalNode* TythonParser::BlockContext::NEWLINE() {
  return getToken(TythonParser::NEWLINE, 0);
}

tree::TerminalNode* TythonParser::BlockContext::INDENT() {
  return getToken(TythonParser::INDENT, 0);
}

tree::TerminalNode* TythonParser::BlockContext::DEDENT() {
  return getToken(TythonParser::DEDENT, 0);
}

std::vector<TythonParser::StatementContext *> TythonParser::BlockContext::statement() {
  return getRuleContexts<TythonParser::StatementContext>();
}

TythonParser::StatementContext* TythonParser::BlockContext::statement(size_t i) {
  return getRuleContext<TythonParser::StatementContext>(i);
}


size_t TythonParser::BlockContext::getRuleIndex() const {
  return TythonParser::RuleBlock;
}


std::any TythonParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::BlockContext* TythonParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, TythonParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(64);
        simple_statements();
        break;
      }

      case TythonParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(65);
        match(TythonParser::NEWLINE);
        setState(66);
        match(TythonParser::INDENT);
        setState(68); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(67);
          antlrcpp::downCast<BlockContext *>(_localctx)->indent_statements = statement();
          setState(70); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 32212255544) != 0));
        setState(72);
        match(TythonParser::DEDENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

TythonParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::Simple_statementsContext* TythonParser::StatementContext::simple_statements() {
  return getRuleContext<TythonParser::Simple_statementsContext>(0);
}

TythonParser::Compound_statementContext* TythonParser::StatementContext::compound_statement() {
  return getRuleContext<TythonParser::Compound_statementContext>(0);
}


size_t TythonParser::StatementContext::getRuleIndex() const {
  return TythonParser::RuleStatement;
}


std::any TythonParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::StatementContext* TythonParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, TythonParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        simple_statements();
        break;
      }

      case TythonParser::KW_DEF:
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        compound_statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_statementContext ------------------------------------------------------------------

TythonParser::Simple_statementContext::Simple_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::ExpressionContext* TythonParser::Simple_statementContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Assign_statementContext* TythonParser::Simple_statementContext::assign_statement() {
  return getRuleContext<TythonParser::Assign_statementContext>(0);
}

TythonParser::Return_statementContext* TythonParser::Simple_statementContext::return_statement() {
  return getRuleContext<TythonParser::Return_statementContext>(0);
}


size_t TythonParser::Simple_statementContext::getRuleIndex() const {
  return TythonParser::RuleSimple_statement;
}


std::any TythonParser::Simple_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitSimple_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Simple_statementContext* TythonParser::simple_statement() {
  Simple_statementContext *_localctx = _tracker.createInstance<Simple_statementContext>(_ctx, getState());
  enterRule(_localctx, 10, TythonParser::RuleSimple_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(80);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(81);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(82);
      return_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_statementsContext ------------------------------------------------------------------

TythonParser::Simple_statementsContext::Simple_statementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TythonParser::Simple_statementContext *> TythonParser::Simple_statementsContext::simple_statement() {
  return getRuleContexts<TythonParser::Simple_statementContext>();
}

TythonParser::Simple_statementContext* TythonParser::Simple_statementsContext::simple_statement(size_t i) {
  return getRuleContext<TythonParser::Simple_statementContext>(i);
}

tree::TerminalNode* TythonParser::Simple_statementsContext::NEWLINE() {
  return getToken(TythonParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TythonParser::Simple_statementsContext::SYM_STMNT_DELIMITER() {
  return getTokens(TythonParser::SYM_STMNT_DELIMITER);
}

tree::TerminalNode* TythonParser::Simple_statementsContext::SYM_STMNT_DELIMITER(size_t i) {
  return getToken(TythonParser::SYM_STMNT_DELIMITER, i);
}


size_t TythonParser::Simple_statementsContext::getRuleIndex() const {
  return TythonParser::RuleSimple_statements;
}


std::any TythonParser::Simple_statementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitSimple_statements(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Simple_statementsContext* TythonParser::simple_statements() {
  Simple_statementsContext *_localctx = _tracker.createInstance<Simple_statementsContext>(_ctx, getState());
  enterRule(_localctx, 12, TythonParser::RuleSimple_statements);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(85);
    simple_statement();
    setState(90);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(86);
        match(TythonParser::SYM_STMNT_DELIMITER);
        setState(87);
        simple_statement(); 
      }
      setState(92);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(94);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_STMNT_DELIMITER) {
      setState(93);
      match(TythonParser::SYM_STMNT_DELIMITER);
    }
    setState(96);
    match(TythonParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

TythonParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::If_statementContext* TythonParser::Compound_statementContext::if_statement() {
  return getRuleContext<TythonParser::If_statementContext>(0);
}

TythonParser::Function_defContext* TythonParser::Compound_statementContext::function_def() {
  return getRuleContext<TythonParser::Function_defContext>(0);
}


size_t TythonParser::Compound_statementContext::getRuleIndex() const {
  return TythonParser::RuleCompound_statement;
}


std::any TythonParser::Compound_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitCompound_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Compound_statementContext* TythonParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 14, TythonParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(100);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        if_statement();
        break;
      }

      case TythonParser::KW_DEF: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        function_def();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_statementContext ------------------------------------------------------------------

TythonParser::Assign_statementContext::Assign_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Assign_statementContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

tree::TerminalNode* TythonParser::Assign_statementContext::SYM_ASSIGN() {
  return getToken(TythonParser::SYM_ASSIGN, 0);
}

TythonParser::ExpressionContext* TythonParser::Assign_statementContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}


size_t TythonParser::Assign_statementContext::getRuleIndex() const {
  return TythonParser::RuleAssign_statement;
}


std::any TythonParser::Assign_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitAssign_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Assign_statementContext* TythonParser::assign_statement() {
  Assign_statementContext *_localctx = _tracker.createInstance<Assign_statementContext>(_ctx, getState());
  enterRule(_localctx, 16, TythonParser::RuleAssign_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(TythonParser::IDENTIFIER);
    setState(103);
    match(TythonParser::SYM_ASSIGN);
    setState(104);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

TythonParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Return_statementContext::KW_RETURN() {
  return getToken(TythonParser::KW_RETURN, 0);
}

TythonParser::ExpressionContext* TythonParser::Return_statementContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}


size_t TythonParser::Return_statementContext::getRuleIndex() const {
  return TythonParser::RuleReturn_statement;
}


std::any TythonParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Return_statementContext* TythonParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, TythonParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(TythonParser::KW_RETURN);
    setState(107);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

TythonParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::If_statementContext::KW_IF() {
  return getToken(TythonParser::KW_IF, 0);
}

TythonParser::ExpressionContext* TythonParser::If_statementContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> TythonParser::If_statementContext::SYM_BLOCK_START() {
  return getTokens(TythonParser::SYM_BLOCK_START);
}

tree::TerminalNode* TythonParser::If_statementContext::SYM_BLOCK_START(size_t i) {
  return getToken(TythonParser::SYM_BLOCK_START, i);
}

std::vector<TythonParser::BlockContext *> TythonParser::If_statementContext::block() {
  return getRuleContexts<TythonParser::BlockContext>();
}

TythonParser::BlockContext* TythonParser::If_statementContext::block(size_t i) {
  return getRuleContext<TythonParser::BlockContext>(i);
}

tree::TerminalNode* TythonParser::If_statementContext::KW_ELSE() {
  return getToken(TythonParser::KW_ELSE, 0);
}

TythonParser::If_statementContext* TythonParser::If_statementContext::if_statement() {
  return getRuleContext<TythonParser::If_statementContext>(0);
}


size_t TythonParser::If_statementContext::getRuleIndex() const {
  return TythonParser::RuleIf_statement;
}


std::any TythonParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::If_statementContext* TythonParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 20, TythonParser::RuleIf_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(TythonParser::KW_IF);
    setState(110);
    expression(0);
    setState(111);
    match(TythonParser::SYM_BLOCK_START);
    setState(112);
    antlrcpp::downCast<If_statementContext *>(_localctx)->br_if = block();
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_ELSE) {
      setState(113);
      match(TythonParser::KW_ELSE);
      setState(117);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TythonParser::KW_IF: {
          setState(114);
          antlrcpp::downCast<If_statementContext *>(_localctx)->br_else_if = if_statement();
          break;
        }

        case TythonParser::SYM_BLOCK_START: {
          setState(115);
          match(TythonParser::SYM_BLOCK_START);
          setState(116);
          antlrcpp::downCast<If_statementContext *>(_localctx)->br_else = block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

TythonParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TythonParser::ArgumentsContext::IDENTIFIER() {
  return getTokens(TythonParser::IDENTIFIER);
}

tree::TerminalNode* TythonParser::ArgumentsContext::IDENTIFIER(size_t i) {
  return getToken(TythonParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> TythonParser::ArgumentsContext::SYM_ARG_SEPARATOR() {
  return getTokens(TythonParser::SYM_ARG_SEPARATOR);
}

tree::TerminalNode* TythonParser::ArgumentsContext::SYM_ARG_SEPARATOR(size_t i) {
  return getToken(TythonParser::SYM_ARG_SEPARATOR, i);
}


size_t TythonParser::ArgumentsContext::getRuleIndex() const {
  return TythonParser::RuleArguments;
}


std::any TythonParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::ArgumentsContext* TythonParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 22, TythonParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(122);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TythonParser::IDENTIFIER) {
        setState(121);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(124);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      setState(127); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(125);
        match(TythonParser::SYM_ARG_SEPARATOR);
        setState(126);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
        setState(129); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_ARG_SEPARATOR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

TythonParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TythonParser::ExpressionContext *> TythonParser::ParametersContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::ParametersContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TythonParser::ParametersContext::SYM_ARG_SEPARATOR() {
  return getTokens(TythonParser::SYM_ARG_SEPARATOR);
}

tree::TerminalNode* TythonParser::ParametersContext::SYM_ARG_SEPARATOR(size_t i) {
  return getToken(TythonParser::SYM_ARG_SEPARATOR, i);
}


size_t TythonParser::ParametersContext::getRuleIndex() const {
  return TythonParser::RuleParameters;
}


std::any TythonParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::ParametersContext* TythonParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 24, TythonParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32212255488) != 0)) {
        setState(133);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(136);
      antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
      antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      setState(139); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(137);
        match(TythonParser::SYM_ARG_SEPARATOR);
        setState(138);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
        setState(141); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_ARG_SEPARATOR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_expressionContext ------------------------------------------------------------------

TythonParser::Call_expressionContext::Call_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Call_expressionContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

tree::TerminalNode* TythonParser::Call_expressionContext::SYM_LPAR() {
  return getToken(TythonParser::SYM_LPAR, 0);
}

TythonParser::ParametersContext* TythonParser::Call_expressionContext::parameters() {
  return getRuleContext<TythonParser::ParametersContext>(0);
}

tree::TerminalNode* TythonParser::Call_expressionContext::SYM_RPAR() {
  return getToken(TythonParser::SYM_RPAR, 0);
}

tree::TerminalNode* TythonParser::Call_expressionContext::KW_EXTERN() {
  return getToken(TythonParser::KW_EXTERN, 0);
}


size_t TythonParser::Call_expressionContext::getRuleIndex() const {
  return TythonParser::RuleCall_expression;
}


std::any TythonParser::Call_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitCall_expression(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Call_expressionContext* TythonParser::call_expression() {
  Call_expressionContext *_localctx = _tracker.createInstance<Call_expressionContext>(_ctx, getState());
  enterRule(_localctx, 26, TythonParser::RuleCall_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(145);
      match(TythonParser::KW_EXTERN);
    }
    setState(148);
    match(TythonParser::IDENTIFIER);
    setState(149);
    match(TythonParser::SYM_LPAR);
    setState(150);
    parameters();
    setState(151);
    match(TythonParser::SYM_RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

TythonParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TythonParser::ExpressionContext::getRuleIndex() const {
  return TythonParser::RuleExpression;
}

void TythonParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Binary_expressionContext ------------------------------------------------------------------

TythonParser::Binary_operatorContext* TythonParser::Binary_expressionContext::binary_operator() {
  return getRuleContext<TythonParser::Binary_operatorContext>(0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Binary_expressionContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Binary_expressionContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Binary_expressionContext::Binary_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Binary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitBinary_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_call_expressionContext ------------------------------------------------------------------

TythonParser::Call_expressionContext* TythonParser::Lbl_call_expressionContext::call_expression() {
  return getRuleContext<TythonParser::Call_expressionContext>(0);
}

TythonParser::Lbl_call_expressionContext::Lbl_call_expressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_call_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_call_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_expression_parenthesesContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_expression_parenthesesContext::SYM_LPAR() {
  return getToken(TythonParser::SYM_LPAR, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_expression_parenthesesContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_expression_parenthesesContext::SYM_RPAR() {
  return getToken(TythonParser::SYM_RPAR, 0);
}

TythonParser::Lbl_expression_parenthesesContext::Lbl_expression_parenthesesContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_expression_parenthesesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_expression_parentheses(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_atomicContext ------------------------------------------------------------------

TythonParser::AtomicContext* TythonParser::Lbl_atomicContext::atomic() {
  return getRuleContext<TythonParser::AtomicContext>(0);
}

TythonParser::Lbl_atomicContext::Lbl_atomicContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_atomicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_atomic(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::ExpressionContext* TythonParser::expression() {
   return expression(0);
}

TythonParser::ExpressionContext* TythonParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TythonParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  TythonParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, TythonParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Lbl_call_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(154);
      call_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Lbl_expression_parenthesesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(155);
      match(TythonParser::SYM_LPAR);
      setState(156);
      expression(0);
      setState(157);
      match(TythonParser::SYM_RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lbl_atomicContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(159);
      atomic();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(168);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Binary_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->lhs = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(162);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(163);
        binary_operator();
        setState(164);
        antlrcpp::downCast<Binary_expressionContext *>(_localctx)->rhs = expression(5); 
      }
      setState(170);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

TythonParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::Inequality_operatorContext* TythonParser::Binary_operatorContext::inequality_operator() {
  return getRuleContext<TythonParser::Inequality_operatorContext>(0);
}

TythonParser::Logic_operatorContext* TythonParser::Binary_operatorContext::logic_operator() {
  return getRuleContext<TythonParser::Logic_operatorContext>(0);
}

TythonParser::Arithmetic_operatorContext* TythonParser::Binary_operatorContext::arithmetic_operator() {
  return getRuleContext<TythonParser::Arithmetic_operatorContext>(0);
}


size_t TythonParser::Binary_operatorContext::getRuleIndex() const {
  return TythonParser::RuleBinary_operator;
}


std::any TythonParser::Binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitBinary_operator(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Binary_operatorContext* TythonParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 30, TythonParser::RuleBinary_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::SYM_NEQ:
      case TythonParser::SYM_LTE:
      case TythonParser::SYM_LT:
      case TythonParser::SYM_EQ:
      case TythonParser::SYM_GT:
      case TythonParser::SYM_GTE: {
        enterOuterAlt(_localctx, 1);
        setState(171);
        inequality_operator();
        break;
      }

      case TythonParser::SYM_AND:
      case TythonParser::SYM_OR: {
        enterOuterAlt(_localctx, 2);
        setState(172);
        logic_operator();
        break;
      }

      case TythonParser::SYM_PLUS:
      case TythonParser::SYM_MINUS:
      case TythonParser::SYM_MULT:
      case TythonParser::SYM_DIV:
      case TythonParser::SYM_EXP: {
        enterOuterAlt(_localctx, 3);
        setState(173);
        arithmetic_operator();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Inequality_operatorContext ------------------------------------------------------------------

TythonParser::Inequality_operatorContext::Inequality_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Inequality_operatorContext::SYM_NEQ() {
  return getToken(TythonParser::SYM_NEQ, 0);
}

tree::TerminalNode* TythonParser::Inequality_operatorContext::SYM_LT() {
  return getToken(TythonParser::SYM_LT, 0);
}

tree::TerminalNode* TythonParser::Inequality_operatorContext::SYM_LTE() {
  return getToken(TythonParser::SYM_LTE, 0);
}

tree::TerminalNode* TythonParser::Inequality_operatorContext::SYM_EQ() {
  return getToken(TythonParser::SYM_EQ, 0);
}

tree::TerminalNode* TythonParser::Inequality_operatorContext::SYM_GT() {
  return getToken(TythonParser::SYM_GT, 0);
}

tree::TerminalNode* TythonParser::Inequality_operatorContext::SYM_GTE() {
  return getToken(TythonParser::SYM_GTE, 0);
}


size_t TythonParser::Inequality_operatorContext::getRuleIndex() const {
  return TythonParser::RuleInequality_operator;
}


std::any TythonParser::Inequality_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitInequality_operator(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Inequality_operatorContext* TythonParser::inequality_operator() {
  Inequality_operatorContext *_localctx = _tracker.createInstance<Inequality_operatorContext>(_ctx, getState());
  enterRule(_localctx, 32, TythonParser::RuleInequality_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2064384) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_operatorContext ------------------------------------------------------------------

TythonParser::Logic_operatorContext::Logic_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Logic_operatorContext::SYM_AND() {
  return getToken(TythonParser::SYM_AND, 0);
}

tree::TerminalNode* TythonParser::Logic_operatorContext::SYM_OR() {
  return getToken(TythonParser::SYM_OR, 0);
}


size_t TythonParser::Logic_operatorContext::getRuleIndex() const {
  return TythonParser::RuleLogic_operator;
}


std::any TythonParser::Logic_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLogic_operator(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Logic_operatorContext* TythonParser::logic_operator() {
  Logic_operatorContext *_localctx = _tracker.createInstance<Logic_operatorContext>(_ctx, getState());
  enterRule(_localctx, 34, TythonParser::RuleLogic_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _la = _input->LA(1);
    if (!(_la == TythonParser::SYM_AND

    || _la == TythonParser::SYM_OR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arithmetic_operatorContext ------------------------------------------------------------------

TythonParser::Arithmetic_operatorContext::Arithmetic_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Arithmetic_operatorContext::SYM_PLUS() {
  return getToken(TythonParser::SYM_PLUS, 0);
}

tree::TerminalNode* TythonParser::Arithmetic_operatorContext::SYM_MINUS() {
  return getToken(TythonParser::SYM_MINUS, 0);
}

tree::TerminalNode* TythonParser::Arithmetic_operatorContext::SYM_MULT() {
  return getToken(TythonParser::SYM_MULT, 0);
}

tree::TerminalNode* TythonParser::Arithmetic_operatorContext::SYM_DIV() {
  return getToken(TythonParser::SYM_DIV, 0);
}

tree::TerminalNode* TythonParser::Arithmetic_operatorContext::SYM_EXP() {
  return getToken(TythonParser::SYM_EXP, 0);
}


size_t TythonParser::Arithmetic_operatorContext::getRuleIndex() const {
  return TythonParser::RuleArithmetic_operator;
}


std::any TythonParser::Arithmetic_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitArithmetic_operator(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Arithmetic_operatorContext* TythonParser::arithmetic_operator() {
  Arithmetic_operatorContext *_localctx = _tracker.createInstance<Arithmetic_operatorContext>(_ctx, getState());
  enterRule(_localctx, 36, TythonParser::RuleArithmetic_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 260046848) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicContext ------------------------------------------------------------------

TythonParser::AtomicContext::AtomicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::ConstantContext* TythonParser::AtomicContext::constant() {
  return getRuleContext<TythonParser::ConstantContext>(0);
}

tree::TerminalNode* TythonParser::AtomicContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}


size_t TythonParser::AtomicContext::getRuleIndex() const {
  return TythonParser::RuleAtomic;
}


std::any TythonParser::AtomicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitAtomic(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::AtomicContext* TythonParser::atomic() {
  AtomicContext *_localctx = _tracker.createInstance<AtomicContext>(_ctx, getState());
  enterRule(_localctx, 38, TythonParser::RuleAtomic);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(182);
        constant();
        break;
      }

      case TythonParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(183);
        match(TythonParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

TythonParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::ConstantContext::INT_LIT() {
  return getToken(TythonParser::INT_LIT, 0);
}

tree::TerminalNode* TythonParser::ConstantContext::FLOAT_LIT() {
  return getToken(TythonParser::FLOAT_LIT, 0);
}

tree::TerminalNode* TythonParser::ConstantContext::STR_LIT() {
  return getToken(TythonParser::STR_LIT, 0);
}


size_t TythonParser::ConstantContext::getRuleIndex() const {
  return TythonParser::RuleConstant;
}


std::any TythonParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::ConstantContext* TythonParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 40, TythonParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30064771072) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool TythonParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 14: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TythonParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void TythonParser::initialize() {
  ::antlr4::internal::call_once(tythonparserParserOnceFlag, tythonparserParserInitialize);
}
