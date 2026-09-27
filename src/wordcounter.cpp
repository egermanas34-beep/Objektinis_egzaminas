#include "wordcounter.h"

bool WordCounter::arSkyryba(char c)
{
    string skyryba = ".,!?;:\"'()[]{}-_<>/\\|@#$%^&*~`"; //! skyrybos zenklai, kuriuos norime ignoruoti
    return skyryba.find(c) != string::npos;
};
string WordCounter::arZodis(const string& zodis)
{
    string rezultatas;

    for (unsigned char c : zodis)
    {
            if (isupper(c)) {
                c = tolower(c); //! konvertuojame didziasias raides i mazasias
            }
        if (!arSkyryba(c))
        {
            rezultatas += c;
        }
    }
   
    return rezultatas;
}
void WordCounter::nuskaitymas(const string& failas) //! funkcija, kuri skaito faila ir skaiciuoja zodzius, ju kieki ir sakinius, kuriuose jie yra
{
    ifstream fr(failas);
    if(!fr.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << failas << std::endl;
        return;
    }
    string eilute;
    int sakinioNumeris = 1;
    while(fr >> eilute)
    {
        bool sakinioPabaiga = false;//! tikriname ar eilute baigiasi sakinio pabaigos zenklu, jei taip, tai kitame zodyje padidinsime sakinio numeri  
            if(eilute.find('.') != string::npos || eilute.find('!') != string::npos || eilute.find('?') != string::npos)//! npos - tai reikšmė, kurią grąžina find funkcija, jei neranda ieškomo simbolio. Jei simbolis randamas, tai grąžina jo poziciją eilutėje, o jei nerandamas, tai grąžina npos.
            {
                sakinioPabaiga = true;
            }

        string tuscia = arZodis(eilute); //! patikriname ar eilute yra zodis, jei ne, tai tuscia bus tuscia string, o jei taip, tai tuscia bus zodis be skyrybos zenklu ir mazosios raides
        if (tuscia.empty()) {if(sakinioPabaiga) sakinioNumeris++; continue;}

        if (zodziai.find(tuscia) == zodziai.end())
        {  
            Word naujasZodis(tuscia, 1);
            naujasZodis.pridetiSakini(sakinioNumeris);
            zodziai.insert({tuscia, naujasZodis});//! pridedama i zozdiu zemelapi zodzio reiksme ir count 1. zodzio reiksme
        } else {
            //! jei zodis jau yra, tai padidiname count reiksme
            zodziai[tuscia].setWord(tuscia);
            zodziai[tuscia].didintiCount();
            zodziai[tuscia].pridetiSakini(sakinioNumeris);
        }
        if(sakinioPabaiga) sakinioNumeris++;
    }
    fr.close();
}
void WordCounter::isvedimas(const string& failas) //! funkcija, kuri isveda zodzius ir ju kieki i faila
{
    ofstream fd(failas);
    if(!fd.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << failas << std::endl;
        return;
    }
    fd << std::left << std::setw(25) << "Zodis" << "Kiekis" << endl;
    for(const auto& pora : zodziai)
    {
        if(pora.second.getCount() > 1) //! isvedame tik tuos zodzius, kurie yra daugiau nei 1 karta
        fd << std::left << std::setw(25) << pora.second.getWord() << pora.second.getCount() << endl;
    }
    fd.close();
}
void WordCounter::isvedimasCrossReference(const string& failas) //! funkcija, kuri isveda zodzius, ju kieki ir sakinius, kuriuose jie yra i faila
{
    ofstream fd(failas);
    if(!fd.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << failas << std::endl;
        return;
    }
    fd << std::left << std::setw(25) << "Zodis" << std::setw(10) << "Kiekis" << "Sakiniai" << endl;
    fd<< std::string(60, '-') << endl;
    for(const auto& pora : zodziai)
    {
        if(pora.second.getCount() > 1)
        {
            fd << pora.second;
        }
    }
    fd.close();
}