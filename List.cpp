#include "List.h"


template<>
List<Word>* List<Word>::Find(const Word& to_be_found) noexcept
{
    size_t length = to_be_found.word_.length();
    const char* first = to_be_found.word_.c_str();


    List<Word>* current = this;
    while(current)
    {
        if(length != current->GetData().word_.length())
        {
            current = current->GetNext();
            continue;
        }
        if(length == 0)
            return current;

        int equal = 1;
        const char* second = current->GetData().word_.c_str();

        asm volatile(
                "movq %1, %%rax\n\t"
                "movq %%rax, %%rsi\n\t"
                "movq %2, %%rax\n\t"
                "movq %%rax, %%rdi\n\t"
                "movq %3, %%rcx\n\t"

                "cld\n\t"
                "rep cmpsb\n\t"
                "jne different\n\t"

                "mov $1, %%rax\n\t"
                "jmp end\n\t"

                "different:\n\t"
                "mov $0, %%rax\n\t"

                "end:\n\t"
                "mov %%eax, %0\n\t"

            :   "=g" (equal)
            :   "g"  (first), "g" (second), "g" (length)
            :   "rax", "rcx", "rdi", "rsi"
        );

        if(equal == 1)
        {
            return current;
        }

        current = current->GetNext();
    }

    // std::cout << "not found\t\t\t\t==================\n";
    return nullptr;
}

