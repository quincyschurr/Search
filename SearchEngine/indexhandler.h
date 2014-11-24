#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include "avltree.h"
#include "word.h"
#include "documentparser.h"
#include "avl2.h"
#include <iostream>
#include <fstream>

using namespace std;
class IndexHandler
{
private:
    AVLTree <Word> avlindex;
    //hashtable
public:

    void print();
    //all this for indexinterface
    //.cpp will just look like this
    //Interface::Interface()
    //{
    //}
    /*virtual void addtoindex(string&, int) = 0;
    virtual void removefromindex(string&) = 0;
    virtual vector<int> search(string&) = 0;
    virtual bool contains(string&) = 0;
    //virtual vector <Data <string, int> >* save() = 0;
    //virtual void load(vector<Data<string, int>>&) = 0;
    virtual void printreversefileindex() = 0;
    virtual void deleteIndexes() = 0;*/

    IndexHandler();
    ~IndexHandler();
};

#endif // INDEXHANDLER_H
