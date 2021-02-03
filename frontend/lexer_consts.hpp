#pragma once

#include "string"

using namespace std;

enum TOKEN_TYPE
{
    UNKNOWN = 0,
    KEYWORD_VAR,           // var
    KEYWORD_FUN,           // fun
    KEYWORD_RETURN,        // return
    KEYWORD_IF,            // if
    KEYWORD_ELSE,          // else
    KEYWORD_FOR,           // for
    KEYWORD_IN,            // in
    KEYWORD_END,           // end
    OPERATOR_ADD,          // +
    OPERATOR_SUB,          // -
    OPERATOR_MUL,          // *
    OPERATOR_DIV,          // /
    OPERATOR_MEMO,         // #
    OPERATOR_EQ,           // ==
    OPERATOR_ASSIGN,       // =
    OPERATOR_BIT_MOVE_L,   // <<
    OPERATOR_BIT_MOVE_R,   // >>
    OPERATOR_BIT_AND,      // &
    OPERATOR_BIT_OR,       // |
    OPERATOR_BIT_XOR,      // ~
    OPERATOR_LOGIC_OR,     // ||
    OPERATOR_LOGIC_AND,    // &&
    OPERATOR_LOGIC_NOT_EQ, // <>
    OPERATOR_LOGIC_GT,     // >
    OPERATOR_LOGIC_LT,     // <
    OPERATOR_LOGIC_GET,    // >=
    OPERATOR_LOGIC_LET,    // <=
    OPERATOR_SYM_LB_1,     // (
    OPERATOR_SYM_RB_1,     // )
    OPERATOR_SYM_LB_2,     // [
    OPERATOR_SYM_RB_2,     // ]
    OPERATOR_SYM_LB_3,     // {
    OPERATOR_SYM_RB_3,     // }
    OPERATOR_SYM_DOT,      // .
    OPERATOR_SYM_COM,      // ,
    OPERATOR_SYM_STR,      // "
    OPERATOR_SYM_SEM,      // ;

    NUMBER_INT,
    NUMBER_FLOAT,
    NUMBER_HEX,
    NUMBER_BIN,

    IDENTITY,
    STRING,
};

const string TOKEN_TYPE_NAME[] = {
    "UNKNOWN",
    "KEYWORD",
    "KEYWORD",
    "KEYWORD",
    "KEYWORD",
    "KEYWORD",
    "KEYWORD",
    "KEYWORD",
    "KEYWORD",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "OPERATOR",
    "NUMBER",
    "NUMBER",
    "NUMBER",
    "NUMBER",
    "NUMBER",
    "IDENTITY",
    "STRING",
};

#define TOKEN_DEFINE_KEYWORD_START (int)KEYWORD_VAR
#define TOKEN_DEFINE_KEYWORD_END (int)KEYWORD_END

#define TOKEN_DEFINE_OPERATOR_START (int)OPERATOR_ADD
#define TOKEN_DEFINE_OPERATOR_END (int)OPERATOR_SYM_SEM

const string TOKEN_DEFINE[] = {
    "UNKNOWN",
    "var",
    "fun",
    "return",
    "if",
    "else",
    "for",
    "in",
    "end",
    "+",
    "-",
    "*",
    "/",
    "#",
    "==",
    "=",
    "<<",
    ">>",
    "&",
    "|",
    "~",
    "||",
    "&&",
    "<>",
    ">",
    "<",
    ">=",
    "<=",
    "(",
    ")",
    "[",
    "]",
    "{",
    "}",
    ".",
    ",",
    ";",
};