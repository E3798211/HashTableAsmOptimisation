#ifndef HASHTABLE_HPP_INCLUDED
#define HASHTABLE_HPP_INCLUDED

template<typename data_T, size_t max_hash_table_size>
List<data_T>*  HashTable<data_T, max_hash_table_size>::Add(size_t index, const data_T& data)
{
    if(index >= max_hash_table_size)
    {
        std::cout << "Invalid index size: " << index << "\n";
        // List<data_T>* tmp = &tmp_;                                              //  <-- Do I have to do it?
        return &tmp_;
    }

    List<data_T>* new_elem = nullptr;
    try
    {
        new_elem = new List<data_T>;
        new_elem->SetData(data);
    }
    catch(const std::bad_alloc& ex)
    {
        std::cout << "Couldn't allocate " << sizeof(data_T) << " bytes\n";
        return &tmp_;
    }

    if(table_[index] != nullptr)
    {
        table_[index]->Add(new_elem);
        table_[index] = new_elem;
    }
    else
    {
        table_[index] = new_elem;
    }

    return table_[index];

}

#endif // HASHTABLE_HPP_INCLUDED
