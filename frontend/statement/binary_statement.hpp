#pragma once

#include "stdio.h"
#include "statement.hpp"
#include "memory"

using namespace std;

class binary_statement : statement
{
private:
    /* data */
public:
    binary_statement(/* args */);
    ~binary_statement();
    shared_ptr<statement> left;
    shared_ptr<statement> right;
};

binary_statement::binary_statement(/* args */)
{
    this->type = STATEMENT_TYPE_BINARY;
}

binary_statement::~binary_statement()
{

}
