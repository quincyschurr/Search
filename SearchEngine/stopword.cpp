#include "stopword.h"

StopWord::StopWord()
{

}

<<<<<<< HEAD
/*StopWord::StopWord(ifstream& fin)
{
}

StopWord::StopWord(string testWord)
{
    this->testWord = testWord;

}

=======
>>>>>>> c516c95e9142ae117e5b6f5f6fceba3d5413b307
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

}*/

