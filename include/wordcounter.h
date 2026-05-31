#pragma once
#include "word.h"

class WordCounter
{
    private:
        map<string, Word> zodziai;
        string arZodis(const string& zodis);
    
    public:
    void nuskaitymas(const string& failas);
    void isvedimas(const string& failas);
};