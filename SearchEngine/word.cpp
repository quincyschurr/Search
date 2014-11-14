#include "word.h"

Word::Word()
{
}

Word::Word(string word, int hashKey, int pageId, int freqency)
{
    this->word = word;
    this->hashKey = hashKey;
    this->pageId = pageId;
    this->frequency = frequency;
}

void Word::addFrequency()
{
    frequency.push_back(1);
}

void Word::addPageId(int pageId)
{
    pageIds.push_back(pageId);
}

void Word::increaseFrequency()
{//supposed to add one to the correct subscript in the vector

}

int Word::getHashKey()
{
    return hashKey;
}

string Word::getWord()
{
    return word;
}

Word::~Word()
{

}
