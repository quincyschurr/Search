#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include "stopword.h"
#include <vector>
#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include "rapidxml_utils.hpp"
#include <sstream>
#include <cstdlib>
#include <map>

using namespace std;
using namespace rapidxml;

class DocumentParser
{
private:
    vector <Page> pages;
    vector <Word> words;

public:
    DocumentParser();
    ~DocumentParser();

    void addWord(Word*& w);
    void addPage(Page*& p);
    void getInput();
    void stopWords();
    void makeLowerCase(char*&);
};

#endif // DOCUMENTPARSER_H
