#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Word
{
private:
    string word;
    int pageId;
    //AVLTree <int> pages;
    vector <int> pages;
    //vector <int> pageIds;
    int frequency;
    map <int, int> info;

public:
    void addPages(int pageId);
    void addToMap(int pageId);
    string getWord() const;
    int getPageId() const;
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
