#include <iostream>
#include "HashTable.h"
#include "WordStruct.h"

int main()
{
/*
    Word w1("a");
    Word w2("b");
    Word w3("c");
    Word w4("d");
    List<Word> a(w1);
    List<Word> b(w2, &a);
    List<Word> c(w3, &b);

    std::cout << "a = " << &a << "\n";
    std::cout << "b = " << &b << "\n";
    std::cout << "c = " << &c << "\n";

    std::cout << c.Find(w3);
*/
    List<Word> a("qwe");
    HashTable<Word, 10> c;
}
