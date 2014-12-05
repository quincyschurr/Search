/*
 * Jake Osselaer
 * &
 * Quincy Schurr
 *
*/

#include <iostream>
#include <fstream>
#include "userinterface.h"


using namespace std;

int main()
{
    UserInterface* n = new UserInterface(); //START
    n->startProgram();
    cout << "END" << endl;
    return 0;
}
