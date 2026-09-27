#pragma once
#include "word.h"

class WordCounter
{
    private:
        map<string, Word> zodziai;
        string arZodis(const string& zodis);
        bool arSkyryba(char c);
    public:
   
    void nuskaitymas(const string& failas);
    void isvedimas(const string& failas);
    void isvedimasCrossReference(const string& failas);
};