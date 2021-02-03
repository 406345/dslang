#pragma once

#include "stdio.h"
#include "statement.hpp"
#include "memory"
#include "vector"

using namespace std;

class block_statement : public statement
{
private:
    /* data */
public:
    block_statement(/* args */);
    ~block_statement();
    vector<shared_ptr<statement>> body;
};

block_statement::block_statement(/* args */)
{
    this->type = STATEMENT_TYPE_BLOCK;
}

block_statement::~block_statement()
{
}
