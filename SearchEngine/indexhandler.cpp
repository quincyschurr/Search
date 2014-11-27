#include "indexhandler.h"


IndexHandler::IndexHandler()
{

}

void IndexHandler::print()
{
    ofstream indexPrint("output2.txt");
    DocumentParser* d = new DocumentParser();
    d->getInput();
    d->wordAVL.print(indexPrint);
}

IndexHandler::~IndexHandler()
{

}
