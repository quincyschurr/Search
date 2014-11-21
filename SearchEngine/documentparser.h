#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include "stopword.h"
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include "Stemmer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
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
    void makeLowerCase(char*&);
    void stopWords();
    char** splitWords(char* buffer, int size);
};

#endif // DOCUMENTPARSER_H
