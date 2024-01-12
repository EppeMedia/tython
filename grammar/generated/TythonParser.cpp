
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
      "program", "import_statement", "import_path", "function_def", "block", 
      "statement", "simple_statement", "simple_statements", "compound_statement", 
      "assign_statement", "return_statement", "if_statement", "arguments", 
      "parameters", "call_expression", "expression", "binary_operator", 
      "inequality_operator", "logic_operator", "arithmetic_operator", "atomic", 
      "constant"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'while'", "'extern'", 
      "'import'", "'('", "')'", "':'", "','", "';'", "'='", "'!='", "'<='", 
      "'<'", "'=='", "'>'", "'>='", "'&&'", "'||'", "'+'", "'-'", "'*'", 
      "'/'", "'**'", "'.'", "'...'", "", "'/*'", "", "", "", "", "'true'", 
      "'false'", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_WHILE", "KW_EXTERN", "KW_IMPORT", "SYM_LPAR", "SYM_RPAR", "SYM_BLOCK_START", 
      "SYM_ARG_SEPARATOR", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", "SYM_NEQ", 
      "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", 
      "SYM_PLUS", "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", "SYM_DOT", 
      "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "IDENTIFIER", "INT_LIT", 
      "FLOAT_LIT", "STR_LIT", "TRUE_LIT", "FALSE_LIT", "NEWLINE", "WS", 
      "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,211,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,5,0,46,8,0,10,0,12,0,49,9,0,1,0,4,0,52,8,0,11,0,12,0,53,1,0,1,
  	0,1,1,1,1,1,1,3,1,61,8,1,1,1,1,1,1,2,1,2,1,2,5,2,68,8,2,10,2,12,2,71,
  	9,2,1,3,1,3,3,3,75,8,3,1,3,1,3,1,3,1,3,3,3,81,8,3,1,3,1,3,1,3,1,3,1,4,
  	1,4,1,4,1,4,4,4,91,8,4,11,4,12,4,92,1,4,1,4,3,4,97,8,4,1,5,1,5,3,5,101,
  	8,5,1,6,1,6,1,6,3,6,106,8,6,1,7,1,7,1,7,5,7,111,8,7,10,7,12,7,114,9,7,
  	1,7,3,7,117,8,7,1,7,1,7,1,8,1,8,3,8,123,8,8,1,9,1,9,1,9,1,9,1,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,140,8,11,3,11,142,8,
  	11,1,12,3,12,145,8,12,1,12,1,12,1,12,4,12,150,8,12,11,12,12,12,151,3,
  	12,154,8,12,1,13,3,13,157,8,13,1,13,1,13,1,13,4,13,162,8,13,11,13,12,
  	13,163,3,13,166,8,13,1,14,3,14,169,8,14,1,14,1,14,1,14,1,14,1,14,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,3,15,183,8,15,1,15,1,15,1,15,1,15,5,15,
  	189,8,15,10,15,12,15,192,9,15,1,16,1,16,1,16,3,16,197,8,16,1,17,1,17,
  	1,18,1,18,1,19,1,19,1,20,1,20,3,20,207,8,20,1,21,1,21,1,21,0,1,30,22,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,0,4,1,0,
  	16,21,1,0,22,23,1,0,24,28,1,0,34,36,217,0,47,1,0,0,0,2,57,1,0,0,0,4,64,
  	1,0,0,0,6,72,1,0,0,0,8,96,1,0,0,0,10,100,1,0,0,0,12,105,1,0,0,0,14,107,
  	1,0,0,0,16,122,1,0,0,0,18,124,1,0,0,0,20,128,1,0,0,0,22,131,1,0,0,0,24,
  	153,1,0,0,0,26,165,1,0,0,0,28,168,1,0,0,0,30,182,1,0,0,0,32,196,1,0,0,
  	0,34,198,1,0,0,0,36,200,1,0,0,0,38,202,1,0,0,0,40,206,1,0,0,0,42,208,
  	1,0,0,0,44,46,3,2,1,0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,
  	1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,50,52,3,10,5,0,51,50,1,0,0,0,52,53,
  	1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,55,1,0,0,0,55,56,5,0,0,1,56,1,
  	1,0,0,0,57,58,5,9,0,0,58,60,3,4,2,0,59,61,5,14,0,0,60,59,1,0,0,0,60,61,
  	1,0,0,0,61,62,1,0,0,0,62,63,5,39,0,0,63,3,1,0,0,0,64,69,5,33,0,0,65,66,
  	5,29,0,0,66,68,5,33,0,0,67,65,1,0,0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,
  	70,1,0,0,0,70,5,1,0,0,0,71,69,1,0,0,0,72,74,5,3,0,0,73,75,5,8,0,0,74,
  	73,1,0,0,0,74,75,1,0,0,0,75,76,1,0,0,0,76,77,5,33,0,0,77,78,5,10,0,0,
  	78,80,3,24,12,0,79,81,5,30,0,0,80,79,1,0,0,0,80,81,1,0,0,0,81,82,1,0,
  	0,0,82,83,5,11,0,0,83,84,5,12,0,0,84,85,3,8,4,0,85,7,1,0,0,0,86,97,3,
  	14,7,0,87,88,5,39,0,0,88,90,5,1,0,0,89,91,3,10,5,0,90,89,1,0,0,0,91,92,
  	1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,94,1,0,0,0,94,95,5,2,0,0,95,97,
  	1,0,0,0,96,86,1,0,0,0,96,87,1,0,0,0,97,9,1,0,0,0,98,101,3,14,7,0,99,101,
  	3,16,8,0,100,98,1,0,0,0,100,99,1,0,0,0,101,11,1,0,0,0,102,106,3,30,15,
  	0,103,106,3,18,9,0,104,106,3,20,10,0,105,102,1,0,0,0,105,103,1,0,0,0,
  	105,104,1,0,0,0,106,13,1,0,0,0,107,112,3,12,6,0,108,109,5,14,0,0,109,
  	111,3,12,6,0,110,108,1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,
  	1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,115,117,5,14,0,0,116,115,1,0,
  	0,0,116,117,1,0,0,0,117,118,1,0,0,0,118,119,5,39,0,0,119,15,1,0,0,0,120,
  	123,3,22,11,0,121,123,3,6,3,0,122,120,1,0,0,0,122,121,1,0,0,0,123,17,
  	1,0,0,0,124,125,5,33,0,0,125,126,5,15,0,0,126,127,3,30,15,0,127,19,1,
  	0,0,0,128,129,5,4,0,0,129,130,3,30,15,0,130,21,1,0,0,0,131,132,5,5,0,
  	0,132,133,3,30,15,0,133,134,5,12,0,0,134,141,3,8,4,0,135,139,5,6,0,0,
  	136,140,3,22,11,0,137,138,5,12,0,0,138,140,3,8,4,0,139,136,1,0,0,0,139,
  	137,1,0,0,0,140,142,1,0,0,0,141,135,1,0,0,0,141,142,1,0,0,0,142,23,1,
  	0,0,0,143,145,5,33,0,0,144,143,1,0,0,0,144,145,1,0,0,0,145,154,1,0,0,
  	0,146,149,5,33,0,0,147,148,5,13,0,0,148,150,5,33,0,0,149,147,1,0,0,0,
  	150,151,1,0,0,0,151,149,1,0,0,0,151,152,1,0,0,0,152,154,1,0,0,0,153,144,
  	1,0,0,0,153,146,1,0,0,0,154,25,1,0,0,0,155,157,3,30,15,0,156,155,1,0,
  	0,0,156,157,1,0,0,0,157,166,1,0,0,0,158,161,3,30,15,0,159,160,5,13,0,
  	0,160,162,3,30,15,0,161,159,1,0,0,0,162,163,1,0,0,0,163,161,1,0,0,0,163,
  	164,1,0,0,0,164,166,1,0,0,0,165,156,1,0,0,0,165,158,1,0,0,0,166,27,1,
  	0,0,0,167,169,5,8,0,0,168,167,1,0,0,0,168,169,1,0,0,0,169,170,1,0,0,0,
  	170,171,5,33,0,0,171,172,5,10,0,0,172,173,3,26,13,0,173,174,5,11,0,0,
  	174,29,1,0,0,0,175,176,6,15,-1,0,176,183,3,28,14,0,177,178,5,10,0,0,178,
  	179,3,30,15,0,179,180,5,11,0,0,180,183,1,0,0,0,181,183,3,40,20,0,182,
  	175,1,0,0,0,182,177,1,0,0,0,182,181,1,0,0,0,183,190,1,0,0,0,184,185,10,
  	4,0,0,185,186,3,32,16,0,186,187,3,30,15,5,187,189,1,0,0,0,188,184,1,0,
  	0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,191,1,0,0,0,191,31,1,0,0,0,192,
  	190,1,0,0,0,193,197,3,34,17,0,194,197,3,36,18,0,195,197,3,38,19,0,196,
  	193,1,0,0,0,196,194,1,0,0,0,196,195,1,0,0,0,197,33,1,0,0,0,198,199,7,
  	0,0,0,199,35,1,0,0,0,200,201,7,1,0,0,201,37,1,0,0,0,202,203,7,2,0,0,203,
  	39,1,0,0,0,204,207,3,42,21,0,205,207,5,33,0,0,206,204,1,0,0,0,206,205,
  	1,0,0,0,207,41,1,0,0,0,208,209,7,3,0,0,209,43,1,0,0,0,26,47,53,60,69,
  	74,80,92,96,100,105,112,116,122,139,141,144,151,153,156,163,165,168,182,
  	190,196,206
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

