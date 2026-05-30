
#include "word.h"
#include "funkcijos.h"
string arZodis(const string& zodis)
{
    string rezultatas;
    for (size_t i = 0; i < zodis.size(); i++) {
        unsigned char c = zodis[i];
        // Išmetame tik ASCII skyrybos ženklus
        if (c == '.' || c == ',' || c == '!' || c == '?' ||
            c == ';' || c == ':' || c == '-' || c == '"' ||
            c == '(' || c == ')' || c == '\'' || c == '"' || c == '„' || c == '\xE2') {
            continue;
        }
        rezultatas += (char)tolower(c);
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
            zodziai.insert({tuscia, Word(tuscia, 1)});
        } else {
            //jei zodis jau yra, tai padidiname count reiksme
            zodziai[tuscia].setCount(zodziai[tuscia].getCount() + 1);
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
        fd << pora.second.getWord() << ": " << pora.second.getCount() << std::endl;
       std::cout << "[" << pora.first << "] = " << pora.second.getCount() << "\n";
    }
    fd.close();
}