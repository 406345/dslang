#pragma once
#include "string"
#include "vector"
#include "token.hpp"
#include "consts_helper.hpp"

using namespace std;

class scanner
{
private:
    enum SCAN_STATE
    {
        SCAN_STATE_NONE = 1,
        SCAN_STATE_NUMBER,
        SCAN_STATE_NUMBER_FLOAT,
        SCAN_STATE_NUMBER_HEX,
        SCAN_STATE_NUMBER_BIN,
        SCAN_STATE_WORD,
        SCAN_STATE_OPERATE,
        SCAN_STATE_STRING,

    };

public:
    scanner(){

    };

    vector<token> scan(const string &source_code)
    {
        vector<token> ret;
        int index = 0;
        int source_size = source_code.size();
        int line = 0;
        int pos = 0;
        SCAN_STATE state = SCAN_STATE_NONE;
        int word_start = 0;

        while (index < source_size)
        {
            char cur_chr = source_code[index];

            switch (state)
            {
            case SCAN_STATE_NONE:
            {
                if (cur_chr == '\n')
                {
                    pos = 0;
                    ++line;
                    ++index;
                }
                else if (cur_chr == ' ' || cur_chr == '\t'  || cur_chr == '\r')
                {
                    ++pos;
                    ++index;
                }
                else if (is_char_number(cur_chr))
                {
                    word_start = index;
                    state = SCAN_STATE_NUMBER;
                }
                else if (is_char_alphabet(cur_chr))
                {
                    word_start = index;
                    state = SCAN_STATE_WORD;
                }
                else if (is_char_end(cur_chr))
                {
                    token t;
                    t.symbol = string(source_code.data() + index, 1);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::END;
                    ret.push_back(std::move(t));
                    ++index;
                    ++pos;
                }  
                else if( is_char_symbol(cur_chr)){
                    word_start = index;
                    state = SCAN_STATE_OPERATE;
                }
                else {
                    token t;
                    t.symbol = string(source_code.data() + index, 1);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::UNKNOWN;
                    ret.push_back(std::move(t));
                    ++index;
                    ++pos;
                }
            }
            break;
            case SCAN_STATE_NUMBER:
            {
                if (is_char_number(cur_chr))
                {
                    ++index;
                    ++pos;
                }
                else if(cur_chr == '.'){
                    ++index;
                    ++pos;
                    state = SCAN_STATE_NUMBER_FLOAT;
                    continue;
                }
                else if( cur_chr == 'x'){
                    ++index;
                    ++pos;
                    state = SCAN_STATE_NUMBER_HEX;
                    continue;
                }
                else if( cur_chr == 'b'){
                    ++index;
                    ++pos;
                    state = SCAN_STATE_NUMBER_BIN;
                    continue;
                }
                else {
                    token t;
                    t.symbol = string(source_code.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::NUMBER;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
                // if (is_char_number(cur_chr) || cur_chr == '.' || cur_chr == 'x' || cur_chr == 'f')
                // {
                //     ++index;
                //     ++pos;
                // }
                // else
                // {
                //     token t;
                //     t.symbol = string(source_code.data() + word_start, index - word_start);
                //     t.line = line;
                //     t.position = pos - index + word_start;
                //     t.type = TOKEN_TYPE::NUMBER;
                //     ret.push_back(std::move(t));

                //     state = SCAN_STATE_NONE;
                // }
            }
            break;
            case SCAN_STATE_NUMBER_FLOAT:{
                if( is_char_number(cur_chr)){
                    ++index;
                    ++pos;
                }
                else{
                    token t;
                    t.symbol = string(source_code.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::NUMBER_FLOAT;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }break;
            case SCAN_STATE_NUMBER_HEX:{
                if( is_char_number(cur_chr) || (cur_chr >= 'A' && cur_chr <= 'F')){
                    ++index;
                    ++pos;
                }
                else{
                    token t;
                    t.symbol = string(source_code.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::NUMBER_HEX;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }break;
            case SCAN_STATE_NUMBER_BIN:{
                if( cur_chr == '0' || cur_chr == '1'){
                    ++index;
                    ++pos;
                }
                else{
                    token t;
                    t.symbol = string(source_code.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::NUMBER_BIN;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }break;
            case SCAN_STATE_WORD:
            {
                if (is_char_alphabet(cur_chr))
                {
                    ++index;
                    ++pos;
                }
                else
                {
                    token t;
                    t.symbol = string(source_code.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;

                    if( is_keyword(t.symbol)){
                        t.type = TOKEN_TYPE::KEYWORD;
                    }
                    else {
                        t.type = TOKEN_TYPE::IDENTITY;
                    }
                    
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }
            break;
            case SCAN_STATE_OPERATE:{
                if (is_char_symbol(cur_chr))
                {
                    ++index;
                    ++pos;
                }
                else
                {
                    token t;
                    t.symbol = string(source_code.data() + word_start, index - word_start);
                    t.line = line;
                    t.position = pos - index + word_start;
                    t.type = TOKEN_TYPE::OPERATOR;
                    ret.push_back(std::move(t));

                    state = SCAN_STATE_NONE;
                }
            }break;
            default:
                break;
            }
        }

        return std::move(ret);
    };
};