
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
      "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", "KW_FOR", "KW_IN", "KW_WHILE", 
      "KW_EXTERN", "KW_IMPORT", "KW_SELF", "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", 
      "SYM_RSQ", "SYM_LBR", "SYM_RBR", "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", 
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
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'for'", "'in'", 
      "'while'", "'extern'", "'import'", "'self'", "'('", "')'", "'['", 
      "']'", "'{'", "'}'", "':'", "';'", "','", "", "'='", "'!='", "'<='", 
      "'<'", "'=='", "'>'", "'>='", "'&&'", "'||'", "'+'", "'-'", "'*'", 
      "'/'", "'**'", "'.'", "'...'", "", "'/*'", "", "", "", "", "'true'", 
      "'false'", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_FOR", "KW_IN", "KW_WHILE", "KW_EXTERN", "KW_IMPORT", "KW_SELF", 
      "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", "SYM_LBR", "SYM_RBR", 
      "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", 
      "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", 
      "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", 
      "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "IDENTIFIER", 
      "INT_LIT", "FLOAT_LIT", "STR_LIT", "TRUE_LIT", "FALSE_LIT", "NEWLINE", 
      "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,50,311,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,1,0,1,
  	0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,
  	10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,
  	15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,
  	21,1,22,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,
  	27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,
  	33,1,33,1,33,1,34,1,34,1,35,1,35,1,35,1,35,1,36,1,36,5,36,219,8,36,10,
  	36,12,36,222,9,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,37,1,38,4,38,233,
  	8,38,11,38,12,38,234,1,38,5,38,238,8,38,10,38,12,38,241,9,38,1,39,3,39,
  	244,8,39,1,39,4,39,247,8,39,11,39,12,39,248,1,40,3,40,252,8,40,1,40,1,
  	40,4,40,256,8,40,11,40,12,40,257,1,41,1,41,4,41,262,8,41,11,41,12,41,
  	263,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,43,
  	1,44,1,44,1,44,3,44,282,8,44,1,44,1,44,3,44,286,8,44,1,44,3,44,289,8,
  	44,3,44,291,8,44,1,44,1,44,1,45,4,45,296,8,45,11,45,12,45,297,1,45,1,
  	45,1,46,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,0,0,48,2,3,4,4,6,
  	5,8,6,10,7,12,8,14,9,16,10,18,11,20,12,22,13,24,14,26,15,28,16,30,17,
  	32,18,34,19,36,20,38,21,40,22,42,23,44,24,46,25,48,26,50,27,52,28,54,
  	29,56,30,58,31,60,32,62,33,64,34,66,35,68,36,70,37,72,38,74,39,76,40,
  	78,41,80,42,82,43,84,44,86,45,88,46,90,47,92,48,94,49,96,50,2,0,1,6,2,
  	0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,
  	48,57,1,0,34,34,2,0,9,9,32,32,322,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,
  	0,8,1,0,0,0,0,10,1,0,0,0,0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,18,
  	1,0,0,0,0,20,1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,1,0,
  	0,0,0,30,1,0,0,0,0,32,1,0,0,0,0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,0,0,
  	0,40,1,0,0,0,0,42,1,0,0,0,0,44,1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,0,50,
  	1,0,0,0,0,52,1,0,0,0,0,54,1,0,0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,1,0,
  	0,0,0,62,1,0,0,0,0,64,1,0,0,0,0,66,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,0,
  	0,72,1,0,0,0,0,74,1,0,0,0,0,76,1,0,0,0,0,78,1,0,0,0,0,80,1,0,0,0,0,82,
  	1,0,0,0,0,84,1,0,0,0,0,86,1,0,0,0,0,88,1,0,0,0,0,90,1,0,0,0,0,92,1,0,
  	0,0,1,94,1,0,0,0,1,96,1,0,0,0,2,98,1,0,0,0,4,102,1,0,0,0,6,109,1,0,0,
  	0,8,112,1,0,0,0,10,117,1,0,0,0,12,121,1,0,0,0,14,124,1,0,0,0,16,130,1,
  	0,0,0,18,137,1,0,0,0,20,144,1,0,0,0,22,149,1,0,0,0,24,152,1,0,0,0,26,
  	155,1,0,0,0,28,158,1,0,0,0,30,161,1,0,0,0,32,164,1,0,0,0,34,167,1,0,0,
  	0,36,169,1,0,0,0,38,171,1,0,0,0,40,173,1,0,0,0,42,175,1,0,0,0,44,177,
  	1,0,0,0,46,180,1,0,0,0,48,183,1,0,0,0,50,185,1,0,0,0,52,188,1,0,0,0,54,
  	190,1,0,0,0,56,193,1,0,0,0,58,196,1,0,0,0,60,199,1,0,0,0,62,201,1,0,0,
  	0,64,203,1,0,0,0,66,205,1,0,0,0,68,207,1,0,0,0,70,210,1,0,0,0,72,212,
  	1,0,0,0,74,216,1,0,0,0,76,225,1,0,0,0,78,232,1,0,0,0,80,243,1,0,0,0,82,
  	251,1,0,0,0,84,259,1,0,0,0,86,267,1,0,0,0,88,272,1,0,0,0,90,290,1,0,0,
  	0,92,295,1,0,0,0,94,301,1,0,0,0,96,307,1,0,0,0,98,99,5,100,0,0,99,100,
  	5,101,0,0,100,101,5,102,0,0,101,3,1,0,0,0,102,103,5,114,0,0,103,104,5,
  	101,0,0,104,105,5,116,0,0,105,106,5,117,0,0,106,107,5,114,0,0,107,108,
  	5,110,0,0,108,5,1,0,0,0,109,110,5,105,0,0,110,111,5,102,0,0,111,7,1,0,
  	0,0,112,113,5,101,0,0,113,114,5,108,0,0,114,115,5,115,0,0,115,116,5,101,
  	0,0,116,9,1,0,0,0,117,118,5,102,0,0,118,119,5,111,0,0,119,120,5,114,0,
  	0,120,11,1,0,0,0,121,122,5,105,0,0,122,123,5,110,0,0,123,13,1,0,0,0,124,
  	125,5,119,0,0,125,126,5,104,0,0,126,127,5,105,0,0,127,128,5,108,0,0,128,
  	129,5,101,0,0,129,15,1,0,0,0,130,131,5,101,0,0,131,132,5,120,0,0,132,
  	133,5,116,0,0,133,134,5,101,0,0,134,135,5,114,0,0,135,136,5,110,0,0,136,
  	17,1,0,0,0,137,138,5,105,0,0,138,139,5,109,0,0,139,140,5,112,0,0,140,
  	141,5,111,0,0,141,142,5,114,0,0,142,143,5,116,0,0,143,19,1,0,0,0,144,
  	145,5,115,0,0,145,146,5,101,0,0,146,147,5,108,0,0,147,148,5,102,0,0,148,
  	21,1,0,0,0,149,150,5,40,0,0,150,151,6,10,0,0,151,23,1,0,0,0,152,153,5,
  	41,0,0,153,154,6,11,1,0,154,25,1,0,0,0,155,156,5,91,0,0,156,157,6,12,
  	2,0,157,27,1,0,0,0,158,159,5,93,0,0,159,160,6,13,3,0,160,29,1,0,0,0,161,
  	162,5,123,0,0,162,163,6,14,4,0,163,31,1,0,0,0,164,165,5,125,0,0,165,166,
  	6,15,5,0,166,33,1,0,0,0,167,168,5,58,0,0,168,35,1,0,0,0,169,170,5,59,
  	0,0,170,37,1,0,0,0,171,172,5,44,0,0,172,39,1,0,0,0,173,174,3,36,17,0,
  	174,41,1,0,0,0,175,176,5,61,0,0,176,43,1,0,0,0,177,178,5,33,0,0,178,179,
  	5,61,0,0,179,45,1,0,0,0,180,181,5,60,0,0,181,182,5,61,0,0,182,47,1,0,
  	0,0,183,184,5,60,0,0,184,49,1,0,0,0,185,186,5,61,0,0,186,187,5,61,0,0,
  	187,51,1,0,0,0,188,189,5,62,0,0,189,53,1,0,0,0,190,191,5,62,0,0,191,192,
  	5,61,0,0,192,55,1,0,0,0,193,194,5,38,0,0,194,195,5,38,0,0,195,57,1,0,
  	0,0,196,197,5,124,0,0,197,198,5,124,0,0,198,59,1,0,0,0,199,200,5,43,0,
  	0,200,61,1,0,0,0,201,202,5,45,0,0,202,63,1,0,0,0,203,204,5,42,0,0,204,
  	65,1,0,0,0,205,206,5,47,0,0,206,67,1,0,0,0,207,208,5,42,0,0,208,209,5,
  	42,0,0,209,69,1,0,0,0,210,211,5,46,0,0,211,71,1,0,0,0,212,213,5,46,0,
  	0,213,214,5,46,0,0,214,215,5,46,0,0,215,73,1,0,0,0,216,220,5,35,0,0,217,
  	219,8,0,0,0,218,217,1,0,0,0,219,222,1,0,0,0,220,218,1,0,0,0,220,221,1,
  	0,0,0,221,223,1,0,0,0,222,220,1,0,0,0,223,224,6,36,6,0,224,75,1,0,0,0,
  	225,226,5,47,0,0,226,227,5,42,0,0,227,228,1,0,0,0,228,229,6,37,7,0,229,
  	230,6,37,6,0,230,77,1,0,0,0,231,233,7,1,0,0,232,231,1,0,0,0,233,234,1,
  	0,0,0,234,232,1,0,0,0,234,235,1,0,0,0,235,239,1,0,0,0,236,238,7,2,0,0,
  	237,236,1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,0,239,240,1,0,0,0,240,79,
  	1,0,0,0,241,239,1,0,0,0,242,244,5,45,0,0,243,242,1,0,0,0,243,244,1,0,
  	0,0,244,246,1,0,0,0,245,247,7,3,0,0,246,245,1,0,0,0,247,248,1,0,0,0,248,
  	246,1,0,0,0,248,249,1,0,0,0,249,81,1,0,0,0,250,252,3,80,39,0,251,250,
  	1,0,0,0,251,252,1,0,0,0,252,253,1,0,0,0,253,255,5,46,0,0,254,256,7,3,
  	0,0,255,254,1,0,0,0,256,257,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,
  	83,1,0,0,0,259,261,5,34,0,0,260,262,8,4,0,0,261,260,1,0,0,0,262,263,1,
  	0,0,0,263,261,1,0,0,0,263,264,1,0,0,0,264,265,1,0,0,0,265,266,5,34,0,
  	0,266,85,1,0,0,0,267,268,5,116,0,0,268,269,5,114,0,0,269,270,5,117,0,
  	0,270,271,5,101,0,0,271,87,1,0,0,0,272,273,5,102,0,0,273,274,5,97,0,0,
  	274,275,5,108,0,0,275,276,5,115,0,0,276,277,5,101,0,0,277,89,1,0,0,0,
  	278,279,4,44,0,0,279,291,3,92,45,0,280,282,5,13,0,0,281,280,1,0,0,0,281,
  	282,1,0,0,0,282,283,1,0,0,0,283,286,5,10,0,0,284,286,2,12,13,0,285,281,
  	1,0,0,0,285,284,1,0,0,0,286,288,1,0,0,0,287,289,3,92,45,0,288,287,1,0,
  	0,0,288,289,1,0,0,0,289,291,1,0,0,0,290,278,1,0,0,0,290,285,1,0,0,0,291,
  	292,1,0,0,0,292,293,6,44,8,0,293,91,1,0,0,0,294,296,7,5,0,0,295,294,1,
  	0,0,0,296,297,1,0,0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,299,1,0,0,0,
  	299,300,6,45,9,0,300,93,1,0,0,0,301,302,5,42,0,0,302,303,5,47,0,0,303,
  	304,1,0,0,0,304,305,6,46,10,0,305,306,6,46,6,0,306,95,1,0,0,0,307,308,
  	9,0,0,0,308,309,1,0,0,0,309,310,6,47,6,0,310,97,1,0,0,0,17,0,1,220,232,
  	234,237,239,243,248,251,257,263,281,285,288,290,297,11,1,10,0,1,11,1,
  	1,12,2,1,13,3,1,14,4,1,15,5,6,0,0,5,1,0,1,44,6,0,1,0,4,0,0
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
    case 10: SYM_LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: SYM_RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: SYM_LSQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: SYM_RSQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: SYM_LBRAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: SYM_RBRAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 44: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void TythonLexer::SYM_LSQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: this->openBrace(); break;

  default:
    break;
  }
}

void TythonLexer::SYM_RSQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3: this->closeBrace(); break;

  default:
    break;
  }
}

void TythonLexer::SYM_LBRAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4: this->openBrace(); break;

  default:
    break;
  }
}

void TythonLexer::SYM_RBRAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5: this->closeBrace(); break;

  default:
    break;
  }
}

void TythonLexer::NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6: this->onNewLine(); break;

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
