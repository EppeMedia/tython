
#include "../include/lexer/TythonLexerBase.h"


// Generated from /home/manzi/repos/tython/src/grammar/TythonLexer.g4 by ANTLR 4.12.0


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
      "KW_IMPORT", "KW_SELF", "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", 
      "SYM_BLOCK_START", "SYM_ARG_SEPARATOR", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", 
      "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", 
      "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", 
      "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "IDENTIFIER", 
      "INT_LIT", "FLOAT_LIT", "STR_LIT", "TRUE_LIT", "FALSE_LIT", "NEWLINE", 
      "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "comment_block"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'while'", "'extern'", 
      "'import'", "'self'", "'('", "')'", "'['", "']'", "':'", "','", "';'", 
      "'='", "'!='", "'<='", "'<'", "'=='", "'>'", "'>='", "'&&'", "'||'", 
      "'+'", "'-'", "'*'", "'/'", "'**'", "'.'", "'...'", "", "'/*'", "", 
      "", "", "", "'true'", "'false'", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_WHILE", "KW_EXTERN", "KW_IMPORT", "KW_SELF", "SYM_LPAR", "SYM_RPAR", 
      "SYM_LSQ", "SYM_RSQ", "SYM_BLOCK_START", "SYM_ARG_SEPARATOR", "SYM_STMNT_DELIMITER", 
      "SYM_ASSIGN", "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", 
      "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", 
      "SYM_DIV", "SYM_EXP", "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", 
      "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", "TRUE_LIT", "FALSE_LIT", 
      "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,45,284,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,
  	1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,
  	1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,21,1,21,
  	1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,
  	1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,30,1,31,1,31,5,31,192,
  	8,31,10,31,12,31,195,9,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,33,
  	4,33,206,8,33,11,33,12,33,207,1,33,5,33,211,8,33,10,33,12,33,214,9,33,
  	1,34,3,34,217,8,34,1,34,4,34,220,8,34,11,34,12,34,221,1,35,3,35,225,8,
  	35,1,35,1,35,4,35,229,8,35,11,35,12,35,230,1,36,1,36,4,36,235,8,36,11,
  	36,12,36,236,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,
  	38,1,38,1,39,1,39,1,39,3,39,255,8,39,1,39,1,39,3,39,259,8,39,1,39,3,39,
  	262,8,39,3,39,264,8,39,1,39,1,39,1,40,4,40,269,8,40,11,40,12,40,270,1,
  	40,1,40,1,41,1,41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,42,0,0,43,2,3,
  	4,4,6,5,8,6,10,7,12,8,14,9,16,10,18,11,20,12,22,13,24,14,26,15,28,16,
  	30,17,32,18,34,19,36,20,38,21,40,22,42,23,44,24,46,25,48,26,50,27,52,
  	28,54,29,56,30,58,31,60,32,62,33,64,34,66,35,68,36,70,37,72,38,74,39,
  	76,40,78,41,80,42,82,43,84,44,86,45,2,0,1,6,2,0,10,10,13,13,3,0,65,90,
  	95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,1,0,34,34,2,0,9,9,
  	32,32,295,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,0,0,10,1,0,0,
  	0,0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,18,1,0,0,0,0,20,1,0,0,0,0,
  	22,1,0,0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,1,0,0,0,0,30,1,0,0,0,0,32,1,
  	0,0,0,0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,0,0,0,40,1,0,0,0,0,42,1,0,0,
  	0,0,44,1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,0,50,1,0,0,0,0,52,1,0,0,0,0,
  	54,1,0,0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,1,0,0,0,0,62,1,0,0,0,0,64,1,
  	0,0,0,0,66,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,0,0,0,74,1,0,0,
  	0,0,76,1,0,0,0,0,78,1,0,0,0,0,80,1,0,0,0,0,82,1,0,0,0,1,84,1,0,0,0,1,
  	86,1,0,0,0,2,88,1,0,0,0,4,92,1,0,0,0,6,99,1,0,0,0,8,102,1,0,0,0,10,107,
  	1,0,0,0,12,113,1,0,0,0,14,120,1,0,0,0,16,127,1,0,0,0,18,132,1,0,0,0,20,
  	135,1,0,0,0,22,138,1,0,0,0,24,140,1,0,0,0,26,142,1,0,0,0,28,144,1,0,0,
  	0,30,146,1,0,0,0,32,148,1,0,0,0,34,150,1,0,0,0,36,153,1,0,0,0,38,156,
  	1,0,0,0,40,158,1,0,0,0,42,161,1,0,0,0,44,163,1,0,0,0,46,166,1,0,0,0,48,
  	169,1,0,0,0,50,172,1,0,0,0,52,174,1,0,0,0,54,176,1,0,0,0,56,178,1,0,0,
  	0,58,180,1,0,0,0,60,183,1,0,0,0,62,185,1,0,0,0,64,189,1,0,0,0,66,198,
  	1,0,0,0,68,205,1,0,0,0,70,216,1,0,0,0,72,224,1,0,0,0,74,232,1,0,0,0,76,
  	240,1,0,0,0,78,245,1,0,0,0,80,263,1,0,0,0,82,268,1,0,0,0,84,274,1,0,0,
  	0,86,280,1,0,0,0,88,89,5,100,0,0,89,90,5,101,0,0,90,91,5,102,0,0,91,3,
  	1,0,0,0,92,93,5,114,0,0,93,94,5,101,0,0,94,95,5,116,0,0,95,96,5,117,0,
  	0,96,97,5,114,0,0,97,98,5,110,0,0,98,5,1,0,0,0,99,100,5,105,0,0,100,101,
  	5,102,0,0,101,7,1,0,0,0,102,103,5,101,0,0,103,104,5,108,0,0,104,105,5,
  	115,0,0,105,106,5,101,0,0,106,9,1,0,0,0,107,108,5,119,0,0,108,109,5,104,
  	0,0,109,110,5,105,0,0,110,111,5,108,0,0,111,112,5,101,0,0,112,11,1,0,
  	0,0,113,114,5,101,0,0,114,115,5,120,0,0,115,116,5,116,0,0,116,117,5,101,
  	0,0,117,118,5,114,0,0,118,119,5,110,0,0,119,13,1,0,0,0,120,121,5,105,
  	0,0,121,122,5,109,0,0,122,123,5,112,0,0,123,124,5,111,0,0,124,125,5,114,
  	0,0,125,126,5,116,0,0,126,15,1,0,0,0,127,128,5,115,0,0,128,129,5,101,
  	0,0,129,130,5,108,0,0,130,131,5,102,0,0,131,17,1,0,0,0,132,133,5,40,0,
  	0,133,134,6,8,0,0,134,19,1,0,0,0,135,136,5,41,0,0,136,137,6,9,1,0,137,
  	21,1,0,0,0,138,139,5,91,0,0,139,23,1,0,0,0,140,141,5,93,0,0,141,25,1,
  	0,0,0,142,143,5,58,0,0,143,27,1,0,0,0,144,145,5,44,0,0,145,29,1,0,0,0,
  	146,147,5,59,0,0,147,31,1,0,0,0,148,149,5,61,0,0,149,33,1,0,0,0,150,151,
  	5,33,0,0,151,152,5,61,0,0,152,35,1,0,0,0,153,154,5,60,0,0,154,155,5,61,
  	0,0,155,37,1,0,0,0,156,157,5,60,0,0,157,39,1,0,0,0,158,159,5,61,0,0,159,
  	160,5,61,0,0,160,41,1,0,0,0,161,162,5,62,0,0,162,43,1,0,0,0,163,164,5,
  	62,0,0,164,165,5,61,0,0,165,45,1,0,0,0,166,167,5,38,0,0,167,168,5,38,
  	0,0,168,47,1,0,0,0,169,170,5,124,0,0,170,171,5,124,0,0,171,49,1,0,0,0,
  	172,173,5,43,0,0,173,51,1,0,0,0,174,175,5,45,0,0,175,53,1,0,0,0,176,177,
  	5,42,0,0,177,55,1,0,0,0,178,179,5,47,0,0,179,57,1,0,0,0,180,181,5,42,
  	0,0,181,182,5,42,0,0,182,59,1,0,0,0,183,184,5,46,0,0,184,61,1,0,0,0,185,
  	186,5,46,0,0,186,187,5,46,0,0,187,188,5,46,0,0,188,63,1,0,0,0,189,193,
  	5,35,0,0,190,192,8,0,0,0,191,190,1,0,0,0,192,195,1,0,0,0,193,191,1,0,
  	0,0,193,194,1,0,0,0,194,196,1,0,0,0,195,193,1,0,0,0,196,197,6,31,2,0,
  	197,65,1,0,0,0,198,199,5,47,0,0,199,200,5,42,0,0,200,201,1,0,0,0,201,
  	202,6,32,3,0,202,203,6,32,2,0,203,67,1,0,0,0,204,206,7,1,0,0,205,204,
  	1,0,0,0,206,207,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,212,1,0,0,
  	0,209,211,7,2,0,0,210,209,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,
  	213,1,0,0,0,213,69,1,0,0,0,214,212,1,0,0,0,215,217,5,45,0,0,216,215,1,
  	0,0,0,216,217,1,0,0,0,217,219,1,0,0,0,218,220,7,3,0,0,219,218,1,0,0,0,
  	220,221,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,222,71,1,0,0,0,223,225,
  	3,70,34,0,224,223,1,0,0,0,224,225,1,0,0,0,225,226,1,0,0,0,226,228,5,46,
  	0,0,227,229,7,3,0,0,228,227,1,0,0,0,229,230,1,0,0,0,230,228,1,0,0,0,230,
  	231,1,0,0,0,231,73,1,0,0,0,232,234,5,34,0,0,233,235,8,4,0,0,234,233,1,
  	0,0,0,235,236,1,0,0,0,236,234,1,0,0,0,236,237,1,0,0,0,237,238,1,0,0,0,
  	238,239,5,34,0,0,239,75,1,0,0,0,240,241,5,116,0,0,241,242,5,114,0,0,242,
  	243,5,117,0,0,243,244,5,101,0,0,244,77,1,0,0,0,245,246,5,102,0,0,246,
  	247,5,97,0,0,247,248,5,108,0,0,248,249,5,115,0,0,249,250,5,101,0,0,250,
  	79,1,0,0,0,251,252,4,39,0,0,252,264,3,82,40,0,253,255,5,13,0,0,254,253,
  	1,0,0,0,254,255,1,0,0,0,255,256,1,0,0,0,256,259,5,10,0,0,257,259,2,12,
  	13,0,258,254,1,0,0,0,258,257,1,0,0,0,259,261,1,0,0,0,260,262,3,82,40,
  	0,261,260,1,0,0,0,261,262,1,0,0,0,262,264,1,0,0,0,263,251,1,0,0,0,263,
  	258,1,0,0,0,264,265,1,0,0,0,265,266,6,39,4,0,266,81,1,0,0,0,267,269,7,
  	5,0,0,268,267,1,0,0,0,269,270,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,
  	271,272,1,0,0,0,272,273,6,40,5,0,273,83,1,0,0,0,274,275,5,42,0,0,275,
  	276,5,47,0,0,276,277,1,0,0,0,277,278,6,41,6,0,278,279,6,41,2,0,279,85,
  	1,0,0,0,280,281,9,0,0,0,281,282,1,0,0,0,282,283,6,42,2,0,283,87,1,0,0,
  	0,17,0,1,193,205,207,210,212,216,221,224,230,236,254,258,261,263,270,
  	7,1,8,0,1,9,1,6,0,0,5,1,0,1,39,2,0,1,0,4,0,0
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
    case 8: SYM_LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: SYM_RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 39: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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
