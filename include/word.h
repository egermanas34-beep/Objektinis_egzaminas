
#pragma once
#include "bibliotekos.h"

class Word
{
    private:
        string word;
        int count;
    public:
    Word();
    Word(const string& word, int count);
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
    friend std::ostream& operator<<(std::ostream& os, const Word& zodis);
};