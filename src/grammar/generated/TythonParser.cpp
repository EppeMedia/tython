
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
      "assign_statement", "break_statement", "return_statement", "ewout_statement", 
      "if_statement", "for_loop", "while_loop", "arguments", "parameters", 
      "call_expression", "expression", "lval", "key_value_pair", "dict_lit", 
      "list_lit", "tuple_lit", "slice_lit", "literal"
    },
    std::vector<std::string>{
      "", "", "", "'def'", "'return'", "'if'", "'else'", "'for'", "'in'", 
      "'while'", "'break'", "'extern'", "'import'", "'self'", "'ewout'", 
      "'('", "')'", "'['", "']'", "'{'", "'}'", "':'", "';'", "','", "", 
      "'='", "'+='", "'-='", "'!='", "'<='", "'<'", "'=='", "'>'", "'>='", 
      "'&&'", "'||'", "'+'", "'-'", "'*'", "'/'", "'**'", "'++'", "'--'", 
      "'.'", "'...'", "", "'/*'", "'true'", "'false'", "'None'", "", "", 
      "", "", "", "", "'*/'"
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "KW_DEF", "KW_RETURN", "KW_IF", "KW_ELSE", 
      "KW_FOR", "KW_IN", "KW_WHILE", "KW_BREAK", "KW_EXTERN", "KW_IMPORT", 
      "KW_SELF", "KW_EWOUT", "SYM_LPAR", "SYM_RPAR", "SYM_LSQ", "SYM_RSQ", 
      "SYM_LBR", "SYM_RBR", "SYM_COL", "SYM_SEMCOL", "SYM_COMMA", "SYM_STMNT_DELIMITER", 
      "SYM_ASSIGN", "SYM_PLUS_EQ", "SYM_MINUS_EQ", "SYM_NEQ", "SYM_LTE", 
      "SYM_LT", "SYM_EQ", "SYM_GT", "SYM_GTE", "SYM_AND", "SYM_OR", "SYM_PLUS", 
      "SYM_MINUS", "SYM_MULT", "SYM_DIV", "SYM_EXP", "SYM_INC", "SYM_DEC", 
      "SYM_DOT", "SYM_ELLIPS", "SYM_COMMENT", "SYM_COMMENT_START", "TRUE_LIT", 
      "FALSE_LIT", "NONE_LIT", "IDENTIFIER", "INT_LIT", "FLOAT_LIT", "STR_LIT", 
      "NEWLINE", "WS", "SYM_COMMENT_END", "COMMENT_CONTENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,57,382,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,5,0,56,8,0,10,
  	0,12,0,59,9,0,1,0,4,0,62,8,0,11,0,12,0,63,1,0,1,0,1,1,1,1,1,1,3,1,71,
  	8,1,1,1,1,1,1,2,1,2,1,2,5,2,78,8,2,10,2,12,2,81,9,2,1,3,1,3,3,3,85,8,
  	3,1,3,1,3,1,3,1,3,3,3,91,8,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,4,4,101,
  	8,4,11,4,12,4,102,1,4,1,4,3,4,107,8,4,1,5,1,5,3,5,111,8,5,1,6,1,6,1,6,
  	1,6,1,6,3,6,118,8,6,1,7,1,7,1,7,5,7,123,8,7,10,7,12,7,126,9,7,1,7,3,7,
  	129,8,7,1,7,1,7,1,8,1,8,1,8,1,8,3,8,137,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,3,9,151,8,9,1,10,1,10,1,11,1,11,1,11,1,12,1,12,
  	1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,169,8,13,3,13,171,8,
  	13,1,14,1,14,1,14,3,14,176,8,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,
  	15,1,15,1,16,3,16,188,8,16,1,16,1,16,1,16,4,16,193,8,16,11,16,12,16,194,
  	3,16,197,8,16,1,17,3,17,200,8,17,1,17,1,17,1,17,4,17,205,8,17,11,17,12,
  	17,206,3,17,209,8,17,1,18,3,18,212,8,18,1,18,1,18,1,18,1,18,1,18,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,231,8,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	5,19,289,8,19,10,19,12,19,292,9,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	300,8,20,1,21,1,21,1,21,1,21,1,22,1,22,3,22,308,8,22,1,22,3,22,311,8,
  	22,1,22,1,22,4,22,315,8,22,11,22,12,22,316,3,22,319,8,22,1,22,3,22,322,
  	8,22,1,22,1,22,1,23,1,23,3,23,328,8,23,1,23,3,23,331,8,23,1,23,1,23,4,
  	23,335,8,23,11,23,12,23,336,3,23,339,8,23,1,23,1,23,1,24,1,24,3,24,345,
  	8,24,1,24,3,24,348,8,24,1,24,1,24,4,24,352,8,24,11,24,12,24,353,3,24,
  	356,8,24,1,24,1,24,1,25,3,25,361,8,25,1,25,1,25,3,25,365,8,25,1,25,3,
  	25,368,8,25,1,25,3,25,371,8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,
  	380,8,26,1,26,0,1,38,27,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,46,48,50,52,0,0,431,0,57,1,0,0,0,2,67,1,0,0,0,4,74,
  	1,0,0,0,6,82,1,0,0,0,8,106,1,0,0,0,10,110,1,0,0,0,12,117,1,0,0,0,14,119,
  	1,0,0,0,16,136,1,0,0,0,18,150,1,0,0,0,20,152,1,0,0,0,22,154,1,0,0,0,24,
  	157,1,0,0,0,26,160,1,0,0,0,28,172,1,0,0,0,30,181,1,0,0,0,32,196,1,0,0,
  	0,34,208,1,0,0,0,36,211,1,0,0,0,38,230,1,0,0,0,40,299,1,0,0,0,42,301,
  	1,0,0,0,44,305,1,0,0,0,46,325,1,0,0,0,48,342,1,0,0,0,50,360,1,0,0,0,52,
  	379,1,0,0,0,54,56,3,2,1,0,55,54,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,
  	58,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,60,62,3,10,5,0,61,60,1,0,0,0,62,
  	63,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,65,1,0,0,0,65,66,5,0,0,1,66,
  	1,1,0,0,0,67,68,5,12,0,0,68,70,3,4,2,0,69,71,5,22,0,0,70,69,1,0,0,0,70,
  	71,1,0,0,0,71,72,1,0,0,0,72,73,5,54,0,0,73,3,1,0,0,0,74,79,5,50,0,0,75,
  	76,5,43,0,0,76,78,5,50,0,0,77,75,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,
  	79,80,1,0,0,0,80,5,1,0,0,0,81,79,1,0,0,0,82,84,5,3,0,0,83,85,5,11,0,0,
  	84,83,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,87,5,50,0,0,87,88,5,15,0,
  	0,88,90,3,32,16,0,89,91,5,44,0,0,90,89,1,0,0,0,90,91,1,0,0,0,91,92,1,
  	0,0,0,92,93,5,16,0,0,93,94,5,21,0,0,94,95,3,8,4,0,95,7,1,0,0,0,96,107,
  	3,14,7,0,97,98,5,54,0,0,98,100,5,1,0,0,99,101,3,10,5,0,100,99,1,0,0,0,
  	101,102,1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,105,
  	5,2,0,0,105,107,1,0,0,0,106,96,1,0,0,0,106,97,1,0,0,0,107,9,1,0,0,0,108,
  	111,3,14,7,0,109,111,3,16,8,0,110,108,1,0,0,0,110,109,1,0,0,0,111,11,
  	1,0,0,0,112,118,3,38,19,0,113,118,3,18,9,0,114,118,3,20,10,0,115,118,
  	3,22,11,0,116,118,3,24,12,0,117,112,1,0,0,0,117,113,1,0,0,0,117,114,1,
  	0,0,0,117,115,1,0,0,0,117,116,1,0,0,0,118,13,1,0,0,0,119,124,3,12,6,0,
  	120,121,5,22,0,0,121,123,3,12,6,0,122,120,1,0,0,0,123,126,1,0,0,0,124,
  	122,1,0,0,0,124,125,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,127,129,5,
  	22,0,0,128,127,1,0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,131,5,54,0,
  	0,131,15,1,0,0,0,132,137,3,26,13,0,133,137,3,6,3,0,134,137,3,28,14,0,
  	135,137,3,30,15,0,136,132,1,0,0,0,136,133,1,0,0,0,136,134,1,0,0,0,136,
  	135,1,0,0,0,137,17,1,0,0,0,138,139,3,40,20,0,139,140,5,25,0,0,140,141,
  	3,38,19,0,141,151,1,0,0,0,142,143,3,40,20,0,143,144,5,26,0,0,144,145,
  	3,38,19,0,145,151,1,0,0,0,146,147,3,40,20,0,147,148,5,27,0,0,148,149,
  	3,38,19,0,149,151,1,0,0,0,150,138,1,0,0,0,150,142,1,0,0,0,150,146,1,0,
  	0,0,151,19,1,0,0,0,152,153,5,10,0,0,153,21,1,0,0,0,154,155,5,4,0,0,155,
  	156,3,38,19,0,156,23,1,0,0,0,157,158,5,14,0,0,158,159,3,38,19,0,159,25,
  	1,0,0,0,160,161,5,5,0,0,161,162,3,38,19,0,162,163,5,21,0,0,163,170,3,
  	8,4,0,164,168,5,6,0,0,165,169,3,26,13,0,166,167,5,21,0,0,167,169,3,8,
  	4,0,168,165,1,0,0,0,168,166,1,0,0,0,169,171,1,0,0,0,170,164,1,0,0,0,170,
  	171,1,0,0,0,171,27,1,0,0,0,172,175,5,7,0,0,173,174,5,50,0,0,174,176,5,
  	8,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,177,1,0,0,0,177,178,3,38,19,
  	0,178,179,5,21,0,0,179,180,3,8,4,0,180,29,1,0,0,0,181,182,5,9,0,0,182,
  	183,3,38,19,0,183,184,5,21,0,0,184,185,3,8,4,0,185,31,1,0,0,0,186,188,
  	5,50,0,0,187,186,1,0,0,0,187,188,1,0,0,0,188,197,1,0,0,0,189,192,5,50,
  	0,0,190,191,5,23,0,0,191,193,5,50,0,0,192,190,1,0,0,0,193,194,1,0,0,0,
  	194,192,1,0,0,0,194,195,1,0,0,0,195,197,1,0,0,0,196,187,1,0,0,0,196,189,
  	1,0,0,0,197,33,1,0,0,0,198,200,3,38,19,0,199,198,1,0,0,0,199,200,1,0,
  	0,0,200,209,1,0,0,0,201,204,3,38,19,0,202,203,5,23,0,0,203,205,3,38,19,
  	0,204,202,1,0,0,0,205,206,1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,
  	209,1,0,0,0,208,199,1,0,0,0,208,201,1,0,0,0,209,35,1,0,0,0,210,212,5,
  	11,0,0,211,210,1,0,0,0,211,212,1,0,0,0,212,213,1,0,0,0,213,214,5,50,0,
  	0,214,215,5,15,0,0,215,216,3,34,17,0,216,217,5,16,0,0,217,37,1,0,0,0,
  	218,219,6,19,-1,0,219,220,5,15,0,0,220,221,3,38,19,0,221,222,5,16,0,0,
  	222,231,1,0,0,0,223,231,3,36,18,0,224,225,5,41,0,0,225,231,3,38,19,21,
  	226,227,5,42,0,0,227,231,3,38,19,19,228,231,3,52,26,0,229,231,5,50,0,
  	0,230,218,1,0,0,0,230,223,1,0,0,0,230,224,1,0,0,0,230,226,1,0,0,0,230,
  	228,1,0,0,0,230,229,1,0,0,0,231,290,1,0,0,0,232,233,10,17,0,0,233,234,
  	5,40,0,0,234,289,3,38,19,18,235,236,10,16,0,0,236,237,5,38,0,0,237,289,
  	3,38,19,17,238,239,10,15,0,0,239,240,5,39,0,0,240,289,3,38,19,16,241,
  	242,10,14,0,0,242,243,5,36,0,0,243,289,3,38,19,15,244,245,10,13,0,0,245,
  	246,5,37,0,0,246,289,3,38,19,14,247,248,10,12,0,0,248,249,5,34,0,0,249,
  	289,3,38,19,13,250,251,10,11,0,0,251,252,5,35,0,0,252,289,3,38,19,12,
  	253,254,10,10,0,0,254,255,5,28,0,0,255,289,3,38,19,11,256,257,10,9,0,
  	0,257,258,5,30,0,0,258,289,3,38,19,10,259,260,10,8,0,0,260,261,5,29,0,
  	0,261,289,3,38,19,9,262,263,10,7,0,0,263,264,5,31,0,0,264,289,3,38,19,
  	8,265,266,10,6,0,0,266,267,5,32,0,0,267,289,3,38,19,7,268,269,10,5,0,
  	0,269,270,5,33,0,0,270,289,3,38,19,6,271,272,10,23,0,0,272,273,5,43,0,
  	0,273,289,3,36,18,0,274,275,10,20,0,0,275,289,5,41,0,0,276,277,10,18,
  	0,0,277,289,5,42,0,0,278,279,10,4,0,0,279,280,5,17,0,0,280,281,3,50,25,
  	0,281,282,5,18,0,0,282,289,1,0,0,0,283,284,10,3,0,0,284,285,5,17,0,0,
  	285,286,3,38,19,0,286,287,5,18,0,0,287,289,1,0,0,0,288,232,1,0,0,0,288,
  	235,1,0,0,0,288,238,1,0,0,0,288,241,1,0,0,0,288,244,1,0,0,0,288,247,1,
  	0,0,0,288,250,1,0,0,0,288,253,1,0,0,0,288,256,1,0,0,0,288,259,1,0,0,0,
  	288,262,1,0,0,0,288,265,1,0,0,0,288,268,1,0,0,0,288,271,1,0,0,0,288,274,
  	1,0,0,0,288,276,1,0,0,0,288,278,1,0,0,0,288,283,1,0,0,0,289,292,1,0,0,
  	0,290,288,1,0,0,0,290,291,1,0,0,0,291,39,1,0,0,0,292,290,1,0,0,0,293,
  	294,3,38,19,0,294,295,5,17,0,0,295,296,3,38,19,0,296,297,5,18,0,0,297,
  	300,1,0,0,0,298,300,5,50,0,0,299,293,1,0,0,0,299,298,1,0,0,0,300,41,1,
  	0,0,0,301,302,3,38,19,0,302,303,5,21,0,0,303,304,3,38,19,0,304,43,1,0,
  	0,0,305,318,5,19,0,0,306,308,3,42,21,0,307,306,1,0,0,0,307,308,1,0,0,
  	0,308,319,1,0,0,0,309,311,3,42,21,0,310,309,1,0,0,0,310,311,1,0,0,0,311,
  	314,1,0,0,0,312,313,5,23,0,0,313,315,3,42,21,0,314,312,1,0,0,0,315,316,
  	1,0,0,0,316,314,1,0,0,0,316,317,1,0,0,0,317,319,1,0,0,0,318,307,1,0,0,
  	0,318,310,1,0,0,0,319,321,1,0,0,0,320,322,5,23,0,0,321,320,1,0,0,0,321,
  	322,1,0,0,0,322,323,1,0,0,0,323,324,5,20,0,0,324,45,1,0,0,0,325,338,5,
  	17,0,0,326,328,3,38,19,0,327,326,1,0,0,0,327,328,1,0,0,0,328,339,1,0,
  	0,0,329,331,3,38,19,0,330,329,1,0,0,0,330,331,1,0,0,0,331,334,1,0,0,0,
  	332,333,5,23,0,0,333,335,3,38,19,0,334,332,1,0,0,0,335,336,1,0,0,0,336,
  	334,1,0,0,0,336,337,1,0,0,0,337,339,1,0,0,0,338,327,1,0,0,0,338,330,1,
  	0,0,0,339,340,1,0,0,0,340,341,5,18,0,0,341,47,1,0,0,0,342,355,5,15,0,
  	0,343,345,3,38,19,0,344,343,1,0,0,0,344,345,1,0,0,0,345,356,1,0,0,0,346,
  	348,3,38,19,0,347,346,1,0,0,0,347,348,1,0,0,0,348,351,1,0,0,0,349,350,
  	5,23,0,0,350,352,3,38,19,0,351,349,1,0,0,0,352,353,1,0,0,0,353,351,1,
  	0,0,0,353,354,1,0,0,0,354,356,1,0,0,0,355,344,1,0,0,0,355,347,1,0,0,0,
  	356,357,1,0,0,0,357,358,5,16,0,0,358,49,1,0,0,0,359,361,3,38,19,0,360,
  	359,1,0,0,0,360,361,1,0,0,0,361,362,1,0,0,0,362,364,5,21,0,0,363,365,
  	3,38,19,0,364,363,1,0,0,0,364,365,1,0,0,0,365,367,1,0,0,0,366,368,5,21,
  	0,0,367,366,1,0,0,0,367,368,1,0,0,0,368,370,1,0,0,0,369,371,3,38,19,0,
  	370,369,1,0,0,0,370,371,1,0,0,0,371,51,1,0,0,0,372,380,5,51,0,0,373,380,
  	5,52,0,0,374,380,5,53,0,0,375,380,5,49,0,0,376,380,3,44,22,0,377,380,
  	3,46,23,0,378,380,3,48,24,0,379,372,1,0,0,0,379,373,1,0,0,0,379,374,1,
  	0,0,0,379,375,1,0,0,0,379,376,1,0,0,0,379,377,1,0,0,0,379,378,1,0,0,0,
  	380,53,1,0,0,0,46,57,63,70,79,84,90,102,106,110,117,124,128,136,150,168,
  	170,175,187,194,196,199,206,208,211,230,288,290,299,307,310,316,318,321,
  	327,330,336,338,344,347,353,355,360,364,367,370,379
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
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::KW_IMPORT) {
      setState(54);
      import_statement();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(60);
      statement();
      setState(63); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17458045626535608) != 0));
    setState(65);
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
    setState(67);
    match(TythonParser::KW_IMPORT);
    setState(68);
    import_path();
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(69);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(72);
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
    setState(74);
    match(TythonParser::IDENTIFIER);
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::SYM_DOT) {
      setState(75);
      match(TythonParser::SYM_DOT);
      setState(76);
      match(TythonParser::IDENTIFIER);
      setState(81);
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
    setState(82);
    match(TythonParser::KW_DEF);
    setState(84);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(83);
      match(TythonParser::KW_EXTERN);
    }
    setState(86);
    match(TythonParser::IDENTIFIER);
    setState(87);
    match(TythonParser::SYM_LPAR);
    setState(88);
    arguments();
    setState(90);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_ELLIPS) {
      setState(89);
      match(TythonParser::SYM_ELLIPS);
    }
    setState(92);
    match(TythonParser::SYM_RPAR);
    setState(93);
    match(TythonParser::SYM_COL);
    setState(94);
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
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_BREAK:
      case TythonParser::KW_EXTERN:
      case TythonParser::KW_EWOUT:
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
        setState(96);
        simple_statements();
        break;
      }

      case TythonParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(97);
        match(TythonParser::NEWLINE);
        setState(98);
        match(TythonParser::INDENT);
        setState(100); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(99);
          antlrcpp::downCast<BlockContext *>(_localctx)->indent_statements = statement();
          setState(102); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 17458045626535608) != 0));
        setState(104);
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
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_RETURN:
      case TythonParser::KW_BREAK:
      case TythonParser::KW_EXTERN:
      case TythonParser::KW_EWOUT:
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
        setState(108);
        simple_statements();
        break;
      }

      case TythonParser::KW_DEF:
      case TythonParser::KW_IF:
      case TythonParser::KW_FOR:
      case TythonParser::KW_WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(109);
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

