#pragma once

#include "stdio.h"
#include "statement.hpp"
#include "memory"

using namespace std;

class declaration_statement : public statement
{
private:
    /* data */
public:
    declaration_statement(/* args */);
    ~declaration_statement();

    string identity;
    shared_ptr<statement> value;
};

declaration_statement::declaration_statement(/* args */)
{
    this->type = STATEMENT_TYPE_DECLARATION;
}

declaration_statement::~declaration_statement()
{
}
