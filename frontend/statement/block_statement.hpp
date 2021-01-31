#pragma

#include "stdio.h"
#include "statement.hpp"
#include "memory"

using namespace std;

class block_statement : statement
{
private:
    /* data */
public:
    block_statement(/* args */);
    ~block_statement();
};

block_statement::block_statement(/* args */)
{
    this->type = STATEMENT_TYPE_BLOCK;
}

block_statement::~block_statement()
{
}
