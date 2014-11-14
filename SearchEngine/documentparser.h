#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include <vector>
#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
//#include "rapidxml_iterators.hpp"

using namespace std;

class DocumentParser
{
private:
    vector <Page> pages;
    vector <Word> words;

public:
    DocumentParser();
    ~DocumentParser();
    void getInput();
};

#endif // DOCUMENTPARSER_H
