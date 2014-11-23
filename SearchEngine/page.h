#ifndef PAGE_H
#define PAGE_H
#include <string>

using namespace std;

class Page
{
private:
    int id;
    string title;
public:
    int getId();
    string getTitle();

    Page();
    Page(string title, int id);
    ~Page();
};

#endif // PAGE_H
