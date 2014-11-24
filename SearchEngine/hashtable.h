#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "word.h"
#include "avl2.h"

class HashTable
{
private:
    int count;
    AVL2 * trees;
public:
    HashTable();
    ~HashTable();
    void addWord(Word&);
    unsigned hashKey(const char*);
    Word* searchTrees(string);
    bool containsKey(char*);
};

#endif // HASHTABLE_H
