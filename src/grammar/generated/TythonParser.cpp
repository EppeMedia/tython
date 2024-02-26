
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
      "expression", "binary_operator", "inequality_operator", "logic_operator", 
      "arithmetic_operator", "rval", "access_key", "lval", "key_value_pair", 
      "dict_lit", "list_lit", "tuple_lit", "literal"
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
  	4,1,54,344,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,1,0,5,0,64,8,0,10,0,12,0,67,9,0,1,0,4,0,70,8,0,
  	11,0,12,0,71,1,0,1,0,1,1,1,1,1,1,3,1,79,8,1,1,1,1,1,1,2,1,2,1,2,5,2,86,
  	8,2,10,2,12,2,89,9,2,1,3,1,3,3,3,93,8,3,1,3,1,3,1,3,1,3,3,3,99,8,3,1,
  	3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,4,4,109,8,4,11,4,12,4,110,1,4,1,4,3,4,115,
  	8,4,1,5,1,5,3,5,119,8,5,1,6,1,6,1,6,1,6,3,6,125,8,6,1,7,1,7,1,7,5,7,130,
  	8,7,10,7,12,7,133,9,7,1,7,3,7,136,8,7,1,7,1,7,1,8,1,8,1,8,1,8,3,8,144,
  	8,8,1,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,3,12,163,8,12,3,12,165,8,12,1,13,1,13,1,13,3,13,170,8,
  	13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,3,15,182,8,15,1,
  	15,1,15,1,15,4,15,187,8,15,11,15,12,15,188,3,15,191,8,15,1,16,3,16,194,
  	8,16,1,16,1,16,1,16,4,16,199,8,16,11,16,12,16,200,3,16,203,8,16,1,17,
  	3,17,206,8,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,230,8,18,
  	1,18,1,18,1,18,1,18,5,18,236,8,18,10,18,12,18,239,9,18,1,19,1,19,1,19,
  	3,19,244,8,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,3,23,254,8,23,1,
  	24,3,24,257,8,24,1,24,1,24,3,24,261,8,24,1,24,3,24,264,8,24,1,24,3,24,
  	267,8,24,1,24,3,24,270,8,24,1,25,1,25,1,25,1,25,1,25,1,25,3,25,278,8,
  	25,1,26,1,26,1,26,1,26,1,27,1,27,3,27,286,8,27,1,27,3,27,289,8,27,1,27,
  	1,27,4,27,293,8,27,11,27,12,27,294,3,27,297,8,27,1,27,1,27,1,28,1,28,
  	3,28,303,8,28,1,28,3,28,306,8,28,1,28,1,28,4,28,310,8,28,11,28,12,28,
  	311,3,28,314,8,28,1,28,1,28,1,29,1,29,3,29,320,8,29,1,29,3,29,323,8,29,
  	1,29,1,29,4,29,327,8,29,11,29,12,29,328,3,29,331,8,29,1,29,1,29,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,3,30,342,8,30,1,30,0,1,36,31,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,0,3,1,0,25,30,1,0,31,32,1,0,33,37,373,0,65,1,0,0,0,2,75,1,0,
  	0,0,4,82,1,0,0,0,6,90,1,0,0,0,8,114,1,0,0,0,10,118,1,0,0,0,12,124,1,0,
  	0,0,14,126,1,0,0,0,16,143,1,0,0,0,18,145,1,0,0,0,20,149,1,0,0,0,22,151,
  	1,0,0,0,24,154,1,0,0,0,26,166,1,0,0,0,28,175,1,0,0,0,30,190,1,0,0,0,32,
  	202,1,0,0,0,34,205,1,0,0,0,36,229,1,0,0,0,38,243,1,0,0,0,40,245,1,0,0,
  	0,42,247,1,0,0,0,44,249,1,0,0,0,46,253,1,0,0,0,48,269,1,0,0,0,50,277,
  	1,0,0,0,52,279,1,0,0,0,54,283,1,0,0,0,56,300,1,0,0,0,58,317,1,0,0,0,60,
  	341,1,0,0,0,62,64,3,2,1,0,63,62,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,
  	66,1,0,0,0,66,69,1,0,0,0,67,65,1,0,0,0,68,70,3,10,5,0,69,68,1,0,0,0,70,
  	71,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,73,1,0,0,0,73,74,5,0,0,1,74,
  	1,1,0,0,0,75,76,5,12,0,0,76,78,3,4,2,0,77,79,5,21,0,0,78,77,1,0,0,0,78,
  	79,1,0,0,0,79,80,1,0,0,0,80,81,5,51,0,0,81,3,1,0,0,0,82,87,5,47,0,0,83,
  	84,5,40,0,0,84,86,5,47,0,0,85,83,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,
  	87,88,1,0,0,0,88,5,1,0,0,0,89,87,1,0,0,0,90,92,5,3,0,0,91,93,5,11,0,0,
  	92,91,1,0,0,0,92,93,1,0,0,0,93,94,1,0,0,0,94,95,5,47,0,0,95,96,5,14,0,
  	0,96,98,3,30,15,0,97,99,5,41,0,0,98,97,1,0,0,0,98,99,1,0,0,0,99,100,1,
  	0,0,0,100,101,5,15,0,0,101,102,5,20,0,0,102,103,3,8,4,0,103,7,1,0,0,0,
  	104,115,3,14,7,0,105,106,5,51,0,0,106,108,5,1,0,0,107,109,3,10,5,0,108,
  	107,1,0,0,0,109,110,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,112,1,
  	0,0,0,112,113,5,2,0,0,113,115,1,0,0,0,114,104,1,0,0,0,114,105,1,0,0,0,
  	115,9,1,0,0,0,116,119,3,14,7,0,117,119,3,16,8,0,118,116,1,0,0,0,118,117,
  	1,0,0,0,119,11,1,0,0,0,120,125,3,36,18,0,121,125,3,18,9,0,122,125,3,20,
  	10,0,123,125,3,22,11,0,124,120,1,0,0,0,124,121,1,0,0,0,124,122,1,0,0,
  	0,124,123,1,0,0,0,125,13,1,0,0,0,126,131,3,12,6,0,127,128,5,21,0,0,128,
  	130,3,12,6,0,129,127,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,132,
  	1,0,0,0,132,135,1,0,0,0,133,131,1,0,0,0,134,136,5,21,0,0,135,134,1,0,
  	0,0,135,136,1,0,0,0,136,137,1,0,0,0,137,138,5,51,0,0,138,15,1,0,0,0,139,
  	144,3,24,12,0,140,144,3,6,3,0,141,144,3,26,13,0,142,144,3,28,14,0,143,
  	139,1,0,0,0,143,140,1,0,0,0,143,141,1,0,0,0,143,142,1,0,0,0,144,17,1,
  	0,0,0,145,146,3,50,25,0,146,147,5,24,0,0,147,148,3,36,18,0,148,19,1,0,
  	0,0,149,150,5,10,0,0,150,21,1,0,0,0,151,152,5,4,0,0,152,153,3,36,18,0,
  	153,23,1,0,0,0,154,155,5,5,0,0,155,156,3,36,18,0,156,157,5,20,0,0,157,
  	164,3,8,4,0,158,162,5,6,0,0,159,163,3,24,12,0,160,161,5,20,0,0,161,163,
  	3,8,4,0,162,159,1,0,0,0,162,160,1,0,0,0,163,165,1,0,0,0,164,158,1,0,0,
  	0,164,165,1,0,0,0,165,25,1,0,0,0,166,169,5,7,0,0,167,168,5,47,0,0,168,
  	170,5,8,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,171,1,0,0,0,171,172,3,
  	36,18,0,172,173,5,20,0,0,173,174,3,8,4,0,174,27,1,0,0,0,175,176,5,9,0,
  	0,176,177,3,36,18,0,177,178,5,20,0,0,178,179,3,8,4,0,179,29,1,0,0,0,180,
  	182,5,47,0,0,181,180,1,0,0,0,181,182,1,0,0,0,182,191,1,0,0,0,183,186,
  	5,47,0,0,184,185,5,22,0,0,185,187,5,47,0,0,186,184,1,0,0,0,187,188,1,
  	0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,191,1,0,0,0,190,181,1,0,0,0,
  	190,183,1,0,0,0,191,31,1,0,0,0,192,194,3,36,18,0,193,192,1,0,0,0,193,
  	194,1,0,0,0,194,203,1,0,0,0,195,198,3,36,18,0,196,197,5,22,0,0,197,199,
  	3,36,18,0,198,196,1,0,0,0,199,200,1,0,0,0,200,198,1,0,0,0,200,201,1,0,
  	0,0,201,203,1,0,0,0,202,193,1,0,0,0,202,195,1,0,0,0,203,33,1,0,0,0,204,
  	206,5,11,0,0,205,204,1,0,0,0,205,206,1,0,0,0,206,207,1,0,0,0,207,208,
  	5,47,0,0,208,209,5,14,0,0,209,210,3,32,16,0,210,211,5,15,0,0,211,35,1,
  	0,0,0,212,213,6,18,-1,0,213,230,3,34,17,0,214,215,5,14,0,0,215,216,3,
  	36,18,0,216,217,5,15,0,0,217,230,1,0,0,0,218,230,3,46,23,0,219,220,5,
  	38,0,0,220,230,3,50,25,0,221,222,3,50,25,0,222,223,5,38,0,0,223,230,1,
  	0,0,0,224,225,5,39,0,0,225,230,3,50,25,0,226,227,3,50,25,0,227,228,5,
  	39,0,0,228,230,1,0,0,0,229,212,1,0,0,0,229,214,1,0,0,0,229,218,1,0,0,
  	0,229,219,1,0,0,0,229,221,1,0,0,0,229,224,1,0,0,0,229,226,1,0,0,0,230,
  	237,1,0,0,0,231,232,10,8,0,0,232,233,3,38,19,0,233,234,3,36,18,9,234,
  	236,1,0,0,0,235,231,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,1,
  	0,0,0,238,37,1,0,0,0,239,237,1,0,0,0,240,244,3,40,20,0,241,244,3,42,21,
  	0,242,244,3,44,22,0,243,240,1,0,0,0,243,241,1,0,0,0,243,242,1,0,0,0,244,
  	39,1,0,0,0,245,246,7,0,0,0,246,41,1,0,0,0,247,248,7,1,0,0,248,43,1,0,
  	0,0,249,250,7,2,0,0,250,45,1,0,0,0,251,254,3,60,30,0,252,254,3,50,25,
  	0,253,251,1,0,0,0,253,252,1,0,0,0,254,47,1,0,0,0,255,257,3,46,23,0,256,
  	255,1,0,0,0,256,257,1,0,0,0,257,258,1,0,0,0,258,260,5,20,0,0,259,261,
  	3,46,23,0,260,259,1,0,0,0,260,261,1,0,0,0,261,263,1,0,0,0,262,264,5,20,
  	0,0,263,262,1,0,0,0,263,264,1,0,0,0,264,266,1,0,0,0,265,267,3,46,23,0,
  	266,265,1,0,0,0,266,267,1,0,0,0,267,270,1,0,0,0,268,270,3,36,18,0,269,
  	256,1,0,0,0,269,268,1,0,0,0,270,49,1,0,0,0,271,278,5,47,0,0,272,273,5,
  	47,0,0,273,274,5,16,0,0,274,275,3,48,24,0,275,276,5,17,0,0,276,278,1,
  	0,0,0,277,271,1,0,0,0,277,272,1,0,0,0,278,51,1,0,0,0,279,280,3,36,18,
  	0,280,281,5,20,0,0,281,282,3,36,18,0,282,53,1,0,0,0,283,296,5,18,0,0,
  	284,286,3,52,26,0,285,284,1,0,0,0,285,286,1,0,0,0,286,297,1,0,0,0,287,
  	289,3,52,26,0,288,287,1,0,0,0,288,289,1,0,0,0,289,292,1,0,0,0,290,291,
  	5,22,0,0,291,293,3,52,26,0,292,290,1,0,0,0,293,294,1,0,0,0,294,292,1,
  	0,0,0,294,295,1,0,0,0,295,297,1,0,0,0,296,285,1,0,0,0,296,288,1,0,0,0,
  	297,298,1,0,0,0,298,299,5,19,0,0,299,55,1,0,0,0,300,313,5,16,0,0,301,
  	303,3,46,23,0,302,301,1,0,0,0,302,303,1,0,0,0,303,314,1,0,0,0,304,306,
  	3,46,23,0,305,304,1,0,0,0,305,306,1,0,0,0,306,309,1,0,0,0,307,308,5,22,
  	0,0,308,310,3,46,23,0,309,307,1,0,0,0,310,311,1,0,0,0,311,309,1,0,0,0,
  	311,312,1,0,0,0,312,314,1,0,0,0,313,302,1,0,0,0,313,305,1,0,0,0,314,315,
  	1,0,0,0,315,316,5,17,0,0,316,57,1,0,0,0,317,330,5,14,0,0,318,320,3,46,
  	23,0,319,318,1,0,0,0,319,320,1,0,0,0,320,331,1,0,0,0,321,323,3,46,23,
  	0,322,321,1,0,0,0,322,323,1,0,0,0,323,326,1,0,0,0,324,325,5,22,0,0,325,
  	327,3,46,23,0,326,324,1,0,0,0,327,328,1,0,0,0,328,326,1,0,0,0,328,329,
  	1,0,0,0,329,331,1,0,0,0,330,319,1,0,0,0,330,322,1,0,0,0,331,332,1,0,0,
  	0,332,333,5,15,0,0,333,59,1,0,0,0,334,342,5,48,0,0,335,342,5,49,0,0,336,
  	342,5,50,0,0,337,342,5,46,0,0,338,342,3,54,27,0,339,342,3,56,28,0,340,
  	342,3,58,29,0,341,334,1,0,0,0,341,335,1,0,0,0,341,336,1,0,0,0,341,337,
  	1,0,0,0,341,338,1,0,0,0,341,339,1,0,0,0,341,340,1,0,0,0,342,61,1,0,0,
  	0,46,65,71,78,87,92,98,110,114,118,124,131,135,143,162,164,169,181,188,
  	190,193,200,202,205,229,237,243,253,256,260,263,266,269,277,285,288,294,
  	296,302,305,311,313,319,322,328,330,341
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
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::KW_IMPORT) {
      setState(62);
      import_statement();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(68);
      statement();
      setState(71); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2182255703576248) != 0));
    setState(73);
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
    setState(75);
    match(TythonParser::KW_IMPORT);
    setState(76);
    import_path();
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(77);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(80);
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
    setState(82);
    match(TythonParser::IDENTIFIER);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TythonParser::SYM_DOT) {
      setState(83);
      match(TythonParser::SYM_DOT);
      setState(84);
      match(TythonParser::IDENTIFIER);
      setState(89);
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
    setState(90);
    match(TythonParser::KW_DEF);
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::KW_EXTERN) {
      setState(91);
      match(TythonParser::KW_EXTERN);
    }
    setState(94);
    match(TythonParser::IDENTIFIER);
    setState(95);
    match(TythonParser::SYM_LPAR);
    setState(96);
    arguments();
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_ELLIPS) {
      setState(97);
      match(TythonParser::SYM_ELLIPS);
    }
    setState(100);
    match(TythonParser::SYM_RPAR);
    setState(101);
    match(TythonParser::SYM_COL);
    setState(102);
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
    setState(114);
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
        setState(104);
        simple_statements();
        break;
      }

      case TythonParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        match(TythonParser::NEWLINE);
        setState(106);
        match(TythonParser::INDENT);
        setState(108); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(107);
          antlrcpp::downCast<BlockContext *>(_localctx)->indent_statements = statement();
          setState(110); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2182255703576248) != 0));
        setState(112);
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
    setState(118);
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
        setState(116);
        simple_statements();
        break;
      }

      case TythonParser::KW_DEF:
      case TythonParser::KW_IF:
      case TythonParser::KW_FOR:
      case TythonParser::KW_WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(117);
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
    setState(124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(121);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(122);
      break_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(123);
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
    setState(126);
    simple_statement();
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(127);
        match(TythonParser::SYM_SEMCOL);
        setState(128);
        simple_statement(); 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TythonParser::SYM_SEMCOL) {
      setState(134);
      match(TythonParser::SYM_SEMCOL);
    }
    setState(137);
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
    setState(143);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::KW_IF: {
        enterOuterAlt(_localctx, 1);
        setState(139);
        if_statement();
        break;
      }

      case TythonParser::KW_DEF: {
        enterOuterAlt(_localctx, 2);
        setState(140);
        function_def();
        break;
      }

      case TythonParser::KW_FOR: {
        enterOuterAlt(_localctx, 3);
        setState(141);
        for_loop();
        break;
      }

      case TythonParser::KW_WHILE: {
        enterOuterAlt(_localctx, 4);
        setState(142);
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
    setState(145);
    lval();
    setState(146);
    match(TythonParser::SYM_ASSIGN);
    setState(147);
    expression(0);
   
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

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2182255703574528) != 0)) {
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
//----------------- Lbl_inc_prefixContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lbl_inc_prefixContext::SYM_INC() {
  return getToken(TythonParser::SYM_INC, 0);
}

