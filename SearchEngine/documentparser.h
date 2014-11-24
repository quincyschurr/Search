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
    vector <Page*> pages;
    //AVLTree <Page*> pages2;
    vector <Word*> words;
<<<<<<< HEAD
=======
    AVL2 * wordAVL;
>>>>>>> 24af8799a97685723773fe4ac411c40d5c094fc0
    HashTable table;

public:
    DocumentParser();
    ~DocumentParser();

<<<<<<< HEAD
    AVL2 wordAVL;
    AVL2 getwordAVL();
=======
    AVL2* getwordAVL();
>>>>>>> 24af8799a97685723773fe4ac411c40d5c094fc0
    bool checkForWord(string& temp);
    //bool checkForWord(Word*& temp);
    void getInput();
    Word* returnWordObject(string&);
};

#endif // DOCUMENTPARSER_H
