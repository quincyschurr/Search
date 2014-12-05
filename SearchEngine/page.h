#ifndef PAGE_H
#define PAGE_H
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

class Page
{
private:
    int id;
    string title;
    string text;
public:
    int getId();
    string getTitle();
    string getText();
    void print(ostream&);

    Page();
    Page(string title, int id);
    Page(string title, int id, string text);
    ~Page();
};

#endif // PAGE_H
