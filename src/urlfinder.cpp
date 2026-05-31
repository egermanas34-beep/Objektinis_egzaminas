#include "urlfinder.h"

bool UrlFinder::arURL(const string& zodis) //! funkcija, kuri patikrina ar zodis yra URL adresas
{
    return zodis.rfind("https://", 0) == 0 ||
            zodis.rfind("http://", 0) == 0 ||
            zodis.rfind("www.", 0) == 0 ||
            zodis.find(".lt") != string::npos ||
            zodis.find(".com") != string::npos ||
            zodis.find(".net") != string::npos ||
            zodis.find(".org") != string::npos;
}
string UrlFinder::sutvarkytiURL(const string& zodis) //! funkcija, kuri pašalina galimus skyrybos ženklus iš URL pradžios ir pabaigos
{
    string sutvarkytasURL = zodis;
    //! Pašaliname galimus skyrybos ženklus iš URL pradžios ir pabaigos
    while (!sutvarkytasURL.empty() &&
        (sutvarkytasURL.back() == '.' ||
         sutvarkytasURL.back() == ',' ||
         sutvarkytasURL.back() == '!' ||
         sutvarkytasURL.back() == '?' ||
         sutvarkytasURL.back() == ';' ||
         sutvarkytasURL.back() == ':' ||
         sutvarkytasURL.back() == '-' ||
         sutvarkytasURL.back() == '"' ||
         sutvarkytasURL.back() == '(' ||
         sutvarkytasURL.back() == ')' ||
         sutvarkytasURL.back() == '\''))
    {
        sutvarkytasURL.pop_back();
    }
    while (!sutvarkytasURL.empty() &&
        (sutvarkytasURL.front() == '.' ||
         sutvarkytasURL.front() == ',' ||
         sutvarkytasURL.front() == '!' ||
         sutvarkytasURL.front() == '?' ||
         sutvarkytasURL.front() == ';' ||
         sutvarkytasURL.front() == ':' ||
         sutvarkytasURL.front() == '-' ||
         sutvarkytasURL.front() == '"' ||
         sutvarkytasURL.front() == '(' ||
         sutvarkytasURL.front() == ')' ||
         sutvarkytasURL.front() == '\''))
    {
        sutvarkytasURL.erase(0,1);
    }
    return sutvarkytasURL;
}
void UrlFinder::nuskaitymas(const string& failas) //! funkcija, kuri skaito faila ir iesko URL adresu
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
        string url = sutvarkytiURL(eilute);
        if(arURL(url))
        {
            urls.insert(url);
        }
    }
}
void UrlFinder::isvedimas(const string& failas)
{
    ofstream fd(failas);
    if(!fd.is_open())
    {cout << " Nepavyko atidaryti failo: " << failas << endl;
    return;
    }
    fd << "Rasti URL adresai:" << endl;
    fd<<"-------------------" << endl;
    for(const auto& url : urls)
    {
        fd << url << endl;
    }
}
