#pragma once
#include "bibliotekos.h"

class UrlFinder
{
    private:
    set<string> urls;
    
    public:
     bool arURL(const string& zodis);
    string sutvarkytiURL(const string& zodis);
    void nuskaitymas(const string& failas);
    void isvedimas(const string& failas);


};