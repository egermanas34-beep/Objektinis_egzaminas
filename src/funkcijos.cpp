
#include "word.h"
#include "funkcijos.h"
string arZodis(const string& zodis)
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
            zodziai.insert({tuscia, Word(tuscia, 1)});//pridedama i zozdiu zemelapi zodzio reiksme ir count 1. zodzio reiksme
        } else {
            //jei zodis jau yra, tai padidiname count reiksme
            zodziai[tuscia].setWord(tuscia);
            zodziai[tuscia].didintiCount();
        }
    }
    fr.close();

}
void isvedimas(const map<string, Word>& zodziai)
{
    ofstream fd("rezultatai.txt");
    if(!fd.is_open())
    {
        cout << "Nepavyko atidaryti failo: rezultatai.txt" << std::endl;
        return;
    }
    for(const auto& pora : zodziai)
    {
        if(pora.second.getCount() > 1) //isvedame tik tuos zodzius, kurie pasikartoja daugiau nei 1 karta
        {
            fd << pora.second << std::endl;
            cout << " raktas [" << pora.first << "] = zodis : " << pora.second.getWord() << ", skaicius: " << pora.second.getCount() << "\n";
        }
    }
    fd.close();
}