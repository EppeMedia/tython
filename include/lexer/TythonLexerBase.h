//
// Created by manzi on 10/01/24.
//

// todo: license https://github.com/antlr/grammars-v4/tree/master/python/python3

#ifndef TYTHON_TYTHONLEXERBASE_H
#define TYTHON_TYTHONLEXERBASE_H

#include <vector>
#include <memory>
#include <antlr4-runtime.h>

class TythonLexerBase : public antlr4::Lexer {

public:
    TythonLexerBase(antlr4::CharStream *input);

    std::vector<std::unique_ptr<antlr4::Token>> tokens;
    std::stack<int> indents;
    int opened;
    std::unique_ptr<antlr4::Token> lastToken;

    void emit(std::unique_ptr<antlr4::Token> newToken) override;
    std::unique_ptr<antlr4::Token> nextToken() override;
    std::unique_ptr<antlr4::Token> createDedent();
    std::unique_ptr<antlr4::CommonToken> commonToken(size_t type, const std::string& text);
    static int getIndentationCount(const std::string& spaces);
    bool atStartOfInput();
    void openBrace();
    void closeBrace();
    void onNewLine();
    void reset() override;
    std::unique_ptr<antlr4::CommonToken> cloneToken(const std::unique_ptr<antlr4::Token>& source);

};


#endif //TYTHON_TYTHONLEXERBASE_H
