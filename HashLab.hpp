#ifndef HASHLAB_HPP_INCLUDED
#define HASHLAB_HPP_INCLUDED

template<size_t max_hash_table_size>
HashTable<Word, max_hash_table_size>&
InitHashTable(  HashTable<Word, max_hash_table_size>& htable,
                Word* words, size_t n_words,
                size_t (*hash_function)(const Word& seed))  noexcept
{
    if(!words)
    {
        std::cout << "Unexpected nullptr as words\n";
        return htable;
    }
    if(!hash_function)
    {
        std::cout << "Unexpected nullptr as hash_function\n";
        return htable;
    }

    size_t hash = 0;
    List<Word>* tmp = nullptr;
    for(size_t i = 0; i < n_words; i++)
    {
        hash = hash_function(words[i]);
        hash = hash % max_hash_table_size;

        if(htable[hash] == nullptr)                 // If there haven't been any hashes before
        {
            htable.Add(hash, words[i]);
        }
        else                                        // This hash has already been met
        {
            tmp = htable[hash]->Find(words[i]);
            if(tmp == nullptr)                      // Word is met for the first time
            {
                htable.Add(hash, words[i]);
            }
            else                                    // Word has already been counted
            {
                tmp->GetData().times_met_++;
            }
        }
    }

    return htable;
}

template<size_t max_hash_table_size>
int LoadPoints(FILE* output, HashTable<Word, max_hash_table_size>& htable)    noexcept
{
    if(!output)
    {
        std::cout << "Unexpected nullptr as words\n";
        return -1;
    }

    fprintf(output, DIAGRAM_BEG);
    for(size_t i = 0; i < max_hash_table_size; i++)
        fprintf(output, "(%u, %u)\n", i, htable[i]->GetLength());
    fprintf(output, DIAGRAM_END);

    return 0;
}

#endif // HASHLAB_HPP_INCLUDED