std::vector<TythonParser::Import_statementContext *> TythonParser::ProgramContext::import_statement() {
  return getRuleContexts<TythonParser::Import_statementContext>();
}

TythonParser::Import_statementContext* TythonParser::ProgramContext::import_statement(size_t i) {
  return getRuleContext<TythonParser::Import_statementContext>(i);
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
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::KW_IMPORT) {
      setState(44);
      import_statement();
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(50);
      statement();
      setState(53); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 128849020216) != 0));
    setState(55);
    match(TythonParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_statementContext ------------------------------------------------------------------

TythonParser::Import_statementContext::Import_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Import_statementContext::KW_IMPORT() {
  return getToken(TythonParser::KW_IMPORT, 0);
}

TythonParser::Import_pathContext* TythonParser::Import_statementContext::import_path() {
  return getRuleContext<TythonParser::Import_pathContext>(0);
}

tree::TerminalNode* TythonParser::Import_statementContext::NEWLINE() {
  return getToken(TythonParser::NEWLINE, 0);
}

tree::TerminalNode* TythonParser::Import_statementContext::SYM_STMNT_DELIMITER() {
  return getToken(TythonParser::SYM_STMNT_DELIMITER, 0);
}


size_t TythonParser::Import_statementContext::getRuleIndex() const {
  return TythonParser::RuleImport_statement;
}


std::any TythonParser::Import_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitImport_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Import_statementContext* TythonParser::import_statement() {
  Import_statementContext *_localctx = _tracker.createInstance<Import_statementContext>(_ctx, getState());
  enterRule(_localctx, 2, TythonParser::RuleImport_statement);
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
    setState(57);
    match(TythonParser::KW_IMPORT);
    setState(58);
    import_path();
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_STMNT_DELIMITER) {
      setState(59);
      match(TythonParser::SYM_STMNT_DELIMITER);
    }
    setState(62);
    match(TythonParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_pathContext ------------------------------------------------------------------

TythonParser::Import_pathContext::Import_pathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TythonParser::Import_pathContext::IDENTIFIER() {
  return getTokens(TythonParser::IDENTIFIER);
}

tree::TerminalNode* TythonParser::Import_pathContext::IDENTIFIER(size_t i) {
  return getToken(TythonParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> TythonParser::Import_pathContext::SYM_DOT() {
  return getTokens(TythonParser::SYM_DOT);
}

tree::TerminalNode* TythonParser::Import_pathContext::SYM_DOT(size_t i) {
  return getToken(TythonParser::SYM_DOT, i);
}


size_t TythonParser::Import_pathContext::getRuleIndex() const {
  return TythonParser::RuleImport_path;
}


std::any TythonParser::Import_pathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitImport_path(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Import_pathContext* TythonParser::import_path() {
  Import_pathContext *_localctx = _tracker.createInstance<Import_pathContext>(_ctx, getState());
  enterRule(_localctx, 4, TythonParser::RuleImport_path);
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
    setState(64);
    match(TythonParser::IDENTIFIER);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::SYM_DOT) {
      setState(65);
      match(TythonParser::SYM_DOT);
      setState(66);
      match(TythonParser::IDENTIFIER);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
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

tree::TerminalNode* TythonParser::Function_defContext::KW_EXTERN() {
  return getToken(TythonParser::KW_EXTERN, 0);
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
  enterRule(_localctx, 6, TythonParser::RuleFunction_def);
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
    setState(72);
    match(TythonParser::KW_DEF);
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(73);
      match(TythonParser::KW_EXTERN);
    }
    setState(76);
    match(TythonParser::IDENTIFIER);
    setState(77);
    match(TythonParser::SYM_LPAR);
    setState(78);
    arguments();
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_ELLIPS) {
      setState(79);
      match(TythonParser::SYM_ELLIPS);
    }
    setState(82);
    match(TythonParser::SYM_RPAR);
    setState(83);
    match(TythonParser::SYM_BLOCK_START);
    setState(84);
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
  enterRule(_localctx, 8, TythonParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(96);
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
        setState(86);
        simple_statements();
        break;
      }

      case TythonParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(87);
        match(TythonParser::NEWLINE);
        setState(88);
        match(TythonParser::INDENT);
        setState(90); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(89);
          antlrcpp::downCast<BlockContext *>(_localctx)->indent_statements = statement();
          setState(92); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 128849020216) != 0));
        setState(94);
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
  enterRule(_localctx, 10, TythonParser::RuleStatement);

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
      case TythonParser::KW_RETURN:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        simple_statements();
        break;
      }

      case TythonParser::KW_DEF:
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 2);
        setState(99);
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
  enterRule(_localctx, 12, TythonParser::RuleSimple_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(102);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(104);
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
  enterRule(_localctx, 14, TythonParser::RuleSimple_statements);
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
    setState(107);
    simple_statement();
    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(108);
        match(TythonParser::SYM_STMNT_DELIMITER);
        setState(109);
        simple_statement(); 
      }
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_STMNT_DELIMITER) {
      setState(115);
      match(TythonParser::SYM_STMNT_DELIMITER);
    }
    setState(118);
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
  enterRule(_localctx, 16, TythonParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        if_statement();
        break;
      }

      case TythonParser::KW_DEF: {
        enterOuterAlt(_localctx, 2);
        setState(121);
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
  enterRule(_localctx, 18, TythonParser::RuleAssign_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(TythonParser::IDENTIFIER);
    setState(125);
    match(TythonParser::SYM_ASSIGN);
    setState(126);
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
  enterRule(_localctx, 20, TythonParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(TythonParser::KW_RETURN);
    setState(129);
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
  enterRule(_localctx, 22, TythonParser::RuleIf_statement);
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
    setState(131);
    match(TythonParser::KW_IF);
    setState(132);
    expression(0);
    setState(133);
    match(TythonParser::SYM_BLOCK_START);
    setState(134);
    antlrcpp::downCast<If_statementContext *>(_localctx)->br_if = block();
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_ELSE) {
      setState(135);
      match(TythonParser::KW_ELSE);
      setState(139);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TythonParser::KW_IF: {
          setState(136);
          antlrcpp::downCast<If_statementContext *>(_localctx)->br_else_if = if_statement();
          break;
        }

        case TythonParser::SYM_BLOCK_START: {
          setState(137);
          match(TythonParser::SYM_BLOCK_START);
          setState(138);
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
  enterRule(_localctx, 24, TythonParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TythonParser::IDENTIFIER) {
        setState(143);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      setState(149); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(147);
        match(TythonParser::SYM_ARG_SEPARATOR);
        setState(148);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
        setState(151); 
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
  enterRule(_localctx, 26, TythonParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 128849020160) != 0)) {
        setState(155);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(158);
      antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
      antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      setState(161); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(159);
        match(TythonParser::SYM_ARG_SEPARATOR);
        setState(160);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
        setState(163); 
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
  enterRule(_localctx, 28, TythonParser::RuleCall_expression);
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
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(167);
      match(TythonParser::KW_EXTERN);
    }
    setState(170);
    match(TythonParser::IDENTIFIER);
    setState(171);
    match(TythonParser::SYM_LPAR);
    setState(172);
    parameters();
    setState(173);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, TythonParser::RuleExpression, precedence);

    

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
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Lbl_call_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(176);
      call_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Lbl_expression_parenthesesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(177);
      match(TythonParser::SYM_LPAR);
      setState(178);
      expression(0);
      setState(179);
      match(TythonParser::SYM_RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lbl_atomicContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      atomic();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(190);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Binary_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->lhs = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(184);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(185);
        binary_operator();
        setState(186);
        antlrcpp::downCast<Binary_expressionContext *>(_localctx)->rhs = expression(5); 
      }
      setState(192);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
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
  enterRule(_localctx, 32, TythonParser::RuleBinary_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::SYM_NEQ:
      case TythonParser::SYM_LTE:
      case TythonParser::SYM_LT:
      case TythonParser::SYM_EQ:
      case TythonParser::SYM_GT:
      case TythonParser::SYM_GTE: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        inequality_operator();
        break;
      }

      case TythonParser::SYM_AND:
      case TythonParser::SYM_OR: {
        enterOuterAlt(_localctx, 2);
        setState(194);
        logic_operator();
        break;
      }

      case TythonParser::SYM_PLUS:
      case TythonParser::SYM_MINUS:
      case TythonParser::SYM_MULT:
      case TythonParser::SYM_DIV:
      case TythonParser::SYM_EXP: {
        enterOuterAlt(_localctx, 3);
        setState(195);
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
  enterRule(_localctx, 34, TythonParser::RuleInequality_operator);
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
    setState(198);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4128768) != 0))) {
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
  enterRule(_localctx, 36, TythonParser::RuleLogic_operator);
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
    setState(200);
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
  enterRule(_localctx, 38, TythonParser::RuleArithmetic_operator);
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
    setState(202);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 520093696) != 0))) {
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
  enterRule(_localctx, 40, TythonParser::RuleAtomic);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(206);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(204);
        constant();
        break;
      }

      case TythonParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(205);
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
  enterRule(_localctx, 42, TythonParser::RuleConstant);
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
    setState(208);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120259084288) != 0))) {
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
    case 15: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
