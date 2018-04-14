#include <iostream>
#include "HashTable.h"
#include "WordStruct.h"

int Compare(const int* first, const int* second)
{
    if(*first == *second)   return 0;
    return 1;
}

int main()
{
    List<int> a(1);
    List<int> b(2, &a);
    List<int> c(3, &b);

    std::cout << "a = " << &a << "\n";
    std::cout << "b = " << &b << "\n";
    std::cout << "c = " << &c << "\n";

    std::cout << c.Find(4, Compare);

    // HashTable<Word, 10> c;
}
