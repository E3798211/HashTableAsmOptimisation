#ifndef HASHLAB_H_INCLUDED
#define HASHLAB_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <ctype.h>

#include "HashTable.hpp"
#include "WordStruct.h"


const char PREPARED_DEFAULT_FILENAME[] = "prepared";



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

// Hash functions   ================================================================

/// const 1 hash
size_t Hash1(const Word* seed)  noexcept;

/// first symbol hash
size_t Hash2(const Word* seed)  noexcept;

/// lenght hash
size_t Hash3(const Word* seed)  noexcept;

/// sum hash
size_t Hash4(const Word* seed)  noexcept;

/// ?
size_t Hash5(const Word* seed)  noexcept;

/// gnu hash
size_t Hash6(const Word* seed)  noexcept;


#endif // HASHLAB_H_INCLUDED
