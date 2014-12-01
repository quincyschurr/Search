#include "query.h"

Query::Query()
{

}


void Query::startQuery()
{
    string input;
    string temp = "";
//http://www.codecogs.com/library/computing/stl/algorithms/set/set_union.php
    //good for parameters for a set
    cout << "To start a query please enter the words you would like to search for: " << endl;
    getline(cin, input);
    stringstream ss(input);

    while(ss >> temp)
    {
        searchWords.push_back(temp);
        //try to separate the string into vector or array

    }



    //the stl has container classes. Iterators allow algoritms to operate on containers
    //there is a class set, Put the pages in separate set objects, could be vectors of Pages
}

Query::~Query()
{

}
