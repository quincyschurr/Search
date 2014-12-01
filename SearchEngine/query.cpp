#include "query.h"

Query::Query()
{

}

void Query::buildIndex()
{
    ifstream fin("output2.txt");
    string word = "";
    int pageNum = 0;
    int frequency = 0;

        fin >> word;
        fin.ignore(2);
        fin >> pageNum;
        fin.ignore();
        fin >> frequency;
        fin.ignore(3);
        cout << word << ": " << pageNum << "(" << frequency << ")" << endl;
        //how to loop through getting word and frequency for each word?
        //and how to loop through entire index..eof

}

void Query::startQuery()
{

    //before starting query we have to get the index
    buildIndex();
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
