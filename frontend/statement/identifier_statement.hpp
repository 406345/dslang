#pragma once

#include "stdio.h"
#include "statement.hpp"
#include "memory"
#include "string"

using namespace std;

class identifier_statement : public statement
{
private:
    /* data */
public:
    identifier_statement(/* args */);
    ~identifier_statement();

    string name;
    string var_type;
};

identifier_statement::identifier_statement(/* args */)
{
}

identifier_statement::~identifier_statement()
{
}
