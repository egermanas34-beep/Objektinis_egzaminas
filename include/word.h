
#pragma once
#include "bibliotekos.h"

class Word
{
    private:
        string word;
        int count;
        std::set<int> sakiniai;
    public:
    Word();
    Word(const string& word, int count);
    Word(const string& word, int count, int sakinys);
    Word(const Word& zodis);
    Word& operator=(const Word& zodis);
    Word(Word&& zodis);
    Word& operator=(Word&& zodis); 
    ~Word();
    const string& getWord()const {return word;};
    int getCount()const {return count;};
    void setWord(const string& word) {this->word = word;};
    void setCount(int count) {this->count = count;};
    
    void didintiCount() {this->count++;};
    void pridetiSakini(int sakinioNumeris) {sakiniai.insert(sakinioNumeris);};
    const std::set<int>& getSakiniai() const {return sakiniai;};
    friend std::ostream& operator<<(std::ostream& os, const Word& zodis);
};