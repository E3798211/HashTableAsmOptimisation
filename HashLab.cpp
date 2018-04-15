#include "HashLab.h"

char* PrepareFile(const char* filename) noexcept
{
    char* buffer = FileRead(filename);
    if(!buffer)
    {
        std::cout << "FileRead() failed\n";
        return nullptr;
    }

    char* current_char = buffer;
    std::string clean_string;                   // <-- Is it good enough or too weird to habe char* and std::string together?
    while(*current_char != '\0')
    {
        if(isalpha(*current_char) || isspace(*current_char))
            clean_string += *current_char;
        current_char++;
    }

    FILE* output = fopen(PREPARED_DEFAULT_FILENAME, "w");
    if(!output)
    {
        std::cout << "Couldn't open " << PREPARED_DEFAULT_FILENAME << "\n";
        delete [] buffer;
        return nullptr;
    }

    fwrite(clean_string.c_str(), sizeof(char), clean_string.length(), output);

    fclose(output);
    return buffer;
}

char* FileRead(const char* filename)    noexcept
{
    if(!filename)
    {
        std::cout << "Unexpected nullptr as filename\n";
        return nullptr;
    }

    FILE* input = fopen(filename, "r");
    if(!input)
    {
        std::cout << "Couldn't open " << filename << "\n";
        return nullptr;
    }

    if(fseek(input, 0, SEEK_END))
    {
        std::cout << "Couldn't set position in " << filename << "\n";
        return nullptr;
    }

    int filesize = ftell(input);
    if(filesize == EOF)
    {
        std::cout << "Couldn't get pointer's position in " << filename << "\n";
        return nullptr;
    }

    char* poem_in_line = nullptr;
    try
    {
        poem_in_line = new char [filesize];
    }
    catch(const std::bad_alloc& ex)
    {
        std::cout << "Couldn't allocate " << filesize << " bytes\n";
        return nullptr;
    }

    rewind(input);
    /* int n_chars = */fread(poem_in_line, 1, filesize, input);

    fclose(input);
    return poem_in_line;
}

size_t CountWords(char* file_content)   noexcept
{
    if(!file_content)
    {
        std::cout << "Unexpected nullptr as file content\n";
        return -1;
    }

    size_t n_words = 0;
    while(*file_content != '\0')
    {
        if(isspace(*file_content) || *file_content == '\0')
        {
            *file_content = '\0';
            n_words++;
        }
        file_content++;
    }

    return n_words;
}

Word* Parse(char* file_content, size_t n_words) noexcept
{
    if(!file_content)
    {
        std::cout << "Unexpected nullptr as file content\n";
        return nullptr;
    }

    Word* words = nullptr;
    try
    {
        words = new Word [n_words];
    }
    catch(const std::bad_alloc& ex)
    {
        std::cout << "Failed to allocate memory for " << n_words << " words\n";
        return nullptr;
    }

    for(size_t i = 0; i < n_words; i++)
    {
        words[i].word_ = file_content;

        while(*file_content != '\0')
            file_content++;
        file_content++;
    }

    return words;
}

size_t Hash1(const Word& seed)  noexcept
{
    return 1;
}

size_t Hash2(const Word& seed)  noexcept
{
    return seed.word_[0];
}

size_t Hash3(const Word& seed)  noexcept
{
    return seed.word_.length();
}

size_t Hash4(const Word& seed)  noexcept
{
    size_t hash = 0;
    for(auto iter = seed.word_.begin(); iter != seed.word_.end(); iter++)
        hash += *iter;

    return hash;
}

size_t Hash5(const Word& seed)  noexcept
{
    //
}

size_t Hash6(const Word& seed)   noexcept
{
    //
}

