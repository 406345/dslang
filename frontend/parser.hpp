#pragma once

#include "stdio.h"
#include "string"
#include "vector"
#include "memory"

#include "token.hpp"
#include "statement/statement.hpp"

using namespace std;

struct parser_error
{
    string message;
    int code;
    int position;
    int line;
};

class parser
{
private:
    int cur_idx = 0;
    shared_ptr<statement> ast_root;
    vector<parser_error> errors;
    vector<token> tokens;
    
    token& get_token(){
        return tokens.at(this->cur_idx);
    }

    void next()
    {
        ++cur_idx;
    }

    void back()
    {
        --cur_idx;
        if (cur_idx < 0)
            cur_idx = 0;
    }
    
    bool is_end(){
        return false;
    }

    bool build_ast(shared_ptr<statement>& root)
    {   
        while(!is_end()){
            auto token = get_token();
            switch (token.type)
            {
            case KEYWORD_FUN:
                

                break;
            default:
                break;
            }
        }

        return true;
    };

public:
    bool translate(vector<token> &tokens)
    {
        ast_root = make_shared<statement>();
        build_ast(ast_root);
        return true;
    };
};