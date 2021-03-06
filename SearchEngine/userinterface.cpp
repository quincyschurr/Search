#include "userinterface.h"
UserInterface::UserInterface()
{

}

void UserInterface::clearIndex()
{
    ofstream("output2.txt", ios::out);
    ofstream("output3.txt", ios::out);
    stringstream ss;
    string oFile;
    for(int i = 0; i < 100; i++)
    {
        ss << i;
        ss << ".txt";
        ss >> oFile;
        ofstream(oFile, ios::out);
        ss.clear();
    }
}

void UserInterface::startProgram()
{
    IndexHandler* h = new IndexHandler();
    cout << "Welcome to MustangWiki" << endl;
    while(true) {

    cout << "What would you like to do?" << endl;
    cout << "Please press 'P' to parse the data," << endl;
    cout << "'Q' to start a query," << endl;
    cout << "'C' to clear the index" << endl;
    cout << "'E' to exit" << endl;
    cin >> input;

    if(input == "p" || input == "P")
    {
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
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
    else if(input == "C" || input == "c") {
        clearIndex();
        cout << "index is now clear" << endl;
    }
    else if(input == "E" || input == "e") {
        cout << "Exiting" << endl;
        break;
    }
    else
    {
        cout << "Please choose a valid option" << endl;
        exit(1);
    }

    }//end main while
}

UserInterface::~UserInterface()
{

}
