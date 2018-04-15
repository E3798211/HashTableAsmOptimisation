#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "List.h"

template<typename data_T, size_t max_hash_table_size>
class HashTable
{
private:

    /// Table
    List<data_T>* table_[max_hash_table_size] = {};

    /// Buffer list. Used in cases of fault
    List<data_T> tmp_;

public:

    /// Default constructor
    HashTable()     noexcept
    {
        std::cout << "HashTable default constructor\n";
    }

    /// Copy constructor deleted
    HashTable(const HashTable<data_T, max_hash_table_size>& that)   = delete;

    /// Move constructor deleted
    HashTable(HashTable<data_T, max_hash_table_size>&& that)        = delete;

    /// Assignment operator
    HashTable<data_T, max_hash_table_size>&
    operator=(const HashTable<data_T, max_hash_table_size>& that)   const   noexcept
    {
        return *this;
    }

    /// Subscript operator
    List<data_T>* operator[](size_t index)     noexcept
    {
        if(index >= max_hash_table_size)
        {
            std::cout << "Invalid index size: " << index << "\n";
            // List<data_T>* tmp = &tmp_;                                              //  <-- Do I have to do it?
            return &tmp_;
        }

        return table_[index];
    }

    /// Destructor
    ~HashTable()
    {
        for(size_t i = 0; i < max_hash_table_size; i++)
        {
            delete table_[i];
        }
    }

    // Service  ====================================================

    /// Adds word to the list
    List<data_T>* Add(size_t index, const data_T& data);

    /// Gets length of the list
    size_t GetLength(size_t index)
    {
        if(index >= max_hash_table_size)
        {
            std::cout << "Invalid index size: " << index << "\n";
            return -1;
        }

        if(table_[index] == nullptr)    return 0;
        return table_[index]->GetLength();
    }

    /// Resets hashtable
    HashTable<data_T, max_hash_table_size>& Reset()
    {
        for(size_t i = 0; i < max_hash_table_size; i++)
        {
            delete table_[i];
            table_[i] = nullptr;
        }

        return *this;
    }
};

#include "HashTable.hpp"

#endif // HASHTABLE_H_INCLUDED
