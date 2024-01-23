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

parser grammar TythonParser;

options {
    tokenVocab=TythonLexer;
}

program             : import_statement* (statement)+ EOF;

import_statement    : KW_IMPORT import_path SYM_STMNT_DELIMITER? NEWLINE;

import_path         : IDENTIFIER (SYM_DOT IDENTIFIER)*;

function_def        : KW_DEF KW_EXTERN? IDENTIFIER SYM_LPAR arguments SYM_ELLIPS? SYM_RPAR SYM_BLOCK_START
                        block;

block               : simple_statements
                    | NEWLINE INDENT indent_statements=statement+ DEDENT;

statement           : simple_statements
                    | compound_statement;

simple_statement    : expression
                    | assign_statement
                    | return_statement;

simple_statements   : simple_statement (SYM_STMNT_DELIMITER simple_statement)* SYM_STMNT_DELIMITER? NEWLINE;

compound_statement  : if_statement
                    | function_def;

assign_statement    : IDENTIFIER SYM_ASSIGN expression;
return_statement    : KW_RETURN expression;

if_statement        : KW_IF expression SYM_BLOCK_START
                        br_if=block
                      (KW_ELSE (
                        br_else_if=if_statement
                        | (SYM_BLOCK_START br_else=block)
                      )
                      )?;

arguments           : args+=IDENTIFIER?
                    | args+=IDENTIFIER (SYM_ARG_SEPARATOR args+=IDENTIFIER)+;

parameters          : params+=expression?
                    | params+=expression (SYM_ARG_SEPARATOR params+=expression)+;

call_expression     : KW_EXTERN? IDENTIFIER SYM_LPAR parameters SYM_RPAR;

expression          : lhs=expression binary_operator rhs=expression #binary_expression
                    | call_expression                               #lbl_call_expression
                    | SYM_LPAR expression SYM_RPAR                  #lbl_expression_parentheses
                    | rval                                          #lbl_rval
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

lval                : IDENTIFIER                                #lbl_identifier
                    | IDENTIFIER SYM_LSQ lval SYM_RSQ           #lbl_array_access
                    | instance=lval (SYM_DOT attribute=lval)    #lbl_attribute_access
                    ;

rval                : constant
                    | lval;

constant            : INT_LIT | FLOAT_LIT | STR_LIT;
