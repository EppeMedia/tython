//
// Created by manzi on 10/01/24.
//

// todo: license https://github.com/antlr/grammars-v4/tree/master/python/python3

#include "../../include/lexer/TythonLexerBase.h"
#include "../../grammar/generated/TythonParser.h"
#include <regex>

using namespace antlr4;

TythonLexerBase::TythonLexerBase(antlr4::CharStream *input): Lexer(input)
{
    opened = 0;
    lastToken = nullptr;
}

void TythonLexerBase::emit(std::unique_ptr<antlr4::Token> t)
{
    tokens.push_back(cloneToken(t));
    setToken(std::move(t));
}


std::unique_ptr<antlr4::Token> TythonLexerBase::nextToken()
{
    if (_input->LA(1) == EOF && !indents.empty()) {
        for (int i = tokens.size() - 1; i >= 0; i--) {
            if (tokens[i]->getType() == EOF) {
                tokens.erase(tokens.begin() + i);
            }
        }
        emit(commonToken(TythonParser::NEWLINE, "\n"));
        while (!indents.empty()) {
            emit(createDedent());
            indents.pop();
        }
        emit(commonToken(EOF, "<EOF>"));
    }
    std::unique_ptr<antlr4::Token> next = Lexer::nextToken();
    if (next->getChannel() == antlr4::Token::DEFAULT_CHANNEL) {
        lastToken = cloneToken(next);
    }
    if (!tokens.empty())
    {
        next = std::move(*tokens.begin());
        tokens.erase(tokens.begin());
    }
    return next;
}

std::unique_ptr<antlr4::Token> TythonLexerBase::createDedent() {
    std::unique_ptr<antlr4::CommonToken> dedent = commonToken(TythonParser::DEDENT, "");
    return dedent;
}

std::unique_ptr<antlr4::CommonToken> TythonLexerBase::commonToken(size_t type, const std::string& text) {
    int stop = getCharIndex() - 1;
    int start = text.empty() ? stop : stop - text.size() + 1;
    return _factory->create({ this, _input }, type, text, DEFAULT_TOKEN_CHANNEL, start, stop, lastToken ? lastToken->getLine() : 0, lastToken ? lastToken->getCharPositionInLine() : 0);
}

std::unique_ptr<antlr4::CommonToken> TythonLexerBase::cloneToken(const std::unique_ptr<antlr4::Token>& source) {
    return _factory->create({ this, _input }, source->getType(), source->getText(), source->getChannel(), source->getStartIndex(), source->getStopIndex(), source->getLine(), source->getCharPositionInLine());
}

int TythonLexerBase::getIndentationCount(const std::string& spaces) {
    int count = 0;
    for (char ch : spaces) {
        switch (ch) {
            case '\t':
                count += 8 - (count % 8);
                break;
            default:
                // A normal space char.
                count++;
        }
    }

    return count;
}

bool TythonLexerBase::atStartOfInput() {
    return getCharPositionInLine() == 0 && getLine() == 1;
}

void TythonLexerBase::openBrace() {
    this->opened++;
}

void TythonLexerBase::closeBrace() {
    this->opened--;
}

void TythonLexerBase::onNewLine()
{
    std::string newLine = std::regex_replace(getText(), std::regex("[^\r\n\f]+"), "");
    std::string spaces = std::regex_replace(getText(), std::regex("[\r\n\f]+"), "");
    int next = _input->LA(1);
    int nextnext = _input->LA(2);
    if (opened > 0 || (nextnext != -1 && (next == '\r' || next == '\n' || next == '\f' || next == '#'))) {
        skip();
    }
    else {
        emit(commonToken(TythonParser::NEWLINE, newLine));
        int indent = getIndentationCount(spaces);
        int previous = indents.empty() ? 0 : indents.top();
        if (indent == previous) {
            skip();
        }
        else if (indent > previous) {
            indents.push(indent);
            emit(commonToken(TythonParser::INDENT, spaces));
        }
        else {
            while(!indents.empty() && indents.top() > indent) {
                emit(createDedent());
                indents.pop();
            }
        }
    }
}

void TythonLexerBase::reset()
{
    tokens = std::vector<std::unique_ptr<antlr4::Token>>{};
    indents = std::stack<int>{};
    opened = 0;
    lastToken = nullptr;
    Lexer::reset();
}
