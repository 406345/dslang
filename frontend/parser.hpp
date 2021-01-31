#pragma once

#include "stdio.h"
#include "string"
#include "vector"
#include "memory"

#include "utils.hpp"
#include "token.hpp"
#include "statement/statement.hpp"
#include "statement/root_statement.hpp"
#include "statement/block_statement.hpp"
#include "statement/function_statement.hpp"
#include "statement/expression_statement.hpp"
#include "statement/identifier_statement.hpp"
#include "statement/declaration_statement.hpp"

using namespace std;

#define ASSERT_TYPE(TOKEN, TYPE, CODE, MSG)  \
    if (TOKEN == nullptr)                    \
    {                                        \
        this->add_error(CODE, MSG, nullptr); \
        return nullptr;                      \
    }                                        \
    if (TOKEN->type != TYPE)                 \
    {                                        \
        this->add_error(CODE, MSG, TOKEN);   \
        return nullptr;                      \
    }

struct parser_error
{
    string message;
    int code;
    int position;
    int line;

    parser_error(int code, string msg, int p, int l)
    {
        this->code = code;
        this->message = std::move(msg);
        this->position = p;
        this->line = l;
    };
};

class parser
{
private:
    int cur_idx = -1;
    shared_ptr<root_statement> ast_root;
    vector<parser_error> errors;
    vector<shared_ptr<token>> tokens;

    // template<typename T>
    // std::shared_ptr<
    //     typename std::enable_if<(!std::is_same<statement,T>::value)
    //                             &&(std::is_base_of<statement,T>::value),T>::type
    // >
    // shared_ptr_cast(std::shared_ptr<statement> ptr){
    //     return std::static_pointer_cast<T>(ptr);
    // }

    shared_ptr<token> get_token()
    {
        return tokens.at(this->cur_idx);
    };
 
    shared_ptr<token> next()
    {
        ++cur_idx;
        return tokens.at(this->cur_idx);
    };

    shared_ptr<token> back()
    {
        --cur_idx;
        if (cur_idx < 0)
            cur_idx = 0;

        return tokens.at(this->cur_idx);
    };

    bool is_end()
    {
        return false;
    };

    void add_error(int code, string msg, shared_ptr<token> token)
    {
        this->errors.push_back(std::move(parser_error(code, msg, token->position, token->line)));
    };

    shared_ptr<function_statement> parse_declaration(shared_ptr<declaration_statement> root)
    {
        auto token = next();
        ASSERT_TYPE(token, IDENTITY, 1, "need a variable");

        root->identity = token->symbol;
        
        return nullptr;
    };

    shared_ptr<function_statement> parse_expression(shared_ptr<expression_statement> root)
    {
        return nullptr;
    };

    shared_ptr<block_statement> parse_block(shared_ptr<block_statement> root)
    {
        while (true)
        {
            auto token = next();
            if (token == nullptr)
            {
                this->add_error(1, "need a end to close block", back());
                return nullptr;
            }
            else if (token->type == KEYWORD_END)
            {
                break;
            }

            switch (token->type)
            {
            case KEYWORD_VAR:
            {
                auto s_var = this->build_ast(make_shared<declaration_statement>());
                
                if(s_var == nullptr){
                    return root;
                }

                root->body.push_back(s_var);
            }
            break;
            case KEYWORD_IF:
            {
            }
            break;
            case KEYWORD_FUN:
            {
                auto s_fun = this->build_ast(make_shared<function_statement>());
                
                if(s_fun == nullptr){
                    return root;
                }
                root->body.push_back(s_fun);
            }
            break;
            default:
                break;
            }
        }

        return root;
    }

    shared_ptr<function_statement> parse_function(shared_ptr<function_statement> root)
    {
        auto ret = root;
        auto token = next();

        ASSERT_TYPE(token, IDENTITY, 1, "need a function name");
        ret->name = token->symbol;

        token = next();
        ASSERT_TYPE(token, OPERATOR_SYM_LB_1, 1, "need a (");

        while (true)
        {
            token = next();
            if (token == nullptr)
            {
                this->add_error(1, "errors in define a function", back());
                return nullptr;
            }
            else if (token->type == OPERATOR_SYM_COM)
            {
                continue;
            }
            else if (token->type == OPERATOR_SYM_RB_1)
            {
                break;
            }

            ASSERT_TYPE(token, IDENTITY, 1, "need a variable");
            auto identifier = make_shared<identifier_statement>();
            identifier->name = token->symbol;
            ret->args.push_back(identifier);
        }

        ret->body = make_shared<block_statement>();

        this->build_ast(ret->body);

        if (ret->body == nullptr)
        {
            return nullptr;
        }

        return ret;
    };

    shared_ptr<statement> build_ast(shared_ptr<statement> root)
    {
        while (!is_end())
        {
            switch (root->type)
            {
            case STATEMENT_TYPE_FUN:
            {
                return parse_function(shared_type_cast<function_statement>(root));
            }
            break;
            case STATEMENT_TYPE_DECLARATION:
            {
                return parse_declaration(shared_type_cast<declaration_statement>(root));
            }
            break;
            case STATEMENT_TYPE_BLOCK:
            {
                return parse_block(shared_type_cast<block_statement>(root));
            }
            break;
            default:
                break;
            }
        }

        return root;
    };

public:
    bool translate(vector<shared_ptr<token>> &tokens)
    {
        this->tokens = std::move(tokens);
        this->ast_root = make_shared<root_statement>();
        this->ast_root->block = make_shared<block_statement>();
        build_ast(static_pointer_cast<statement>(this->ast_root->block));
        return true;
    };
};