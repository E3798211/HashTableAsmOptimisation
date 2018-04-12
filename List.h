#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

template<typename data_T>
class List
{
private:

    /// Pointer to the next element
    List<data_T>* next_elem_ = nullptr;

    /// Data itself
    data_T data_;

public:

    /// Default constructor
    List():
        next_elem_  (nullptr)
    {
        std::cout << "Default list constructor\n";
    }

    /// Copy constructor deleted
    List(const List<data_T>& that)      = delete;

    /// Move constructor deleted
    List(List<data_T>&& that)           = delete;

    /// Assignment operator
    List<data_T>& operator=(const List<data_T>& that)   const
    {
        return *this;
    }

};

#include "List.hpp"


#endif // LIST_H_INCLUDED
