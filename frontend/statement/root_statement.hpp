#pragma once

#include "stdio.h"
#include "memory"
#include "vector"

#include "statement.hpp"
#include "block_statement.hpp"

using namespace std;

class root_statement : public statement
{
private:
    /* data */
public:
    root_statement(/* args */);
    ~root_statement();

    shared_ptr<block_statement> block;
};

root_statement::root_statement(/* args */)
{
    this->type = STATEMENT_TYPE_ROOT;
}

root_statement::~root_statement()
{
}
