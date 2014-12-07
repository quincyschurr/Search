#include "word.h"

Word::Word()
{

}

Word::Word(string& word)
{
    this->word = word;
    numOfPages = 0;
}

void Word::addPages(int& pageId)
{
    vPages.push_back(pageId);
    numOfPages++;
    pages.insert(pageId);
}

void Word::addToMap(int& pageId, int o)
{
    int page = pageId;
    int occurance = o;
    info[page] = occurance;
}

map<int,int> Word::getInfo()
{
    return info;
}

int Word::getNumPages() const
{
    return numOfPages;
}

vector<int> Word::getPages()
{
    return vPages;
}

int Word::getPageId() const
{
    return pageId;
}

void Word::getPageTree(ostream& fout)
{
    for(map<int, int>::iterator it = info.begin(); it!=info.end(); ++it)
    {
        fout << it->first << "(" << it->second << "), ";
    }
}

string Word::getWord() const
{
    return word;
}

void Word::increaseFrequency(int& pageId)
{
    info[pageId]++;
}

bool Word::lookForPage(int& page)
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
