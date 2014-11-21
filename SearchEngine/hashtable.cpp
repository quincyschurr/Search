#include "hashtable.h"

HashTable::HashTable()
{
    count = 104729;
    trees = new AVLTree<Word>[count]; //might seg fault
    //for(int i = 0; i < count; i++)
    //{
        //trees[i] = new AVLTree<Word>;
    //}
}

HashTable::~HashTable() {

}

void HashTable::addWord(Word& w) {
    string test = w.getWord();
    int key = hashKey(test.c_str()) % count;
    trees[key].insert(w);
}

unsigned HashTable::hashKey(const char* word) {
        unsigned h = 1;
        while (*word)
            h = h * 101 + (unsigned) *word++;
        return h;
}

Word HashTable::searchTrees(char* test) {
    int key = hashKey(test) % count;
    //need get roodnode funciton in AVL
    AVLNode * root = trees[key].getRoot();
    trees[key].find(test, root);
}

