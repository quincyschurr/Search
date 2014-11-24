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
    AVLTree<string> test;
    test.insert("hello");
    test.insert("world");
    test.insert("data");
    test.insert("structures");
    test.insert("zoo");
    test.insert("apples");
    test.insert("oranges");
    test.insert("pineapples");
    test.insert("later");
    test.insert("work");
    test.insert("sum");
    test.insert("break");
    test.insert("weekend");
    test.insert("search");
    test.insert("find");
    test.insert("get");
    test.insert("zero");
    test.insert("look");

    int searchString = 53;
    /*if(test.search(searchString, test.getRoot()) == true)
    {
        cout << "The item was found" << endl;
    }

    else
        cout << "The item was not found" << endl;


    test.print(fout);*/

    return 0;
}
