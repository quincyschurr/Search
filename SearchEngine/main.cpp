#include <iostream>
#include <fstream>
#include "avltree.h"
//#include "english_stem.h"
#include "documentparser.h"

using namespace std;

int main(int argc, char *argv[])
{
    DocumentParser * d = new DocumentParser;
    d->getInput();

    /*ofstream fout(argv[2]);
    AVLTree<int> test;
    test.insert(5);
    test.insert(9);
    test.insert(3);
    test.insert(22);
    test.insert(70);
    test.insert(53);
    test.insert(8);
    test.insert(32);
    test.insert(1);
    test.insert(67);
    test.insert(65);
    test.insert(66);
    test.insert(82);
    test.insert(74);
    test.insert(100);
    test.insert(78);
    test.insert(93);
    test.insert(81);
    test.insert(77);
    test.insert(69);
    test.insert(79);
    test.print(fout);*/

    return 0;
}
