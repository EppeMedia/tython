// Copyright (c) 2023 by Manzi Aimé Ntagengerwa

// Recognition of substantial portions:

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

parser grammar TythonParser;

options {
    tokenVocab=TythonLexer;
}

program             : import_statement* (statement)+ EOF;

import_statement    : KW_IMPORT import_path SYM_SEMCOL? NEWLINE;

import_path         : IDENTIFIER (SYM_DOT IDENTIFIER)*;

function_def        : KW_DEF KW_EXTERN? IDENTIFIER SYM_LPAR arguments SYM_ELLIPS? SYM_RPAR SYM_COL
                        block;

block               : simple_statements
                    | NEWLINE INDENT indent_statements=statement+ DEDENT;

statement           : simple_statements
                    | compound_statement;

simple_statement    : expression
                    | assign_statement
                    | break_statement
                    | return_statement;

simple_statements   : simple_statement (SYM_SEMCOL simple_statement)* SYM_SEMCOL? NEWLINE;

compound_statement  : if_statement
                    | function_def
                    | for_loop
                    | while_loop;

assign_statement    : lval SYM_ASSIGN expression;
break_statement     : KW_BREAK;
return_statement    : KW_RETURN expression;

if_statement        : KW_IF expression SYM_COL
                        br_if=block
                      (KW_ELSE (
                        br_else_if=if_statement
                        | (SYM_COL br_else=block)
                      )
                      )?;

for_loop            : KW_FOR (IDENTIFIER KW_IN)? expression SYM_COL
                        block;

while_loop          : KW_WHILE expression SYM_COL
                        block;

arguments           : args+=IDENTIFIER?
                    | args+=IDENTIFIER (SYM_COMMA args+=IDENTIFIER)+;

parameters          : params+=expression?
                    | params+=expression (SYM_COMMA params+=expression)+;

call_expression     : KW_EXTERN? IDENTIFIER SYM_LPAR parameters SYM_RPAR;

expression          : lhs=expression binary_operator rhs=expression #binary_expression
                    | call_expression                               #lbl_call_expression
                    | SYM_LPAR expression SYM_RPAR                  #lbl_expression_parentheses
                    | lval SYM_DOT call_expression                  #lbl_method_call
                    | rval                                          #lbl_rval
                    | SYM_INC lval                                  #lbl_inc_prefix
                    | lval SYM_INC                                  #lbl_inc_suffix
                    | SYM_DEC lval                                  #lcl_dec_prefix
                    | lval SYM_DEC                                  #lcl_dec_suffix
                    ;

binary_operator     : inequality_operator | logic_operator | arithmetic_operator;

inequality_operator : SYM_NEQ
                    | SYM_LT
                    | SYM_LTE
                    | SYM_EQ
                    | SYM_GT
                    | SYM_GTE;

logic_operator      : SYM_AND | SYM_OR;

arithmetic_operator : SYM_PLUS
                    | SYM_MINUS
                    | SYM_MULT
                    | SYM_DIV
                    | SYM_EXP;

rval                : literal
                    | lval;

access_key          : start=rval? SYM_COL end=rval? SYM_COL? step=rval?     #lbl_access_key_slice
                    | expression                                            #lbl_access_key_idx
                    ;

lval                : IDENTIFIER                                #lbl_identifier
                    | IDENTIFIER SYM_LSQ access_key SYM_RSQ     #lbl_key_access
                    ;

key_value_pair      : key=expression SYM_COL value=expression;

dict_lit            : SYM_LBR (entries+=key_value_pair? | (entries+=key_value_pair? (SYM_COMMA entries+=key_value_pair)+)) SYM_RBR;
list_lit            : SYM_LSQ (elements+=rval? | (elements+=rval? (SYM_COMMA elements+=rval)+)) SYM_RSQ;
tuple_lit           : SYM_LPAR (elements+=rval? | (elements+=rval? (SYM_COMMA elements+=rval)+)) SYM_RPAR;

literal             : INT_LIT | FLOAT_LIT | STR_LIT | NONE_LIT | dict_lit | list_lit | tuple_lit;
