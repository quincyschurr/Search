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
    pages.insert(pageId);
}

void Word::addToMap(int pageId)
{
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

ostream& Word::getPageTree(ostream& fout)
{
    return pages.print2(fout);
}

void Word::increaseFrequency(int pageId)
{
    info[pageId]++;
    cout << info[pageId] << endl;
}

bool Word::lookForPage(int page)
{
    if(pages.search(page, pages.getRoot()) == true)
        return true;
    else
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

bool operator==(const Word& lhs, const Word& rhs)
{
    if(lhs.getWord() == rhs.getWord())
        return true;
    else
        return false;
}




Word::~Word()
{

}
