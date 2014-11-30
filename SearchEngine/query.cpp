#include "query.h"

Query::Query()
{

}

void Query::startQuery()
{
    int input = 0;
//http://www.codecogs.com/library/computing/stl/algorithms/set/set_union.php
    //good for parameters for a set
    cout << "To start a query please choose how you would like to proceed:" << endl;
    cout << "To search for books containing any words in your search press 1," << endl;
    cout << "to search for books containing all of the words in your search press 2," << endl;
    cout << "if you would like to just search for one word press 3." << endl;
    cin >> input;

    if(input == 1)
    {
        cout << "Please enter the words you want to search for, separated by a space: " << endl;
    }

    else if(input == 2)
    {

    }

    else if(input == 3)
    {

    }

    else
    {

    }
}

Query::~Query()
{

}
