#include "wordcounter.h"
string WordCounter::arZodis(const string& zodis)
{
    string rezultatas;
    for (size_t i = 0; i < zodis.size(); ) {
        unsigned char c = zodis[i];

        // Daugiabaitiai UTF-8 simboliai (skyrybos ženklai kaip „ " – —)
        if (c >= 0x80) {
            // Nustatome kiek baitų užima šis simbolis
            int baitai = 1;
            if      (c >= 0xF0) baitai = 4;
            else if (c >= 0xE0) baitai = 3;
            else if (c >= 0xC0) baitai = 2;

            // Surenkame visą simbolį
            string simbolis = zodis.substr(i, baitai);

            // Lietuviškos raidės prasideda nuo 0xC3 arba 0xC5
            if (c == 0xC3 || c == 0xC5) {
                // Tai lietuviška raidė – paliekame
                for (char ch : simbolis) rezultatas += ch;
            }
            // Kiti daugiabaitiai – skyrybos ženklai, praleidžiame
            i += baitai;
            continue;
        }

        // ASCII skyrybos ženklai
        if (c == '.' || c == ',' || c == '!' || c == '?' ||
            c == ';' || c == ':' || c == '-' || c == '"' ||
            c == '(' || c == ')' || c == '\'') {
            i++;
            continue;
        }

        // Paprastos ASCII raidės
        rezultatas += (char)tolower(c);
        i++;
    }
    return rezultatas;
}
void WordCounter::nuskaitymas(const string& failas)
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
        bool sakinioPabaiga = false;
            if(eilute.find('.') != string::npos || eilute.find('!') != string::npos || eilute.find('?') != string::npos)
            {
                sakinioPabaiga = true;
            }

        string tuscia = arZodis(eilute);
        if (tuscia.empty()) {if(sakinioPabaiga) sakinioNumeris++; continue;}

        if (zodziai.find(tuscia) == zodziai.end())
        {  
            Word naujasZodis(tuscia, 1);
            naujasZodis.pridetiSakini(sakinioNumeris);
            zodziai.insert({tuscia, naujasZodis});//pridedama i zozdiu zemelapi zodzio reiksme ir count 1. zodzio reiksme
        } else {
            //jei zodis jau yra, tai padidiname count reiksme
            zodziai[tuscia].setWord(tuscia);
            zodziai[tuscia].didintiCount();
            zodziai[tuscia].pridetiSakini(sakinioNumeris);
        }
        if(sakinioPabaiga) sakinioNumeris++;
    }
    fr.close();
}
void WordCounter::isvedimas(const string& failas)
{
    ofstream fd(failas);
    if(!fd.is_open())
    {
        cout << "Nepavyko atidaryti failo: " << failas << std::endl;
        return;
    }
    for(const auto& pora : zodziai)
    {
        if(pora.second.getCount() > 1)
        {
            fd << pora.second << endl;
        }
    }
    fd.close();
}