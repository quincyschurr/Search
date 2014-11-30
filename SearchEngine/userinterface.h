#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "documentparser.h"
#include "indexhandler.h"
#include "query.h"
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;
class UserInterface
{
private:
    string input;
public:
    void startProgram();

    UserInterface();
    ~UserInterface();
};

#endif // USERINTERFACE_H
