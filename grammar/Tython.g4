grammar Tython;

program             : (statement | function)+ EOF;

globalStatement     : assign_statement SYM_STMNT_DELIMITER?;

function            : KW_DEF IDENTIFIER SYM_LPAR arguments SYM_ELLIPS? SYM_RPAR SYM_BLOCK_START
                        block;

block               : (SYM_INDENT statement)*;

statement           : (expression | assign_statement | branch_statement | return_statement) SYM_STMNT_DELIMITER?;

assign_statement    : IDENTIFIER SYM_ASSIGN expression;
branch_statement    : if_statement;
return_statement    : KW_RETURN expression;

if_statement        : KW_IF expression SYM_BLOCK_START
                        br_if=block
                      (KW_ELSE (
                        br_else_if=if_statement
                        | (SYM_BLOCK_START br_else=block)
                      )
                      )?;

else_if_statement   : ;

else_statement      : KW_ELSE SYM_BLOCK_START
                        br_else=block;

arguments           : args+=IDENTIFIER?
                    | args+=IDENTIFIER (SYM_ARG_SEPARATOR args+=IDENTIFIER)+;

parameters          : params+=expression?
                    | params+=expression (SYM_ARG_SEPARATOR params+=expression)+;

call_expression     : KW_EXTERN? IDENTIFIER SYM_LPAR parameters SYM_RPAR;

expression          : lhs=expression binary_operator rhs=expression #binary_expression
                    | call_expression                               #lbl_call_expression
                    | SYM_LPAR expression SYM_RPAR                  #lbl_expression_parentheses
                    | atomic                                        #lbl_atomic
                    ;

binary_operator     : inequality_operator | logic_operator | arithmetic_operator;

inequality_operator : SYM_NEQ
                    | SYM_LT
                    | SYM_LTE
                    | SYM_EQ
                    | SYM_GT
                    | SYM_GTE;

logic_operator    : SYM_AND | SYM_OR;

arithmetic_operator : SYM_PLUS
                    | SYM_MINUS
                    | SYM_MULT
                    | SYM_DIV
                    | SYM_EXP;

atomic              : constant | IDENTIFIER;
constant            : INT_LIT | FLOAT_LIT | STR_LIT;

// keywords
KW_DEF              : 'def';
KW_RETURN           : 'return';
KW_IF               : 'if';
KW_ELSE             : 'else';
KW_WHILE            : 'while';
KW_EXTERN           : 'extern';

// symbols
SYM_LPAR            : '(';
SYM_RPAR            : ')';
SYM_BLOCK_START     : ':';
SYM_ARG_SEPARATOR   : ',';
SYM_STMNT_DELIMITER : ';';

SYM_ASSIGN          : '=';

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

SYM_INDENT          : [\t] | '    ';
SYM_COMMENT         : '#' ~[\r\n]* -> skip;

SYM_ELLIPS          : '...';

IDENTIFIER          : ([a-zA-Z] | '_')+([a-zA-Z0-9] | '_')*;

// literals
INT_LIT             : '-'?[0-9]+;
FLOAT_LIT           : INT_LIT? '.' [0-9]+;
STR_LIT             : '"' ~'"'+ '"';
TRUE_LIT            : 'true';
FALSE_LIT           : 'false';

WS                  : (SPACE | [\t\r\n\f]+) -> channel(HIDDEN);
SPACE               : ' ';
