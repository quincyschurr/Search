#include "page.h"

Page::Page()
{
}

Page::Page(string& title, int& id)
{
    this->title = title;
    this->id = id;
}

Page::Page(string& title, int& id, string& text)
{
    this->title = title;
    this->id = id;
    this->text = text;
}

int Page::getId()
{
    return id;
}

string Page::getTitle()
{
    return title;
}

string Page::getText()
{
    return text;
}

void Page::print(ostream& fout)
{
    fout << title << " : " << id << " " << text << endl << "$#**%" << endl;
}

Page::~Page()
{

}
