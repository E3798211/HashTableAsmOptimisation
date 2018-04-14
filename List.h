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
    List()  noexcept:
        next_elem_  (nullptr)
    {
        std::cout << "Default list constructor\n";
    }

    /// Constructor with parameters
    List(data_T new_data, List<data_T>* next = nullptr) noexcept:
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
    /**
        \warning DOES NOTHING
    */
    List<data_T>& operator=(const List<data_T>& that)   const   noexcept
    {
        return *this;
    }


    // Service  ====================================================

    /// Get next element
    List<data_T>* GetNext()     noexcept
    {
        return next_elem_;
    }

    /// Gets data
    data_T& GetData()           noexcept
    {
        return data_;
    }

    /// Set next element
    List<data_T>* SetNext(List<data_T>* new_next)     noexcept
    {
        next_elem_ = new_next;
        return this;
    }

    /// Sets data
    data_T& SetData(const data_T& new_data)           noexcept
    {
        data_ = new_data;
        return data_;
    }

    /// Find element in the list
    /**
        \warning data_T needs operator== defined

        Returns pointer to the first element that contains wanted data or nullptr if data was not found.
    */
    List<data_T>* Find(const data_T& to_be_found)   const   noexcept;

    /// Addition operator
    /**
        \warning Returns nullptr if new_elem is nullptr

        Places new_elem in front of this.
        Returns pointer to new_elem
    */
    List<data_T>* operator+=(List<data_T>* new_elem)  noexcept
    {
        if(!new_elem)
        {
            std::cout << "Unexpected nullptr!\n";
            return nullptr;
        }

        new_elem->SetNext(this);
        return new_elem;
    }
};

#include "List.hpp"


#endif // LIST_H_INCLUDED
