#ifndef DOCUMENTPARSER_H
#define DOCUMENTPARSER_H

#include "word.h"
#include "page.h"
#include <./porterstem.h>
#include "stopword.h"
#include "avltree.h"
#include "avl2.h"
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include "AVLNODE.h"
#include "hashtable.h"

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
    AVL2 wordAVL;
    HashTable table;
    AVLTree <Page*> pages;

public:
    DocumentParser();
    ~DocumentParser();

    AVLTree <Page*> getPageAVL();
    HashTable getTable();
    AVL2 getwordAVL();

    bool checkForWordAVL(string& temp);
    bool checkForWordHash(string& temp);
    void getInputAVL();
    void getInputHash();
    //http://stackoverflow.com/questions/10178700/c-strip-non-ascii-characters-from-string
    void stripUnicode(string& temp);

    struct InvalidChar
    {
        bool operator()(char c) const
        {
            return !isprint((unsigned) c);
        }
    };
};

#endif // DOCUMENTPARSER_H
