#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
#include <map>

using namespace std;

class Word
{
private:
    string word;
    int hashKey;
    int pageId;
    int frequency;
    map <int, int> info;

public:
    void addFrequency(int pageId);
    int getHashKey();
    string getWord();
    void insertToMap(int pageId);

    friend bool operator>(const Word& lhs, const Word& rhs);
    friend bool operator<(const Word& lhs, const Word& rhs);

    Word();
    Word(string word, int hashKey, int pageId);
    ~Word();
};

#endif // WORD_H
