#include "word.h"
#include "wordcounter.h"
#include "urlfinder.h"

#include "windows.h"
int main()
{
    SetConsoleOutputCP(CP_UTF8); //! Nustatome konsolės išvesties koduotę į UTF-8
    SetConsoleCP(CP_UTF8); //! Nustatome konsolės įvesties koduotę į UTF-8
    
    WordCounter wc;
    UrlFinder uf;
    
    cout<< " Ka jus norite padaryti? \n 1. Rasti zodzius ir ju skaiciu tekste \n 2. Rasti URL adresus tekste \n";
    int pasirinkimas;
    std::cin >> pasirinkimas;
    switch(pasirinkimas)
    {
        case 1:
            wc.nuskaitymas("tekstas.txt");
            wc.isvedimas("rezultatai.txt");
            break;
        case 2:
            uf.nuskaitymas("tekstas2.txt");
            uf.isvedimas("rezultatai2.txt");
            break;
        default:
            cout << "Neteisingas pasirinkimas. Programa baigiama." << endl;
    }
    cout<<"Programa baigta. Rezultatai issaugoti atitinkamuose failuose."<<endl;
    cout<<"Paspauskite Enter, kad uzdarytumete programa..."<<endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}