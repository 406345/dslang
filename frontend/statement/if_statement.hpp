#pragma once

#include "statement.hpp"
#include "string"
#include "vector"
#include "memory"

using namespace std;

/*
    declaration of a IF expression
    if <EXPRESSION>
        [BODY]
    [else if <expression>]
    [else]
    end
*/
class if_statement : public statement
{
private:
    /* data */
public:
    if_statement(/* args */);
    ~if_statement();

    shared_ptr<statement> condition;
    shared_ptr<statement> body;
};

if_statement::if_statement(/* args */)
{
    this->type = STATEMENT_TYPE_IF;
}

if_statement::~if_statement()
{
}
