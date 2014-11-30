#include "userinterface.h"
UserInterface::UserInterface()
{

}

void UserInterface::startProgram()
{
    IndexHandler* h = new IndexHandler();
    cout << "Welcome to MustangWiki" << endl;
    cout << "What would you like to do?" << endl;
    cout << "Please press 'P' to parse the data," << endl;
    cout << "'Q' to start a query," << endl;
    cin >> input;

    if(input == "p" || input == "P")
    {
        //DocumentParser* dp = new DocumentParser();
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        //dp->getInput();
        h->print();
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        time_t end_time = chrono::system_clock::to_time_t(end);

        cout << "Finished computation at " << ctime(&end_time) << endl;
        cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }

    else if(input == "q" || input == "Q")
    {
        Query* q = new Query();
        q->startQuery();

    }
    else
    {
        cout << "Please choose a valid option" << endl;
        exit(1);
    }


}

UserInterface::~UserInterface()
{

}
















