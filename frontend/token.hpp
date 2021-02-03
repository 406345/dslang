#pragma once

#include "string"
#include "lexer_consts.hpp"

using namespace std;
 
class token
{
public:
    TOKEN_TYPE type;
    string symbol;
    int line;
    int position;
};