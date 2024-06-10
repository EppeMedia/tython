// Copyright (c) 2023 by Manzi Aimé Ntagengerwa

// Recognition of substantial portions

/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 by Bart Kiers
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Project      : python3-parser; an ANTLR4 grammar for Python 3
 *                https://github.com/bkiers/python3-parser
 * Developed by : Bart Kiers, bart@big-o.nl
 */

lexer grammar TythonLexer;

options {
    superClass=TythonLexerBase;
}

tokens {
    INDENT,
    DEDENT
}

@header {
#include "../include/lexer/TythonLexerBase.h"
}

// keywords
KW_DEF              : 'def';
KW_RETURN           : 'return';
KW_IF               : 'if';
KW_ELSE             : 'else';
KW_FOR              : 'for';
KW_IN               : 'in';
KW_WHILE            : 'while';
KW_BREAK            : 'break';
KW_EXTERN           : 'extern';
KW_IMPORT           : 'import';
KW_SELF             : 'self';
KW_EWOUT            : 'ewout';      // Error/Warning OUT

// symbols
SYM_LPAR            : '(' {this->openBrace();};
SYM_RPAR            : ')' {this->closeBrace();};
SYM_LSQ             : '[' {this->openBrace();};
SYM_RSQ             : ']' {this->closeBrace();};
SYM_LBR             : '{' {this->openBrace();};
SYM_RBR             : '}' {this->closeBrace();};
SYM_COL             : ':';
SYM_SEMCOL          : ';';
SYM_COMMA           : ',';

SYM_STMNT_DELIMITER : SYM_SEMCOL;

SYM_ASSIGN          : '=';
SYM_PLUS_EQ         : '+=';
SYM_MINUS_EQ        : '-=';

SYM_NEQ             : '!=';
SYM_LTE             : '<=';
SYM_LT              : '<';
SYM_EQ              : '==';
SYM_GT              : '>';
SYM_GTE             : '>=';

SYM_AND             : '&&';
SYM_OR              : '||';

SYM_PLUS            : '+';
SYM_MINUS           : '-';
SYM_MULT            : '*';
SYM_DIV             : '/';
SYM_EXP             : '**';

SYM_INC             : '++';
SYM_DEC             : '--';

SYM_DOT             : '.';
SYM_ELLIPS          : '...';

SYM_COMMENT         : '#' ~[\r\n]* -> skip;
SYM_COMMENT_START   : '/*' -> pushMode(comment_block), skip;

// identifier-like literals
TRUE_LIT            : 'true';
FALSE_LIT           : 'false';
NONE_LIT            : 'None';

// references
IDENTIFIER          : ([a-zA-Z] | '_')+([a-zA-Z0-9] | '_')*;

// non-identifier-like literals
INT_LIT             : '-'?[0-9]+;
FLOAT_LIT           : INT_LIT? '.' ([0-9]+)? ('e' ('+'|'-') [0-9]+)?;
STR_LIT             : '"' ~'"'+ '"';

NEWLINE             : ({this->atStartOfInput()}? WS | ( '\r'? '\n' | '\r' | '\f') WS?) {this->onNewLine();};
WS                  : [ \t]+ -> channel(HIDDEN);

mode comment_block;

SYM_COMMENT_END     : '*/' -> popMode, skip;
COMMENT_CONTENT     : . -> skip;
