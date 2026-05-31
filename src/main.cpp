#include "word.h"
#include "wordcounter.h"
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
    return 0;
}