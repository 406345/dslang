#include "consts.hpp"

inline bool is_char_alphabet(const char &chr)
{
    if ('a' <= chr && chr <= 'z')
        return true;

    if ('A' <= chr && chr <= 'z')
        return true;

    return false;
};

inline bool is_char_number(const char &chr)
{
    if ('0' <= chr && chr <= '9')
        return true;

    return false;
};

inline bool is_char_end(const char &chr)
{
    // int size = sizeof(consts::END);
    for (auto end : SYMBOL_END)
    {
        if (end == chr)
        {
            return true;
        }
    }

    return false;
};

inline bool is_char_symbol(const char &chr)
{
    for (auto end : SYMBOL_ALL)
    {
        if (end == chr)
        {
            return true;
        }
    }

    return false;
}

inline bool is_keyword(const string &word)
{
    for (auto keyword : SYMBOL_KEYWORD)
    {
        if (keyword == word)
        {
            return true;
        }
    }

    return false;
};

inline bool is_opt(const string &word)
{
    for (auto opt : SYMBOL_OPERATER)
    {
        if (opt == word)
        {
            return true;
        }
    }

    return false;
};