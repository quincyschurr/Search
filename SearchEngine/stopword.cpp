#include "stopword.h"

StopWord::StopWord()
{

}


void StopWord::createArray()
{
    ifstream fin("stopWords.txt");
    for(int i = 0; i < 643; i++)
    {
        fin >> inputWord;
        stWordArray.push_back(inputWord);
    }
}

bool StopWord::isStopWord(const string& testWord)
{
    if(binary_search(stWordArray.begin(), stWordArray.end(), testWord))
        return true;
    else
        return false;

}


StopWord::~StopWord()
{

}

