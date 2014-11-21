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

Word HashTable::searchTrees(string test) {
    int key = hashKey(test.c_str()) % count;
<<<<<<< HEAD

=======
    //AVLNode* root = trees[key].getRoot();
    //string temp2 = trees[key].find(test);
>>>>>>> ae4c6791ada408fd44b726ba5ffcbe2d67f052ef
}

