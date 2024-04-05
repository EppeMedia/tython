
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
      "assign_statement", "break_statement", "return_statement", "if_statement", 
      "for_loop", "while_loop", "arguments", "parameters", "call_expression", 
      "expression", "lval", "key_value_pair", "dict_lit", "list_lit", "tuple_lit", 
      "slice_lit", "literal"
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
  	4,1,56,370,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,5,0,54,8,0,10,0,12,0,57,
  	9,0,1,0,4,0,60,8,0,11,0,12,0,61,1,0,1,0,1,1,1,1,1,1,3,1,69,8,1,1,1,1,
  	1,1,2,1,2,1,2,5,2,76,8,2,10,2,12,2,79,9,2,1,3,1,3,3,3,83,8,3,1,3,1,3,
  	1,3,1,3,3,3,89,8,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,4,4,99,8,4,11,4,12,
  	4,100,1,4,1,4,3,4,105,8,4,1,5,1,5,3,5,109,8,5,1,6,1,6,1,6,1,6,3,6,115,
  	8,6,1,7,1,7,1,7,5,7,120,8,7,10,7,12,7,123,9,7,1,7,3,7,126,8,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,3,8,134,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,3,9,148,8,9,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,3,12,163,8,12,3,12,165,8,12,1,13,1,13,1,13,3,13,170,8,13,
  	1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,3,15,182,8,15,1,15,
  	1,15,1,15,4,15,187,8,15,11,15,12,15,188,3,15,191,8,15,1,16,3,16,194,8,
  	16,1,16,1,16,1,16,4,16,199,8,16,11,16,12,16,200,3,16,203,8,16,1,17,3,
  	17,206,8,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,3,18,225,8,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,283,8,18,10,18,12,18,
  	286,9,18,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,3,21,296,8,21,1,21,3,
  	21,299,8,21,1,21,1,21,4,21,303,8,21,11,21,12,21,304,3,21,307,8,21,1,21,
  	3,21,310,8,21,1,21,1,21,1,22,1,22,3,22,316,8,22,1,22,3,22,319,8,22,1,
  	22,1,22,4,22,323,8,22,11,22,12,22,324,3,22,327,8,22,1,22,1,22,1,23,1,
  	23,3,23,333,8,23,1,23,3,23,336,8,23,1,23,1,23,4,23,340,8,23,11,23,12,
  	23,341,3,23,344,8,23,1,23,1,23,1,24,3,24,349,8,24,1,24,1,24,3,24,353,
  	8,24,1,24,3,24,356,8,24,1,24,3,24,359,8,24,1,25,1,25,1,25,1,25,1,25,1,
  	25,1,25,3,25,368,8,25,1,25,0,1,36,26,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,0,0,418,0,55,1,0,0,0,2,65,1,0,
  	0,0,4,72,1,0,0,0,6,80,1,0,0,0,8,104,1,0,0,0,10,108,1,0,0,0,12,114,1,0,
  	0,0,14,116,1,0,0,0,16,133,1,0,0,0,18,147,1,0,0,0,20,149,1,0,0,0,22,151,
  	1,0,0,0,24,154,1,0,0,0,26,166,1,0,0,0,28,175,1,0,0,0,30,190,1,0,0,0,32,
  	202,1,0,0,0,34,205,1,0,0,0,36,224,1,0,0,0,38,287,1,0,0,0,40,289,1,0,0,
  	0,42,293,1,0,0,0,44,313,1,0,0,0,46,330,1,0,0,0,48,348,1,0,0,0,50,367,
  	1,0,0,0,52,54,3,2,1,0,53,52,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,
  	1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,58,60,3,10,5,0,59,58,1,0,0,0,60,61,
  	1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,63,1,0,0,0,63,64,5,0,0,1,64,1,
  	1,0,0,0,65,66,5,12,0,0,66,68,3,4,2,0,67,69,5,21,0,0,68,67,1,0,0,0,68,
  	69,1,0,0,0,69,70,1,0,0,0,70,71,5,53,0,0,71,3,1,0,0,0,72,77,5,49,0,0,73,
  	74,5,42,0,0,74,76,5,49,0,0,75,73,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,
  	77,78,1,0,0,0,78,5,1,0,0,0,79,77,1,0,0,0,80,82,5,3,0,0,81,83,5,11,0,0,
  	82,81,1,0,0,0,82,83,1,0,0,0,83,84,1,0,0,0,84,85,5,49,0,0,85,86,5,14,0,
  	0,86,88,3,30,15,0,87,89,5,43,0,0,88,87,1,0,0,0,88,89,1,0,0,0,89,90,1,
  	0,0,0,90,91,5,15,0,0,91,92,5,20,0,0,92,93,3,8,4,0,93,7,1,0,0,0,94,105,
  	3,14,7,0,95,96,5,53,0,0,96,98,5,1,0,0,97,99,3,10,5,0,98,97,1,0,0,0,99,
  	100,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,102,1,0,0,0,102,103,5,
  	2,0,0,103,105,1,0,0,0,104,94,1,0,0,0,104,95,1,0,0,0,105,9,1,0,0,0,106,
  	109,3,14,7,0,107,109,3,16,8,0,108,106,1,0,0,0,108,107,1,0,0,0,109,11,
  	1,0,0,0,110,115,3,36,18,0,111,115,3,18,9,0,112,115,3,20,10,0,113,115,
  	3,22,11,0,114,110,1,0,0,0,114,111,1,0,0,0,114,112,1,0,0,0,114,113,1,0,
  	0,0,115,13,1,0,0,0,116,121,3,12,6,0,117,118,5,21,0,0,118,120,3,12,6,0,
  	119,117,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,125,
  	1,0,0,0,123,121,1,0,0,0,124,126,5,21,0,0,125,124,1,0,0,0,125,126,1,0,
  	0,0,126,127,1,0,0,0,127,128,5,53,0,0,128,15,1,0,0,0,129,134,3,24,12,0,
  	130,134,3,6,3,0,131,134,3,26,13,0,132,134,3,28,14,0,133,129,1,0,0,0,133,
  	130,1,0,0,0,133,131,1,0,0,0,133,132,1,0,0,0,134,17,1,0,0,0,135,136,3,
  	38,19,0,136,137,5,24,0,0,137,138,3,36,18,0,138,148,1,0,0,0,139,140,3,
  	38,19,0,140,141,5,25,0,0,141,142,3,36,18,0,142,148,1,0,0,0,143,144,3,
  	38,19,0,144,145,5,26,0,0,145,146,3,36,18,0,146,148,1,0,0,0,147,135,1,
  	0,0,0,147,139,1,0,0,0,147,143,1,0,0,0,148,19,1,0,0,0,149,150,5,10,0,0,
  	150,21,1,0,0,0,151,152,5,4,0,0,152,153,3,36,18,0,153,23,1,0,0,0,154,155,
  	5,5,0,0,155,156,3,36,18,0,156,157,5,20,0,0,157,164,3,8,4,0,158,162,5,
  	6,0,0,159,163,3,24,12,0,160,161,5,20,0,0,161,163,3,8,4,0,162,159,1,0,
  	0,0,162,160,1,0,0,0,163,165,1,0,0,0,164,158,1,0,0,0,164,165,1,0,0,0,165,
  	25,1,0,0,0,166,169,5,7,0,0,167,168,5,49,0,0,168,170,5,8,0,0,169,167,1,
  	0,0,0,169,170,1,0,0,0,170,171,1,0,0,0,171,172,3,36,18,0,172,173,5,20,
  	0,0,173,174,3,8,4,0,174,27,1,0,0,0,175,176,5,9,0,0,176,177,3,36,18,0,
  	177,178,5,20,0,0,178,179,3,8,4,0,179,29,1,0,0,0,180,182,5,49,0,0,181,
  	180,1,0,0,0,181,182,1,0,0,0,182,191,1,0,0,0,183,186,5,49,0,0,184,185,
  	5,22,0,0,185,187,5,49,0,0,186,184,1,0,0,0,187,188,1,0,0,0,188,186,1,0,
  	0,0,188,189,1,0,0,0,189,191,1,0,0,0,190,181,1,0,0,0,190,183,1,0,0,0,191,
  	31,1,0,0,0,192,194,3,36,18,0,193,192,1,0,0,0,193,194,1,0,0,0,194,203,
  	1,0,0,0,195,198,3,36,18,0,196,197,5,22,0,0,197,199,3,36,18,0,198,196,
  	1,0,0,0,199,200,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,203,1,0,0,
  	0,202,193,1,0,0,0,202,195,1,0,0,0,203,33,1,0,0,0,204,206,5,11,0,0,205,
  	204,1,0,0,0,205,206,1,0,0,0,206,207,1,0,0,0,207,208,5,49,0,0,208,209,
  	5,14,0,0,209,210,3,32,16,0,210,211,5,15,0,0,211,35,1,0,0,0,212,213,6,
  	18,-1,0,213,214,5,14,0,0,214,215,3,36,18,0,215,216,5,15,0,0,216,225,1,
  	0,0,0,217,225,3,34,17,0,218,219,5,40,0,0,219,225,3,36,18,8,220,221,5,
  	41,0,0,221,225,3,36,18,6,222,225,3,50,25,0,223,225,5,49,0,0,224,212,1,
  	0,0,0,224,217,1,0,0,0,224,218,1,0,0,0,224,220,1,0,0,0,224,222,1,0,0,0,
  	224,223,1,0,0,0,225,284,1,0,0,0,226,227,10,21,0,0,227,228,5,39,0,0,228,
  	283,3,36,18,22,229,230,10,20,0,0,230,231,5,37,0,0,231,283,3,36,18,21,
  	232,233,10,19,0,0,233,234,5,38,0,0,234,283,3,36,18,20,235,236,10,18,0,
  	0,236,237,5,35,0,0,237,283,3,36,18,19,238,239,10,17,0,0,239,240,5,36,
  	0,0,240,283,3,36,18,18,241,242,10,16,0,0,242,243,5,33,0,0,243,283,3,36,
  	18,17,244,245,10,15,0,0,245,246,5,34,0,0,246,283,3,36,18,16,247,248,10,
  	14,0,0,248,249,5,27,0,0,249,283,3,36,18,15,250,251,10,13,0,0,251,252,
  	5,29,0,0,252,283,3,36,18,14,253,254,10,12,0,0,254,255,5,28,0,0,255,283,
  	3,36,18,13,256,257,10,11,0,0,257,258,5,30,0,0,258,283,3,36,18,12,259,
  	260,10,10,0,0,260,261,5,31,0,0,261,283,3,36,18,11,262,263,10,9,0,0,263,
  	264,5,32,0,0,264,283,3,36,18,10,265,266,10,23,0,0,266,267,5,42,0,0,267,
  	283,3,34,17,0,268,269,10,7,0,0,269,283,5,40,0,0,270,271,10,5,0,0,271,
  	283,5,41,0,0,272,273,10,4,0,0,273,274,5,16,0,0,274,275,3,48,24,0,275,
  	276,5,17,0,0,276,283,1,0,0,0,277,278,10,3,0,0,278,279,5,16,0,0,279,280,
  	3,36,18,0,280,281,5,17,0,0,281,283,1,0,0,0,282,226,1,0,0,0,282,229,1,
  	0,0,0,282,232,1,0,0,0,282,235,1,0,0,0,282,238,1,0,0,0,282,241,1,0,0,0,
  	282,244,1,0,0,0,282,247,1,0,0,0,282,250,1,0,0,0,282,253,1,0,0,0,282,256,
  	1,0,0,0,282,259,1,0,0,0,282,262,1,0,0,0,282,265,1,0,0,0,282,268,1,0,0,
  	0,282,270,1,0,0,0,282,272,1,0,0,0,282,277,1,0,0,0,283,286,1,0,0,0,284,
  	282,1,0,0,0,284,285,1,0,0,0,285,37,1,0,0,0,286,284,1,0,0,0,287,288,3,
  	36,18,0,288,39,1,0,0,0,289,290,3,36,18,0,290,291,5,20,0,0,291,292,3,36,
  	18,0,292,41,1,0,0,0,293,306,5,18,0,0,294,296,3,40,20,0,295,294,1,0,0,
  	0,295,296,1,0,0,0,296,307,1,0,0,0,297,299,3,40,20,0,298,297,1,0,0,0,298,
  	299,1,0,0,0,299,302,1,0,0,0,300,301,5,22,0,0,301,303,3,40,20,0,302,300,
  	1,0,0,0,303,304,1,0,0,0,304,302,1,0,0,0,304,305,1,0,0,0,305,307,1,0,0,
  	0,306,295,1,0,0,0,306,298,1,0,0,0,307,309,1,0,0,0,308,310,5,22,0,0,309,
  	308,1,0,0,0,309,310,1,0,0,0,310,311,1,0,0,0,311,312,5,19,0,0,312,43,1,
  	0,0,0,313,326,5,16,0,0,314,316,3,36,18,0,315,314,1,0,0,0,315,316,1,0,
  	0,0,316,327,1,0,0,0,317,319,3,36,18,0,318,317,1,0,0,0,318,319,1,0,0,0,
  	319,322,1,0,0,0,320,321,5,22,0,0,321,323,3,36,18,0,322,320,1,0,0,0,323,
  	324,1,0,0,0,324,322,1,0,0,0,324,325,1,0,0,0,325,327,1,0,0,0,326,315,1,
  	0,0,0,326,318,1,0,0,0,327,328,1,0,0,0,328,329,5,17,0,0,329,45,1,0,0,0,
  	330,343,5,14,0,0,331,333,3,36,18,0,332,331,1,0,0,0,332,333,1,0,0,0,333,
  	344,1,0,0,0,334,336,3,36,18,0,335,334,1,0,0,0,335,336,1,0,0,0,336,339,
  	1,0,0,0,337,338,5,22,0,0,338,340,3,36,18,0,339,337,1,0,0,0,340,341,1,
  	0,0,0,341,339,1,0,0,0,341,342,1,0,0,0,342,344,1,0,0,0,343,332,1,0,0,0,
  	343,335,1,0,0,0,344,345,1,0,0,0,345,346,5,15,0,0,346,47,1,0,0,0,347,349,
  	3,36,18,0,348,347,1,0,0,0,348,349,1,0,0,0,349,350,1,0,0,0,350,352,5,20,
  	0,0,351,353,3,36,18,0,352,351,1,0,0,0,352,353,1,0,0,0,353,355,1,0,0,0,
  	354,356,5,20,0,0,355,354,1,0,0,0,355,356,1,0,0,0,356,358,1,0,0,0,357,
  	359,3,36,18,0,358,357,1,0,0,0,358,359,1,0,0,0,359,49,1,0,0,0,360,368,
  	5,50,0,0,361,368,5,51,0,0,362,368,5,52,0,0,363,368,5,48,0,0,364,368,3,
  	42,21,0,365,368,3,44,22,0,366,368,3,46,23,0,367,360,1,0,0,0,367,361,1,
  	0,0,0,367,362,1,0,0,0,367,363,1,0,0,0,367,364,1,0,0,0,367,365,1,0,0,0,
  	367,366,1,0,0,0,368,51,1,0,0,0,45,55,61,68,77,82,88,100,104,108,114,121,
  	125,133,147,162,164,169,181,188,190,193,200,202,205,224,282,284,295,298,
  	304,306,309,315,318,324,326,332,335,341,343,348,352,355,358,367
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
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::KW_IMPORT) {
      setState(52);
      import_statement();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(58);
      statement();
      setState(61); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8729022813261496) != 0));
    setState(63);
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
    setState(65);
    match(TythonParser::KW_IMPORT);
    setState(66);
    import_path();
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(67);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(70);
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
    setState(72);
    match(TythonParser::IDENTIFIER);
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::SYM_DOT) {
      setState(73);
      match(TythonParser::SYM_DOT);
      setState(74);
      match(TythonParser::IDENTIFIER);
      setState(79);
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
    setState(80);
    match(TythonParser::KW_DEF);
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(81);
      match(TythonParser::KW_EXTERN);
    }
    setState(84);
    match(TythonParser::IDENTIFIER);
    setState(85);
    match(TythonParser::SYM_LPAR);
    setState(86);
    arguments();
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_ELLIPS) {
      setState(87);
      match(TythonParser::SYM_ELLIPS);
    }
    setState(90);
    match(TythonParser::SYM_RPAR);
    setState(91);
    match(TythonParser::SYM_COL);
    setState(92);
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
    setState(104);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_BREAK:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::SYM_LSQ:
      case TythonParser::SYM_LBR:
      case TythonParser::SYM_INC:
      case TythonParser::SYM_DEC:
      case TythonParser::NONE_LIT:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        simple_statements();
        break;
      }

      case TythonParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(95);
        match(TythonParser::NEWLINE);
        setState(96);
        match(TythonParser::INDENT);
        setState(98); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(97);
          antlrcpp::downCast<BlockContext *>(_localctx)->indent_statements = statement();
          setState(100); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 8729022813261496) != 0));
        setState(102);
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
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_BREAK:
      case TythonParser::KW_EXTERN:
      case TythonParser::SYM_LPAR:
      case TythonParser::SYM_LSQ:
      case TythonParser::SYM_LBR:
      case TythonParser::SYM_INC:
      case TythonParser::SYM_DEC:
      case TythonParser::NONE_LIT:
      case TythonParser::IDENTIFIER:
      case TythonParser::INT_LIT:
      case TythonParser::FLOAT_LIT:
      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(106);
        simple_statements();
        break;
      }

      case TythonParser::KW_DEF:
      case TythonParser::KW_IF:
      case TythonParser::KW_FOR:
      case TythonParser::KW_WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(107);
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

