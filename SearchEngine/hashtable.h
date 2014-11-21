#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "word.h"
#include "avltree.h"

class HashTable
{
private:
    int count;
    AVLTree<Word> * trees;
public:
    HashTable();
    ~HashTable();
    void addWord(Word);
    unsigned hashKey(const char*);
    Word searchTrees(char*);
    bool containsKey(char*);
};

#endif // HASHTABLE_H
