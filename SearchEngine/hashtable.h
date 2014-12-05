#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "word.h"
#include "avl2.h"
#include "AVLNODE.h"

class HashTable
{
private:
    int count;
    AVL2 * trees;
public:
    HashTable();
    ~HashTable();
    void addWord(Word*);
    AVLNODE* getRoot(string);
    unsigned hashKey(const char*);
    void printTrees(ostream&);
    Word* returnWord(string& test);
    bool searchFor(string& x, AVLNODE* root);
    Word* searchTrees(string);
};

#endif // HASHTABLE_H
