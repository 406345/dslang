#pragma once

#include "statement.hpp"
#include "string"
#include "vector"
#include "memory"

using namespace std;

/*
    declaration of a function
    fun <IDENTITY> [( [IDENTITY_1], [IDENTITY_2], [IDENTITY_3], ... )]
    [BODY]
    end
*/
class function_statement : statement
{
private:
    /* data */
public:
    function_statement(/* args */);
    ~function_statement();
    string name;
    vector<shared_ptr<statement>> args;
    shared_ptr<statement> body = nullptr;
};

function_statement::function_statement(/* args */)
{
    this->type = STATEMENT_TYPE_FUN;   
}

function_statement::~function_statement()
{
}
