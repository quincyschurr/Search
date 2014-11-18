#include <iostream>
#include <fstream>
#include "avltree.h"
#include "stopword.h"
//#include "english_stem.h"
#include "documentparser.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin(argv[2]);
    StopWord* y = new StopWord();
    y->createArray(fin);
    //DocumentParser * d = new DocumentParser;
    //d->getInput();

    //use prime number as table size for hash table

    ofstream fout(argv[1]);
    AVLTree<string> test;
    /*test.insert("ckels");
    test.insert("abels");
    test.insert("zeleb");
    test.insert("dekls");
    test.insert("lenent");
    test.insert("apple");
    test.insert("bannana");
    test.insert("pineapple");
    test.insert("watermelon");
    test.insert("orange");
    test.insert("zebra");
    test.insert("giraffe");
    test.insert("wembly");
    test.insert("lelsne");
    test.insert("poeple");
    */
    test.print(fout);

    return 0;
}
