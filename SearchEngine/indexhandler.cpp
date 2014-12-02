#include "indexhandler.h"


IndexHandler::IndexHandler()
{

}

void IndexHandler::print()
{
    string parseType = "";
    ofstream indexPrint("output2.txt");
    DocumentParser* d = new DocumentParser();
    cout << "Would you like to parse the data using an AVL Tree ('A') or a Hash Table ('H')?" << endl;
    cin >> parseType;
    if(parseType == "A" || parseType == "a")
    {
        d->getInputAVL();
        d->wordAVL.print(indexPrint);
    }
    else if(parseType == "H" || parseType == "h")
    {
        d->getInputHash();
    }

}

IndexHandler::~IndexHandler()
{

}
