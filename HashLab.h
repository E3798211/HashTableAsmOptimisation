#ifndef HASHLAB_H_INCLUDED
#define HASHLAB_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <ctype.h>

#include "HashTable.h"
#include "WordStruct.h"


typedef size_t (*hash_func_t)(const Word&);

const char PREPARED_DEFAULT_FILENAME[] = "prepared";
const char TEX_DEFAULT_FILENAME[] = "HashCmp.tex";
const char CALL_TEX[] = "pdflatex ";
const char OPEN_FILE[] = "xdg-open ";

const char TEX_FILE_BEG[] =
"\\documentclass{article}\n"
"\\usepackage{pgfplots}\n"
"\\usepackage{geometry}\n"
"\\geometry{left=2cm}\n"
"\\geometry{right=1.5cm}\n"
"\\geometry{top=2cm}\n"
"\\geometry{bottom=2cm}\n\n"
"\\begin{document}";

const char TEX_FILE_END[] =
"\\end{document}";

const char DIAGRAM_BEG[] =
"\\begin{tikzpicture}\\begin{axis}[	height = 15cm,	width  = 17cm,	every axis y label/.style={at = {(ticklabel cs: 0.5)}, "
"rotate = 90, anchor = near ticklabel},	xlabel = {Hash value},	ylabel = {Elements in list},	ybar,	bar width = 2pt]"
"\\addplot+[ybar] coordinates{\n";
const char DIAGRAM_END[] =
"};\\end{axis}\\end{tikzpicture}\\newpage\n";



// Service          ================================================================


/// Creates "clean" file to be read
/**
    Returns -1 in case of fault, 0 if all is OK
*/
int PrepareFile(const char* filename)   noexcept;

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

/// Initializes hashtable with words
template<size_t max_hash_table_size>
HashTable<Word, max_hash_table_size>&
InitHashTable(  HashTable<Word, max_hash_table_size>& htable,
                Word* words, size_t n_words,
                size_t (*hash_function)(const Word& seed))  noexcept;

/// Opens TeX file and begins it
FILE* PrepareTeX()  noexcept;

/// Writes dots to the TeX file
template<size_t max_hash_table_size>
int LoadPoints(FILE* output, HashTable<Word, max_hash_table_size>& htable)    noexcept;

/// Finishes TeX file and closes it
int FinishTeX(FILE* output) noexcept;

/// Calls TeX
int CallTeX();

/// Opens file
/**
    \param [in] filename    File to be opened
*/
int OpenFile(const char* filename);

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
