#pragma once

#include "statement_consts.hpp"

class statement
{
private:
    /* data */
public:
    statement(/* args */);
    ~statement();
    STATEMENT_TYPE type = STATEMENT_TYPE_UNKNOWN;
};

statement::statement(/* args */)
{
}

statement::~statement()
{
}
