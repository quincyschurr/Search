/*
 * Jake Osselaer
 * &
 * Quincy Schurr
 *
*/

#include <iostream>
#include <fstream>
#include "avltree.h"
#include "word.h"
#include "stopword.h"
#include "userinterface.h"
//user interface is the only .h we will need.
#include "documentparser.h"

using namespace std;

int main(int argc, char *argv[])
{
    UserInterface* n = new UserInterface(); //START
    n->startProgram();//maybe need to add an ifstream to this

    //use prime number as table size for hash table

    /*ofstream fout(argv[1]);
    AVLTree<int> test;
    test.insert(6);
    test.insert(34);
    test.insert(29);
    test.insert(52);
    test.insert(79);
    test.insert(12);
    test.insert(7);
    test.insert(45);
    test.insert(67);
    test.insert(100);
    test.insert(6);
    test.insert(99);
    test.insert(80);
    test.insert(78);
    test.insert(82);
    test.insert(83);
    test.insert(41);
    test.insert(94);

    int searchString = 53;
    if(test.search(searchString, test.getRoot()) == true)
    {
        cout << "The item was found" << endl;
    }

    else
        cout << "The item was not found" << endl;


    test.print(fout);*/

    return 0;
}
