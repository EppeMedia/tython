
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
      "SYM_COMMA", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", "SYM_PLUS_EQ", "SYM_MINUS_EQ", 
      "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", 
      "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", 
      "SYM_INC", "SYM_DEC", "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", 
      "TRUE_LIT", "FALSE_LIT", "NONE_LIT", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", 
      "STR_LIT", "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
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
      "'['", "']'", "'{'", "'}'", "':'", "';'", "','", "", "'='", "'+='", 
      "'-='", "'!='", "'<='", "'<'", "'=='", "'>'", "'>='", "'&&'", "'||'", 
      "'+'", "'-'", "'*'", "'/'", "'**'", "'++'", "'--'", "'.'", "'...'", 
      "", "'/*'", "'true'", "'false'", "'None'", "", "", "", "", "", "", 
      "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_FOR", "KW_IN", "KW_WHILE", "KW_BREAK", "KW_EXTERN", "KW_IMPORT", 
      "KW_SELF", "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", "SYM_LBR", 
      "SYM_RBR", "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", 
      "SYM_ASSIGN", "SYM_PLUS_EQ", "SYM_MINUS_EQ", "SYM_NEQ", "SYM_LTE", 
      "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", 
      "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", "SYM_INC", "SYM_DEC", 
      "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "TRUE_LIT", 
      "FALSE_LIT", "NONE_LIT", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", 
      "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,56,357,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,
  	48,2,49,7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,1,0,1,0,1,0,1,0,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,
  	15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,
  	21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,
  	26,1,26,1,27,1,27,1,27,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,
  	31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,36,1,37,1,
  	37,1,37,1,38,1,38,1,38,1,39,1,39,1,40,1,40,1,40,1,40,1,41,1,41,5,41,249,
  	8,41,10,41,12,41,252,9,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,42,1,43,
  	1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,45,
  	1,45,1,46,4,46,279,8,46,11,46,12,46,280,1,46,5,46,284,8,46,10,46,12,46,
  	287,9,46,1,47,3,47,290,8,47,1,47,4,47,293,8,47,11,47,12,47,294,1,48,3,
  	48,298,8,48,1,48,1,48,4,48,302,8,48,11,48,12,48,303,3,48,306,8,48,1,48,
  	1,48,1,48,4,48,311,8,48,11,48,12,48,312,3,48,315,8,48,1,49,1,49,4,49,
  	319,8,49,11,49,12,49,320,1,49,1,49,1,50,1,50,1,50,3,50,328,8,50,1,50,
  	1,50,3,50,332,8,50,1,50,3,50,335,8,50,3,50,337,8,50,1,50,1,50,1,51,4,
  	51,342,8,51,11,51,12,51,343,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,52,1,
  	53,1,53,1,53,1,53,0,0,54,2,3,4,4,6,5,8,6,10,7,12,8,14,9,16,10,18,11,20,
  	12,22,13,24,14,26,15,28,16,30,17,32,18,34,19,36,20,38,21,40,22,42,23,
  	44,24,46,25,48,26,50,27,52,28,54,29,56,30,58,31,60,32,62,33,64,34,66,
  	35,68,36,70,37,72,38,74,39,76,40,78,41,80,42,82,43,84,44,86,45,88,46,
  	90,47,92,48,94,49,96,50,98,51,100,52,102,53,104,54,106,55,108,56,2,0,
  	1,7,2,0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,
  	1,0,48,57,2,0,43,43,45,45,1,0,34,34,2,0,9,9,32,32,371,0,2,1,0,0,0,0,4,
  	1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,0,0,10,1,0,0,0,0,12,1,0,0,0,0,14,1,0,0,
  	0,0,16,1,0,0,0,0,18,1,0,0,0,0,20,1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,0,
  	26,1,0,0,0,0,28,1,0,0,0,0,30,1,0,0,0,0,32,1,0,0,0,0,34,1,0,0,0,0,36,1,
  	0,0,0,0,38,1,0,0,0,0,40,1,0,0,0,0,42,1,0,0,0,0,44,1,0,0,0,0,46,1,0,0,
  	0,0,48,1,0,0,0,0,50,1,0,0,0,0,52,1,0,0,0,0,54,1,0,0,0,0,56,1,0,0,0,0,
  	58,1,0,0,0,0,60,1,0,0,0,0,62,1,0,0,0,0,64,1,0,0,0,0,66,1,0,0,0,0,68,1,
  	0,0,0,0,70,1,0,0,0,0,72,1,0,0,0,0,74,1,0,0,0,0,76,1,0,0,0,0,78,1,0,0,
  	0,0,80,1,0,0,0,0,82,1,0,0,0,0,84,1,0,0,0,0,86,1,0,0,0,0,88,1,0,0,0,0,
  	90,1,0,0,0,0,92,1,0,0,0,0,94,1,0,0,0,0,96,1,0,0,0,0,98,1,0,0,0,0,100,
  	1,0,0,0,0,102,1,0,0,0,0,104,1,0,0,0,1,106,1,0,0,0,1,108,1,0,0,0,2,110,
  	1,0,0,0,4,114,1,0,0,0,6,121,1,0,0,0,8,124,1,0,0,0,10,129,1,0,0,0,12,133,
  	1,0,0,0,14,136,1,0,0,0,16,142,1,0,0,0,18,148,1,0,0,0,20,155,1,0,0,0,22,
  	162,1,0,0,0,24,167,1,0,0,0,26,170,1,0,0,0,28,173,1,0,0,0,30,176,1,0,0,
  	0,32,179,1,0,0,0,34,182,1,0,0,0,36,185,1,0,0,0,38,187,1,0,0,0,40,189,
  	1,0,0,0,42,191,1,0,0,0,44,193,1,0,0,0,46,195,1,0,0,0,48,198,1,0,0,0,50,
  	201,1,0,0,0,52,204,1,0,0,0,54,207,1,0,0,0,56,209,1,0,0,0,58,212,1,0,0,
  	0,60,214,1,0,0,0,62,217,1,0,0,0,64,220,1,0,0,0,66,223,1,0,0,0,68,225,
  	1,0,0,0,70,227,1,0,0,0,72,229,1,0,0,0,74,231,1,0,0,0,76,234,1,0,0,0,78,
  	237,1,0,0,0,80,240,1,0,0,0,82,242,1,0,0,0,84,246,1,0,0,0,86,255,1,0,0,
  	0,88,261,1,0,0,0,90,266,1,0,0,0,92,272,1,0,0,0,94,278,1,0,0,0,96,289,
  	1,0,0,0,98,297,1,0,0,0,100,316,1,0,0,0,102,336,1,0,0,0,104,341,1,0,0,
  	0,106,347,1,0,0,0,108,353,1,0,0,0,110,111,5,100,0,0,111,112,5,101,0,0,
  	112,113,5,102,0,0,113,3,1,0,0,0,114,115,5,114,0,0,115,116,5,101,0,0,116,
  	117,5,116,0,0,117,118,5,117,0,0,118,119,5,114,0,0,119,120,5,110,0,0,120,
  	5,1,0,0,0,121,122,5,105,0,0,122,123,5,102,0,0,123,7,1,0,0,0,124,125,5,
  	101,0,0,125,126,5,108,0,0,126,127,5,115,0,0,127,128,5,101,0,0,128,9,1,
  	0,0,0,129,130,5,102,0,0,130,131,5,111,0,0,131,132,5,114,0,0,132,11,1,
  	0,0,0,133,134,5,105,0,0,134,135,5,110,0,0,135,13,1,0,0,0,136,137,5,119,
  	0,0,137,138,5,104,0,0,138,139,5,105,0,0,139,140,5,108,0,0,140,141,5,101,
  	0,0,141,15,1,0,0,0,142,143,5,98,0,0,143,144,5,114,0,0,144,145,5,101,0,
  	0,145,146,5,97,0,0,146,147,5,107,0,0,147,17,1,0,0,0,148,149,5,101,0,0,
  	149,150,5,120,0,0,150,151,5,116,0,0,151,152,5,101,0,0,152,153,5,114,0,
  	0,153,154,5,110,0,0,154,19,1,0,0,0,155,156,5,105,0,0,156,157,5,109,0,
  	0,157,158,5,112,0,0,158,159,5,111,0,0,159,160,5,114,0,0,160,161,5,116,
  	0,0,161,21,1,0,0,0,162,163,5,115,0,0,163,164,5,101,0,0,164,165,5,108,
  	0,0,165,166,5,102,0,0,166,23,1,0,0,0,167,168,5,40,0,0,168,169,6,11,0,
  	0,169,25,1,0,0,0,170,171,5,41,0,0,171,172,6,12,1,0,172,27,1,0,0,0,173,
  	174,5,91,0,0,174,175,6,13,2,0,175,29,1,0,0,0,176,177,5,93,0,0,177,178,
  	6,14,3,0,178,31,1,0,0,0,179,180,5,123,0,0,180,181,6,15,4,0,181,33,1,0,
  	0,0,182,183,5,125,0,0,183,184,6,16,5,0,184,35,1,0,0,0,185,186,5,58,0,
  	0,186,37,1,0,0,0,187,188,5,59,0,0,188,39,1,0,0,0,189,190,5,44,0,0,190,
  	41,1,0,0,0,191,192,3,38,18,0,192,43,1,0,0,0,193,194,5,61,0,0,194,45,1,
  	0,0,0,195,196,5,43,0,0,196,197,5,61,0,0,197,47,1,0,0,0,198,199,5,45,0,
  	0,199,200,5,61,0,0,200,49,1,0,0,0,201,202,5,33,0,0,202,203,5,61,0,0,203,
  	51,1,0,0,0,204,205,5,60,0,0,205,206,5,61,0,0,206,53,1,0,0,0,207,208,5,
  	60,0,0,208,55,1,0,0,0,209,210,5,61,0,0,210,211,5,61,0,0,211,57,1,0,0,
  	0,212,213,5,62,0,0,213,59,1,0,0,0,214,215,5,62,0,0,215,216,5,61,0,0,216,
  	61,1,0,0,0,217,218,5,38,0,0,218,219,5,38,0,0,219,63,1,0,0,0,220,221,5,
  	124,0,0,221,222,5,124,0,0,222,65,1,0,0,0,223,224,5,43,0,0,224,67,1,0,
  	0,0,225,226,5,45,0,0,226,69,1,0,0,0,227,228,5,42,0,0,228,71,1,0,0,0,229,
  	230,5,47,0,0,230,73,1,0,0,0,231,232,5,42,0,0,232,233,5,42,0,0,233,75,
  	1,0,0,0,234,235,5,43,0,0,235,236,5,43,0,0,236,77,1,0,0,0,237,238,5,45,
  	0,0,238,239,5,45,0,0,239,79,1,0,0,0,240,241,5,46,0,0,241,81,1,0,0,0,242,
  	243,5,46,0,0,243,244,5,46,0,0,244,245,5,46,0,0,245,83,1,0,0,0,246,250,
  	5,35,0,0,247,249,8,0,0,0,248,247,1,0,0,0,249,252,1,0,0,0,250,248,1,0,
  	0,0,250,251,1,0,0,0,251,253,1,0,0,0,252,250,1,0,0,0,253,254,6,41,6,0,
  	254,85,1,0,0,0,255,256,5,47,0,0,256,257,5,42,0,0,257,258,1,0,0,0,258,
  	259,6,42,7,0,259,260,6,42,6,0,260,87,1,0,0,0,261,262,5,116,0,0,262,263,
  	5,114,0,0,263,264,5,117,0,0,264,265,5,101,0,0,265,89,1,0,0,0,266,267,
  	5,102,0,0,267,268,5,97,0,0,268,269,5,108,0,0,269,270,5,115,0,0,270,271,
  	5,101,0,0,271,91,1,0,0,0,272,273,5,78,0,0,273,274,5,111,0,0,274,275,5,
  	110,0,0,275,276,5,101,0,0,276,93,1,0,0,0,277,279,7,1,0,0,278,277,1,0,
  	0,0,279,280,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,285,1,0,0,0,282,
  	284,7,2,0,0,283,282,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,286,1,
  	0,0,0,286,95,1,0,0,0,287,285,1,0,0,0,288,290,5,45,0,0,289,288,1,0,0,0,
  	289,290,1,0,0,0,290,292,1,0,0,0,291,293,7,3,0,0,292,291,1,0,0,0,293,294,
  	1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,97,1,0,0,0,296,298,3,96,47,
  	0,297,296,1,0,0,0,297,298,1,0,0,0,298,299,1,0,0,0,299,305,5,46,0,0,300,
  	302,7,3,0,0,301,300,1,0,0,0,302,303,1,0,0,0,303,301,1,0,0,0,303,304,1,
  	0,0,0,304,306,1,0,0,0,305,301,1,0,0,0,305,306,1,0,0,0,306,314,1,0,0,0,
  	307,308,5,101,0,0,308,310,7,4,0,0,309,311,7,3,0,0,310,309,1,0,0,0,311,
  	312,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,315,1,0,0,0,314,307,1,
  	0,0,0,314,315,1,0,0,0,315,99,1,0,0,0,316,318,5,34,0,0,317,319,8,5,0,0,
  	318,317,1,0,0,0,319,320,1,0,0,0,320,318,1,0,0,0,320,321,1,0,0,0,321,322,
  	1,0,0,0,322,323,5,34,0,0,323,101,1,0,0,0,324,325,4,50,0,0,325,337,3,104,
  	51,0,326,328,5,13,0,0,327,326,1,0,0,0,327,328,1,0,0,0,328,329,1,0,0,0,
  	329,332,5,10,0,0,330,332,2,12,13,0,331,327,1,0,0,0,331,330,1,0,0,0,332,
  	334,1,0,0,0,333,335,3,104,51,0,334,333,1,0,0,0,334,335,1,0,0,0,335,337,
  	1,0,0,0,336,324,1,0,0,0,336,331,1,0,0,0,337,338,1,0,0,0,338,339,6,50,
  	8,0,339,103,1,0,0,0,340,342,7,6,0,0,341,340,1,0,0,0,342,343,1,0,0,0,343,
  	341,1,0,0,0,343,344,1,0,0,0,344,345,1,0,0,0,345,346,6,51,9,0,346,105,
  	1,0,0,0,347,348,5,42,0,0,348,349,5,47,0,0,349,350,1,0,0,0,350,351,6,52,
  	10,0,351,352,6,52,6,0,352,107,1,0,0,0,353,354,9,0,0,0,354,355,1,0,0,0,
  	355,356,6,53,6,0,356,109,1,0,0,0,20,0,1,250,278,280,283,285,289,294,297,
  	303,305,312,314,320,327,331,334,336,343,11,1,11,0,1,12,1,1,13,2,1,14,
  	3,1,15,4,1,16,5,6,0,0,5,1,0,1,50,6,0,1,0,4,0,0
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
    case 50: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 50: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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
