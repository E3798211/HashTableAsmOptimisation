#include <iostream>
#include "HashLab.h"

int main()
{
    PrepareFile("input");
    char* line = FileRead("prepared");
    size_t n_words = CountWords(line);

    Word* words = Parse(line, n_words);

    HashTable<Word, 10> htable;

    InitHashTable(htable, words, n_words, Hash2);

    for(int i = 0; i < 10; i++)
    {
        std::cout << "len[" << i << "] = " << htable.GetLength(i) << "\n";

        List<Word>* current = htable[i];
        while(current)
        {
            std::cout << current->GetData().word_ << "\n";
            current = current->GetNext();
        }
    }
}




