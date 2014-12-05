#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>
#include <iostream>
#include <array>
#include <fstream>
#include <cstring>

using namespace std;

class StopWord
{
private:
    vector<string> stWordArray;
public:
    void createArray();
    bool isStopWord(const string& testWord);
    StopWord();
    ~StopWord();
};

#endif // STOPWORD_H
