#pragma once

#include "stdio.h"
#include "statement.hpp"
#include "memory"

using namespace std;

class statement_template : public statement
{
private:
    /* data */
public:
    statement_template(/* args */);
    ~statement_template();
};

statement_template::statement_template(/* args */)
{
}

statement_template::~statement_template()
{
}
