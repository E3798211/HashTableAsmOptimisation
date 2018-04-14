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

    /// Constructor with parameters
    List(data_T new_data, List<data_T>* next = nullptr):
        next_elem_  (next),
        data_       (new_data)
    {
        std::cout << "List constructor with parameters\n";
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


    // Service  ====================================================

    /// Get next element
    List<data_T>* GetNext()
    {
        return next_elem_;
    }

    /// Gets data
    data_T& GetData()
    {
        return data_;
    }

    /// Find element in the list
    /**
        \warning data_T needs operator== defined

        Returns pointer to the first element that contains wanted data or nullptr if data was not found.
    */
    List<data_T>* Find(const data_T& to_be_found);
};

#include "List.hpp"


#endif // LIST_H_INCLUDED
