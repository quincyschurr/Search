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
#include "AVLNODE.h"
#include "hashtable.h"

using namespace std;
using namespace rapidxml;

class DocumentParser
{
private:

public:
    DocumentParser();
    ~DocumentParser();

    AVL2 wordAVL; //probably need to be private
    HashTable table; //probably need ot be private
    AVLTree <Page*> pages;//make private and use getter/setters

    AVL2 getwordAVL();
    HashTable getTable();

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
