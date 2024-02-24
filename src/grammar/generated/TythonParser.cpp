
// Generated from /home/manzi/repos/tython/src/grammar/TythonParser.g4 by ANTLR 4.12.0


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
      "assign_statement", "return_statement", "if_statement", "for_loop", 
      "arguments", "parameters", "call_expression", "expression", "binary_operator", 
      "inequality_operator", "logic_operator", "arithmetic_operator", "rval", 
      "lval", "key_value_pair", "dict_lit", "list_lit", "tuple_lit", "literal"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'for'", "'in'", 
      "'while'", "'extern'", "'import'", "'self'", "'('", "')'", "'['", 
      "']'", "'{'", "'}'", "':'", "';'", "','", "", "'='", "'!='", "'<='", 
      "'<'", "'=='", "'>'", "'>='", "'&&'", "'||'", "'+'", "'-'", "'*'", 
      "'/'", "'**'", "'.'", "'...'", "", "'/*'", "'true'", "'false'", "'None'", 
      "", "", "", "", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_FOR", "KW_IN", "KW_WHILE", "KW_EXTERN", "KW_IMPORT", "KW_SELF", 
      "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", "SYM_LBR", "SYM_RBR", 
      "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", 
      "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", 
      "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", 
      "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "TRUE_LIT", 
      "FALSE_LIT", "NONE_LIT", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", 
      "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,51,303,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,5,
  	0,58,8,0,10,0,12,0,61,9,0,1,0,4,0,64,8,0,11,0,12,0,65,1,0,1,0,1,1,1,1,
  	1,1,3,1,73,8,1,1,1,1,1,1,2,1,2,1,2,5,2,80,8,2,10,2,12,2,83,9,2,1,3,1,
  	3,3,3,87,8,3,1,3,1,3,1,3,1,3,3,3,93,8,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,
  	4,4,4,103,8,4,11,4,12,4,104,1,4,1,4,3,4,109,8,4,1,5,1,5,3,5,113,8,5,1,
  	6,1,6,1,6,3,6,118,8,6,1,7,1,7,1,7,5,7,123,8,7,10,7,12,7,126,9,7,1,7,3,
  	7,129,8,7,1,7,1,7,1,8,1,8,1,8,3,8,136,8,8,1,9,1,9,1,9,1,9,1,10,1,10,1,
  	10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,153,8,11,3,11,155,8,11,
  	1,12,1,12,1,12,3,12,160,8,12,1,12,1,12,1,12,1,12,1,13,3,13,167,8,13,1,
  	13,1,13,1,13,4,13,172,8,13,11,13,12,13,173,3,13,176,8,13,1,14,3,14,179,
  	8,14,1,14,1,14,1,14,4,14,184,8,14,11,14,12,14,185,3,14,188,8,14,1,15,
  	3,15,191,8,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,3,16,205,8,16,1,16,1,16,1,16,1,16,5,16,211,8,16,10,16,12,16,214,
  	9,16,1,17,1,17,1,17,3,17,219,8,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,
  	1,21,3,21,229,8,21,1,22,1,22,1,22,1,22,1,22,1,22,3,22,237,8,22,1,23,1,
  	23,1,23,1,23,1,24,1,24,3,24,245,8,24,1,24,3,24,248,8,24,1,24,1,24,4,24,
  	252,8,24,11,24,12,24,253,3,24,256,8,24,1,24,1,24,1,25,1,25,3,25,262,8,
  	25,1,25,3,25,265,8,25,1,25,1,25,4,25,269,8,25,11,25,12,25,270,3,25,273,
  	8,25,1,25,1,25,1,26,1,26,3,26,279,8,26,1,26,3,26,282,8,26,1,26,1,26,4,
  	26,286,8,26,11,26,12,26,287,3,26,290,8,26,1,26,1,26,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,3,27,301,8,27,1,27,0,1,32,28,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,0,3,1,0,24,29,
  	1,0,30,31,1,0,32,36,324,0,59,1,0,0,0,2,69,1,0,0,0,4,76,1,0,0,0,6,84,1,
  	0,0,0,8,108,1,0,0,0,10,112,1,0,0,0,12,117,1,0,0,0,14,119,1,0,0,0,16,135,
  	1,0,0,0,18,137,1,0,0,0,20,141,1,0,0,0,22,144,1,0,0,0,24,156,1,0,0,0,26,
  	175,1,0,0,0,28,187,1,0,0,0,30,190,1,0,0,0,32,204,1,0,0,0,34,218,1,0,0,
  	0,36,220,1,0,0,0,38,222,1,0,0,0,40,224,1,0,0,0,42,228,1,0,0,0,44,236,
  	1,0,0,0,46,238,1,0,0,0,48,242,1,0,0,0,50,259,1,0,0,0,52,276,1,0,0,0,54,
  	300,1,0,0,0,56,58,3,2,1,0,57,56,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,59,
  	60,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,62,64,3,10,5,0,63,62,1,0,0,0,64,
  	65,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,67,1,0,0,0,67,68,5,0,0,1,68,
  	1,1,0,0,0,69,70,5,11,0,0,70,72,3,4,2,0,71,73,5,20,0,0,72,71,1,0,0,0,72,
  	73,1,0,0,0,73,74,1,0,0,0,74,75,5,48,0,0,75,3,1,0,0,0,76,81,5,44,0,0,77,
  	78,5,37,0,0,78,80,5,44,0,0,79,77,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,
  	81,82,1,0,0,0,82,5,1,0,0,0,83,81,1,0,0,0,84,86,5,3,0,0,85,87,5,10,0,0,
  	86,85,1,0,0,0,86,87,1,0,0,0,87,88,1,0,0,0,88,89,5,44,0,0,89,90,5,13,0,
  	0,90,92,3,26,13,0,91,93,5,38,0,0,92,91,1,0,0,0,92,93,1,0,0,0,93,94,1,
  	0,0,0,94,95,5,14,0,0,95,96,5,19,0,0,96,97,3,8,4,0,97,7,1,0,0,0,98,109,
  	3,14,7,0,99,100,5,48,0,0,100,102,5,1,0,0,101,103,3,10,5,0,102,101,1,0,
  	0,0,103,104,1,0,0,0,104,102,1,0,0,0,104,105,1,0,0,0,105,106,1,0,0,0,106,
  	107,5,2,0,0,107,109,1,0,0,0,108,98,1,0,0,0,108,99,1,0,0,0,109,9,1,0,0,
  	0,110,113,3,14,7,0,111,113,3,16,8,0,112,110,1,0,0,0,112,111,1,0,0,0,113,
  	11,1,0,0,0,114,118,3,32,16,0,115,118,3,18,9,0,116,118,3,20,10,0,117,114,
  	1,0,0,0,117,115,1,0,0,0,117,116,1,0,0,0,118,13,1,0,0,0,119,124,3,12,6,
  	0,120,121,5,20,0,0,121,123,3,12,6,0,122,120,1,0,0,0,123,126,1,0,0,0,124,
  	122,1,0,0,0,124,125,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,127,129,5,
  	20,0,0,128,127,1,0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,131,5,48,0,
  	0,131,15,1,0,0,0,132,136,3,22,11,0,133,136,3,6,3,0,134,136,3,24,12,0,
  	135,132,1,0,0,0,135,133,1,0,0,0,135,134,1,0,0,0,136,17,1,0,0,0,137,138,
  	3,44,22,0,138,139,5,23,0,0,139,140,3,32,16,0,140,19,1,0,0,0,141,142,5,
  	4,0,0,142,143,3,32,16,0,143,21,1,0,0,0,144,145,5,5,0,0,145,146,3,32,16,
  	0,146,147,5,19,0,0,147,154,3,8,4,0,148,152,5,6,0,0,149,153,3,22,11,0,
  	150,151,5,19,0,0,151,153,3,8,4,0,152,149,1,0,0,0,152,150,1,0,0,0,153,
  	155,1,0,0,0,154,148,1,0,0,0,154,155,1,0,0,0,155,23,1,0,0,0,156,159,5,
  	7,0,0,157,158,5,44,0,0,158,160,5,8,0,0,159,157,1,0,0,0,159,160,1,0,0,
  	0,160,161,1,0,0,0,161,162,3,32,16,0,162,163,5,19,0,0,163,164,3,8,4,0,
  	164,25,1,0,0,0,165,167,5,44,0,0,166,165,1,0,0,0,166,167,1,0,0,0,167,176,
  	1,0,0,0,168,171,5,44,0,0,169,170,5,21,0,0,170,172,5,44,0,0,171,169,1,
  	0,0,0,172,173,1,0,0,0,173,171,1,0,0,0,173,174,1,0,0,0,174,176,1,0,0,0,
  	175,166,1,0,0,0,175,168,1,0,0,0,176,27,1,0,0,0,177,179,3,32,16,0,178,
  	177,1,0,0,0,178,179,1,0,0,0,179,188,1,0,0,0,180,183,3,32,16,0,181,182,
  	5,21,0,0,182,184,3,32,16,0,183,181,1,0,0,0,184,185,1,0,0,0,185,183,1,
  	0,0,0,185,186,1,0,0,0,186,188,1,0,0,0,187,178,1,0,0,0,187,180,1,0,0,0,
  	188,29,1,0,0,0,189,191,5,10,0,0,190,189,1,0,0,0,190,191,1,0,0,0,191,192,
  	1,0,0,0,192,193,5,44,0,0,193,194,5,13,0,0,194,195,3,28,14,0,195,196,5,
  	14,0,0,196,31,1,0,0,0,197,198,6,16,-1,0,198,205,3,30,15,0,199,200,5,13,
  	0,0,200,201,3,32,16,0,201,202,5,14,0,0,202,205,1,0,0,0,203,205,3,42,21,
  	0,204,197,1,0,0,0,204,199,1,0,0,0,204,203,1,0,0,0,205,212,1,0,0,0,206,
  	207,10,4,0,0,207,208,3,34,17,0,208,209,3,32,16,5,209,211,1,0,0,0,210,
  	206,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,1,0,0,0,213,33,1,
  	0,0,0,214,212,1,0,0,0,215,219,3,36,18,0,216,219,3,38,19,0,217,219,3,40,
  	20,0,218,215,1,0,0,0,218,216,1,0,0,0,218,217,1,0,0,0,219,35,1,0,0,0,220,
  	221,7,0,0,0,221,37,1,0,0,0,222,223,7,1,0,0,223,39,1,0,0,0,224,225,7,2,
  	0,0,225,41,1,0,0,0,226,229,3,54,27,0,227,229,3,44,22,0,228,226,1,0,0,
  	0,228,227,1,0,0,0,229,43,1,0,0,0,230,237,5,44,0,0,231,232,5,44,0,0,232,
  	233,5,15,0,0,233,234,3,32,16,0,234,235,5,16,0,0,235,237,1,0,0,0,236,230,
  	1,0,0,0,236,231,1,0,0,0,237,45,1,0,0,0,238,239,3,32,16,0,239,240,5,19,
  	0,0,240,241,3,32,16,0,241,47,1,0,0,0,242,255,5,17,0,0,243,245,3,46,23,
  	0,244,243,1,0,0,0,244,245,1,0,0,0,245,256,1,0,0,0,246,248,3,46,23,0,247,
  	246,1,0,0,0,247,248,1,0,0,0,248,251,1,0,0,0,249,250,5,21,0,0,250,252,
  	3,46,23,0,251,249,1,0,0,0,252,253,1,0,0,0,253,251,1,0,0,0,253,254,1,0,
  	0,0,254,256,1,0,0,0,255,244,1,0,0,0,255,247,1,0,0,0,256,257,1,0,0,0,257,
  	258,5,18,0,0,258,49,1,0,0,0,259,272,5,15,0,0,260,262,3,42,21,0,261,260,
  	1,0,0,0,261,262,1,0,0,0,262,273,1,0,0,0,263,265,3,42,21,0,264,263,1,0,
  	0,0,264,265,1,0,0,0,265,268,1,0,0,0,266,267,5,21,0,0,267,269,3,42,21,
  	0,268,266,1,0,0,0,269,270,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,271,
  	273,1,0,0,0,272,261,1,0,0,0,272,264,1,0,0,0,273,274,1,0,0,0,274,275,5,
  	16,0,0,275,51,1,0,0,0,276,289,5,13,0,0,277,279,3,42,21,0,278,277,1,0,
  	0,0,278,279,1,0,0,0,279,290,1,0,0,0,280,282,3,42,21,0,281,280,1,0,0,0,
  	281,282,1,0,0,0,282,285,1,0,0,0,283,284,5,21,0,0,284,286,3,42,21,0,285,
  	283,1,0,0,0,286,287,1,0,0,0,287,285,1,0,0,0,287,288,1,0,0,0,288,290,1,
  	0,0,0,289,278,1,0,0,0,289,281,1,0,0,0,290,291,1,0,0,0,291,292,5,14,0,
  	0,292,53,1,0,0,0,293,301,5,45,0,0,294,301,5,46,0,0,295,301,5,47,0,0,296,
  	301,5,43,0,0,297,301,3,48,24,0,298,301,3,50,25,0,299,301,3,52,26,0,300,
  	293,1,0,0,0,300,294,1,0,0,0,300,295,1,0,0,0,300,296,1,0,0,0,300,297,1,
  	0,0,0,300,298,1,0,0,0,300,299,1,0,0,0,301,55,1,0,0,0,41,59,65,72,81,86,
  	92,104,108,112,117,124,128,135,152,154,159,166,173,175,178,185,187,190,
  	204,212,218,228,236,244,247,253,255,261,264,270,272,278,281,287,289,300
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
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::KW_IMPORT) {
      setState(56);
      import_statement();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(62);
      statement();
      setState(65); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 272678883861688) != 0));
    setState(67);
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

