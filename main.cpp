#include <iostream>
#include "HashLab.h"

#include <cstring>

typedef size_t (*hash_func_t)(const Word&);

int main()
{
    PrepareFile("input");
    char* line = FileRead("prepared");
    size_t n_words = CountWords(line);

    HashTable<Word, 10> htable;

    Word* words = nullptr;
    hash_func_t hash_functions[6] = { Hash1, Hash2, Hash3, Hash4, Hash5, Hash6 };

    for(auto func : hash_functions)
    {
        words = Parse(line, n_words);
        InitHashTable(htable, words, n_words, func);
        htable.Reset();
        delete [] words;
    }

/*
    words = Parse(line, n_words);
    InitHashTable(htable, words, n_words, Hash1);
    htable.Reset();
    delete [] words;

    words = Parse(line, n_words);
    InitHashTable(htable, words, n_words, Hash2);
    htable.Reset();
    delete [] words;

    words = Parse(line, n_words);
    InitHashTable(htable, words, n_words, Hash3);
    htable.Reset();
    delete [] words;
*/
    delete [] line;
}




