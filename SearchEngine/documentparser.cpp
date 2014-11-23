#include "documentparser.h"
#include <sstream>

using namespace std;
using namespace rapidxml;

DocumentParser::DocumentParser()
{

}

bool DocumentParser::checkForPage(int page, Word*& x)
{
    if(x->lookForPage(page) == true)
        return true;
    else
        return false;

}

bool DocumentParser::checkForWord(string& temp)
{
   //string compString = find(words.begin().getWord(), words.end().getWord(), temp);
    for(int b = 0; b < words.size(); b++)
    {
        if(words[b]->getWord() == temp)
            return true;
    }

    return false;
}

void DocumentParser::getInput() {
    //unordered hash map


    //might be faster

    /*  xml_document<> doc;
        xml_node<> * root_node;
        // Read the xml file into a vector
        ifstream theFile ("enwikibooks-20141026-pages-meta-current.xml");
        vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
        buffer.push_back('\0');
        // Parse the buffer using the xml file parsing library into doc
        doc.parse<0>(&buffer[0]);*/
        // Find our root node
    xml_document<> doc;

    //std::ifstream file("smallwiki.xml");
    std::ifstream file("enwikibooks-20141026-pages-meta-current.xml");

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    //cout << content << endl;
    doc.parse<0>(&content[0]);

    /*ifstream theFile ("enwikibooks-20141026-pages-meta-current.xml");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);*/

    xml_node<> * root_node;
    root_node = doc.first_node("mediawiki");
    xml_node<> * page_node;
    page_node = root_node->first_node("page");

    xml_node<> * curPage;
    curPage = page_node;
    xml_node<> * curTitle;
    xml_node<> * curText;
    xml_node<> * curID;
    vector<string> titles(0); //probably need to dynamically allocate
    vector<int> ids(0); //probably need to dynamically allocate
    vector<string> texts(0); //probably need to dynamically allocate
    int page = 1;
    string sTemp;
    int iTemp;
    while(curPage != 0)
    {
        //cout << "page " << page++ << endl;
        curTitle = curPage->first_node("title");
        sTemp = curTitle->value();
        titles.push_back(sTemp);
        //cout << "title " << curTitle->value() << endl;
        curID = curTitle->next_sibling("id");
        iTemp = atoi(curID->value());
        ids.push_back(iTemp);
        //cout << "id " << curID->value() << endl;
        curText = curID->next_sibling("revision");
        curText = curText->first_node("text");
        //sTemp = curText->value();
        texts.push_back(curText->value());
        //cout << curText->value() << endl << endl;
        curPage = curPage->next_sibling(); //maybe faster
        makeLowerCase(texts[page-1]);
        page++;
    }


    //vector<char*> test;
    //test.push_back("this is apples another test apples string with apples");
    //test.push_back("why won't this apples function apples work?");
    //test.push_back("between apples able why becuase apples zero work?");

    StopWord* sw = new StopWord();
    //add hashTable

    sw->createArray();
    string testBuffer = "";
    string temp = "";
    int size = 0;
    for(int j = 0; j < texts.size(); j++)
    {
        //need to make sure that it just doesn't add frequency to one page
        //but checks for words all over pages
        //cout << "THIS IS PAGE " << j+1 << endl;
        temp = "";
        testBuffer = "";
        //testBuffer = test[j];
        testBuffer = texts[j];
        stringstream ss(testBuffer);
        while(ss >> temp)
        {

            //cout << "word = " << temp << endl;

            //makeLowerCase(temp); //dont use faster lowercase above
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if(sw->isStopWord(temp) == true)
            {
                //don't need to do anything
            }
            else
            {

                //to test the stemming
                //size = temp.size();
                //char* arr = new char[size];
                //strcpy(arr, temp.c_str());
                //arr[stem(arr, 0, strlen(arr) - 1)] = '\0';
                //delete [] arr;
                //cout << "Now the word is " << temp << endl;*/


                if(checkForWord(temp) == true)
                {
                    //cout << "WORD ALREADY EXISTS" << endl;
                    Word* x = returnWordObject(temp);//This returns the correct Word object
                    if(checkForPage(ids[j], x) == true)
                    {
                        x->increaseFrequency(ids[j]);
                    }
                    else
                    {
                        x->addPages(ids[j]);
                        x->addToMap(ids[j]);
                    }

                }
                else
                {
                    Word* w = new Word(temp, ids[j]);
                    w->addPages(ids[j]);
                    w->addToMap(ids[j]);
                    words.push_back(w);
                }

            }
        }

        Page* p = new Page(titles[j], ids[j], texts[j]);
        pages.push_back(p);
    }

}

void DocumentParser::makeLowerCase(string& word)
{//maybe also use islower to save time
    //tolower(word[0]);
    //transform(word.begin(), word.end(), word.begin(), ::tolower);
}

Word* DocumentParser::returnWordObject(string& temp)
{
    for(int m = 0; m < words.size(); m++)
    {
        if(words[m]->getWord() == temp)
            return words[m];
    }
    //return NULl;

}

DocumentParser::~DocumentParser()
{

}


