#include "page.h"

Page::Page()
{
}

Page::Page(string title, int id)
{
    this->title = title;
    this->id = id;
}

int Page::getId()
{
    return id;
}

string Page::getTitle()
{
    return title;
}

Page::~Page()
{

}
