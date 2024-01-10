
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
      "SYM_LPAR", "SYM_RPAR", "SYM_BLOCK_START", "SYM_ARG_SEPARATOR", "SYM_STMNT_DELIMITER", 
      "SYM_ASSIGN", "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", 
      "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", 
      "SYM_DIV", "SYM_EXP", "SYM_COMMENT", "SYM_COMMENT_START", "SYM_ELLIPS", 
      "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", "TRUE_LIT", "FALSE_LIT", 
      "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "comment_block"
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
      "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,40,256,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,
  	10,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,
  	16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,21,1,
  	21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,5,25,160,8,25,10,25,12,
  	25,163,9,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,
  	27,1,28,4,28,178,8,28,11,28,12,28,179,1,28,5,28,183,8,28,10,28,12,28,
  	186,9,28,1,29,3,29,189,8,29,1,29,4,29,192,8,29,11,29,12,29,193,1,30,3,
  	30,197,8,30,1,30,1,30,4,30,201,8,30,11,30,12,30,202,1,31,1,31,4,31,207,
  	8,31,11,31,12,31,208,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,
  	1,33,1,33,1,33,1,34,1,34,1,34,3,34,227,8,34,1,34,1,34,3,34,231,8,34,1,
  	34,3,34,234,8,34,3,34,236,8,34,1,34,1,34,1,35,4,35,241,8,35,11,35,12,
  	35,242,1,35,1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,0,
  	0,38,2,3,4,4,6,5,8,6,10,7,12,8,14,9,16,10,18,11,20,12,22,13,24,14,26,
  	15,28,16,30,17,32,18,34,19,36,20,38,21,40,22,42,23,44,24,46,25,48,26,
  	50,27,52,28,54,29,56,30,58,31,60,32,62,33,64,34,66,35,68,36,70,37,72,
  	38,74,39,76,40,2,0,1,6,2,0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,48,
  	57,65,90,95,95,97,122,1,0,48,57,1,0,34,34,3,0,9,9,12,12,32,32,267,0,2,
  	1,0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,0,0,10,1,0,0,0,0,12,1,0,0,0,
  	0,14,1,0,0,0,0,16,1,0,0,0,0,18,1,0,0,0,0,20,1,0,0,0,0,22,1,0,0,0,0,24,
  	1,0,0,0,0,26,1,0,0,0,0,28,1,0,0,0,0,30,1,0,0,0,0,32,1,0,0,0,0,34,1,0,
  	0,0,0,36,1,0,0,0,0,38,1,0,0,0,0,40,1,0,0,0,0,42,1,0,0,0,0,44,1,0,0,0,
  	0,46,1,0,0,0,0,48,1,0,0,0,0,50,1,0,0,0,0,52,1,0,0,0,0,54,1,0,0,0,0,56,
  	1,0,0,0,0,58,1,0,0,0,0,60,1,0,0,0,0,62,1,0,0,0,0,64,1,0,0,0,0,66,1,0,
  	0,0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,0,0,1,74,1,0,0,0,1,76,1,0,0,0,
  	2,78,1,0,0,0,4,82,1,0,0,0,6,89,1,0,0,0,8,92,1,0,0,0,10,97,1,0,0,0,12,
  	103,1,0,0,0,14,110,1,0,0,0,16,113,1,0,0,0,18,116,1,0,0,0,20,118,1,0,0,
  	0,22,120,1,0,0,0,24,122,1,0,0,0,26,124,1,0,0,0,28,127,1,0,0,0,30,130,
  	1,0,0,0,32,132,1,0,0,0,34,135,1,0,0,0,36,137,1,0,0,0,38,140,1,0,0,0,40,
  	143,1,0,0,0,42,146,1,0,0,0,44,148,1,0,0,0,46,150,1,0,0,0,48,152,1,0,0,
  	0,50,154,1,0,0,0,52,157,1,0,0,0,54,166,1,0,0,0,56,172,1,0,0,0,58,177,
  	1,0,0,0,60,188,1,0,0,0,62,196,1,0,0,0,64,204,1,0,0,0,66,212,1,0,0,0,68,
  	217,1,0,0,0,70,235,1,0,0,0,72,240,1,0,0,0,74,246,1,0,0,0,76,252,1,0,0,
  	0,78,79,5,100,0,0,79,80,5,101,0,0,80,81,5,102,0,0,81,3,1,0,0,0,82,83,
  	5,114,0,0,83,84,5,101,0,0,84,85,5,116,0,0,85,86,5,117,0,0,86,87,5,114,
  	0,0,87,88,5,110,0,0,88,5,1,0,0,0,89,90,5,105,0,0,90,91,5,102,0,0,91,7,
  	1,0,0,0,92,93,5,101,0,0,93,94,5,108,0,0,94,95,5,115,0,0,95,96,5,101,0,
  	0,96,9,1,0,0,0,97,98,5,119,0,0,98,99,5,104,0,0,99,100,5,105,0,0,100,101,
  	5,108,0,0,101,102,5,101,0,0,102,11,1,0,0,0,103,104,5,101,0,0,104,105,
  	5,120,0,0,105,106,5,116,0,0,106,107,5,101,0,0,107,108,5,114,0,0,108,109,
  	5,110,0,0,109,13,1,0,0,0,110,111,5,40,0,0,111,112,6,6,0,0,112,15,1,0,
  	0,0,113,114,5,41,0,0,114,115,6,7,1,0,115,17,1,0,0,0,116,117,5,58,0,0,
  	117,19,1,0,0,0,118,119,5,44,0,0,119,21,1,0,0,0,120,121,5,59,0,0,121,23,
  	1,0,0,0,122,123,5,61,0,0,123,25,1,0,0,0,124,125,5,33,0,0,125,126,5,61,
  	0,0,126,27,1,0,0,0,127,128,5,60,0,0,128,129,5,61,0,0,129,29,1,0,0,0,130,
  	131,5,60,0,0,131,31,1,0,0,0,132,133,5,61,0,0,133,134,5,61,0,0,134,33,
  	1,0,0,0,135,136,5,62,0,0,136,35,1,0,0,0,137,138,5,62,0,0,138,139,5,61,
  	0,0,139,37,1,0,0,0,140,141,5,38,0,0,141,142,5,38,0,0,142,39,1,0,0,0,143,
  	144,5,124,0,0,144,145,5,124,0,0,145,41,1,0,0,0,146,147,5,43,0,0,147,43,
  	1,0,0,0,148,149,5,45,0,0,149,45,1,0,0,0,150,151,5,42,0,0,151,47,1,0,0,
  	0,152,153,5,47,0,0,153,49,1,0,0,0,154,155,5,42,0,0,155,156,5,42,0,0,156,
  	51,1,0,0,0,157,161,5,35,0,0,158,160,8,0,0,0,159,158,1,0,0,0,160,163,1,
  	0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,164,1,0,0,0,163,161,1,0,0,0,
  	164,165,6,25,2,0,165,53,1,0,0,0,166,167,5,47,0,0,167,168,5,42,0,0,168,
  	169,1,0,0,0,169,170,6,26,3,0,170,171,6,26,2,0,171,55,1,0,0,0,172,173,
  	5,46,0,0,173,174,5,46,0,0,174,175,5,46,0,0,175,57,1,0,0,0,176,178,7,1,
  	0,0,177,176,1,0,0,0,178,179,1,0,0,0,179,177,1,0,0,0,179,180,1,0,0,0,180,
  	184,1,0,0,0,181,183,7,2,0,0,182,181,1,0,0,0,183,186,1,0,0,0,184,182,1,
  	0,0,0,184,185,1,0,0,0,185,59,1,0,0,0,186,184,1,0,0,0,187,189,5,45,0,0,
  	188,187,1,0,0,0,188,189,1,0,0,0,189,191,1,0,0,0,190,192,7,3,0,0,191,190,
  	1,0,0,0,192,193,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,61,1,0,0,
  	0,195,197,3,60,29,0,196,195,1,0,0,0,196,197,1,0,0,0,197,198,1,0,0,0,198,
  	200,5,46,0,0,199,201,7,3,0,0,200,199,1,0,0,0,201,202,1,0,0,0,202,200,
  	1,0,0,0,202,203,1,0,0,0,203,63,1,0,0,0,204,206,5,34,0,0,205,207,8,4,0,
  	0,206,205,1,0,0,0,207,208,1,0,0,0,208,206,1,0,0,0,208,209,1,0,0,0,209,
  	210,1,0,0,0,210,211,5,34,0,0,211,65,1,0,0,0,212,213,5,116,0,0,213,214,
  	5,114,0,0,214,215,5,117,0,0,215,216,5,101,0,0,216,67,1,0,0,0,217,218,
  	5,102,0,0,218,219,5,97,0,0,219,220,5,108,0,0,220,221,5,115,0,0,221,222,
  	5,101,0,0,222,69,1,0,0,0,223,224,4,34,0,0,224,236,3,72,35,0,225,227,5,
  	13,0,0,226,225,1,0,0,0,226,227,1,0,0,0,227,228,1,0,0,0,228,231,5,10,0,
  	0,229,231,2,12,13,0,230,226,1,0,0,0,230,229,1,0,0,0,231,233,1,0,0,0,232,
  	234,3,72,35,0,233,232,1,0,0,0,233,234,1,0,0,0,234,236,1,0,0,0,235,223,
  	1,0,0,0,235,230,1,0,0,0,236,237,1,0,0,0,237,238,6,34,4,0,238,71,1,0,0,
  	0,239,241,7,5,0,0,240,239,1,0,0,0,241,242,1,0,0,0,242,240,1,0,0,0,242,
  	243,1,0,0,0,243,244,1,0,0,0,244,245,6,35,5,0,245,73,1,0,0,0,246,247,5,
  	42,0,0,247,248,5,47,0,0,248,249,1,0,0,0,249,250,6,36,6,0,250,251,6,36,
  	2,0,251,75,1,0,0,0,252,253,9,0,0,0,253,254,1,0,0,0,254,255,6,37,2,0,255,
  	77,1,0,0,0,17,0,1,161,177,179,182,184,188,193,196,202,208,226,230,233,
  	235,242,7,1,6,0,1,7,1,6,0,0,5,1,0,1,34,2,0,1,0,4,0,0
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
    case 6: SYM_LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: SYM_RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 34: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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
