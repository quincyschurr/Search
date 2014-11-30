#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Query
{
private:
    vector <string> searchWords;
public:
    void startQuery();
    Query();
    ~Query();
};

#endif // QUERY_H
