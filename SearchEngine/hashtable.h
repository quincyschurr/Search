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
    unsigned hashKey(const char*);
    Word* searchTrees(string);
    bool containsKey(char*);
    AVLNODE* getRoot(string);
    bool searchFor(string& x, AVLNODE* root);
    Word* returnWord(string& test);
    void printTrees(ostream&);
};

#endif // HASHTABLE_H
