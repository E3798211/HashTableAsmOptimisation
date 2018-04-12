#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "List.h"

template<typename data_T, size_t max_hash_table_size>
class HashTable
{
private:

    /// Table
    List<data_T> table_[max_hash_table_size] = {};

public:

    /// Default constructor
    HashTable()
    {
        std::cout << "HashTable default constructor\n";
    }

    /// Copy constructor deleted
    HashTable(const HashTable<data_T, max_hash_table_size>& that)   = delete;

    /// Move constructor deleted
    HashTable(HashTable<data_T, max_hash_table_size>&& that)        = delete;

    /// Assignment operator
    HashTable<data_T, max_hash_table_size>&
    operator=(const HashTable<data_T, max_hash_table_size>& that)   const
    {
        return *this;
    }
};

#include "HashTable.hpp"

#endif // HASHTABLE_H_INCLUDED
