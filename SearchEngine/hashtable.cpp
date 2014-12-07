#include "hashtable.h"

HashTable::HashTable()
{
    count = 1299827;
    trees = new AVL2[count];
    //for(int i = 0; i < count; i++)
    //{
        //trees[i] = AVL2();
    //}
}

HashTable::~HashTable()
{

}

void HashTable::addWord(Word* w)
{
    string test = w->getWord();
    int key = hashKey(test.c_str()) % count;
    trees[key].insert(w);
}

AVLNODE* HashTable::getRoot(string temp)
{
    int key = hashKey(temp.c_str()) % count;
    return trees[key].getRoot();
}

unsigned HashTable::hashKey(const char* word)
{
        unsigned h = 1;
        while (*word)
            h = h * 101 + (unsigned) *word++;
        return h;
}

void HashTable::printTrees(ostream& out)
{
    for(int i = 0; i < count; i++)
    {
        trees[i].print(out);
    }
}

Word* HashTable::returnWord(string& test)
{
    int key = hashKey(test.c_str()) % count;
    return trees[key].returnWord(test);
}

Word* HashTable::searchTrees(string test)
{
    int key = hashKey(test.c_str()) % count;
    return trees[key].returnWord(test);
    //AVLNode* root = trees[key].getRoot();
    //string temp2 = trees[key].find(test);

}

bool HashTable::searchFor(string& x, AVLNODE* root) {
    int key = hashKey(x.c_str()) % count;
    return trees[key].searchFor(x, root);
}
