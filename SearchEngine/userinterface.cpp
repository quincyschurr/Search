#include "userinterface.h"
UserInterface::UserInterface()
{

}


void UserInterface::getDocumentParser()
{
    //DocumentParser* p = new DocumentParser;
}

void UserInterface::startProgram()
{
    cout << "Welcome to MustangWiki" << endl;
    cout << "What would you like to do?" << endl;
    cout << "Please press 'P' to parse the data," << endl;
    cin >> input;

    //DocumentParser* dp = new DocumentParser();
    IndexHandler* h = new IndexHandler();
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    //dp->getInput();
    h->print();
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "Finished computation at " << ctime(&end_time) << endl;
    cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

    /*if(input = 'p' || input = 'P')
    {
        DocumentParser* b = new DocumentParser();
    }*/

}

UserInterface::~UserInterface()
{

}
















