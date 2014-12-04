#ifndef PAGE_H
#define PAGE_H
#include <string>

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

    Page();
    Page(string title, int id, string text);
    ~Page();
};

#endif // PAGE_H
