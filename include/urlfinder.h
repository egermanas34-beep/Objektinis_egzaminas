#pragma once
#include "bibliotekos.h"

class UrlFinder
{
    private:
    set<string> urls;
    bool arURL(const string& zodis);
    string sutvarkytiURL(const string& zodis);
    public:
    void nuskaitymas(const string& failas);
    void isvedimas(const string& failas);
    

};