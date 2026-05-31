#include "wordcounter.h"
string WordCounter::arZodis(const string& zodis)//! funkcija, kuri patikrina ar zodis yra zodis, o ne skyrybos zenklas
{
    string rezultatas;
    for (size_t i = 0; i < zodis.size(); ) //! iteruojame per zodzio simbolius, bet ne kiekviena baitą, o visą simbolį (daugiabaitiai UTF-8)
    {
        unsigned char c = zodis[i];

        //! Daugiabaitiai UTF-8 simboliai (skyrybos ženklai kaip „ " – —)
        if (c >= 0x80) //! UTF-8 simbolis prasideda, jei baitas yra 128 ar didesnis
        {
            //! Nustatome kiek baitų užima šis simbolis
            int baitai = 1;
            if      (c >= 0xF0) baitai = 4; //! 4 baitų simboliai (retai naudojami, bet gali būti)
            else if (c >= 0xE0) baitai = 3; //! 3 baitų simboliai (dažniausiai lietuviškos raidės)
            else if (c >= 0xC0) baitai = 2; //! 2 baitų simboliai (dažniausiai lietuviškos raidės)

            //! Surenkame visą simbolį
            string simbolis = zodis.substr(i, baitai);

            //! Lietuviškos raidės prasideda nuo 0xC3 arba 0xC5
            if (c == 0xC3 || c == 0xC5) {
                //! Tai lietuviška raidė – paliekame
                for (char ch : simbolis) rezultatas += ch;
            }
            //! Kiti daugiabaitiai – skyrybos ženklai, praleidžiame
            i += baitai;
            continue;
        }

        //! ASCII skyrybos ženklai
        if (c == '.' || c == ',' || c == '!' || c == '?' ||
            c == ';' || c == ':' || c == '-' || c == '"' ||
            c == '(' || c == ')' || c == '\'') {
            i++;
            continue;
        }

        //! Paprastos ASCII raidės
        rezultatas += (char)tolower(c);
        i++;
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
void WordCounter::isvedimas(const string& failas) //! funkcija, kuri isveda zodzius, ju kieki ir sakinius, kuriuose jie yra i faila
{
    ofstream fd(failas);
    if(!fd.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << failas << std::endl;
        return;
    }
    fd << std::left << std::setw(25) << "Zodis" << std::setw(10) << "Kiekis" << "Sakiniai" << endl;
    for(const auto& pora : zodziai)
    {
        if(pora.second.getCount() > 1)
        {
            fd << pora.second;
        }
    }
    fd.close();
}