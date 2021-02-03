/*  
    Welcome to DSLang. This is a studying project for learning how to build a compiler  
    I will customize a language named as DSLang(-. -).

    This version of compiler will not consider the efficiency.

    The entire progress can be slipt into 3 stages;
    #1. Scan - convert source codes into tokens where tokens are list of 
        the element of the language. 
        For example a = b + 1 will convert into 
        [{
            value = 'a',
            type = 'identity',
            positio = 1,
            line = 1,
        },
        {
            value = '=',
            type = 'operator_eq',
            postion = 3,
            line = 1,
        }...]
    #2. Parser - this will convert tokens into an AST(abstract syntax tree).
    #3. Generator - this stage will convert AST or CST into some kinds of IR(costomized by myself)
    After 3 stages, the frontent of a compiler is done. The next is the backend.
*/

#include "stdio.h"
#include "scanner.hpp"
#include "parser.hpp"
#include "test.hpp"

string read_source_code(const string& file){
    auto fp = fopen(file.c_str(), "rb");

    // get the length of the source file.
    fseek(fp, 0, SEEK_END);
    auto size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // alloc the memory to contain the source.
    char *buffer = new char[size];
    fread(buffer, 1, size, fp);
    string source = string(buffer, size);
    fclose(fp);

    // return the source string in memory.
    return std::move(source);
};

int main(int argc, char const *argv[])
{
    string source_file = "./sample.dlang";
    string source = read_source_code(source_file);
    scanner scanner;
    parser parser;

    // scan stage
    auto tokens = scanner.scan(source); 
    // parse stage
    parser.translate(tokens);

    return 0;
}
