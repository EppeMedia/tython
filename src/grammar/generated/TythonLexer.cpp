
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
      "KW_BREAK", "KW_EXTERN", "KW_IMPORT", "KW_SELF", "SYM_LPAR", "SYM_RPAR", 
      "SYM_LSQ", "SYM_RSQ", "SYM_LBR", "SYM_RBR", "SYM_COL", "SYM_SEMCOL", 
      "SYM_COMMA", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", "SYM_NEQ", "SYM_LTE", 
      "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", 
      "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", "SYM_INC", "SYM_DEC", 
      "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "TRUE_LIT", 
      "FALSE_LIT", "NONE_LIT", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", 
      "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "comment_block"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'for'", "'in'", 
      "'while'", "'break'", "'extern'", "'import'", "'self'", "'('", "')'", 
      "'['", "']'", "'{'", "'}'", "':'", "';'", "','", "", "'='", "'!='", 
      "'<='", "'<'", "'=='", "'>'", "'>='", "'&&'", "'||'", "'+'", "'-'", 
      "'*'", "'/'", "'**'", "'++'", "'--'", "'.'", "'...'", "", "'/*'", 
      "'true'", "'false'", "'None'", "", "", "", "", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_FOR", "KW_IN", "KW_WHILE", "KW_BREAK", "KW_EXTERN", "KW_IMPORT", 
      "KW_SELF", "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", "SYM_LBR", 
      "SYM_RBR", "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", 
      "SYM_ASSIGN", "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", 
      "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", 
      "SYM_DIV", "SYM_EXP", "SYM_INC", "SYM_DEC", "SYM_DOT", "SYM_ELLIPS", 
      "SYM_COMMENT", "SYM_COMMENT_START", "TRUE_LIT", "FALSE_LIT", "NONE_LIT", 
      "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", "NEWLINE", "WS", 
      "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,54,336,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,
  	48,2,49,7,49,2,50,7,50,2,51,7,51,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,
  	11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,
  	16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,
  	22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,27,1,
  	28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,
  	34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,38,1,38,1,38,1,
  	38,1,39,1,39,5,39,239,8,39,10,39,12,39,242,9,39,1,39,1,39,1,40,1,40,1,
  	40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,43,1,43,1,43,1,43,1,43,1,44,4,44,269,8,44,11,44,12,44,270,1,44,5,
  	44,274,8,44,10,44,12,44,277,9,44,1,45,3,45,280,8,45,1,45,4,45,283,8,45,
  	11,45,12,45,284,1,46,3,46,288,8,46,1,46,1,46,4,46,292,8,46,11,46,12,46,
  	293,1,47,1,47,4,47,298,8,47,11,47,12,47,299,1,47,1,47,1,48,1,48,1,48,
  	3,48,307,8,48,1,48,1,48,3,48,311,8,48,1,48,3,48,314,8,48,3,48,316,8,48,
  	1,48,1,48,1,49,4,49,321,8,49,11,49,12,49,322,1,49,1,49,1,50,1,50,1,50,
  	1,50,1,50,1,50,1,51,1,51,1,51,1,51,0,0,52,2,3,4,4,6,5,8,6,10,7,12,8,14,
  	9,16,10,18,11,20,12,22,13,24,14,26,15,28,16,30,17,32,18,34,19,36,20,38,
  	21,40,22,42,23,44,24,46,25,48,26,50,27,52,28,54,29,56,30,58,31,60,32,
  	62,33,64,34,66,35,68,36,70,37,72,38,74,39,76,40,78,41,80,42,82,43,84,
  	44,86,45,88,46,90,47,92,48,94,49,96,50,98,51,100,52,102,53,104,54,2,0,
  	1,6,2,0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,
  	1,0,48,57,1,0,34,34,2,0,9,9,32,32,347,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,0,
  	0,0,0,8,1,0,0,0,0,10,1,0,0,0,0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,
  	18,1,0,0,0,0,20,1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,1,
  	0,0,0,0,30,1,0,0,0,0,32,1,0,0,0,0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,0,
  	0,0,40,1,0,0,0,0,42,1,0,0,0,0,44,1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,0,
  	50,1,0,0,0,0,52,1,0,0,0,0,54,1,0,0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,1,
  	0,0,0,0,62,1,0,0,0,0,64,1,0,0,0,0,66,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,
  	0,0,72,1,0,0,0,0,74,1,0,0,0,0,76,1,0,0,0,0,78,1,0,0,0,0,80,1,0,0,0,0,
  	82,1,0,0,0,0,84,1,0,0,0,0,86,1,0,0,0,0,88,1,0,0,0,0,90,1,0,0,0,0,92,1,
  	0,0,0,0,94,1,0,0,0,0,96,1,0,0,0,0,98,1,0,0,0,0,100,1,0,0,0,1,102,1,0,
  	0,0,1,104,1,0,0,0,2,106,1,0,0,0,4,110,1,0,0,0,6,117,1,0,0,0,8,120,1,0,
  	0,0,10,125,1,0,0,0,12,129,1,0,0,0,14,132,1,0,0,0,16,138,1,0,0,0,18,144,
  	1,0,0,0,20,151,1,0,0,0,22,158,1,0,0,0,24,163,1,0,0,0,26,166,1,0,0,0,28,
  	169,1,0,0,0,30,172,1,0,0,0,32,175,1,0,0,0,34,178,1,0,0,0,36,181,1,0,0,
  	0,38,183,1,0,0,0,40,185,1,0,0,0,42,187,1,0,0,0,44,189,1,0,0,0,46,191,
  	1,0,0,0,48,194,1,0,0,0,50,197,1,0,0,0,52,199,1,0,0,0,54,202,1,0,0,0,56,
  	204,1,0,0,0,58,207,1,0,0,0,60,210,1,0,0,0,62,213,1,0,0,0,64,215,1,0,0,
  	0,66,217,1,0,0,0,68,219,1,0,0,0,70,221,1,0,0,0,72,224,1,0,0,0,74,227,
  	1,0,0,0,76,230,1,0,0,0,78,232,1,0,0,0,80,236,1,0,0,0,82,245,1,0,0,0,84,
  	251,1,0,0,0,86,256,1,0,0,0,88,262,1,0,0,0,90,268,1,0,0,0,92,279,1,0,0,
  	0,94,287,1,0,0,0,96,295,1,0,0,0,98,315,1,0,0,0,100,320,1,0,0,0,102,326,
  	1,0,0,0,104,332,1,0,0,0,106,107,5,100,0,0,107,108,5,101,0,0,108,109,5,
  	102,0,0,109,3,1,0,0,0,110,111,5,114,0,0,111,112,5,101,0,0,112,113,5,116,
  	0,0,113,114,5,117,0,0,114,115,5,114,0,0,115,116,5,110,0,0,116,5,1,0,0,
  	0,117,118,5,105,0,0,118,119,5,102,0,0,119,7,1,0,0,0,120,121,5,101,0,0,
  	121,122,5,108,0,0,122,123,5,115,0,0,123,124,5,101,0,0,124,9,1,0,0,0,125,
  	126,5,102,0,0,126,127,5,111,0,0,127,128,5,114,0,0,128,11,1,0,0,0,129,
  	130,5,105,0,0,130,131,5,110,0,0,131,13,1,0,0,0,132,133,5,119,0,0,133,
  	134,5,104,0,0,134,135,5,105,0,0,135,136,5,108,0,0,136,137,5,101,0,0,137,
  	15,1,0,0,0,138,139,5,98,0,0,139,140,5,114,0,0,140,141,5,101,0,0,141,142,
  	5,97,0,0,142,143,5,107,0,0,143,17,1,0,0,0,144,145,5,101,0,0,145,146,5,
  	120,0,0,146,147,5,116,0,0,147,148,5,101,0,0,148,149,5,114,0,0,149,150,
  	5,110,0,0,150,19,1,0,0,0,151,152,5,105,0,0,152,153,5,109,0,0,153,154,
  	5,112,0,0,154,155,5,111,0,0,155,156,5,114,0,0,156,157,5,116,0,0,157,21,
  	1,0,0,0,158,159,5,115,0,0,159,160,5,101,0,0,160,161,5,108,0,0,161,162,
  	5,102,0,0,162,23,1,0,0,0,163,164,5,40,0,0,164,165,6,11,0,0,165,25,1,0,
  	0,0,166,167,5,41,0,0,167,168,6,12,1,0,168,27,1,0,0,0,169,170,5,91,0,0,
  	170,171,6,13,2,0,171,29,1,0,0,0,172,173,5,93,0,0,173,174,6,14,3,0,174,
  	31,1,0,0,0,175,176,5,123,0,0,176,177,6,15,4,0,177,33,1,0,0,0,178,179,
  	5,125,0,0,179,180,6,16,5,0,180,35,1,0,0,0,181,182,5,58,0,0,182,37,1,0,
  	0,0,183,184,5,59,0,0,184,39,1,0,0,0,185,186,5,44,0,0,186,41,1,0,0,0,187,
  	188,3,38,18,0,188,43,1,0,0,0,189,190,5,61,0,0,190,45,1,0,0,0,191,192,
  	5,33,0,0,192,193,5,61,0,0,193,47,1,0,0,0,194,195,5,60,0,0,195,196,5,61,
  	0,0,196,49,1,0,0,0,197,198,5,60,0,0,198,51,1,0,0,0,199,200,5,61,0,0,200,
  	201,5,61,0,0,201,53,1,0,0,0,202,203,5,62,0,0,203,55,1,0,0,0,204,205,5,
  	62,0,0,205,206,5,61,0,0,206,57,1,0,0,0,207,208,5,38,0,0,208,209,5,38,
  	0,0,209,59,1,0,0,0,210,211,5,124,0,0,211,212,5,124,0,0,212,61,1,0,0,0,
  	213,214,5,43,0,0,214,63,1,0,0,0,215,216,5,45,0,0,216,65,1,0,0,0,217,218,
  	5,42,0,0,218,67,1,0,0,0,219,220,5,47,0,0,220,69,1,0,0,0,221,222,5,42,
  	0,0,222,223,5,42,0,0,223,71,1,0,0,0,224,225,5,43,0,0,225,226,5,43,0,0,
  	226,73,1,0,0,0,227,228,5,45,0,0,228,229,5,45,0,0,229,75,1,0,0,0,230,231,
  	5,46,0,0,231,77,1,0,0,0,232,233,5,46,0,0,233,234,5,46,0,0,234,235,5,46,
  	0,0,235,79,1,0,0,0,236,240,5,35,0,0,237,239,8,0,0,0,238,237,1,0,0,0,239,
  	242,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,241,243,1,0,0,0,242,240,1,
  	0,0,0,243,244,6,39,6,0,244,81,1,0,0,0,245,246,5,47,0,0,246,247,5,42,0,
  	0,247,248,1,0,0,0,248,249,6,40,7,0,249,250,6,40,6,0,250,83,1,0,0,0,251,
  	252,5,116,0,0,252,253,5,114,0,0,253,254,5,117,0,0,254,255,5,101,0,0,255,
  	85,1,0,0,0,256,257,5,102,0,0,257,258,5,97,0,0,258,259,5,108,0,0,259,260,
  	5,115,0,0,260,261,5,101,0,0,261,87,1,0,0,0,262,263,5,78,0,0,263,264,5,
  	111,0,0,264,265,5,110,0,0,265,266,5,101,0,0,266,89,1,0,0,0,267,269,7,
  	1,0,0,268,267,1,0,0,0,269,270,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,
  	271,275,1,0,0,0,272,274,7,2,0,0,273,272,1,0,0,0,274,277,1,0,0,0,275,273,
  	1,0,0,0,275,276,1,0,0,0,276,91,1,0,0,0,277,275,1,0,0,0,278,280,5,45,0,
  	0,279,278,1,0,0,0,279,280,1,0,0,0,280,282,1,0,0,0,281,283,7,3,0,0,282,
  	281,1,0,0,0,283,284,1,0,0,0,284,282,1,0,0,0,284,285,1,0,0,0,285,93,1,
  	0,0,0,286,288,3,92,45,0,287,286,1,0,0,0,287,288,1,0,0,0,288,289,1,0,0,
  	0,289,291,5,46,0,0,290,292,7,3,0,0,291,290,1,0,0,0,292,293,1,0,0,0,293,
  	291,1,0,0,0,293,294,1,0,0,0,294,95,1,0,0,0,295,297,5,34,0,0,296,298,8,
  	4,0,0,297,296,1,0,0,0,298,299,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,
  	300,301,1,0,0,0,301,302,5,34,0,0,302,97,1,0,0,0,303,304,4,48,0,0,304,
  	316,3,100,49,0,305,307,5,13,0,0,306,305,1,0,0,0,306,307,1,0,0,0,307,308,
  	1,0,0,0,308,311,5,10,0,0,309,311,2,12,13,0,310,306,1,0,0,0,310,309,1,
  	0,0,0,311,313,1,0,0,0,312,314,3,100,49,0,313,312,1,0,0,0,313,314,1,0,
  	0,0,314,316,1,0,0,0,315,303,1,0,0,0,315,310,1,0,0,0,316,317,1,0,0,0,317,
  	318,6,48,8,0,318,99,1,0,0,0,319,321,7,5,0,0,320,319,1,0,0,0,321,322,1,
  	0,0,0,322,320,1,0,0,0,322,323,1,0,0,0,323,324,1,0,0,0,324,325,6,49,9,
  	0,325,101,1,0,0,0,326,327,5,42,0,0,327,328,5,47,0,0,328,329,1,0,0,0,329,
  	330,6,50,10,0,330,331,6,50,6,0,331,103,1,0,0,0,332,333,9,0,0,0,333,334,
  	1,0,0,0,334,335,6,51,6,0,335,105,1,0,0,0,17,0,1,240,268,270,273,275,279,
  	284,287,293,299,306,310,313,315,322,11,1,11,0,1,12,1,1,13,2,1,14,3,1,
  	15,4,1,16,5,6,0,0,5,1,0,1,48,6,0,1,0,4,0,0
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
    case 11: SYM_LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: SYM_RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: SYM_LSQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: SYM_RSQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: SYM_LBRAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: SYM_RBRAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 48: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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
