#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "documentparser.h"
#include <./porterstem.h>
#include "avl2.h"
#include "hashtable.h"
#include "avltree.h"
#include "page.h"
#include "word.h"

using namespace std;

class Query
{
private:
    AVL2 tree;
    HashTable table;
    AVLTree <Page*> pageIndex;
    vector <string> searchWords;
public:
    void buildIndex();
    void startQuery();
    Query();
    ~Query();
    vector<int> qAND(vector<int>, vector<int>);
    vector<int> qOR(vector<int>, vector<int>);
    vector<int> qNOT(vector<int>, vector<int>);
};

#endif // QUERY_H
