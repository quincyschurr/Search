#include "documentparser.h"
#include <sstream>

using namespace std;
using namespace rapidxml;

DocumentParser::DocumentParser()
{

}

void DocumentParser::addPage(Page*& p)
{
       //causes error
     //pages.push_back(p);
}

void DocumentParser::addWord(Word*& w)
{

}

void DocumentParser::getInput() {
    //unordered hash map


    //might be faster

    /*    xml_document<> doc;
        xml_node<> * root_node;
        // Read the xml file into a vector
        ifstream theFile ("enwikibooks-20141026-pages-meta-current.xml.xml");
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
        curPage = curPage->next_sibling();
        page++;
    }


    vector<char*> test;
    test.push_back("this is another test string with char* references.");
    test.push_back("why won't this function work?");
    test.push_back("adkfjaljf diijjgs   adjfoajokj  asdfjk;o kdiil josd");
    //char* testBuffer = new char [101];

    /*string temp = "";

    for(int k = 0; k < test.size(); k++)
    {
        char* testBuffer = new char[51];
        strcpy(testBuffer, test[k]);
        stringstream ss(testBuffer);
        while (ss >> temp)
        {
            cout << "word = " << temp << endl;
        }


        //add makelowerCaser, stop word, then stemmer, then add to word

        //end loop with
        //temp = "";
    }*/

    StopWord* sw = new StopWord();
    string testBuffer = "";



    for(int j = 0; j < texts.size(); j++)
    {
        //cout << "THIS IS PAGE " << j+1 << endl;
        string temp = "";
        testBuffer = "";
        testBuffer = texts[j];
        stringstream ss(testBuffer);
        while(ss >> temp)
        {
            //cout << "word = " << temp << endl;
            /*if(sw->isStopWord(temp) == true)
            {

            }
            else
            {

            }*/
        }



    }


    /*for(int i = 0; i < titles.size(); i++)
    {
        cout << "page " << i+1 << endl;
        cout << titles[i] << endl;
        cout << ids[i] << endl;
        cout << texts[i] << endl << endl;
    }*/

    /*for(int j = 0; j < page-1; j++)
    {
        Page* p = new Page(titles[j], ids[j], texts[j]);
        addPage(p);
    }*/

}

void DocumentParser::makeLowerCase(char *& word)
{
    tolower(word[0]);
}

DocumentParser::~DocumentParser()
{

}


