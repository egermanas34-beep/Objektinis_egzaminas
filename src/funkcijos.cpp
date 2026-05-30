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
};
void nuskaitymas(const string& failas, map<string,Word>& zodziai)
{
    ifstream fr(failas);
    if(!fr.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << failas << std::endl;
        return;
    }
    string eilute;
    while(fr >> eilute)
    {
        string tuscia = arZodis(eilute);
        if (tuscia.empty()) continue;

        if (zodziai.find(tuscia) == zodziai.end()) 
        {
            //jie zodzio dar nebuvo, tai sukuriame nauja zodi su count 1
            zodziai[tuscia] = Word(tuscia, 1);
        } else {
            //jei zodis jau yra, tai padidiname count reiksme
            zodziai[tuscia].setCount(zodziai[tuscia].getCount() + 1);
        }
    }
    fr.close();
    
}