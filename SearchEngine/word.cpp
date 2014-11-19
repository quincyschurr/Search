#include "word.h"

Word::Word()
{
}

Word::Word(string word, int hashKey, int pageId)
{
    this->word = word;
    this->hashKey = hashKey;
    this->pageId = pageId;
    this->frequency = 1;
}

void addFrequency(int pageId)
{
    info[pageId] = frequency++;
}

int Word::getHashKey()
{
    return hashKey;
}

string Word::getWord()
{
    return word;
}

void insertToMap(int pageId)
{
    //iterator it;
    //it = info.find(pageId);
    if(info.find(pageId) == true)
    {
        info.addFrequency(pageId);
    }
    else
    {
        info.insert(pair<int, int> (pageId, frequency));
    }
}

bool operator>(const Word& lhs, const Word& rhs)
{
    if(lhs.getWord() > rhs.getWord())
        return true;
    else
        return false;
}

bool operator<(const Word& lhs, const Word& rhs)
{
    if(lhs.getWord() < rhs.getWord())
        return true;
    else
        return false;
}

Word::~Word()
{

}
