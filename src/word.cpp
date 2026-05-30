#pragma once
#include "word.h"

Word::Word()
{
    word = "";
    count = 0;
}

Word::Word(const std::string& word, int count)
{
    this->word = word;
    this->count = count;
}
Word::Word(const Word&zodis)
{
    word = zodis.word;
    count = zodis.count;
}
Word& Word::operator=(const Word& zodis)
{
    if(this == &zodis)
    return *this;
        word = zodis.word;
        count = zodis.count;
    
    return *this;
}
Word::Word(Word&& zodis)
{
    word = std::move(zodis.word);
    count = zodis.count;
    word.clear();
    count = 0;
}
Word& Word::operator=(Word&& zodis)
{
    if(this == &zodis)
    return *this;
        word = std::move(zodis.word);
        count = zodis.count;
        word.clear();
        count = 0;
    
    return *this;
}
Word::~Word()
{
    word.clear();
    count = 0;
}