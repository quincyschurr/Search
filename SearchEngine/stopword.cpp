#include "stopword.h"

StopWord::StopWord()
{

}

StopWord::StopWord(ifstream& fin)
{
}

StopWord::StopWord(string testWord)
{
    this->testWord = testWord;

}

void StopWord::createArray(ifstream& fin)
{
    for(int i = 0; i < words.length(); i++)
    {
        fin >> inputWord;
        words[i] = inputWord;
    }
}

bool StopWord::testForStopWord(string testWord)
{

}


StopWord::~StopWord()
{

}

