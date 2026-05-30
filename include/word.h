
#pragma once
#include <string>

class Word
{
    private:
        std::string word;
        int count;
    public:
    Word();
    Word(const std::string& word, int count);
    Word(const Word& zodis);
    Word& operator=(const Word& zodis);
    Word(Word&& zodis);
    Word& operator=(Word&& zodis); 
    ~Word();
    const std::string& getWord()const {return word;};
    int getCount()const {return count;};
    void setWord(const std::string& word) {this->word = word;};
    void setCount(int count) {this->count = count;};
    
};