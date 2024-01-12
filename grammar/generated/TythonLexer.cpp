
#include "../../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/grammar/TythonLexer.g4 by ANTLR 4.12.0


#include "TythonLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct TythonLexerStaticData final {
  TythonLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TythonLexerStaticData(const TythonLexerStaticData&) = delete;
  TythonLexerStaticData(TythonLexerStaticData&&) = delete;
  TythonLexerStaticData& operator=(const TythonLexerStaticData&) = delete;
  TythonLexerStaticData& operator=(TythonLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tythonlexerLexerOnceFlag;
TythonLexerStaticData *tythonlexerLexerStaticData = nullptr;

void tythonlexerLexerInitialize() {
  assert(tythonlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<TythonLexerStaticData>(
    std::vector<std::string>{
      "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_EXTERN", 
      "KW_IMPORT", "SYM_LPAR", "SYM_RPAR", "SYM_BLOCK_START", "SYM_ARG_SEPARATOR", 
      "SYM_STMNT_DELIMITER", "SYM_ASSIGN", "SYM_NEQ", "SYM_LTE", "SYM_LT", 
      "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", "SYM_MINUS", 
      "SYM_MULT", "SYM_DIV", "SYM_EXP", "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", 
      "SYM_COMMENT_START", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", 
      "TRUE_LIT", "FALSE_LIT", "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "comment_block"
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
  	4,0,42,269,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,0,1,0,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,
  	13,1,13,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,
  	18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,
  	24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,27,1,27,1,28,1,28,5,28,177,8,
  	28,10,28,12,28,180,9,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,30,
  	4,30,191,8,30,11,30,12,30,192,1,30,5,30,196,8,30,10,30,12,30,199,9,30,
  	1,31,3,31,202,8,31,1,31,4,31,205,8,31,11,31,12,31,206,1,32,3,32,210,8,
  	32,1,32,1,32,4,32,214,8,32,11,32,12,32,215,1,33,1,33,4,33,220,8,33,11,
  	33,12,33,221,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,
  	35,1,35,1,36,1,36,1,36,3,36,240,8,36,1,36,1,36,3,36,244,8,36,1,36,3,36,
  	247,8,36,3,36,249,8,36,1,36,1,36,1,37,4,37,254,8,37,11,37,12,37,255,1,
  	37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,39,0,0,40,2,3,
  	4,4,6,5,8,6,10,7,12,8,14,9,16,10,18,11,20,12,22,13,24,14,26,15,28,16,
  	30,17,32,18,34,19,36,20,38,21,40,22,42,23,44,24,46,25,48,26,50,27,52,
  	28,54,29,56,30,58,31,60,32,62,33,64,34,66,35,68,36,70,37,72,38,74,39,
  	76,40,78,41,80,42,2,0,1,6,2,0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,
  	48,57,65,90,95,95,97,122,1,0,48,57,1,0,34,34,2,0,9,9,32,32,280,0,2,1,
  	0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,0,0,10,1,0,0,0,0,12,1,0,0,0,0,
  	14,1,0,0,0,0,16,1,0,0,0,0,18,1,0,0,0,0,20,1,0,0,0,0,22,1,0,0,0,0,24,1,
  	0,0,0,0,26,1,0,0,0,0,28,1,0,0,0,0,30,1,0,0,0,0,32,1,0,0,0,0,34,1,0,0,
  	0,0,36,1,0,0,0,0,38,1,0,0,0,0,40,1,0,0,0,0,42,1,0,0,0,0,44,1,0,0,0,0,
  	46,1,0,0,0,0,48,1,0,0,0,0,50,1,0,0,0,0,52,1,0,0,0,0,54,1,0,0,0,0,56,1,
  	0,0,0,0,58,1,0,0,0,0,60,1,0,0,0,0,62,1,0,0,0,0,64,1,0,0,0,0,66,1,0,0,
  	0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,0,0,0,74,1,0,0,0,0,76,1,0,0,0,1,
  	78,1,0,0,0,1,80,1,0,0,0,2,82,1,0,0,0,4,86,1,0,0,0,6,93,1,0,0,0,8,96,1,
  	0,0,0,10,101,1,0,0,0,12,107,1,0,0,0,14,114,1,0,0,0,16,121,1,0,0,0,18,
  	124,1,0,0,0,20,127,1,0,0,0,22,129,1,0,0,0,24,131,1,0,0,0,26,133,1,0,0,
  	0,28,135,1,0,0,0,30,138,1,0,0,0,32,141,1,0,0,0,34,143,1,0,0,0,36,146,
  	1,0,0,0,38,148,1,0,0,0,40,151,1,0,0,0,42,154,1,0,0,0,44,157,1,0,0,0,46,
  	159,1,0,0,0,48,161,1,0,0,0,50,163,1,0,0,0,52,165,1,0,0,0,54,168,1,0,0,
  	0,56,170,1,0,0,0,58,174,1,0,0,0,60,183,1,0,0,0,62,190,1,0,0,0,64,201,
  	1,0,0,0,66,209,1,0,0,0,68,217,1,0,0,0,70,225,1,0,0,0,72,230,1,0,0,0,74,
  	248,1,0,0,0,76,253,1,0,0,0,78,259,1,0,0,0,80,265,1,0,0,0,82,83,5,100,
  	0,0,83,84,5,101,0,0,84,85,5,102,0,0,85,3,1,0,0,0,86,87,5,114,0,0,87,88,
  	5,101,0,0,88,89,5,116,0,0,89,90,5,117,0,0,90,91,5,114,0,0,91,92,5,110,
  	0,0,92,5,1,0,0,0,93,94,5,105,0,0,94,95,5,102,0,0,95,7,1,0,0,0,96,97,5,
  	101,0,0,97,98,5,108,0,0,98,99,5,115,0,0,99,100,5,101,0,0,100,9,1,0,0,
  	0,101,102,5,119,0,0,102,103,5,104,0,0,103,104,5,105,0,0,104,105,5,108,
  	0,0,105,106,5,101,0,0,106,11,1,0,0,0,107,108,5,101,0,0,108,109,5,120,
  	0,0,109,110,5,116,0,0,110,111,5,101,0,0,111,112,5,114,0,0,112,113,5,110,
  	0,0,113,13,1,0,0,0,114,115,5,105,0,0,115,116,5,109,0,0,116,117,5,112,
  	0,0,117,118,5,111,0,0,118,119,5,114,0,0,119,120,5,116,0,0,120,15,1,0,
  	0,0,121,122,5,40,0,0,122,123,6,7,0,0,123,17,1,0,0,0,124,125,5,41,0,0,
  	125,126,6,8,1,0,126,19,1,0,0,0,127,128,5,58,0,0,128,21,1,0,0,0,129,130,
  	5,44,0,0,130,23,1,0,0,0,131,132,5,59,0,0,132,25,1,0,0,0,133,134,5,61,
  	0,0,134,27,1,0,0,0,135,136,5,33,0,0,136,137,5,61,0,0,137,29,1,0,0,0,138,
  	139,5,60,0,0,139,140,5,61,0,0,140,31,1,0,0,0,141,142,5,60,0,0,142,33,
  	1,0,0,0,143,144,5,61,0,0,144,145,5,61,0,0,145,35,1,0,0,0,146,147,5,62,
  	0,0,147,37,1,0,0,0,148,149,5,62,0,0,149,150,5,61,0,0,150,39,1,0,0,0,151,
  	152,5,38,0,0,152,153,5,38,0,0,153,41,1,0,0,0,154,155,5,124,0,0,155,156,
  	5,124,0,0,156,43,1,0,0,0,157,158,5,43,0,0,158,45,1,0,0,0,159,160,5,45,
  	0,0,160,47,1,0,0,0,161,162,5,42,0,0,162,49,1,0,0,0,163,164,5,47,0,0,164,
  	51,1,0,0,0,165,166,5,42,0,0,166,167,5,42,0,0,167,53,1,0,0,0,168,169,5,
  	46,0,0,169,55,1,0,0,0,170,171,5,46,0,0,171,172,5,46,0,0,172,173,5,46,
  	0,0,173,57,1,0,0,0,174,178,5,35,0,0,175,177,8,0,0,0,176,175,1,0,0,0,177,
  	180,1,0,0,0,178,176,1,0,0,0,178,179,1,0,0,0,179,181,1,0,0,0,180,178,1,
  	0,0,0,181,182,6,28,2,0,182,59,1,0,0,0,183,184,5,47,0,0,184,185,5,42,0,
  	0,185,186,1,0,0,0,186,187,6,29,3,0,187,188,6,29,2,0,188,61,1,0,0,0,189,
  	191,7,1,0,0,190,189,1,0,0,0,191,192,1,0,0,0,192,190,1,0,0,0,192,193,1,
  	0,0,0,193,197,1,0,0,0,194,196,7,2,0,0,195,194,1,0,0,0,196,199,1,0,0,0,
  	197,195,1,0,0,0,197,198,1,0,0,0,198,63,1,0,0,0,199,197,1,0,0,0,200,202,
  	5,45,0,0,201,200,1,0,0,0,201,202,1,0,0,0,202,204,1,0,0,0,203,205,7,3,
  	0,0,204,203,1,0,0,0,205,206,1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,
  	65,1,0,0,0,208,210,3,64,31,0,209,208,1,0,0,0,209,210,1,0,0,0,210,211,
  	1,0,0,0,211,213,5,46,0,0,212,214,7,3,0,0,213,212,1,0,0,0,214,215,1,0,
  	0,0,215,213,1,0,0,0,215,216,1,0,0,0,216,67,1,0,0,0,217,219,5,34,0,0,218,
  	220,8,4,0,0,219,218,1,0,0,0,220,221,1,0,0,0,221,219,1,0,0,0,221,222,1,
  	0,0,0,222,223,1,0,0,0,223,224,5,34,0,0,224,69,1,0,0,0,225,226,5,116,0,
  	0,226,227,5,114,0,0,227,228,5,117,0,0,228,229,5,101,0,0,229,71,1,0,0,
  	0,230,231,5,102,0,0,231,232,5,97,0,0,232,233,5,108,0,0,233,234,5,115,
  	0,0,234,235,5,101,0,0,235,73,1,0,0,0,236,237,4,36,0,0,237,249,3,76,37,
  	0,238,240,5,13,0,0,239,238,1,0,0,0,239,240,1,0,0,0,240,241,1,0,0,0,241,
  	244,5,10,0,0,242,244,2,12,13,0,243,239,1,0,0,0,243,242,1,0,0,0,244,246,
  	1,0,0,0,245,247,3,76,37,0,246,245,1,0,0,0,246,247,1,0,0,0,247,249,1,0,
  	0,0,248,236,1,0,0,0,248,243,1,0,0,0,249,250,1,0,0,0,250,251,6,36,4,0,
  	251,75,1,0,0,0,252,254,7,5,0,0,253,252,1,0,0,0,254,255,1,0,0,0,255,253,
  	1,0,0,0,255,256,1,0,0,0,256,257,1,0,0,0,257,258,6,37,5,0,258,77,1,0,0,
  	0,259,260,5,42,0,0,260,261,5,47,0,0,261,262,1,0,0,0,262,263,6,38,6,0,
  	263,264,6,38,2,0,264,79,1,0,0,0,265,266,9,0,0,0,266,267,1,0,0,0,267,268,
  	6,39,2,0,268,81,1,0,0,0,17,0,1,178,190,192,195,197,201,206,209,215,221,
  	239,243,246,248,255,7,1,7,0,1,8,1,6,0,0,5,1,0,1,36,2,0,1,0,4,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tythonlexerLexerStaticData = staticData.release();
}

}

TythonLexer::TythonLexer(CharStream *input) : TythonLexerBase(input) {
  TythonLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *tythonlexerLexerStaticData->atn, tythonlexerLexerStaticData->decisionToDFA, tythonlexerLexerStaticData->sharedContextCache);
}

TythonLexer::~TythonLexer() {
  delete _interpreter;
}

std::string TythonLexer::getGrammarFileName() const {
  return "TythonLexer.g4";
}

const std::vector<std::string>& TythonLexer::getRuleNames() const {
  return tythonlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& TythonLexer::getChannelNames() const {
  return tythonlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& TythonLexer::getModeNames() const {
  return tythonlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& TythonLexer::getVocabulary() const {
  return tythonlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TythonLexer::getSerializedATN() const {
  return tythonlexerLexerStaticData->serializedATN;
}

const atn::ATN& TythonLexer::getATN() const {
  return *tythonlexerLexerStaticData->atn;
}


void TythonLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 7: SYM_LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: SYM_RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 36: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void TythonLexer::SYM_LPARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: this->openBrace(); break;

  default:
    break;
  }
}

void TythonLexer::SYM_RPARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: this->closeBrace(); break;

  default:
    break;
  }
}

void TythonLexer::NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: this->onNewLine(); break;

  default:
    break;
  }
}


bool TythonLexer::NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return this->atStartOfInput();

  default:
    break;
  }
  return true;
}


void TythonLexer::initialize() {
  ::antlr4::internal::call_once(tythonlexerLexerOnceFlag, tythonlexerLexerInitialize);
}