TythonParser::Break_statementContext* TythonParser::Simple_statementContext::break_statement() {
  return getRuleContext<TythonParser::Break_statementContext>(0);
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
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(112);
      break_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(113);
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
    setState(116);
    simple_statement();
    setState(121);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(117);
        match(TythonParser::SYM_SEMCOL);
        setState(118);
        simple_statement(); 
      }
      setState(123);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(124);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(127);
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

TythonParser::While_loopContext* TythonParser::Compound_statementContext::while_loop() {
  return getRuleContext<TythonParser::While_loopContext>(0);
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
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 1);
        setState(129);
        if_statement();
        break;
      }

      case TythonParser::KW_DEF: {
        enterOuterAlt(_localctx, 2);
        setState(130);
        function_def();
        break;
      }

      case TythonParser::KW_FOR: {
        enterOuterAlt(_localctx, 3);
        setState(131);
        for_loop();
        break;
      }

      case TythonParser::KW_WHILE: {
        enterOuterAlt(_localctx, 4);
        setState(132);
        while_loop();
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


size_t TythonParser::Assign_statementContext::getRuleIndex() const {
  return TythonParser::RuleAssign_statement;
}

void TythonParser::Assign_statementContext::copyFrom(Assign_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Lbl_assign_minus_eqContext ------------------------------------------------------------------

TythonParser::LvalContext* TythonParser::Lbl_assign_minus_eqContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_assign_minus_eqContext::SYM_MINUS_EQ() {
  return getToken(TythonParser::SYM_MINUS_EQ, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_assign_minus_eqContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Lbl_assign_minus_eqContext::Lbl_assign_minus_eqContext(Assign_statementContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_assign_minus_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_assign_minus_eq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_assign_statementContext ------------------------------------------------------------------

TythonParser::LvalContext* TythonParser::Lbl_assign_statementContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_assign_statementContext::SYM_ASSIGN() {
  return getToken(TythonParser::SYM_ASSIGN, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_assign_statementContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Lbl_assign_statementContext::Lbl_assign_statementContext(Assign_statementContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_assign_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_assign_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_assign_plus_eqContext ------------------------------------------------------------------

TythonParser::LvalContext* TythonParser::Lbl_assign_plus_eqContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_assign_plus_eqContext::SYM_PLUS_EQ() {
  return getToken(TythonParser::SYM_PLUS_EQ, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_assign_plus_eqContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Lbl_assign_plus_eqContext::Lbl_assign_plus_eqContext(Assign_statementContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_assign_plus_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_assign_plus_eq(this);
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
    setState(147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_assign_statementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(135);
      lval();
      setState(136);
      match(TythonParser::SYM_ASSIGN);
      setState(137);
      expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_assign_plus_eqContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(139);
      lval();
      setState(140);
      match(TythonParser::SYM_PLUS_EQ);
      setState(141);
      expression(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_assign_minus_eqContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(143);
      lval();
      setState(144);
      match(TythonParser::SYM_MINUS_EQ);
      setState(145);
      expression(0);
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

//----------------- Break_statementContext ------------------------------------------------------------------

TythonParser::Break_statementContext::Break_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Break_statementContext::KW_BREAK() {
  return getToken(TythonParser::KW_BREAK, 0);
}


size_t TythonParser::Break_statementContext::getRuleIndex() const {
  return TythonParser::RuleBreak_statement;
}


std::any TythonParser::Break_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitBreak_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Break_statementContext* TythonParser::break_statement() {
  Break_statementContext *_localctx = _tracker.createInstance<Break_statementContext>(_ctx, getState());
  enterRule(_localctx, 20, TythonParser::RuleBreak_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(TythonParser::KW_BREAK);
   
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
  enterRule(_localctx, 22, TythonParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(TythonParser::KW_RETURN);
    setState(152);
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
  enterRule(_localctx, 24, TythonParser::RuleIf_statement);
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
    setState(154);
    match(TythonParser::KW_IF);
    setState(155);
    expression(0);
    setState(156);
    match(TythonParser::SYM_COL);
    setState(157);
    antlrcpp::downCast<If_statementContext *>(_localctx)->br_if = block();
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_ELSE) {
      setState(158);
      match(TythonParser::KW_ELSE);
      setState(162);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TythonParser::KW_IF: {
          setState(159);
          antlrcpp::downCast<If_statementContext *>(_localctx)->br_else_if = if_statement();
          break;
        }

        case TythonParser::SYM_COL: {
          setState(160);
          match(TythonParser::SYM_COL);
          setState(161);
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
  enterRule(_localctx, 26, TythonParser::RuleFor_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(TythonParser::KW_FOR);
    setState(169);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(167);
      match(TythonParser::IDENTIFIER);
      setState(168);
      match(TythonParser::KW_IN);
      break;
    }

    default:
      break;
    }
    setState(171);
    expression(0);
    setState(172);
    match(TythonParser::SYM_COL);
    setState(173);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_loopContext ------------------------------------------------------------------

TythonParser::While_loopContext::While_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::While_loopContext::KW_WHILE() {
  return getToken(TythonParser::KW_WHILE, 0);
}

TythonParser::ExpressionContext* TythonParser::While_loopContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::While_loopContext::SYM_COL() {
  return getToken(TythonParser::SYM_COL, 0);
}

TythonParser::BlockContext* TythonParser::While_loopContext::block() {
  return getRuleContext<TythonParser::BlockContext>(0);
}


size_t TythonParser::While_loopContext::getRuleIndex() const {
  return TythonParser::RuleWhile_loop;
}


std::any TythonParser::While_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitWhile_loop(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::While_loopContext* TythonParser::while_loop() {
  While_loopContext *_localctx = _tracker.createInstance<While_loopContext>(_ctx, getState());
  enterRule(_localctx, 28, TythonParser::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(TythonParser::KW_WHILE);
    setState(176);
    expression(0);
    setState(177);
    match(TythonParser::SYM_COL);
    setState(178);
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
  enterRule(_localctx, 30, TythonParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TythonParser::IDENTIFIER) {
        setState(180);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(183);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      setState(186); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(184);
        match(TythonParser::SYM_COMMA);
        setState(185);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
        setState(188); 
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
  enterRule(_localctx, 32, TythonParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(192);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(195);
      antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
      antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      setState(198); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(196);
        match(TythonParser::SYM_COMMA);
        setState(197);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
        setState(200); 
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
  enterRule(_localctx, 34, TythonParser::RuleCall_expression);
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
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(204);
      match(TythonParser::KW_EXTERN);
    }
    setState(207);
    match(TythonParser::IDENTIFIER);
    setState(208);
    match(TythonParser::SYM_LPAR);
    setState(209);
    parameters();
    setState(210);
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

//----------------- Lbl_identifierContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_identifierContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

TythonParser::Lbl_identifierContext::Lbl_identifierContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_identifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_literalContext ------------------------------------------------------------------

TythonParser::LiteralContext* TythonParser::Lbl_literalContext::literal() {
  return getRuleContext<TythonParser::LiteralContext>(0);
}

TythonParser::Lbl_literalContext::Lbl_literalContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_literal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_div_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_div_exprContext::SYM_DIV() {
  return getToken(TythonParser::SYM_DIV, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_div_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_div_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_div_exprContext::Lbl_div_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_div_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_div_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_or_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_or_exprContext::SYM_OR() {
  return getToken(TythonParser::SYM_OR, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_or_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_or_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_or_exprContext::Lbl_or_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_or_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_eq_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_eq_exprContext::SYM_EQ() {
  return getToken(TythonParser::SYM_EQ, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_eq_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_eq_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_eq_exprContext::Lbl_eq_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_eq_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_eq_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_lt_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_lt_exprContext::SYM_LT() {
  return getToken(TythonParser::SYM_LT, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_lt_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_lt_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_lt_exprContext::Lbl_lt_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_lt_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_lt_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_inc_suffixContext ------------------------------------------------------------------

TythonParser::ExpressionContext* TythonParser::Lbl_inc_suffixContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_inc_suffixContext::SYM_INC() {
  return getToken(TythonParser::SYM_INC, 0);
}

TythonParser::Lbl_inc_suffixContext::Lbl_inc_suffixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_inc_suffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_inc_suffix(this);
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
//----------------- Lbl_dec_prefixContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_dec_prefixContext::SYM_DEC() {
  return getToken(TythonParser::SYM_DEC, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_dec_prefixContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Lbl_dec_prefixContext::Lbl_dec_prefixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_dec_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_dec_prefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_and_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_and_exprContext::SYM_AND() {
  return getToken(TythonParser::SYM_AND, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_and_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_and_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_and_exprContext::Lbl_and_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_and_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_and_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_gte_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_gte_exprContext::SYM_GTE() {
  return getToken(TythonParser::SYM_GTE, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_gte_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_gte_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_gte_exprContext::Lbl_gte_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_gte_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_gte_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_dec_suffixContext ------------------------------------------------------------------

TythonParser::ExpressionContext* TythonParser::Lbl_dec_suffixContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_dec_suffixContext::SYM_DEC() {
  return getToken(TythonParser::SYM_DEC, 0);
}

TythonParser::Lbl_dec_suffixContext::Lbl_dec_suffixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_dec_suffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_dec_suffix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_key_accessContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_key_accessContext::SYM_LSQ() {
  return getToken(TythonParser::SYM_LSQ, 0);
}

tree::TerminalNode* TythonParser::Lbl_key_accessContext::SYM_RSQ() {
  return getToken(TythonParser::SYM_RSQ, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_key_accessContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_key_accessContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_key_accessContext::Lbl_key_accessContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_key_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_key_access(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_neq_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_neq_exprContext::SYM_NEQ() {
  return getToken(TythonParser::SYM_NEQ, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_neq_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_neq_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_neq_exprContext::Lbl_neq_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_neq_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_neq_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_method_callContext ------------------------------------------------------------------

TythonParser::ExpressionContext* TythonParser::Lbl_method_callContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_method_callContext::SYM_DOT() {
  return getToken(TythonParser::SYM_DOT, 0);
}

TythonParser::Call_expressionContext* TythonParser::Lbl_method_callContext::call_expression() {
  return getRuleContext<TythonParser::Call_expressionContext>(0);
}

TythonParser::Lbl_method_callContext::Lbl_method_callContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_method_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_method_call(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_add_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_add_exprContext::SYM_PLUS() {
  return getToken(TythonParser::SYM_PLUS, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_add_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_add_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_add_exprContext::Lbl_add_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_add_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_add_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_lte_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_lte_exprContext::SYM_LTE() {
  return getToken(TythonParser::SYM_LTE, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_lte_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_lte_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_lte_exprContext::Lbl_lte_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_lte_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_lte_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_inc_prefixContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_inc_prefixContext::SYM_INC() {
  return getToken(TythonParser::SYM_INC, 0);
}

TythonParser::ExpressionContext* TythonParser::Lbl_inc_prefixContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Lbl_inc_prefixContext::Lbl_inc_prefixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_inc_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_inc_prefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_mult_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_mult_exprContext::SYM_MULT() {
  return getToken(TythonParser::SYM_MULT, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_mult_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_mult_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_mult_exprContext::Lbl_mult_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_mult_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_mult_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_exponent_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_exponent_exprContext::SYM_EXP() {
  return getToken(TythonParser::SYM_EXP, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_exponent_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_exponent_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_exponent_exprContext::Lbl_exponent_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_exponent_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_exponent_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_sub_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_sub_exprContext::SYM_MINUS() {
  return getToken(TythonParser::SYM_MINUS, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_sub_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_sub_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_sub_exprContext::Lbl_sub_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_sub_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_sub_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_gt_exprContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_gt_exprContext::SYM_GT() {
  return getToken(TythonParser::SYM_GT, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_gt_exprContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_gt_exprContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_gt_exprContext::Lbl_gt_exprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_gt_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_gt_expr(this);
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
//----------------- Lbl_slice_accessContext ------------------------------------------------------------------

TythonParser::ExpressionContext* TythonParser::Lbl_slice_accessContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_slice_accessContext::SYM_LSQ() {
  return getToken(TythonParser::SYM_LSQ, 0);
}

TythonParser::Slice_litContext* TythonParser::Lbl_slice_accessContext::slice_lit() {
  return getRuleContext<TythonParser::Slice_litContext>(0);
}

tree::TerminalNode* TythonParser::Lbl_slice_accessContext::SYM_RSQ() {
  return getToken(TythonParser::SYM_RSQ, 0);
}

TythonParser::Lbl_slice_accessContext::Lbl_slice_accessContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_slice_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_slice_access(this);
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, TythonParser::RuleExpression, precedence);

    

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
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Lbl_expression_parenthesesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(213);
      match(TythonParser::SYM_LPAR);
      setState(214);
      expression(0);
      setState(215);
      match(TythonParser::SYM_RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Lbl_call_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(217);
      call_expression();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lbl_inc_prefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(218);
      match(TythonParser::SYM_INC);
      setState(219);
      expression(8);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Lbl_dec_prefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(220);
      match(TythonParser::SYM_DEC);
      setState(221);
      expression(6);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Lbl_literalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(222);
      literal();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Lbl_identifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      match(TythonParser::IDENTIFIER);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(284);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(282);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Lbl_exponent_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(226);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(227);
          match(TythonParser::SYM_EXP);
          setState(228);
          antlrcpp::downCast<Lbl_exponent_exprContext *>(_localctx)->rhs = expression(22);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Lbl_mult_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(229);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(230);
          match(TythonParser::SYM_MULT);
          setState(231);
          antlrcpp::downCast<Lbl_mult_exprContext *>(_localctx)->rhs = expression(21);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Lbl_div_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(232);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(233);
          match(TythonParser::SYM_DIV);
          setState(234);
          antlrcpp::downCast<Lbl_div_exprContext *>(_localctx)->rhs = expression(20);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Lbl_add_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(235);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(236);
          match(TythonParser::SYM_PLUS);
          setState(237);
          antlrcpp::downCast<Lbl_add_exprContext *>(_localctx)->rhs = expression(19);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Lbl_sub_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(238);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(239);
          match(TythonParser::SYM_MINUS);
          setState(240);
          antlrcpp::downCast<Lbl_sub_exprContext *>(_localctx)->rhs = expression(18);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Lbl_and_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(241);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(242);
          match(TythonParser::SYM_AND);
          setState(243);
          antlrcpp::downCast<Lbl_and_exprContext *>(_localctx)->rhs = expression(17);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Lbl_or_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(244);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(245);
          match(TythonParser::SYM_OR);
          setState(246);
          antlrcpp::downCast<Lbl_or_exprContext *>(_localctx)->rhs = expression(16);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Lbl_neq_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(247);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(248);
          match(TythonParser::SYM_NEQ);
          setState(249);
          antlrcpp::downCast<Lbl_neq_exprContext *>(_localctx)->rhs = expression(15);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Lbl_lt_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(250);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(251);
          match(TythonParser::SYM_LT);
          setState(252);
          antlrcpp::downCast<Lbl_lt_exprContext *>(_localctx)->rhs = expression(14);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Lbl_lte_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(253);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(254);
          match(TythonParser::SYM_LTE);
          setState(255);
          antlrcpp::downCast<Lbl_lte_exprContext *>(_localctx)->rhs = expression(13);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Lbl_eq_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(256);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(257);
          match(TythonParser::SYM_EQ);
          setState(258);
          antlrcpp::downCast<Lbl_eq_exprContext *>(_localctx)->rhs = expression(12);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Lbl_gt_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(259);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(260);
          match(TythonParser::SYM_GT);
          setState(261);
          antlrcpp::downCast<Lbl_gt_exprContext *>(_localctx)->rhs = expression(11);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Lbl_gte_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(262);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(263);
          match(TythonParser::SYM_GTE);
          setState(264);
          antlrcpp::downCast<Lbl_gte_exprContext *>(_localctx)->rhs = expression(10);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Lbl_method_callContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(265);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(266);
          match(TythonParser::SYM_DOT);
          setState(267);
          call_expression();
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Lbl_inc_suffixContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(268);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(269);
          match(TythonParser::SYM_INC);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Lbl_dec_suffixContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(271);
          match(TythonParser::SYM_DEC);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Lbl_slice_accessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(272);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(273);
          match(TythonParser::SYM_LSQ);
          setState(274);
          slice_lit();
          setState(275);
          match(TythonParser::SYM_RSQ);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Lbl_key_accessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->obj = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(277);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(278);
          match(TythonParser::SYM_LSQ);
          setState(279);
          antlrcpp::downCast<Lbl_key_accessContext *>(_localctx)->key = expression(0);
          setState(280);
          match(TythonParser::SYM_RSQ);
          break;
        }

        default:
          break;
        } 
      }
      setState(286);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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

TythonParser::ExpressionContext* TythonParser::LvalContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}


size_t TythonParser::LvalContext::getRuleIndex() const {
  return TythonParser::RuleLval;
}


std::any TythonParser::LvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLval(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::LvalContext* TythonParser::lval() {
  LvalContext *_localctx = _tracker.createInstance<LvalContext>(_ctx, getState());
  enterRule(_localctx, 38, TythonParser::RuleLval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    expression(0);
   
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
  enterRule(_localctx, 40, TythonParser::RuleKey_value_pair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    antlrcpp::downCast<Key_value_pairContext *>(_localctx)->key = expression(0);
    setState(290);
    match(TythonParser::SYM_COL);
    setState(291);
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

std::vector<tree::TerminalNode *> TythonParser::Dict_litContext::SYM_COMMA() {
  return getTokens(TythonParser::SYM_COMMA);
}

tree::TerminalNode* TythonParser::Dict_litContext::SYM_COMMA(size_t i) {
  return getToken(TythonParser::SYM_COMMA, i);
}

std::vector<TythonParser::Key_value_pairContext *> TythonParser::Dict_litContext::key_value_pair() {
  return getRuleContexts<TythonParser::Key_value_pairContext>();
}

TythonParser::Key_value_pairContext* TythonParser::Dict_litContext::key_value_pair(size_t i) {
  return getRuleContext<TythonParser::Key_value_pairContext>(i);
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
  enterRule(_localctx, 42, TythonParser::RuleDict_lit);
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
    setState(293);
    match(TythonParser::SYM_LBR);
    setState(306);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(294);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      break;
    }

    case 2: {
      setState(298);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(297);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      setState(302); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(300);
                match(TythonParser::SYM_COMMA);
                setState(301);
                antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
                antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(304); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    default:
      break;
    }
    setState(309);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_COMMA) {
      setState(308);
      match(TythonParser::SYM_COMMA);
    }
    setState(311);
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

std::vector<TythonParser::ExpressionContext *> TythonParser::List_litContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::List_litContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
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
  enterRule(_localctx, 44, TythonParser::RuleList_lit);
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
    setState(313);
    match(TythonParser::SYM_LSQ);
    setState(326);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(315);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(314);
        antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      setState(318);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(317);
        antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext);
      }
      setState(322); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(320);
        match(TythonParser::SYM_COMMA);
        setState(321);
        antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext);
        setState(324); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(328);
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

std::vector<TythonParser::ExpressionContext *> TythonParser::Tuple_litContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Tuple_litContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
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
  enterRule(_localctx, 46, TythonParser::RuleTuple_lit);
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
    setState(330);
    match(TythonParser::SYM_LPAR);
    setState(343);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(332);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(331);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      setState(335);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8729022813259776) != 0)) {
        setState(334);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext);
      }
      setState(339); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(337);
        match(TythonParser::SYM_COMMA);
        setState(338);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext);
        setState(341); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(345);
    match(TythonParser::SYM_RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Slice_litContext ------------------------------------------------------------------

TythonParser::Slice_litContext::Slice_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TythonParser::Slice_litContext::SYM_COL() {
  return getTokens(TythonParser::SYM_COL);
}

tree::TerminalNode* TythonParser::Slice_litContext::SYM_COL(size_t i) {
  return getToken(TythonParser::SYM_COL, i);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Slice_litContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Slice_litContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}


size_t TythonParser::Slice_litContext::getRuleIndex() const {
  return TythonParser::RuleSlice_lit;
}


std::any TythonParser::Slice_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitSlice_lit(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Slice_litContext* TythonParser::slice_lit() {
  Slice_litContext *_localctx = _tracker.createInstance<Slice_litContext>(_ctx, getState());
  enterRule(_localctx, 48, TythonParser::RuleSlice_lit);
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
    setState(348);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8729022813259776) != 0)) {
      setState(347);
      antlrcpp::downCast<Slice_litContext *>(_localctx)->start = expression(0);
    }
    setState(350);
    match(TythonParser::SYM_COL);
    setState(352);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(351);
      antlrcpp::downCast<Slice_litContext *>(_localctx)->end = expression(0);
      break;
    }

    default:
      break;
    }
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_COL) {
      setState(354);
      match(TythonParser::SYM_COL);
    }
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8729022813259776) != 0)) {
      setState(357);
      antlrcpp::downCast<Slice_litContext *>(_localctx)->step = expression(0);
    }
   
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
  enterRule(_localctx, 50, TythonParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(367);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::INT_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(360);
        match(TythonParser::INT_LIT);
        break;
      }

      case TythonParser::FLOAT_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(361);
        match(TythonParser::FLOAT_LIT);
        break;
      }

      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 3);
        setState(362);
        match(TythonParser::STR_LIT);
        break;
      }

      case TythonParser::NONE_LIT: {
        enterOuterAlt(_localctx, 4);
        setState(363);
        match(TythonParser::NONE_LIT);
        break;
      }

      case TythonParser::SYM_LBR: {
        enterOuterAlt(_localctx, 5);
        setState(364);
        dict_lit();
        break;
      }

      case TythonParser::SYM_LSQ: {
        enterOuterAlt(_localctx, 6);
        setState(365);
        list_lit();
        break;
      }

      case TythonParser::SYM_LPAR: {
        enterOuterAlt(_localctx, 7);
        setState(366);
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
    case 18: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TythonParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 21);
    case 1: return precpred(_ctx, 20);
    case 2: return precpred(_ctx, 19);
    case 3: return precpred(_ctx, 18);
    case 4: return precpred(_ctx, 17);
    case 5: return precpred(_ctx, 16);
    case 6: return precpred(_ctx, 15);
    case 7: return precpred(_ctx, 14);
    case 8: return precpred(_ctx, 13);
    case 9: return precpred(_ctx, 12);
    case 10: return precpred(_ctx, 11);
    case 11: return precpred(_ctx, 10);
    case 12: return precpred(_ctx, 9);
    case 13: return precpred(_ctx, 23);
    case 14: return precpred(_ctx, 7);
    case 15: return precpred(_ctx, 5);
    case 16: return precpred(_ctx, 4);
    case 17: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void TythonParser::initialize() {
  ::antlr4::internal::call_once(tythonparserParserOnceFlag, tythonparserParserInitialize);
}
