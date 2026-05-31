
#include "word.h"

Word::Word() //! defaultinis konstruktorius
{
    word = "";
    count = 0;
}

Word::Word(const string& word, int count) //! konstruktorius su žodžiu ir skaičiumi
{
    this->word = word;
    this->count = count;
}
Word::Word(const string& word, int count, int sakinys) //! konstruktorius su žodžiu, skaičiumi ir sakinio numeriu
{
    this->word = word;
    this->count = count;
    this->sakiniai.insert(sakinys);
}
Word::Word(const Word&zodis) //! kopijavimo konstruktorius
{
    word = zodis.word;
    count = zodis.count;
    sakiniai = zodis.sakiniai;
}
Word& Word::operator=(const Word& zodis) //! kopijavimo priskyrimo operatorius
{
    if(this == &zodis)
    return *this;
        word = zodis.word;
        count = zodis.count;
        sakiniai = zodis.sakiniai;
    
    return *this;
}
Word::Word(Word&& zodis) //! move konstruktorius
{
    word = std::move(zodis.word);
    count = zodis.count;
    sakiniai = std::move(zodis.sakiniai);
    zodis.word.clear();
    zodis.count = 0;
    zodis.sakiniai.clear();
}
Word& Word::operator=(Word&& zodis)//! move priskyrimo operatorius
{
    if(this == &zodis)
    return *this;
        word = std::move(zodis.word);
        count = zodis.count;
        sakiniai = std::move(zodis.sakiniai);
        zodis.word.clear();
        zodis.count = 0;
        zodis.sakiniai.clear();
    
    return *this;
}
Word::~Word()//! destruktorius
{
    word.clear();
    count = 0;
    sakiniai.clear();
}
std::ostream& operator<<(std::ostream& os, const Word& zodis)  //! perdengtas išvedimo operatorius
{
    os << std::left << std::setw(25) << zodis.getWord()<<std::left << std::setw(10) << zodis.getCount();
    for (const auto& sakinys : zodis.getSakiniai())
    {
        os << sakinys << " ";
    }
    os << endl;
    return os;
}