TythonParser::LvalContext* TythonParser::Lbl_inc_prefixContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}

TythonParser::Lbl_inc_prefixContext::Lbl_inc_prefixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_inc_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_inc_prefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lcl_dec_suffixContext ------------------------------------------------------------------

TythonParser::LvalContext* TythonParser::Lcl_dec_suffixContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}

tree::TerminalNode* TythonParser::Lcl_dec_suffixContext::SYM_DEC() {
  return getToken(TythonParser::SYM_DEC, 0);
}

TythonParser::Lcl_dec_suffixContext::Lcl_dec_suffixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lcl_dec_suffixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLcl_dec_suffix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_inc_suffixContext ------------------------------------------------------------------

TythonParser::LvalContext* TythonParser::Lbl_inc_suffixContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
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
//----------------- Lcl_dec_prefixContext ------------------------------------------------------------------

tree::TerminalNode* TythonParser::Lcl_dec_prefixContext::SYM_DEC() {
  return getToken(TythonParser::SYM_DEC, 0);
}

TythonParser::LvalContext* TythonParser::Lcl_dec_prefixContext::lval() {
  return getRuleContext<TythonParser::LvalContext>(0);
}

TythonParser::Lcl_dec_prefixContext::Lcl_dec_prefixContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lcl_dec_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLcl_dec_prefix(this);
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
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Lbl_call_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(213);
      call_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Lbl_expression_parenthesesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(214);
      match(TythonParser::SYM_LPAR);
      setState(215);
      expression(0);
      setState(216);
      match(TythonParser::SYM_RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lbl_rvalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(218);
      rval();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Lbl_inc_prefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(219);
      match(TythonParser::SYM_INC);
      setState(220);
      lval();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Lbl_inc_suffixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(221);
      lval();
      setState(222);
      match(TythonParser::SYM_INC);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Lcl_dec_prefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(224);
      match(TythonParser::SYM_DEC);
      setState(225);
      lval();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Lcl_dec_suffixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(226);
      lval();
      setState(227);
      match(TythonParser::SYM_DEC);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(237);
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
        setState(231);

        if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
        setState(232);
        binary_operator();
        setState(233);
        antlrcpp::downCast<Binary_expressionContext *>(_localctx)->rhs = expression(9); 
      }
      setState(239);
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
  enterRule(_localctx, 38, TythonParser::RuleBinary_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::SYM_NEQ:
      case TythonParser::SYM_LTE:
      case TythonParser::SYM_LT:
      case TythonParser::SYM_EQ:
      case TythonParser::SYM_GT:
      case TythonParser::SYM_GTE: {
        enterOuterAlt(_localctx, 1);
        setState(240);
        inequality_operator();
        break;
      }

      case TythonParser::SYM_AND:
      case TythonParser::SYM_OR: {
        enterOuterAlt(_localctx, 2);
        setState(241);
        logic_operator();
        break;
      }

      case TythonParser::SYM_PLUS:
      case TythonParser::SYM_MINUS:
      case TythonParser::SYM_MULT:
      case TythonParser::SYM_DIV:
      case TythonParser::SYM_EXP: {
        enterOuterAlt(_localctx, 3);
        setState(242);
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
  enterRule(_localctx, 40, TythonParser::RuleInequality_operator);
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
    setState(245);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2113929216) != 0))) {
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
  enterRule(_localctx, 42, TythonParser::RuleLogic_operator);
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
    setState(247);
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
  enterRule(_localctx, 44, TythonParser::RuleArithmetic_operator);
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
    setState(249);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 266287972352) != 0))) {
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
  enterRule(_localctx, 46, TythonParser::RuleRval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(253);
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
        setState(251);
        literal();
        break;
      }

      case TythonParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(252);
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

//----------------- Access_keyContext ------------------------------------------------------------------

TythonParser::Access_keyContext::Access_keyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TythonParser::Access_keyContext::getRuleIndex() const {
  return TythonParser::RuleAccess_key;
}

void TythonParser::Access_keyContext::copyFrom(Access_keyContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Lbl_access_key_sliceContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> TythonParser::Lbl_access_key_sliceContext::SYM_COL() {
  return getTokens(TythonParser::SYM_COL);
}

tree::TerminalNode* TythonParser::Lbl_access_key_sliceContext::SYM_COL(size_t i) {
  return getToken(TythonParser::SYM_COL, i);
}

std::vector<TythonParser::RvalContext *> TythonParser::Lbl_access_key_sliceContext::rval() {
  return getRuleContexts<TythonParser::RvalContext>();
}

TythonParser::RvalContext* TythonParser::Lbl_access_key_sliceContext::rval(size_t i) {
  return getRuleContext<TythonParser::RvalContext>(i);
}

TythonParser::Lbl_access_key_sliceContext::Lbl_access_key_sliceContext(Access_keyContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_access_key_sliceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_access_key_slice(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lbl_access_key_idxContext ------------------------------------------------------------------

TythonParser::ExpressionContext* TythonParser::Lbl_access_key_idxContext::expression() {
  return getRuleContext<TythonParser::ExpressionContext>(0);
}

TythonParser::Lbl_access_key_idxContext::Lbl_access_key_idxContext(Access_keyContext *ctx) { copyFrom(ctx); }


std::any TythonParser::Lbl_access_key_idxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TythonParserVisitor*>(visitor))
    return parserVisitor->visitLbl_access_key_idx(this);
  else
    return visitor->visitChildren(this);
}
TythonParser::Access_keyContext* TythonParser::access_key() {
  Access_keyContext *_localctx = _tracker.createInstance<Access_keyContext>(_ctx, getState());
  enterRule(_localctx, 48, TythonParser::RuleAccess_key);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_access_key_sliceContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(256);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2181431069851648) != 0)) {
        setState(255);
        antlrcpp::downCast<Lbl_access_key_sliceContext *>(_localctx)->start = rval();
      }
      setState(258);
      match(TythonParser::SYM_COL);
      setState(260);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
      case 1: {
        setState(259);
        antlrcpp::downCast<Lbl_access_key_sliceContext *>(_localctx)->end = rval();
        break;
      }

      default:
        break;
      }
      setState(263);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TythonParser::SYM_COL) {
        setState(262);
        match(TythonParser::SYM_COL);
      }
      setState(266);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2181431069851648) != 0)) {
        setState(265);
        antlrcpp::downCast<Lbl_access_key_sliceContext *>(_localctx)->step = rval();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_access_key_idxContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(268);
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

TythonParser::Access_keyContext* TythonParser::Lbl_key_accessContext::access_key() {
  return getRuleContext<TythonParser::Access_keyContext>(0);
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
  enterRule(_localctx, 50, TythonParser::RuleLval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_identifierContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(271);
      match(TythonParser::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TythonParser::Lbl_key_accessContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(272);
      match(TythonParser::IDENTIFIER);
      setState(273);
      match(TythonParser::SYM_LSQ);
      setState(274);
      access_key();
      setState(275);
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
  enterRule(_localctx, 52, TythonParser::RuleKey_value_pair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    antlrcpp::downCast<Key_value_pairContext *>(_localctx)->key = expression(0);
    setState(280);
    match(TythonParser::SYM_COL);
    setState(281);
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
  enterRule(_localctx, 54, TythonParser::RuleDict_lit);
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
    setState(283);
    match(TythonParser::SYM_LBR);
    setState(296);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(285);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2182255703574528) != 0)) {
        setState(284);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      break;
    }

    case 2: {
      setState(288);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2182255703574528) != 0)) {
        setState(287);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
      }
      setState(292); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(290);
        match(TythonParser::SYM_COMMA);
        setState(291);
        antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext = key_value_pair();
        antlrcpp::downCast<Dict_litContext *>(_localctx)->entries.push_back(antlrcpp::downCast<Dict_litContext *>(_localctx)->key_value_pairContext);
        setState(294); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(298);
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
  enterRule(_localctx, 56, TythonParser::RuleList_lit);
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
    setState(300);
    match(TythonParser::SYM_LSQ);
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(302);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2181431069851648) != 0)) {
        setState(301);
        antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext);
      }
      break;
    }

    case 2: {
      setState(305);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2181431069851648) != 0)) {
        setState(304);
        antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext);
      }
      setState(309); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(307);
        match(TythonParser::SYM_COMMA);
        setState(308);
        antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<List_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<List_litContext *>(_localctx)->rvalContext);
        setState(311); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(315);
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
  enterRule(_localctx, 58, TythonParser::RuleTuple_lit);
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
    setState(317);
    match(TythonParser::SYM_LPAR);
    setState(330);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(319);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2181431069851648) != 0)) {
        setState(318);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext);
      }
      break;
    }

    case 2: {
      setState(322);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2181431069851648) != 0)) {
        setState(321);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext);
      }
      setState(326); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(324);
        match(TythonParser::SYM_COMMA);
        setState(325);
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext = rval();
        antlrcpp::downCast<Tuple_litContext *>(_localctx)->elements.push_back(antlrcpp::downCast<Tuple_litContext *>(_localctx)->rvalContext);
        setState(328); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TythonParser::SYM_COMMA);
      break;
    }

    default:
      break;
    }
    setState(332);
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
  enterRule(_localctx, 60, TythonParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(341);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TythonParser::INT_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(334);
        match(TythonParser::INT_LIT);
        break;
      }

      case TythonParser::FLOAT_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(335);
        match(TythonParser::FLOAT_LIT);
        break;
      }

      case TythonParser::STR_LIT: {
        enterOuterAlt(_localctx, 3);
        setState(336);
        match(TythonParser::STR_LIT);
        break;
      }

      case TythonParser::NONE_LIT: {
        enterOuterAlt(_localctx, 4);
        setState(337);
        match(TythonParser::NONE_LIT);
        break;
      }

      case TythonParser::SYM_LBR: {
        enterOuterAlt(_localctx, 5);
        setState(338);
        dict_lit();
        break;
      }

      case TythonParser::SYM_LSQ: {
        enterOuterAlt(_localctx, 6);
        setState(339);
        list_lit();
        break;
      }

      case TythonParser::SYM_LPAR: {
        enterOuterAlt(_localctx, 7);
        setState(340);
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
    case 0: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

void TythonParser::initialize() {
  ::antlr4::internal::call_once(tythonparserParserOnceFlag, tythonparserParserInitialize);
}
