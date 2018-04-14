#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

template<typename data_T>
List<data_T>* List<data_T>::Find(const data_T& to_be_found) const   noexcept
{
    List<data_T>* current = this;
    while(current)
    {
        if(current->GetData() == to_be_found)
        {
            std::cout << "Wanted element found!\n";
            return current;
        }
        current = current->GetNext();
    }

    std::cout << "Wanted element not found!\n";
    return nullptr;
}

#endif // LIST_HPP_INCLUDED
