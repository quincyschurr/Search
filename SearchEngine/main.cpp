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

    //to test the UserInterface
    //UserInterface* n = new UserInterface;
    //n->startProgram();//maybe need to add an ifstream to this
    //also need to pass the stopWords arguments


    //to test if the stopWords are added to a file
    ifstream fin(argv[2]);
    //StopWord* y = new StopWord(fin);
    //y->createArray(fin);


    //to test the Word class
    Word* tester = new Word("something", 22, 3456);
    //tester->insertToMap(3456);
    //tester->insertToMap(3456);


    //DocumentParser * d = new DocumentParser;
    //d->getInput();

    //use prime number as table size for hash table

    //ofstream fout(argv[1]);
    //AVLTree<string> test;
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
    //test.print(fout);

    return 0;
}
