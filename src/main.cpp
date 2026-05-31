#include "word.h"
#include "wordcounter.h"
#include "urlfinder.h"
#include "funkcijos.h"
#include "windows.h"
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    /*map<string, Word> zodziai;
    nuskaitymas("tekstas.txt", zodziai);
    isvedimas(zodziai);*/
    WordCounter wc;
    wc.nuskaitymas("tekstas.txt");
    wc.isvedimas("rezultatai.txt");
    UrlFinder uf;
    uf.nuskaitymas("tekstas2.txt");
    uf.isvedimas("rezultatai2.txt");
    return 0;
}