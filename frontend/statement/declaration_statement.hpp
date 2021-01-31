#pragma

#include "stdio.h"
#include "statement.hpp"
#include "memory"

using namespace std;

class declaration_statement : statement
{
private:
    /* data */
public:
    declaration_statement(/* args */);
    ~declaration_statement();

    shared_ptr<statement> identity;
    shared_ptr<statement> value;
};

declaration_statement::declaration_statement(/* args */)
{
}

declaration_statement::~declaration_statement()
{
}