tree::TerminalNode* TythonParser::Import_statementContext::SYM_SEMCOL() {
  return getToken(TythonParser::SYM_SEMCOL, 0);
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
    setState(69);
    match(TythonParser::KW_IMPORT);
    setState(70);
    import_path();
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(71);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(74);
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
    setState(76);
    match(TythonParser::IDENTIFIER);
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::SYM_DOT) {
      setState(77);
      match(TythonParser::SYM_DOT);
      setState(78);
      match(TythonParser::IDENTIFIER);
      setState(83);
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

tree::TerminalNode* TythonParser::Function_defContext::SYM_COL() {
  return getToken(TythonParser::SYM_COL, 0);
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
    setState(84);
    match(TythonParser::KW_DEF);
    setState(86);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(85);
      match(TythonParser::KW_EXTERN);
    }
    setState(88);
    match(TythonParser::IDENTIFIER);
    setState(89);
    match(TythonParser::SYM_LPAR);
    setState(90);
    arguments();
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_ELLIPS) {
      setState(91);
      match(TythonParser::SYM_ELLIPS);
    }
    setState(94);
    match(TythonParser::SYM_RPAR);
    setState(95);
    match(TythonParser::SYM_COL);
    setState(96);
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
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::SYM_LSQ:
      case TythonParser::SYM_LBR:
      case TythonParser::NONE_LIT:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        simple_statements();
        break;
      }

      case TythonParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        match(TythonParser::NEWLINE);
        setState(100);
        match(TythonParser::INDENT);
        setState(102); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(101);
          antlrcpp::downCast<BlockContext *>(_localctx)->indent_statements = statement();
          setState(104); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 272678883861688) != 0));
        setState(106);
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
    setState(112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::SYM_LSQ:
      case TythonParser::SYM_LBR:
      case TythonParser::NONE_LIT:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(110);
        simple_statements();
        break;
      }

      case TythonParser::KW_DEF:
      case TythonParser::KW_IF:
      case TythonParser::KW_FOR: {
        enterOuterAlt(_localctx, 2);
        setState(111);
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
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(114);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(115);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(116);
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

std::vector<tree::TerminalNode *> TythonParser::Simple_statementsContext::SYM_SEMCOL() {
  return getTokens(TythonParser::SYM_SEMCOL);
}

tree::TerminalNode* TythonParser::Simple_statementsContext::SYM_SEMCOL(size_t i) {
  return getToken(TythonParser::SYM_SEMCOL, i);
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
    setState(119);
    simple_statement();
    setState(124);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(120);
        match(TythonParser::SYM_SEMCOL);
        setState(121);
        simple_statement(); 
      }
      setState(126);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(127);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(130);
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

TythonParser::For_loopContext* TythonParser::Compound_statementContext::for_loop() {
  return getRuleContext<TythonParser::For_loopContext>(0);
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
    setState(135);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 1);
        setState(132);
        if_statement();
        break;
      }

      case TythonParser::KW_DEF: {
        enterOuterAlt(_localctx, 2);
        setState(133);
        function_def();
        break;
      }

      case TythonParser::KW_FOR: {
        enterOuterAlt(_localctx, 3);
        setState(134);
        for_loop();
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

TythonParser::LvalContext* TythonParser::Assign_statementContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
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
    setState(137);
    lval();
    setState(138);
    match(TythonParser::SYM_ASSIGN);
    setState(139);
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
    setState(141);
    match(TythonParser::KW_RETURN);
    setState(142);
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

std::vector<tree::TerminalNode *> TythonParser::If_statementContext::SYM_COL() {
  return getTokens(TythonParser::SYM_COL);
}

tree::TerminalNode* TythonParser::If_statementContext::SYM_COL(size_t i) {
  return getToken(TythonParser::SYM_COL, i);
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
    setState(144);
    match(TythonParser::KW_IF);
    setState(145);
    expression(0);
    setState(146);
    match(TythonParser::SYM_COL);
    setState(147);
    antlrcpp::downCast<If_statementContext *>(_localctx)->br_if = block();
    setState(154);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_ELSE) {
      setState(148);
      match(TythonParser::KW_ELSE);
      setState(152);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TythonParser::KW_IF: {
          setState(149);
          antlrcpp::downCast<If_statementContext *>(_localctx)->br_else_if = if_statement();
          break;
        }

        case TythonParser::SYM_COL: {
          setState(150);
          match(TythonParser::SYM_COL);
          setState(151);
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

//----------------- For_loopContext ------------------------------------------------------------------

TythonParser::For_loopContext::For_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::For_loopContext::KW_FOR() {
  return getToken(TythonParser::KW_FOR, 0);
}

TythonParser::ExpressionContext* TythonParser::For_loopContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::For_loopContext::SYM_COL() {
  return getToken(TythonParser::SYM_COL, 0);
}

TythonParser::BlockContext* TythonParser::For_loopContext::block() {
  return getRuleContext<TythonParser::BlockContext>(0);
}

tree::TerminalNode* TythonParser::For_loopContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

tree::TerminalNode* TythonParser::For_loopContext::KW_IN() {
  return getToken(TythonParser::KW_IN, 0);
}


size_t TythonParser::For_loopContext::getRuleIndex() const {
  return TythonParser::RuleFor_loop;
}


std::any TythonParser::For_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitFor_loop(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::For_loopContext* TythonParser::for_loop() {
  For_loopContext *_localctx = _tracker.createInstance<For_loopContext>(_ctx, getState());
  enterRule(_localctx, 24, TythonParser::RuleFor_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(TythonParser::KW_FOR);
    setState(159);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(157);
      match(TythonParser::IDENTIFIER);
      setState(158);
      match(TythonParser::KW_IN);
      break;
    }

    default:
      break;
    }
    setState(161);
    expression(0);
    setState(162);
    match(TythonParser::SYM_COL);
    setState(163);
    block();
   
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

std::vector<tree::TerminalNode *> TythonParser::ArgumentsContext::SYM_COMMA() {
  return getTokens(TythonParser::SYM_COMMA);
}

tree::TerminalNode* TythonParser::ArgumentsContext::SYM_COMMA(size_t i) {
  return getToken(TythonParser::SYM_COMMA, i);
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
  enterRule(_localctx, 26, TythonParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TythonParser::IDENTIFIER) {
        setState(165);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      setState(171); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(169);
        match(TythonParser::SYM_COMMA);
        setState(170);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
        setState(173); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
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

std::vector<tree::TerminalNode *> TythonParser::ParametersContext::SYM_COMMA() {
  return getTokens(TythonParser::SYM_COMMA);
}

tree::TerminalNode* TythonParser::ParametersContext::SYM_COMMA(size_t i) {
  return getToken(TythonParser::SYM_COMMA, i);
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
  enterRule(_localctx, 28, TythonParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(178);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883861504) != 0)) {
        setState(177);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(180);
      antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
      antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      setState(183); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(181);
        match(TythonParser::SYM_COMMA);
        setState(182);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
        setState(185); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
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
  enterRule(_localctx, 30, TythonParser::RuleCall_expression);
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
    setState(190);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(189);
      match(TythonParser::KW_EXTERN);
    }
    setState(192);
    match(TythonParser::IDENTIFIER);
    setState(193);
    match(TythonParser::SYM_LPAR);
    setState(194);
    parameters();
    setState(195);
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
//----------------- Lbl_rvalContext ------------------------------------------------------------------

TythonParser::RvalContext* TythonParser::Lbl_rvalContext::rval() {
  return getRuleContext<TythonParser::RvalContext>(0);
}

TythonParser::Lbl_rvalContext::Lbl_rvalContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_rvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_rval(this);
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

TythonParser::ExpressionContext* TythonParser::expression() {
   return expression(0);
}

TythonParser::ExpressionContext* TythonParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TythonParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  TythonParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, TythonParser::RuleExpression, precedence);

    

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
    setState(204);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Lbl_call_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(198);
      call_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Lbl_expression_parenthesesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(199);
      match(TythonParser::SYM_LPAR);
      setState(200);
      expression(0);
      setState(201);
      match(TythonParser::SYM_RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lbl_rvalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(203);
      rval();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Binary_expressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->lhs = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(206);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(207);
        binary_operator();
        setState(208);
        antlrcpp::downCast<Binary_expressionContext *>(_localctx)->rhs = expression(5); 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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
  enterRule(_localctx, 34, TythonParser::RuleBinary_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::SYM_NEQ:
      case TythonParser::SYM_LTE:
      case TythonParser::SYM_LT:
      case TythonParser::SYM_EQ:
      case TythonParser::SYM_GT:
      case TythonParser::SYM_GTE: {
        enterOuterAlt(_localctx, 1);
        setState(215);
        inequality_operator();
        break;
      }

      case TythonParser::SYM_AND:
      case TythonParser::SYM_OR: {
        enterOuterAlt(_localctx, 2);
        setState(216);
        logic_operator();
        break;
      }

      case TythonParser::SYM_PLUS:
      case TythonParser::SYM_MINUS:
      case TythonParser::SYM_MULT:
      case TythonParser::SYM_DIV:
      case TythonParser::SYM_EXP: {
        enterOuterAlt(_localctx, 3);
        setState(217);
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
  enterRule(_localctx, 36, TythonParser::RuleInequality_operator);
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
    setState(220);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056964608) != 0))) {
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
  enterRule(_localctx, 38, TythonParser::RuleLogic_operator);
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
    setState(222);
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
  enterRule(_localctx, 40, TythonParser::RuleArithmetic_operator);
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
    setState(224);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 133143986176) != 0))) {
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

//----------------- RvalContext ------------------------------------------------------------------

TythonParser::RvalContext::RvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TythonParser::LiteralContext* TythonParser::RvalContext::literal() {
  return getRuleContext<TythonParser::LiteralContext>(0);
}

TythonParser::LvalContext* TythonParser::RvalContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}


