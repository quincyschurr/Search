#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>
#include <iostream>
#include <array>
#include <fstream>
#include <cstring>

using namespace std;

class StopWord
{
private:
    string testWord;
    string inputWord;
    string words[635];
public:
    void createArray(ifstream&);
    bool isStopWord(const string& testWord);
    StopWord();
    ~StopWord();
};

#endif // STOPWORD_H
