#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include "avltree.h"
#include "word.h"

class IndexHandler
{
private:
    AVLTree <Word> avlindex;
    //hashtable
public:
    //all this for indexinterface
    //.cpp will just look like this
    //Interface::Interface()
    //{
    //}
    virtual void addtoindex(string&, int) = 0;
    virtual void removefromindex(string&) = 0;
    virtual vector<int> search(string&) = 0;
    virtual bool contains(string&) = 0;
    //virtual vector <Data <string, int> >* save() = 0;
    //virtual void load(vector<Data<string, int>>&) = 0;
    virtual void printreversefileindex() = 0;
    virtual void deleteIndexes() = 0;

    IndexHandler();
    virtual ~IndexHandler();
};

#endif // INDEXHANDLER_H
