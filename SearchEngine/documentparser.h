#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include <vector>

using namespace std;

class DocumentParser
{
private:
    vector <Page> pages;
    vector <Word> words;

public:
    DocumentParser();
    ~DocumentParser();

};

#endif // DOCUMENTPARSER_H
