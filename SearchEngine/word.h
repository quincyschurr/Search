#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "frequency.h"

using namespace std;

class Word
{
private:
    char** word;
    int hashKey;
    int pageId;
    //Frequency* freq;
    int frequency;
    map <int, int> info;

public:
    void addFrequency(int pageId);
    int getHashKey();
    char** getWord() const;
    void insertToMap(int pageId);
    char* getHashWord(); //add functionality

    friend bool operator>(const Word& lhs, const Word& rhs);
    friend bool operator<(const Word& lhs, const Word& rhs);

    Word();
    //this is the beginning constructor for when we have a hash table
    //Word(string word, int hashKey, int pageId);
    Word(char** word, int pageId);
    ~Word();
};

#endif // WORD_H
