#include "stopword.h"

StopWord::StopWord()
{

}


void StopWord::createArray()
{
    ifstream fin("stopWords.txt");
    for(int i = 0; i < 635; i++)
    {
        fin >> inputWord;
        stWordArray.push_back(inputWord);
    }
}

bool StopWord::isStopWord(const string& testWord)
{
    if(find(stWordArray.begin(), stWordArray.end(), testWord) == stWordArray.end())
        return false;
    else
        return true;

}


StopWord::~StopWord()
{

}

