#include "word.h"
#include "funkcijos.h"
#include "windows.h"
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    map<string, Word> zodziai;
    nuskaitymas("tekstas.txt", zodziai);
    
    
    isvedimas(zodziai);
    return 0;
}