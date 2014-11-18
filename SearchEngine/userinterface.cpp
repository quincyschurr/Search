#include "userinterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::getDocumentParser()
{
    DocumentParser* p = new DocumentParser;
}

void UserInterface::startProgram()
{
    cout << "Welcome to MustangWiki" << endl;
    cout << "What would you like to do?" << endl;
    cout << "Please press 'P' to parse the data," << endl;
    cin >> input;
}

UserInterface::~UserInterface()
{

}
