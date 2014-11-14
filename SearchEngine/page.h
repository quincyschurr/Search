#ifndef PAGE_H
#define PAGE_H
#include <string>

using namespace std;

class Page
{
private:
    string text;
    int id;
    string title;
public:
    int getId();
    string getTitle();
    string getText();

    Page();
    Page(string title, int id, string text);
    ~Page();
};

#endif // PAGE_H
