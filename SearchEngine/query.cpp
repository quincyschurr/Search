#include "query.h"

Query::Query()
{

}

void Query::startQuery()
{
    string input;
    string temp = "";
    string testBuffer = "";
    stringstream ss(testBuffer);
//http://www.codecogs.com/library/computing/stl/algorithms/set/set_union.php
    //good for parameters for a set
    cout << "To start a query please enter the words you would like to search for: " << endl;
    cin >> input;

    while(ss >> temp);
    {
        searchWords.push_back(temp);
        //try to separate the string into vector or array

    }


}

Query::~Query()
{

}
