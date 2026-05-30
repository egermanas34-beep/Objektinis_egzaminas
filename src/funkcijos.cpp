#pragma once
#include "word.h"
#include "funkcijos.h"
string arZodis(const string& zodis)
{
    string rezultatas;
    for(char c : zodis)
    {
        if(isalpha(c))
        {
            rezultatas += tolower(c);

        }
    }
    return rezultatas;
}