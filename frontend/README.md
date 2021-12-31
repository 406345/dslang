# About

This is the frontend of dslang compiler. It takes source codes and output AST.

# Implement language

C++11

# Details
Welcome to DSLang. This is a studying project for learning how to build a compiler. 
I will customize a language named as DSLang(-. -).
This version of compiler will not consider the efficiency.
The entire progress can be slipt into 3 stages;
## 1. Scan - convert source codes into tokens where tokens are list of 
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
        },
        {
            value = 'b',
            type = 'identity',
            postion = 5,
            line = 1,
        }...]
## 2. Parser - this will convert tokens into an AST(abstract syntax tree).
## 3. Generator - this stage will convert AST or CST into some kinds of IR(customized by myself)

After 3 stages, the frontent of a compiler is done. The next is the backend.
