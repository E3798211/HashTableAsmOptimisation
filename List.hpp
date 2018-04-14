#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

template<typename data_T>
List<data_T>* List<data_T>::Find( const data_T& to_be_found,
                    int (*compare)(const data_T* first, const data_T* second))
{
    List<data_T>* current = this;
    while(current)
    {
        if(!compare(&(current->GetData()), &to_be_found))
        {
            std::cout << "Required element found!\n";
            return current;
        }
        current = current->GetNext();
    }

    std::cout << "Required element not found!\n";
    return nullptr;
}

#endif // LIST_HPP_INCLUDED
