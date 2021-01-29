#include "lexer_consts.hpp"

inline bool is_char_alphabet(const char &chr)
{
    if ('a' <= chr && chr <= 'z')
        return true;

    if ('A' <= chr && chr <= 'z')
        return true;

    if ('0' <= chr && chr <= '9')
        return true;

    return false;
};

inline bool is_char_number(const char &chr)
{
    if ('0' <= chr && chr <= '9')
        return true;

    return false;
};

inline bool is_char_symbol(const char &chr)
{
    for (size_t i = TOKEN_DEFINE_OPERATOR_START; i <= TOKEN_DEFINE_OPERATOR_END; i++)
    {
        for (size_t j = 0; j < TOKEN_DEFINE[i].size(); j++)
        {
            if (TOKEN_DEFINE[i][j] == chr)
            {
                return true;
            }
        }
    }

    return false;
}

inline bool is_number(const string &word)
{
    for (auto w : word)
    {
        if (!is_char_number(w))
        {
            return false;
        }
    }
    return true;
}

inline int is_keyword(const string &word)
{
    for (size_t i = TOKEN_DEFINE_KEYWORD_START; i <= TOKEN_DEFINE_KEYWORD_END; i++)
    {
        if (TOKEN_DEFINE[i] == word)
        {
            return i;
        }
    }

    return -1;
};

inline int is_opt(const string &word)
{
    for (size_t i = TOKEN_DEFINE_OPERATOR_START; i <= TOKEN_DEFINE_OPERATOR_END; i++)
    {
        if (TOKEN_DEFINE[i] == word)
        {
            return i;
        }
    }

    return -1;
};