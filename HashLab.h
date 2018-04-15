#ifndef HASHLAB_H_INCLUDED
#define HASHLAB_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <ctype.h>

#include "HashTable.h"
#include "WordStruct.h"


const char PREPARED_DEFAULT_FILENAME[] = "prepared";


// Service          ================================================================


/// Creates "clean" file to be read
/**
    Returns nullptr in case of fault
*/
char* PrepareFile(const char* filename) noexcept;

/// Reads prepared file
/**
    Returns nullptr in case of fault
*/
char* FileRead(const char* filename)    noexcept;

/// Counts words in the file
size_t CountWords(char* file_content)   noexcept;

/// Creates array with words
Word* Parse(char* file_content, size_t n_words) noexcept;


// Main functions   ================================================================

const size_t MAX_HASH_TABLE_SIZE = 500;

template<size_t max_hash_table_size>
HashTable<Word, max_hash_table_size>&
InitHashTable(  HashTable<Word, max_hash_table_size>& htable,
                Word* words, size_t n_words,
                size_t (*hash_function)(const Word& seed));

// Hash functions   ================================================================


/// const 1 hash
size_t Hash1(const Word& seed)  noexcept;

/// first symbol hash
size_t Hash2(const Word& seed)  noexcept;

/// lenght hash
size_t Hash3(const Word& seed)  noexcept;

/// sum hash
size_t Hash4(const Word& seed)  noexcept;

/// ?
size_t Hash5(const Word& seed)  noexcept;

/// gnu hash
size_t Hash6(const Word& seed)  noexcept;


#include "HashLab.hpp"

#endif // HASHLAB_H_INCLUDED