size_t TythonParser::RvalContext::getRuleIndex() const {
  return TythonParser::RuleRval;
}


std::any TythonParser::RvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitRval(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::RvalContext* TythonParser::rval() {
  RvalContext *_localctx = _tracker.createInstance<RvalContext>(_ctx, getState());
  enterRule(_localctx, 42, TythonParser::RuleRval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::SYM_LPAR:
      case TythonParser::SYM_LSQ:
      case TythonParser::SYM_LBR:
      case TythonParser::NONE_LIT:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(226);
        literal();
        break;
      }

      case TythonParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(227);
        lval();
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

//----------------- LvalContext ------------------------------------------------------------------

TythonParser::LvalContext::LvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TythonParser::LvalContext::getRuleIndex() const {
  return TythonParser::RuleLval;
}

void TythonParser::LvalContext::copyFrom(LvalContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Lbl_identifierContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_identifierContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

TythonParser::Lbl_identifierContext::Lbl_identifierContext(LvalContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_identifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_key_accessContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_key_accessContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

tree::TerminalNode* TythonParser::Lbl_key_accessContext::SYM_LSQ() {
  return getToken(TythonParser::SYM_LSQ, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_key_accessContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_key_accessContext::SYM_RSQ() {
  return getToken(TythonParser::SYM_RSQ, 0);
}

TythonParser::Lbl_key_accessContext::Lbl_key_accessContext(LvalContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_key_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_key_access(this);
  else
    return visitor->visitChildren(this);
}
TythonParser::LvalContext* TythonParser::lval() {
  LvalContext *_localctx = _tracker.createInstance<LvalContext>(_ctx, getState());
  enterRule(_localctx, 44, TythonParser::RuleLval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_identifierContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(230);
      match(TythonParser::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_key_accessContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(231);
      match(TythonParser::IDENTIFIER);
      setState(232);
      match(TythonParser::SYM_LSQ);
      setState(233);
      expression(0);
      setState(234);
      match(TythonParser::SYM_RSQ);
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

//----------------- Key_value_pairContext ------------------------------------------------------------------

TythonParser::Key_value_pairContext::Key_value_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Key_value_pairContext::SYM_COL() {
  return getToken(TythonParser::SYM_COL, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Key_value_pairContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Key_value_pairContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}


size_t TythonParser::Key_value_pairContext::getRuleIndex() const {
  return TythonParser::RuleKey_value_pair;
}


std::any TythonParser::Key_value_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitKey_value_pair(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Key_value_pairContext* TythonParser::key_value_pair() {
  Key_value_pairContext *_localctx = _tracker.createInstance<Key_value_pairContext>(_ctx, getState());
  enterRule(_localctx, 46, TythonParser::RuleKey_value_pair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    antlrcpp::downCast<Key_value_pairContext *>(_localctx)->key = expression(0);
    setState(239);
    match(TythonParser::SYM_COL);
    setState(240);
    antlrcpp::downCast<Key_value_pairContext *>(_localctx)->value = expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dict_litContext ------------------------------------------------------------------

TythonParser::Dict_litContext::Dict_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Dict_litContext::SYM_LBR() {
  return getToken(TythonParser::SYM_LBR, 0);
}

tree::TerminalNode* TythonParser::Dict_litContext::SYM_RBR() {
  return getToken(TythonParser::SYM_RBR, 0);
}

std::vector<TythonParser::Key_value_pairContext *> TythonParser::Dict_litContext::key_value_pair() {
  return getRuleContexts<TythonParser::Key_value_pairContext>();
}

TythonParser::Key_value_pairContext* TythonParser::Dict_litContext::key_value_pair(size_t i) {
  return getRuleContext<TythonParser::Key_value_pairContext>(i);
}

std::vector<tree::TerminalNode *> TythonParser::Dict_litContext::SYM_COMMA() {
  return getTokens(TythonParser::SYM_COMMA);
}

tree::TerminalNode* TythonParser::Dict_litContext::SYM_COMMA(size_t i) {
  return getToken(TythonParser::SYM_COMMA, i);
}


size_t TythonParser::Dict_litContext::getRuleIndex() const {
  return TythonParser::RuleDict_lit;
}


std::any TythonParser::Dict_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitDict_lit(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Dict_litContext* TythonParser::dict_lit() {
  Dict_litContext *_localctx = _tracker.createInstance<Dict_litContext>(_ctx, getState());
  enterRule(_localctx, 48, TythonParser::RuleDict_lit);
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
    setState(242);
    match(TythonParser::SYM_LBR);
    setState(255);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(244);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883861504) != 0)) {
        setState(243);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      break;
    }

    case 2: {
      setState(247);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883861504) != 0)) {
        setState(246);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      setState(251); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(249);
        match(TythonParser::SYM_COMMA);
        setState(250);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
        setState(253); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(257);
    match(TythonParser::SYM_RBR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- List_litContext ------------------------------------------------------------------

TythonParser::List_litContext::List_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::List_litContext::SYM_LSQ() {
  return getToken(TythonParser::SYM_LSQ, 0);
}

tree::TerminalNode* TythonParser::List_litContext::SYM_RSQ() {
  return getToken(TythonParser::SYM_RSQ, 0);
}

std::vector<TythonParser::RvalContext *> TythonParser::List_litContext::rval() {
  return getRuleContexts<TythonParser::RvalContext>();
}

TythonParser::RvalContext* TythonParser::List_litContext::rval(size_t i) {
  return getRuleContext<TythonParser::RvalContext>(i);
}

std::vector<tree::TerminalNode *> TythonParser::List_litContext::SYM_COMMA() {
  return getTokens(TythonParser::SYM_COMMA);
}

tree::TerminalNode* TythonParser::List_litContext::SYM_COMMA(size_t i) {
  return getToken(TythonParser::SYM_COMMA, i);
}


size_t TythonParser::List_litContext::getRuleIndex() const {
  return TythonParser::RuleList_lit;
}


std::any TythonParser::List_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitList_lit(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::List_litContext* TythonParser::list_lit() {
  List_litContext *_localctx = _tracker.createInstance<List_litContext>(_ctx, getState());
  enterRule(_localctx, 50, TythonParser::RuleList_lit);
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
    setState(259);
    match(TythonParser::SYM_LSQ);
    setState(272);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883860480) != 0)) {
        setState(260);
        antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext);
      }
      break;
    }

    case 2: {
      setState(264);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883860480) != 0)) {
        setState(263);
        antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext);
      }
      setState(268); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(266);
        match(TythonParser::SYM_COMMA);
        setState(267);
        antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext);
        setState(270); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(274);
    match(TythonParser::SYM_RSQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tuple_litContext ------------------------------------------------------------------

TythonParser::Tuple_litContext::Tuple_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Tuple_litContext::SYM_LPAR() {
  return getToken(TythonParser::SYM_LPAR, 0);
}

tree::TerminalNode* TythonParser::Tuple_litContext::SYM_RPAR() {
  return getToken(TythonParser::SYM_RPAR, 0);
}

std::vector<TythonParser::RvalContext *> TythonParser::Tuple_litContext::rval() {
  return getRuleContexts<TythonParser::RvalContext>();
}

TythonParser::RvalContext* TythonParser::Tuple_litContext::rval(size_t i) {
  return getRuleContext<TythonParser::RvalContext>(i);
}

std::vector<tree::TerminalNode *> TythonParser::Tuple_litContext::SYM_COMMA() {
  return getTokens(TythonParser::SYM_COMMA);
}

tree::TerminalNode* TythonParser::Tuple_litContext::SYM_COMMA(size_t i) {
  return getToken(TythonParser::SYM_COMMA, i);
}


size_t TythonParser::Tuple_litContext::getRuleIndex() const {
  return TythonParser::RuleTuple_lit;
}


std::any TythonParser::Tuple_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitTuple_lit(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Tuple_litContext* TythonParser::tuple_lit() {
  Tuple_litContext *_localctx = _tracker.createInstance<Tuple_litContext>(_ctx, getState());
  enterRule(_localctx, 52, TythonParser::RuleTuple_lit);
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
    setState(276);
    match(TythonParser::SYM_LPAR);
    setState(289);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(278);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883860480) != 0)) {
        setState(277);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext);
      }
      break;
    }

    case 2: {
      setState(281);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 272678883860480) != 0)) {
        setState(280);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext);
      }
      setState(285); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(283);
        match(TythonParser::SYM_COMMA);
        setState(284);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext);
        setState(287); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(291);
    match(TythonParser::SYM_RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

TythonParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::LiteralContext::INT_LIT() {
  return getToken(TythonParser::INT_LIT, 0);
}

tree::TerminalNode* TythonParser::LiteralContext::FLOAT_LIT() {
  return getToken(TythonParser::FLOAT_LIT, 0);
}

tree::TerminalNode* TythonParser::LiteralContext::STR_LIT() {
  return getToken(TythonParser::STR_LIT, 0);
}

tree::TerminalNode* TythonParser::LiteralContext::NONE_LIT() {
  return getToken(TythonParser::NONE_LIT, 0);
}

TythonParser::Dict_litContext* TythonParser::LiteralContext::dict_lit() {
  return getRuleContext<TythonParser::Dict_litContext>(0);
}

TythonParser::List_litContext* TythonParser::LiteralContext::list_lit() {
  return getRuleContext<TythonParser::List_litContext>(0);
}

TythonParser::Tuple_litContext* TythonParser::LiteralContext::tuple_lit() {
  return getRuleContext<TythonParser::Tuple_litContext>(0);
}


size_t TythonParser::LiteralContext::getRuleIndex() const {
  return TythonParser::RuleLiteral;
}


std::any TythonParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::LiteralContext* TythonParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 54, TythonParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::INT_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(293);
        match(TythonParser::INT_LIT);
        break;
      }

      case TythonParser::FLOAT_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(294);
        match(TythonParser::FLOAT_LIT);
        break;
      }

      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 3);
        setState(295);
        match(TythonParser::STR_LIT);
        break;
      }

      case TythonParser::NONE_LIT: {
        enterOuterAlt(_localctx, 4);
        setState(296);
        match(TythonParser::NONE_LIT);
        break;
      }

      case TythonParser::SYM_LBR: {
        enterOuterAlt(_localctx, 5);
        setState(297);
        dict_lit();
        break;
      }

      case TythonParser::SYM_LSQ: {
        enterOuterAlt(_localctx, 6);
        setState(298);
        list_lit();
        break;
      }

      case TythonParser::SYM_LPAR: {
        enterOuterAlt(_localctx, 7);
        setState(299);
        tuple_lit();
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

bool TythonParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 16: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
