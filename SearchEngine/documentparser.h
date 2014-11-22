#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include "stopword.h"
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
//#include "Stemmer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>

using namespace std;
using namespace rapidxml;

class DocumentParser
{
private:
    vector <Page*> pages;
    vector <Word*> words;
    ifstream fin;

public:
    DocumentParser();
    DocumentParser(ifstream& fin);
    ~DocumentParser();

    void addWord(Word*& w);
    void addPage(Page*& p);
    bool checkForPage(int page, Word*& x);
    bool checkForWord(string& temp);
    void getInput();
    void makeLowerCase(string&);
    Word* returnWordObject(string&);
};

#endif // DOCUMENTPARSER_H
