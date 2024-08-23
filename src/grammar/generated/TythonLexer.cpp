
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
      "KW_BREAK", "KW_EXTERN", "KW_IMPORT", "KW_SELF", "KW_EWOUT", "SYM_LPAR", 
      "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", "SYM_LBR", "SYM_RBR", "SYM_COL", 
      "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", "SYM_ASSIGN", "SYM_PLUS_EQ", 
      "SYM_MINUS_EQ", "SYM_NEQ", "SYM_LTE", "SYM_LT", "SYM_EQ", "SYM_GT", 
      "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", "SYM_MINUS", "SYM_MULT", 
      "SYM_DIV", "SYM_FLOOR_DIV", "SYM_EXP", "SYM_MOD", "SYM_INC", "SYM_DEC", 
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
      "'while'", "'break'", "'extern'", "'import'", "'self'", "'ewout'", 
      "'('", "')'", "'['", "']'", "'{'", "'}'", "':'", "';'", "','", "", 
      "'='", "'+='", "'-='", "'!='", "'<='", "'<'", "'=='", "'>'", "'>='", 
      "'&&'", "'||'", "'+'", "'-'", "'*'", "'/'", "'//'", "'**'", "'%'", 
      "'++'", "'--'", "'.'", "'...'", "", "'/*'", "'True'", "'False'", "'None'", 
      "", "", "", "", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_FOR", "KW_IN", "KW_WHILE", "KW_BREAK", "KW_EXTERN", "KW_IMPORT", 
      "KW_SELF", "KW_EWOUT", "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", 
      "SYM_LBR", "SYM_RBR", "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", 
      "SYM_ASSIGN", "SYM_PLUS_EQ", "SYM_MINUS_EQ", "SYM_NEQ", "SYM_LTE", 
      "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", 
      "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_FLOOR_DIV", "SYM_EXP", "SYM_MOD", 
      "SYM_INC", "SYM_DEC", "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", 
      "TRUE_LIT", "FALSE_LIT", "NONE_LIT", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", 
      "STR_LIT", "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,59,374,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,
  	48,2,49,7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,
  	55,2,56,7,56,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,
  	16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,
  	23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,
  	28,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,
  	33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,
  	39,1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,43,1,43,1,43,1,43,1,
  	44,1,44,5,44,266,8,44,10,44,12,44,269,9,44,1,44,1,44,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,47,1,
  	48,1,48,1,48,1,48,1,48,1,49,4,49,296,8,49,11,49,12,49,297,1,49,5,49,301,
  	8,49,10,49,12,49,304,9,49,1,50,3,50,307,8,50,1,50,4,50,310,8,50,11,50,
  	12,50,311,1,51,3,51,315,8,51,1,51,1,51,4,51,319,8,51,11,51,12,51,320,
  	3,51,323,8,51,1,51,1,51,1,51,4,51,328,8,51,11,51,12,51,329,3,51,332,8,
  	51,1,52,1,52,4,52,336,8,52,11,52,12,52,337,1,52,1,52,1,53,1,53,1,53,3,
  	53,345,8,53,1,53,1,53,3,53,349,8,53,1,53,3,53,352,8,53,3,53,354,8,53,
  	1,53,1,53,1,54,4,54,359,8,54,11,54,12,54,360,1,54,1,54,1,55,1,55,1,55,
  	1,55,1,55,1,55,1,56,1,56,1,56,1,56,0,0,57,2,3,4,4,6,5,8,6,10,7,12,8,14,
  	9,16,10,18,11,20,12,22,13,24,14,26,15,28,16,30,17,32,18,34,19,36,20,38,
  	21,40,22,42,23,44,24,46,25,48,26,50,27,52,28,54,29,56,30,58,31,60,32,
  	62,33,64,34,66,35,68,36,70,37,72,38,74,39,76,40,78,41,80,42,82,43,84,
  	44,86,45,88,46,90,47,92,48,94,49,96,50,98,51,100,52,102,53,104,54,106,
  	55,108,56,110,57,112,58,114,59,2,0,1,7,2,0,10,10,13,13,3,0,65,90,95,95,
  	97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,2,0,43,43,45,45,1,0,34,
  	34,2,0,9,9,32,32,388,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,0,
  	0,10,1,0,0,0,0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,18,1,0,0,0,0,20,
  	1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,1,0,0,0,0,30,1,0,
  	0,0,0,32,1,0,0,0,0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,0,0,0,40,1,0,0,0,
  	0,42,1,0,0,0,0,44,1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,0,50,1,0,0,0,0,52,
  	1,0,0,0,0,54,1,0,0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,1,0,0,0,0,62,1,0,
  	0,0,0,64,1,0,0,0,0,66,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,0,0,
  	0,74,1,0,0,0,0,76,1,0,0,0,0,78,1,0,0,0,0,80,1,0,0,0,0,82,1,0,0,0,0,84,
  	1,0,0,0,0,86,1,0,0,0,0,88,1,0,0,0,0,90,1,0,0,0,0,92,1,0,0,0,0,94,1,0,
  	0,0,0,96,1,0,0,0,0,98,1,0,0,0,0,100,1,0,0,0,0,102,1,0,0,0,0,104,1,0,0,
  	0,0,106,1,0,0,0,0,108,1,0,0,0,0,110,1,0,0,0,1,112,1,0,0,0,1,114,1,0,0,
  	0,2,116,1,0,0,0,4,120,1,0,0,0,6,127,1,0,0,0,8,130,1,0,0,0,10,135,1,0,
  	0,0,12,139,1,0,0,0,14,142,1,0,0,0,16,148,1,0,0,0,18,154,1,0,0,0,20,161,
  	1,0,0,0,22,168,1,0,0,0,24,173,1,0,0,0,26,179,1,0,0,0,28,182,1,0,0,0,30,
  	185,1,0,0,0,32,188,1,0,0,0,34,191,1,0,0,0,36,194,1,0,0,0,38,197,1,0,0,
  	0,40,199,1,0,0,0,42,201,1,0,0,0,44,203,1,0,0,0,46,205,1,0,0,0,48,207,
  	1,0,0,0,50,210,1,0,0,0,52,213,1,0,0,0,54,216,1,0,0,0,56,219,1,0,0,0,58,
  	221,1,0,0,0,60,224,1,0,0,0,62,226,1,0,0,0,64,229,1,0,0,0,66,232,1,0,0,
  	0,68,235,1,0,0,0,70,237,1,0,0,0,72,239,1,0,0,0,74,241,1,0,0,0,76,243,
  	1,0,0,0,78,246,1,0,0,0,80,249,1,0,0,0,82,251,1,0,0,0,84,254,1,0,0,0,86,
  	257,1,0,0,0,88,259,1,0,0,0,90,263,1,0,0,0,92,272,1,0,0,0,94,278,1,0,0,
  	0,96,283,1,0,0,0,98,289,1,0,0,0,100,295,1,0,0,0,102,306,1,0,0,0,104,314,
  	1,0,0,0,106,333,1,0,0,0,108,353,1,0,0,0,110,358,1,0,0,0,112,364,1,0,0,
  	0,114,370,1,0,0,0,116,117,5,100,0,0,117,118,5,101,0,0,118,119,5,102,0,
  	0,119,3,1,0,0,0,120,121,5,114,0,0,121,122,5,101,0,0,122,123,5,116,0,0,
  	123,124,5,117,0,0,124,125,5,114,0,0,125,126,5,110,0,0,126,5,1,0,0,0,127,
  	128,5,105,0,0,128,129,5,102,0,0,129,7,1,0,0,0,130,131,5,101,0,0,131,132,
  	5,108,0,0,132,133,5,115,0,0,133,134,5,101,0,0,134,9,1,0,0,0,135,136,5,
  	102,0,0,136,137,5,111,0,0,137,138,5,114,0,0,138,11,1,0,0,0,139,140,5,
  	105,0,0,140,141,5,110,0,0,141,13,1,0,0,0,142,143,5,119,0,0,143,144,5,
  	104,0,0,144,145,5,105,0,0,145,146,5,108,0,0,146,147,5,101,0,0,147,15,
  	1,0,0,0,148,149,5,98,0,0,149,150,5,114,0,0,150,151,5,101,0,0,151,152,
  	5,97,0,0,152,153,5,107,0,0,153,17,1,0,0,0,154,155,5,101,0,0,155,156,5,
  	120,0,0,156,157,5,116,0,0,157,158,5,101,0,0,158,159,5,114,0,0,159,160,
  	5,110,0,0,160,19,1,0,0,0,161,162,5,105,0,0,162,163,5,109,0,0,163,164,
  	5,112,0,0,164,165,5,111,0,0,165,166,5,114,0,0,166,167,5,116,0,0,167,21,
  	1,0,0,0,168,169,5,115,0,0,169,170,5,101,0,0,170,171,5,108,0,0,171,172,
  	5,102,0,0,172,23,1,0,0,0,173,174,5,101,0,0,174,175,5,119,0,0,175,176,
  	5,111,0,0,176,177,5,117,0,0,177,178,5,116,0,0,178,25,1,0,0,0,179,180,
  	5,40,0,0,180,181,6,12,0,0,181,27,1,0,0,0,182,183,5,41,0,0,183,184,6,13,
  	1,0,184,29,1,0,0,0,185,186,5,91,0,0,186,187,6,14,2,0,187,31,1,0,0,0,188,
  	189,5,93,0,0,189,190,6,15,3,0,190,33,1,0,0,0,191,192,5,123,0,0,192,193,
  	6,16,4,0,193,35,1,0,0,0,194,195,5,125,0,0,195,196,6,17,5,0,196,37,1,0,
  	0,0,197,198,5,58,0,0,198,39,1,0,0,0,199,200,5,59,0,0,200,41,1,0,0,0,201,
  	202,5,44,0,0,202,43,1,0,0,0,203,204,3,40,19,0,204,45,1,0,0,0,205,206,
  	5,61,0,0,206,47,1,0,0,0,207,208,5,43,0,0,208,209,5,61,0,0,209,49,1,0,
  	0,0,210,211,5,45,0,0,211,212,5,61,0,0,212,51,1,0,0,0,213,214,5,33,0,0,
  	214,215,5,61,0,0,215,53,1,0,0,0,216,217,5,60,0,0,217,218,5,61,0,0,218,
  	55,1,0,0,0,219,220,5,60,0,0,220,57,1,0,0,0,221,222,5,61,0,0,222,223,5,
  	61,0,0,223,59,1,0,0,0,224,225,5,62,0,0,225,61,1,0,0,0,226,227,5,62,0,
  	0,227,228,5,61,0,0,228,63,1,0,0,0,229,230,5,38,0,0,230,231,5,38,0,0,231,
  	65,1,0,0,0,232,233,5,124,0,0,233,234,5,124,0,0,234,67,1,0,0,0,235,236,
  	5,43,0,0,236,69,1,0,0,0,237,238,5,45,0,0,238,71,1,0,0,0,239,240,5,42,
  	0,0,240,73,1,0,0,0,241,242,5,47,0,0,242,75,1,0,0,0,243,244,5,47,0,0,244,
  	245,5,47,0,0,245,77,1,0,0,0,246,247,5,42,0,0,247,248,5,42,0,0,248,79,
  	1,0,0,0,249,250,5,37,0,0,250,81,1,0,0,0,251,252,5,43,0,0,252,253,5,43,
  	0,0,253,83,1,0,0,0,254,255,5,45,0,0,255,256,5,45,0,0,256,85,1,0,0,0,257,
  	258,5,46,0,0,258,87,1,0,0,0,259,260,5,46,0,0,260,261,5,46,0,0,261,262,
  	5,46,0,0,262,89,1,0,0,0,263,267,5,35,0,0,264,266,8,0,0,0,265,264,1,0,
  	0,0,266,269,1,0,0,0,267,265,1,0,0,0,267,268,1,0,0,0,268,270,1,0,0,0,269,
  	267,1,0,0,0,270,271,6,44,6,0,271,91,1,0,0,0,272,273,5,47,0,0,273,274,
  	5,42,0,0,274,275,1,0,0,0,275,276,6,45,7,0,276,277,6,45,6,0,277,93,1,0,
  	0,0,278,279,5,84,0,0,279,280,5,114,0,0,280,281,5,117,0,0,281,282,5,101,
  	0,0,282,95,1,0,0,0,283,284,5,70,0,0,284,285,5,97,0,0,285,286,5,108,0,
  	0,286,287,5,115,0,0,287,288,5,101,0,0,288,97,1,0,0,0,289,290,5,78,0,0,
  	290,291,5,111,0,0,291,292,5,110,0,0,292,293,5,101,0,0,293,99,1,0,0,0,
  	294,296,7,1,0,0,295,294,1,0,0,0,296,297,1,0,0,0,297,295,1,0,0,0,297,298,
  	1,0,0,0,298,302,1,0,0,0,299,301,7,2,0,0,300,299,1,0,0,0,301,304,1,0,0,
  	0,302,300,1,0,0,0,302,303,1,0,0,0,303,101,1,0,0,0,304,302,1,0,0,0,305,
  	307,5,45,0,0,306,305,1,0,0,0,306,307,1,0,0,0,307,309,1,0,0,0,308,310,
  	7,3,0,0,309,308,1,0,0,0,310,311,1,0,0,0,311,309,1,0,0,0,311,312,1,0,0,
  	0,312,103,1,0,0,0,313,315,3,102,50,0,314,313,1,0,0,0,314,315,1,0,0,0,
  	315,316,1,0,0,0,316,322,5,46,0,0,317,319,7,3,0,0,318,317,1,0,0,0,319,
  	320,1,0,0,0,320,318,1,0,0,0,320,321,1,0,0,0,321,323,1,0,0,0,322,318,1,
  	0,0,0,322,323,1,0,0,0,323,331,1,0,0,0,324,325,5,101,0,0,325,327,7,4,0,
  	0,326,328,7,3,0,0,327,326,1,0,0,0,328,329,1,0,0,0,329,327,1,0,0,0,329,
  	330,1,0,0,0,330,332,1,0,0,0,331,324,1,0,0,0,331,332,1,0,0,0,332,105,1,
  	0,0,0,333,335,5,34,0,0,334,336,8,5,0,0,335,334,1,0,0,0,336,337,1,0,0,
  	0,337,335,1,0,0,0,337,338,1,0,0,0,338,339,1,0,0,0,339,340,5,34,0,0,340,
  	107,1,0,0,0,341,342,4,53,0,0,342,354,3,110,54,0,343,345,5,13,0,0,344,
  	343,1,0,0,0,344,345,1,0,0,0,345,346,1,0,0,0,346,349,5,10,0,0,347,349,
  	2,12,13,0,348,344,1,0,0,0,348,347,1,0,0,0,349,351,1,0,0,0,350,352,3,110,
  	54,0,351,350,1,0,0,0,351,352,1,0,0,0,352,354,1,0,0,0,353,341,1,0,0,0,
  	353,348,1,0,0,0,354,355,1,0,0,0,355,356,6,53,8,0,356,109,1,0,0,0,357,
  	359,7,6,0,0,358,357,1,0,0,0,359,360,1,0,0,0,360,358,1,0,0,0,360,361,1,
  	0,0,0,361,362,1,0,0,0,362,363,6,54,9,0,363,111,1,0,0,0,364,365,5,42,0,
  	0,365,366,5,47,0,0,366,367,1,0,0,0,367,368,6,55,10,0,368,369,6,55,6,0,
  	369,113,1,0,0,0,370,371,9,0,0,0,371,372,1,0,0,0,372,373,6,56,6,0,373,
  	115,1,0,0,0,20,0,1,267,295,297,300,302,306,311,314,320,322,329,331,337,
  	344,348,351,353,360,11,1,12,0,1,13,1,1,14,2,1,15,3,1,16,4,1,17,5,6,0,
  	0,5,1,0,1,53,6,0,1,0,4,0,0
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
    case 12: SYM_LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: SYM_RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: SYM_LSQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: SYM_RSQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: SYM_LBRAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: SYM_RBRAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool TythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 53: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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
