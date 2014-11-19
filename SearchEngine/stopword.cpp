#include "stopword.h"

StopWord::StopWord()
{

}

void StopWord::createArray(ifstream& fin)
{
    for(int i = 0; i < 635; i++)
    {
        fin >> inputWord;
        words[i] = inputWord;
    }
}

bool StopWord::isStopWord(const string& testWord)
{
   for(int j = 0; j < 635; j++)
   {
       if(testWord == words[j])
       {
           return true;
       }
   }
   return false;

}


StopWord::~StopWord()
{

}

