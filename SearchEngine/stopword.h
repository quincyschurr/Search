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
    //how should I store the stopWords? Just hardcode them in?
public:
    bool testForStopWord(string testWord);
    StopWord();
    StopWord(string testWord);
    ~StopWord();
};

#endif // STOPWORD_H