TythonParser::Ewout_statementContext* TythonParser::Simple_statementContext::ewout_statement() {
  return getRuleContext<TythonParser::Ewout_statementContext>(0);
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
      setState(112);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(113);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(114);
      break_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(115);
      return_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(116);
      ewout_statement();
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
    setState(136);
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

      case TythonParser::KW_WHILE: {
        enterOuterAlt(_localctx, 4);
        setState(135);
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
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_assign_statementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(138);
      lval();
      setState(139);
      match(TythonParser::SYM_ASSIGN);
      setState(140);
      expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_assign_plus_eqContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(142);
      lval();
      setState(143);
      match(TythonParser::SYM_PLUS_EQ);
      setState(144);
      expression(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_assign_minus_eqContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(146);
      lval();
      setState(147);
      match(TythonParser::SYM_MINUS_EQ);
      setState(148);
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
    setState(152);
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
    setState(154);
    match(TythonParser::KW_RETURN);
    setState(155);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ewout_statementContext ------------------------------------------------------------------

TythonParser::Ewout_statementContext::Ewout_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TythonParser::Ewout_statementContext::KW_EWOUT() {
  return getToken(TythonParser::KW_EWOUT, 0);
}

TythonParser::ExpressionContext* TythonParser::Ewout_statementContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}


size_t TythonParser::Ewout_statementContext::getRuleIndex() const {
  return TythonParser::RuleEwout_statement;
}


std::any TythonParser::Ewout_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitEwout_statement(this);
  else
    return visitor->visitChildren(this);
}

TythonParser::Ewout_statementContext* TythonParser::ewout_statement() {
  Ewout_statementContext *_localctx = _tracker.createInstance<Ewout_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, TythonParser::RuleEwout_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(TythonParser::KW_EWOUT);
    setState(158);
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
  enterRule(_localctx, 26, TythonParser::RuleIf_statement);
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
    setState(160);
    match(TythonParser::KW_IF);
    setState(161);
    expression(0);
    setState(162);
    match(TythonParser::SYM_COL);
    setState(163);
    antlrcpp::downCast<If_statementContext *>(_localctx)->br_if = block();
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_ELSE) {
      setState(164);
      match(TythonParser::KW_ELSE);
      setState(168);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TythonParser::KW_IF: {
          setState(165);
          antlrcpp::downCast<If_statementContext *>(_localctx)->br_else_if = if_statement();
          break;
        }

        case TythonParser::SYM_COL: {
          setState(166);
          match(TythonParser::SYM_COL);
          setState(167);
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
  enterRule(_localctx, 28, TythonParser::RuleFor_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(TythonParser::KW_FOR);
    setState(175);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(173);
      match(TythonParser::IDENTIFIER);
      setState(174);
      match(TythonParser::KW_IN);
      break;
    }

    default:
      break;
    }
    setState(177);
    expression(0);
    setState(178);
    match(TythonParser::SYM_COL);
    setState(179);
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
  enterRule(_localctx, 30, TythonParser::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(TythonParser::KW_WHILE);
    setState(182);
    expression(0);
    setState(183);
    match(TythonParser::SYM_COL);
    setState(184);
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
  enterRule(_localctx, 32, TythonParser::RuleArguments);
  size_t _la = 0;

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(187);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TythonParser::IDENTIFIER) {
        setState(186);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(189);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
      setState(192); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(190);
        match(TythonParser::SYM_COMMA);
        setState(191);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken = match(TythonParser::IDENTIFIER);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->args.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->identifierToken);
        setState(194); 
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
  enterRule(_localctx, 34, TythonParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(199);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(198);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
      antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
      setState(204); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(202);
        match(TythonParser::SYM_COMMA);
        setState(203);
        antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<ParametersContext *>(_localctx)->params.push_back(antlrcpp::downCast<ParametersContext *>(_localctx)->expressionContext);
        setState(206); 
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
  enterRule(_localctx, 36, TythonParser::RuleCall_expression);
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
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(210);
      match(TythonParser::KW_EXTERN);
    }
    setState(213);
    match(TythonParser::IDENTIFIER);
    setState(214);
    match(TythonParser::SYM_LPAR);
    setState(215);
    parameters();
    setState(216);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, TythonParser::RuleExpression, precedence);

    

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
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Lbl_expression_parenthesesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(219);
      match(TythonParser::SYM_LPAR);
      setState(220);
      expression(0);
      setState(221);
      match(TythonParser::SYM_RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Lbl_call_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      call_expression();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lbl_inc_prefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(224);
      match(TythonParser::SYM_INC);
      setState(225);
      expression(21);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Lbl_dec_prefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(226);
      match(TythonParser::SYM_DEC);
      setState(227);
      expression(19);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Lbl_literalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(228);
      literal();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Lbl_identifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(229);
      match(TythonParser::IDENTIFIER);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(290);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(288);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Lbl_exponent_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(232);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(233);
          match(TythonParser::SYM_EXP);
          setState(234);
          antlrcpp::downCast<Lbl_exponent_exprContext *>(_localctx)->rhs = expression(18);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Lbl_mult_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(235);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(236);
          match(TythonParser::SYM_MULT);
          setState(237);
          antlrcpp::downCast<Lbl_mult_exprContext *>(_localctx)->rhs = expression(17);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Lbl_div_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(238);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(239);
          match(TythonParser::SYM_DIV);
          setState(240);
          antlrcpp::downCast<Lbl_div_exprContext *>(_localctx)->rhs = expression(16);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Lbl_add_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(241);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(242);
          match(TythonParser::SYM_PLUS);
          setState(243);
          antlrcpp::downCast<Lbl_add_exprContext *>(_localctx)->rhs = expression(15);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Lbl_sub_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(244);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(245);
          match(TythonParser::SYM_MINUS);
          setState(246);
          antlrcpp::downCast<Lbl_sub_exprContext *>(_localctx)->rhs = expression(14);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Lbl_and_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(247);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(248);
          match(TythonParser::SYM_AND);
          setState(249);
          antlrcpp::downCast<Lbl_and_exprContext *>(_localctx)->rhs = expression(13);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Lbl_or_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(250);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(251);
          match(TythonParser::SYM_OR);
          setState(252);
          antlrcpp::downCast<Lbl_or_exprContext *>(_localctx)->rhs = expression(12);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Lbl_neq_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(253);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(254);
          match(TythonParser::SYM_NEQ);
          setState(255);
          antlrcpp::downCast<Lbl_neq_exprContext *>(_localctx)->rhs = expression(11);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Lbl_lt_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(256);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(257);
          match(TythonParser::SYM_LT);
          setState(258);
          antlrcpp::downCast<Lbl_lt_exprContext *>(_localctx)->rhs = expression(10);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Lbl_lte_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(259);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(260);
          match(TythonParser::SYM_LTE);
          setState(261);
          antlrcpp::downCast<Lbl_lte_exprContext *>(_localctx)->rhs = expression(9);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Lbl_eq_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(262);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(263);
          match(TythonParser::SYM_EQ);
          setState(264);
          antlrcpp::downCast<Lbl_eq_exprContext *>(_localctx)->rhs = expression(8);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Lbl_gt_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(265);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(266);
          match(TythonParser::SYM_GT);
          setState(267);
          antlrcpp::downCast<Lbl_gt_exprContext *>(_localctx)->rhs = expression(7);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Lbl_gte_exprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(268);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(269);
          match(TythonParser::SYM_GTE);
          setState(270);
          antlrcpp::downCast<Lbl_gte_exprContext *>(_localctx)->rhs = expression(6);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Lbl_method_callContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(271);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(272);
          match(TythonParser::SYM_DOT);
          setState(273);
          call_expression();
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Lbl_inc_suffixContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(274);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(275);
          match(TythonParser::SYM_INC);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Lbl_dec_suffixContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(276);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(277);
          match(TythonParser::SYM_DEC);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Lbl_slice_accessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(278);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(279);
          match(TythonParser::SYM_LSQ);
          setState(280);
          slice_lit();
          setState(281);
          match(TythonParser::SYM_RSQ);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Lbl_key_accessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->obj = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(283);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(284);
          match(TythonParser::SYM_LSQ);
          setState(285);
          antlrcpp::downCast<Lbl_key_accessContext *>(_localctx)->key = expression(0);
          setState(286);
          match(TythonParser::SYM_RSQ);
          break;
        }

        default:
          break;
        } 
      }
      setState(292);
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


