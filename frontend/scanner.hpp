#pragma once
#include "string"
#include "vector"
#include "token.hpp"
#include "lexer_consts_helper.hpp"

using namespace std;

class scanner
{
private:
    enum SCAN_STATE
    {
        SCAN_STATE_NONE = 1,
        SCAN_STATE_NUMBER,
        SCAN_STATE_WORD,
        SCAN_STATE_OPERATE,
        SCAN_STATE_STRING,
        SCAN_STATE_DESCRIPTION,
    };

    int index = 0;
    int pos = 1;
    int line = 1;
    int source_size = 0;
    string source;

    void next()
    {
        ++index;
        ++pos;
        
    };

    char get_char()
    {
        if (this->is_end())
            return 0;

        return source[this->index];
    };

    void back()
    {
        --index;
        --pos;
    };

    void next_line()
    {
        ++line;
        ++index;
        pos = 1;
    };

    void reset(){
        line = 1;
        index = 0;
        pos = 1;
    };

    inline bool is_source_end(){
        return this->index >= (this->source_size-1);
    };


    inline bool is_end(){
        return this->index >= (this->source_size);
    };

    vector<token> scan_source(){
        vector<token> ret; 
        SCAN_STATE state = SCAN_STATE_NONE;
        int word_start = 0;
        int last_token_id = 0;

        do
        {
            char cur_chr = get_char();

            switch (state)
            {
            case SCAN_STATE_NONE:
            {
                if (cur_chr == '\n')
                {
                    pos = 1;
                    this->next_line();
                }
                else if (cur_chr == ' ' || cur_chr == '\t' || cur_chr == '\r')
                {
                    this->next();
                    continue;
                }
                else if (cur_chr == '\"')
                {
                    word_start = index;
                    state = SCAN_STATE_STRING;

                    token t;
                    t.symbol = string(this->source.data() + word_start, 1);
                    t.line = line;
                    t.position = pos;
                    t.type = TOKEN_TYPE::OPERATOR_SYM_STR;
                    ret.push_back(std::move(t));

                    this->next();
                    continue;
                }
                else if (cur_chr == '#')
                {
                    state = SCAN_STATE_DESCRIPTION;
                    this->next();
                    continue;
                } 
                else if (is_char_alphabet(cur_chr))
                {
                    word_start = index;
                    state = SCAN_STATE_WORD;
                    continue;
                }
                else if (is_char_symbol(cur_chr))
                {
                    word_start = index;
                    state = SCAN_STATE_OPERATE;
                    continue;
                }
                else
                {
                    token t;
                    t.symbol = string(this->source.data() + index, 1);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::UNKNOWN;
                    ret.push_back(std::move(t));
                    this->next();
                }
            }
            break;
            case SCAN_STATE_NUMBER:
            {
                if (is_char_number(cur_chr) || cur_chr == '.')
                {
                    this->next();
                    continue;
                }
                else
                {
                    token t;
                    t.symbol = string(this->source.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::NUMBER_INT;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }
            break;
            case SCAN_STATE_WORD:
            {
                if (is_char_alphabet(cur_chr))
                {
                    this->next();
                    continue;
                }
                else
                {
                    token t;
                    t.symbol = string(this->source.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;

                    int flag = is_keyword(t.symbol);
                    if (flag>=0)
                    {
                        t.type = (TOKEN_TYPE)flag;
                    }
                    else if (is_number(t.symbol))
                    {
                        t.type = TOKEN_TYPE::NUMBER_INT;
                    }
                    else
                    {
                        t.type = TOKEN_TYPE::IDENTITY;
                    }

                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }
            break;
            case SCAN_STATE_OPERATE:
            {
                auto tmp = string(this->source.data() + word_start, index - word_start+1);
                auto opt_id = is_opt(tmp);

                if (opt_id>=0)
                {
                    this->next();
                    last_token_id = opt_id;
                    continue;
                }
                else
                {
                    token t;
                    t.symbol = string(this->source.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = (TOKEN_TYPE)last_token_id;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }
            break;
            case SCAN_STATE_STRING:
            {
                if (cur_chr == '\"' || this->is_source_end())
                {
                    token t;
                    t.symbol = string(this->source.data() + word_start + 1, index - word_start-1);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::STRING;
                    ret.push_back(std::move(t));

                    if(cur_chr == '\"'){
                        token t;
                        t.symbol = "\"";
                        t.line = line;
                        t.position = pos;
                        t.type = TOKEN_TYPE::OPERATOR_SYM_STR;
                        ret.push_back(std::move(t));
                    }

                    state = SCAN_STATE_NONE;
                }

                
                this->next();
            }
            break;
            case SCAN_STATE_DESCRIPTION:
            {
                if (cur_chr == '\n')
                {
                    state = SCAN_STATE_NONE;
                }
                else
                {
                    this->next();
                }
            }
            break;
            default:
                next();
                break;
            }
        }while (!this->is_end());

        return std::move(ret);
    };
public:
    scanner(){

    };

    vector<token> scan(const string &source_code)
    {
        this->reset();
        // add " " to protect overstep the size of source code
        this->source = source_code + " ";
        this->source_size = this->source.size();
        auto ret = this->scan_source();
        return std::move(ret);
    };
};