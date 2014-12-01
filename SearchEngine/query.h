#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class Query
{
private:
    vector <string> searchWords;
public:
    //pass avl and hash table by reference to query
    void buildIndex();
    void startQuery();
    Query();
    ~Query();
    vector<int> qAND(vector<int>, vector<int>);
    vector<int> qOR(vector<int>, vector<int>);
    vector<int> qNOT(vector<int>, vector<int>);
};

#endif // QUERY_H