size_t TythonParser::LvalContext::getRuleIndex() const {
  return TythonParser::RuleLval;
}

void TythonParser::LvalContext::copyFrom(LvalContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Lbl_lval_identifierContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_lval_identifierContext::IDENTIFIER() {
  return getToken(TythonParser::IDENTIFIER, 0);
}

TythonParser::Lbl_lval_identifierContext::Lbl_lval_identifierContext(LvalContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_lval_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_lval_identifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_lval_key_accessContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_lval_key_accessContext::SYM_LSQ() {
  return getToken(TythonParser::SYM_LSQ, 0);
}

tree::TerminalNode* TythonParser::Lbl_lval_key_accessContext::SYM_RSQ() {
  return getToken(TythonParser::SYM_RSQ, 0);
}

std::vector<TythonParser::ExpressionContext *> TythonParser::Lbl_lval_key_accessContext::expression() {
  return getRuleContexts<TythonParser::ExpressionContext>();
}

TythonParser::ExpressionContext* TythonParser::Lbl_lval_key_accessContext::expression(size_t i) {
  return getRuleContext<TythonParser::ExpressionContext>(i);
}

TythonParser::Lbl_lval_key_accessContext::Lbl_lval_key_accessContext(LvalContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_lval_key_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_lval_key_access(this);
  else
    return visitor->visitChildren(this);
}
TythonParser::LvalContext* TythonParser::lval() {
  LvalContext *_localctx = _tracker.createInstance<LvalContext>(_ctx, getState());
  enterRule(_localctx, 40, TythonParser::RuleLval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_lval_key_accessContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(293);
      antlrcpp::downCast<Lbl_lval_key_accessContext *>(_localctx)->obj = expression(0);
      setState(294);
      match(TythonParser::SYM_LSQ);
      setState(295);
      antlrcpp::downCast<Lbl_lval_key_accessContext *>(_localctx)->key = expression(0);
      setState(296);
      match(TythonParser::SYM_RSQ);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_lval_identifierContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(298);
      match(TythonParser::IDENTIFIER);
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
  enterRule(_localctx, 42, TythonParser::RuleKey_value_pair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    antlrcpp::downCast<Key_value_pairContext *>(_localctx)->key = expression(0);
    setState(302);
    match(TythonParser::SYM_COL);
    setState(303);
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
  enterRule(_localctx, 44, TythonParser::RuleDict_lit);
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
    setState(305);
    match(TythonParser::SYM_LBR);
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(307);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(306);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      break;
    }

    case 2: {
      setState(310);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(309);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      setState(314); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(312);
                match(TythonParser::SYM_COMMA);
                setState(313);
                antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
                antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(316); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    default:
      break;
    }
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_COMMA) {
      setState(320);
      match(TythonParser::SYM_COMMA);
    }
    setState(323);
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
  enterRule(_localctx, 46, TythonParser::RuleList_lit);
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
    setState(325);
    match(TythonParser::SYM_LSQ);
    setState(338);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(327);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(326);
        antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      setState(330);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(329);
        antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext);
      }
      setState(334); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(332);
        match(TythonParser::SYM_COMMA);
        setState(333);
        antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->expressionContext);
        setState(336); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(340);
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
  enterRule(_localctx, 48, TythonParser::RuleTuple_lit);
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
    setState(342);
    match(TythonParser::SYM_LPAR);
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(344);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(343);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext);
      }
      break;
    }

    case 2: {
      setState(347);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17458045626517504) != 0)) {
        setState(346);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext);
      }
      setState(351); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(349);
        match(TythonParser::SYM_COMMA);
        setState(350);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext = expression(0);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->expressionContext);
        setState(353); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(357);
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
  enterRule(_localctx, 50, TythonParser::RuleSlice_lit);
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
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17458045626517504) != 0)) {
      setState(359);
      antlrcpp::downCast<Slice_litContext *>(_localctx)->start = expression(0);
    }
    setState(362);
    match(TythonParser::SYM_COL);
    setState(364);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(363);
      antlrcpp::downCast<Slice_litContext *>(_localctx)->end = expression(0);
      break;
    }

    default:
      break;
    }
    setState(367);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_COL) {
      setState(366);
      match(TythonParser::SYM_COL);
    }
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17458045626517504) != 0)) {
      setState(369);
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
  enterRule(_localctx, 52, TythonParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(379);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::INT_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(372);
        match(TythonParser::INT_LIT);
        break;
      }

      case TythonParser::FLOAT_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(373);
        match(TythonParser::FLOAT_LIT);
        break;
      }

      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 3);
        setState(374);
        match(TythonParser::STR_LIT);
        break;
      }

      case TythonParser::NONE_LIT: {
        enterOuterAlt(_localctx, 4);
        setState(375);
        match(TythonParser::NONE_LIT);
        break;
      }

      case TythonParser::SYM_LBR: {
        enterOuterAlt(_localctx, 5);
        setState(376);
        dict_lit();
        break;
      }

      case TythonParser::SYM_LSQ: {
        enterOuterAlt(_localctx, 6);
        setState(377);
        list_lit();
        break;
      }

      case TythonParser::SYM_LPAR: {
        enterOuterAlt(_localctx, 7);
        setState(378);
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
    case 19: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TythonParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 17);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 12);
    case 6: return precpred(_ctx, 11);
    case 7: return precpred(_ctx, 10);
    case 8: return precpred(_ctx, 9);
    case 9: return precpred(_ctx, 8);
    case 10: return precpred(_ctx, 7);
    case 11: return precpred(_ctx, 6);
    case 12: return precpred(_ctx, 5);
    case 13: return precpred(_ctx, 23);
    case 14: return precpred(_ctx, 20);
    case 15: return precpred(_ctx, 18);
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
