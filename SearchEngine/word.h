#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "avltree.h"

using namespace std;

class Word
{
private:
    string word;
    int pageId;
    AVLTree <int> pages;
    map <int, int> info;

public:
    void addPages(int pageId);
    void addToMap(int pageId, int occurance);
    string getWord() const;
    int getPageId() const;
    void getPageTree(ostream&);
    void increaseFrequency(int pageId);
    bool lookForPage(int page);

    friend bool operator>(const string& lhs, const Word& rhs);
    friend bool operator<(const string& lhs, const Word& rhs);
    friend bool operator==(const string& lhs, const Word& rhs);

    Word();
    Word(string word, int pageId);
    ~Word();
};

#endif // WORD_H
