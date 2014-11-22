#include "word.h"

Word::Word()
{
}


Word::Word(string word, int pageId)
{
    this->word = word;
    this->pageId = pageId;
}

void Word::addPages(int pageId)
{
    pageIds.push_back(pageId);
}

void Word::addToMap(int pageId)
{
    cout << "getting to insert function!" << endl;
    int page = pageId;
    int occurance = 1;
    info[page] = occurance;
}


string Word::getWord() const
{
    return word;
}

int Word::getPageId() const
{
    return pageId;
}

void Word::increaseFrequency(int pageId)
{
    info[pageId]++;
    cout << info[pageId] << endl;
}

bool Word::lookForPage(int page)
{
    for(int k = 0; k < pageIds.size(); k++)
    {
        if(page == pageIds[k])
        {
            return true;
        }

    }

    return false;
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
