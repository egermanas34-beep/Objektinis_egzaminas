#include "urlfinder.h"

bool UrlFinder::arURL(const string& zodis)
{
    return zodis.rfind("https://", 0) == 0 ||
            zodis.rfind("http://", 0) == 0 ||
            zodis.rfind("www.", 0) == 0 ||
            zodis.find(".lt") != string::npos ||
            zodis.find(".com") != string::npos ||
            zodis.find(".net") != string::npos ||
            zodis.find(".org") != string::npos;
}
string UrlFinder::sutvarkytiURL(const string& zodis)
{
    string sutvarkytasURL = zodis;
    // Pašaliname galimus skyrybos ženklus iš URL pradžios ir pabaigos
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
