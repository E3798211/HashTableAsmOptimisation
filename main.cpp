#include <iostream>
#include "HashLab.h"

#include <cstring>

int main()
{
    PrepareFile("input");
    char* line = FileRead("prepared");
    size_t n_words = CountWords(line);

    HashTable<Word, MAX_HASH_TABLE_SIZE> htable;

    Word* words = nullptr;
    hash_func_t hash_functions[6] = { Hash1, Hash2, Hash3, Hash4, Hash5, Hash6 };
    FILE* output = PrepareTeX();

    for(auto func : hash_functions)
    {
        words = Parse(line, n_words);
        InitHashTable(htable, words, n_words, func);

        LoadPoints(output, htable);

        htable.Reset();
        delete [] words;
    }

    FinishTeX(output);
    CallTeX();
    // OpenFile();

    delete [] line;
}




