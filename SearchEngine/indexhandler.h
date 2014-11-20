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
    IndexHandler();
    ~IndexHandler();
};

#endif // INDEXHANDLER_H
