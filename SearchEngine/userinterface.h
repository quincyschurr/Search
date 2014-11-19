#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "documentparser.h"

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
