#pragma once

#include "statement.hpp"

class expression_statement : statement
{
private:
    /* data */
public:
    expression_statement(/* args */);
    ~expression_statement();
};

expression_statement::expression_statement(/* args */)
{
    this->type = STATEMENT_TYPE_EXPRESSION;
}

expression_statement::~expression_statement()
{
}
