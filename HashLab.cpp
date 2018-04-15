#include "HashLab.h"

int PrepareFile(const char* filename)   noexcept
{
    char* buffer = FileRead(filename);
    if(!buffer)
    {
        std::cout << "FileRead() failed\n";
        return -1;
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
        return -1;
    }

    fwrite(clean_string.c_str(), sizeof(char), clean_string.length(), output);

    fclose(output);
    delete [] buffer;
    return 0;
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


FILE* PrepareTeX()  noexcept
{
    FILE* output = fopen(TEX_DEFAULT_FILENAME, "w");
    if(!output)
    {
        std::cout << "Couldn't open " << TEX_DEFAULT_FILENAME << "\n";
        return nullptr;
    }

    fprintf(output, TEX_FILE_BEG);

    return output;
}

int FinishTeX(FILE* output) noexcept
{
    if(!output)
    {
        std::cout << "Output stream is already closed\n";
        return -1;
    }

    fprintf(output, TEX_FILE_END);
    fclose(output);

    return 0;
}

int CallTeX()
{
    std::string command = CALL_TEX;
    command += TEX_DEFAULT_FILENAME;

    return system(command.c_str());
}

int OpenFile(const char* filename)
{
    if(!filename)
    {
        std::cout << "Unexpected nullptr as filename\n";
        return -1;
    }

    std::string command = OPEN_FILE;
    command += filename;

    return system(command.c_str());
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
    size_t hash = 0;

    const char* str = seed.word_.c_str();
    while(*str != '\0'){
        if(hash % 2 == 0)
            hash = hash >> 1;
        else{
            hash = hash >> 1;
            hash += 2147483648; // 2^31
        }

        hash = hash ^ (*str++);
    }
    return hash;
}

size_t Hash6(const Word& seed)   noexcept
{
    size_t hash = 5381;
    const char* str = seed.word_.c_str();
    int c = str[0];

    if(seed.word_.length() > 1)
    {
        while (c != '\0'){
            c = *str;
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
            str++;
        }
    }

    return hash;
}

