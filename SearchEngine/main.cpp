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

    //to test if the stopWords are added to a file
    //ifstream fin(argv[2]);
    UserInterface* n = new UserInterface(); //START
    n->startProgram();//maybe need to add an ifstream to this
    //StopWord* y = new StopWord(fin);
    //y->createArray(fin);
    //ifstream fin(argv[2]);
    //StopWord* y = new StopWord();
    //y->createArray(fin);


    //to test the Word class
    //Word* tester = new Word("something", 3456);
    //tester->insertToMap(3456);
    //tester->insertToMap(3456);

    //use prime number as table size for hash table

    /*ofstream fout(argv[1]);
    AVLTree<string> test;
    test.insert("ckels");
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
    test.insert("sdfeeih");
    test.insert("unsdd");
    test.insert("umbrella");

    test.print(fout);*/

    return 0;
}
