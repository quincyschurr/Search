#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StopWord
{
private:
    string testWord;
    string inputWord;
    string words[635];
public:
    void createArray(ifstream& fin);
    bool testForStopWord(string testWord);
    StopWord();
    StopWord(ifstream&);
    StopWord(string testWord);
    ~StopWord();
};

#endif // STOPWORD_H
