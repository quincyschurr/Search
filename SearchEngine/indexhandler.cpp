#include "indexhandler.h"


IndexHandler::IndexHandler()
{

}

void IndexHandler::print()
{
    ofstream indexPrint("output2.txt");
    DocumentParser* d = new DocumentParser();
    d->getInput();
    AVL2 printAVL = d->getwordAVL();
    printAVL.print(indexPrint);
}

IndexHandler::~IndexHandler()
{

}
