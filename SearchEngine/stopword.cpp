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
    if(binary_search(stWordArray.begin(), stWordArray.end(), testWord))
        return true;
    else
        return false;

    /*if(find(stWordArray.begin(), stWordArray.end(), testWord) == stWordArray.end())
        return false;//means that the word wasn't found
    else
        return true;*/
}


StopWord::~StopWord()
{

}

