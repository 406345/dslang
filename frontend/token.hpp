#pragma once

#include "string"

using namespace std;

enum TOKEN_TYPE{
    KEYWORD = 1,
    IDENTITY,
    OPERATOR,
    NUMBER,
    STRING,
    END,
    UNKNOWN,
};

class token
{
public:
    TOKEN_TYPE type;
    string symbol;
    int line;
    int position;
};