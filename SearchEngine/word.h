#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>

using namespace std;

class Word
{
private:
    string word;
    int hashKey;
    vector <int> pageId;
    vector <int> frequency;

public:
    int getHashKey();
    string getWord();
    int getPageId();
    int getFrequency();
    void addFrequency();
    void addPageId(int pageId);
    void frequencyCount();
    Word();
    Word(string word, int hashKey, int pageId, int frequency);
    ~Word();
};

#endif // WORD_H
