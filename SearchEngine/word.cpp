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

void Word::addFrequency(int pageId)
{
    info[pageId] = frequency++;
}

int Word::getHashKey()
{
    return hashKey;
}

string Word::getWord() const
{
    return word;
}

void Word::insertToMap(int pageId)
{
    cout << "getting to insert function!" << endl;
    //iterator it;
    //it = info.find(pageId);
    /*if(info.find(pageId) == true)
    {
        info->addFrequency(pageId);
    }
    else
    {
        info.insert(pair<int, int> (pageId, frequency));
    }*/
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
