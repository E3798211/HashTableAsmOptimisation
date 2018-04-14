#ifndef WORDSTRUCT_H_INCLUDED
#define WORDSTRUCT_H_INCLUDED

#include <string>

struct Word
{
    /// Word itself
    std::string  word_;

    /// Times met
    size_t times_met_ = 0;

    /// Default constructor
    Word() {};

    /// Constructor with parameters
    Word(const char* word)  noexcept:
        word_   (word)
    {
        std::cout << "Word constructor with parameters\n";
    }

    /// Compare operator
    bool operator==(const Word& that)   noexcept
    {
        if(that.word_ == this->word_)   return true;
        return false;
    }
};

#endif // WORDSTRUCT_H_INCLUDED
