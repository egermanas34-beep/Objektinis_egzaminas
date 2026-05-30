
#pragma once
#include <string>

class Word
{
    private:
        std::string word;
        int count;
    public:
     
    const std::string& getWord()const {return word;};
    int getCount()const {return count;};
    void setWord(const std::string& word) {this->word = word;};
    void setCount(int count) {this->count = count;};
    
};