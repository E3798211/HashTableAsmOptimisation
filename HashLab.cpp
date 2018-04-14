#include "HashLab.h"

size_t Hash1(const Word* seed)  noexcept
{
    return 1;
}

size_t Hash2(const Word* seed)  noexcept
{
    if(!seed)   return -1;

    return seed->word_[0];
}

size_t Hash3(const Word* seed)  noexcept
{
    if(!seed)   return -1;

    return seed->word_.length();
}

size_t Hash4(const Word* seed)  noexcept
{
    if(!seed)   return -1;

    size_t hash = 0;
    for(auto iter = seed->word_.begin(); iter != seed->word_.end(); iter++)
        hash += *iter;

    return hash;
}

size_t Hash5(const Word* seed)  noexcept
{
    //
}

size_t Hash6(const Word* seed)  noexcept
{
    //
}

