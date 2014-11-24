#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include "stopword.h"
#include "avltree.h"
#include "avl2.h"
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;
using namespace rapidxml;

class DocumentParser
{
private:
    vector <Page*> pages;
    vector <Word*> words;
    AVLTree <Word*> wordAVL;

public:
    DocumentParser();
    ~DocumentParser();

    bool checkForWord(string& temp);
    bool checkForWord(Word*& temp);
    void getInput();
    void makeLowerCase(string&);
    Word* returnWordObject(string&);
};

#endif // DOCUMENTPARSER_H
