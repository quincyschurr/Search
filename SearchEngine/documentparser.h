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
    //AVLTree <Page*> pages2;
    HashTable table;

public:
    DocumentParser();
    ~DocumentParser();

    AVL2 wordAVL;
    AVL2 getwordAVL();

    bool checkForWord(string& temp);
    void getInput();
};

#endif // DOCUMENTPARSER_H
