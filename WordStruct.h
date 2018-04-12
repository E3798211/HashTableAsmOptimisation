#ifndef WORDSTRUCT_H_INCLUDED
#define WORDSTRUCT_H_INCLUDED

struct Word
{
    /// Word itself
    char*  word_ = nullptr;

    /// Times met
    size_t times_met_ = 0;
};

#endif // WORDSTRUCT_H_INCLUDED
