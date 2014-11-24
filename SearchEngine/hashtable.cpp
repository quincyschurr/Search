#include "hashtable.h"

HashTable::HashTable()
{
    count = 104729;
    trees = new AVL2[count]; //might seg fault
    //for(int i = 0; i < count; i++)
    //{
        //trees[i] = AVL2();
    //}
}

HashTable::~HashTable() {

}

void HashTable::addWord(Word*& w) {
    string test = w->getWord();
    int key = hashKey(test.c_str()) % count;
    trees[key].insert(w);
}

unsigned HashTable::hashKey(const char* word) {
        /*unsigned h = 1;
        while (*word)
            h = h * 101 + (unsigned) *word++;
        return h;*/
    unsigned h = 1;
    for(int i = 0; i < 2; i++)
        h = h * 101 + (unsigned) *word++;
    return h;
}

Word* HashTable::searchTrees(string test) {
    int key = hashKey(test.c_str()) % count;
    return trees[key].returnWord(test);
    //AVLNode* root = trees[key].getRoot();
    //string temp2 = trees[key].find(test);

}

AVLNODE* HashTable::getRoot(string temp) {
    int key = hashKey(temp.c_str()) % count;
    return trees[key].getRoot();
}

bool HashTable::searchFor(string& x, AVLNODE* root) {
    int key = hashKey(x.c_str()) % count;
    return trees[key].searchFor(x, root);
}

Word*& HashTable::returnWord(string& test) {
    int key = hashKey(test.c_str()) % count;
    return trees[key].returnWord(test);
}


