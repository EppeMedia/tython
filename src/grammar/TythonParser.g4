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

assign_statement    : lval SYM_ASSIGN expression    #lbl_assign_statement
                    | lval SYM_PLUS_EQ expression   #lbl_assign_plus_eq
                    | lval SYM_MINUS_EQ expression  #lbl_assign_minus_eq
                    ;

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

expression          : SYM_LPAR expression SYM_RPAR                  #lbl_expression_parentheses
                    | expression SYM_DOT call_expression            #lbl_method_call
                    | call_expression                               #lbl_call_expression

//                    Shorthand increment/decrement (Super set instructions)
                    | SYM_INC expression                            #lbl_inc_prefix
                    | expression SYM_INC                            #lbl_inc_suffix
                    | SYM_DEC expression                            #lbl_dec_prefix
                    | expression SYM_DEC                            #lbl_dec_suffix

//                    Arithmetic expressions
                    | lhs=expression SYM_EXP rhs=expression         #lbl_exponent_expr
                    | lhs=expression SYM_MULT rhs=expression        #lbl_mult_expr
                    | lhs=expression SYM_DIV rhs=expression         #lbl_div_expr
                    | lhs=expression SYM_PLUS rhs=expression        #lbl_add_expr
                    | lhs=expression SYM_MINUS rhs=expression       #lbl_sub_expr
//                    Logic expressions
                    | lhs=expression SYM_AND rhs=expression         #lbl_and_expr
                    | lhs=expression SYM_OR rhs=expression          #lbl_or_expr
//                    Inequality expressions
                    | lhs=expression SYM_NEQ rhs=expression         #lbl_neq_expr
                    | lhs=expression SYM_LT rhs=expression          #lbl_lt_expr
                    | lhs=expression SYM_LTE rhs=expression         #lbl_lte_expr
                    | lhs=expression SYM_EQ rhs=expression          #lbl_eq_expr
                    | lhs=expression SYM_GT rhs=expression          #lbl_gt_expr
                    | lhs=expression SYM_GTE rhs=expression         #lbl_gte_expr

                    | expression SYM_LSQ slice_lit SYM_RSQ          #lbl_slice_access
                    | obj=expression SYM_LSQ key=expression SYM_RSQ #lbl_key_access
                    | literal                                       #lbl_literal
                    | IDENTIFIER                                    #lbl_identifier
                    ;

lval                : obj=expression SYM_LSQ key=expression SYM_RSQ #lbl_lval_key_access
                    | IDENTIFIER                                    #lbl_lval_identifier
                    ;

key_value_pair      : key=expression SYM_COL value=expression;

dict_lit            : SYM_LBR (entries+=key_value_pair? | (entries+=key_value_pair? (SYM_COMMA entries+=key_value_pair)+)) SYM_COMMA? SYM_RBR;
list_lit            : SYM_LSQ (elements+=expression? | (elements+=expression? (SYM_COMMA elements+=expression)+)) SYM_RSQ;
tuple_lit           : SYM_LPAR (elements+=expression? | (elements+=expression? (SYM_COMMA elements+=expression)+)) SYM_RPAR;

slice_lit          : start=expression? SYM_COL end=expression? SYM_COL? step=expression?;

literal             : INT_LIT
                    | FLOAT_LIT
                    | STR_LIT
                    | NONE_LIT
                    | dict_lit
                    | list_lit
                    | tuple_lit
                    ;
