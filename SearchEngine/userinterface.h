#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "documentparser.h"
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;
class UserInterface
{
private:
    string input;
public:
    void startProgram();
    void getDocumentParser();

    UserInterface();
    ~UserInterface();
};

#endif // USERINTERFACE_H
