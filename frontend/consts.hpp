#pragma once

#include "string"

using namespace std;

const string SYMBOL_KEYWORD[] = {"fun", "var", "end", "if", "else"};
const string SYMBOL_OPERATER[] = {
    "=",
    "+", "-", "*", "/",                           // 多项式
    "&&", "||", ">", "<", "<=", ">=", "==", "<>", // 逻辑运算符
    ">>", "<<", "|", "&", "~",                    // 位运算符
};
const char SYMBOL_END[] = {
    '(', ')', '[', ']', '{', '}', ';' // 终止符
};
const char SYMBOL_ALL[] = {
    '(', ')', '[', ']', '{', '}', '+', '-', '*', '/', '&', '|', '>', '<', '!', '~', '='};