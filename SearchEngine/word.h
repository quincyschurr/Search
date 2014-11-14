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
    int pageId;
    vector <int> pageIds;
    vector <int> frequency;

public:
    int getHashKey();
    string getWord();
    void addFrequency();
    void addPageId(int pageId);
    void increaseFrequency();
    Word();
    Word(string word, int hashKey, int pageId, int frequency);
    ~Word();
};

#endif // WORD_H
