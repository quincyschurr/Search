#include "documentparser.h"
#include <sstream>
#include <./porterstem.h>

using namespace std;
using namespace rapidxml;

DocumentParser::DocumentParser()
{

}

bool DocumentParser::checkForWord(string& temp)
{
    AVLNODE* temp2 = wordAVL.getRoot();
    //AVLNODE* temp2 = table.getRoot(temp);
    if(wordAVL.searchFor(temp, temp2) == true)
    //if(table.searchFor(temp, temp2) == true)
        return true;
    else
        return false;
}

void DocumentParser::getInput()
{
    //unordered hash map


      /*xml_document<> doc;
        xml_node<> * root_node;
        // Read the xml file into a vector
        ifstream theFile ("enwikibooks-20141026-pages-meta-current.xml");
        vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
        buffer.push_back('\0');
        // Parse the buffer using the xml file parsing library into doc
        doc.parse<0>(&buffer[0]); */
        // Find our root node
    xml_document<> doc;

    std::ifstream file("smallwiki.xml");
    //std::ifstream file("enwikibooks-20141026-pages-meta-current.xml");

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    //cout << content << endl;
    doc.parse<0>(&content[0]); //parse_fastest */

    //rapidxml::file<> xmlFile("enwikibooks-20141026-pages-meta-current.xml"); //maybe faster
    //doc.parse<0>(xmlFile.data());

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
    //for(int i = 0; i < 80000; i++)
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
        page++;
    }

    vector<char*> test;
    test.push_back("this is running apples anot/her te?sting apples string with apples");
    test.push_back("why w\on't this apples. !functioning apples work?");
    test.push_back("between apples ab%l*e why becuase apples zero work?");
    test.push_back("apples are necessary for survival and work");

    StopWord* sw = new StopWord();
    sw->createArray();
    string testBuffer = "";
    string temp = "";
    int size = 0;
    for(int j = 0; j < test.size(); j++)
    {//start overall for
        temp = "";
        testBuffer = "";
        testBuffer = test[j];
        //testBuffer = texts[j];
        stringstream ss(testBuffer);
        while(ss >> temp)
        {
            //first step is to remove punctuation
            temp.erase(remove_if(temp.begin(), temp.end(), ::ispunct), temp.end());
            temp.erase(remove_if(temp.begin(), temp.end(), ::isdigit), temp.end());
            stripUnicode(temp);
            if(temp == "" || temp.length() == 1 || temp.length() > 50)
            {
                //do nothing
            }

            else
            {
                //makes everything lowercase
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                if(sw->isStopWord(temp) == true)
                {
                    //don't need to do anything
                }

                else
                {
                    char* arr = new char[temp.length() + 1];
                    strcpy(arr, temp.c_str());
                    int x = stem(arr, 0, strlen(arr)-1);
                    arr[x+1] = '\0';
                    temp = arr;

                    //check if word exists already
                    if(checkForWord(temp) == true)
                    {//if it exists

                        Word* x = wordAVL.returnWord(temp);
                        //Word* x = table.returnWord(temp);
                        if(x->lookForPage(ids[j]) == true)
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
                        wordAVL.insert(w);
                        //table.addWord(w);
                    }
                }
            }
         }//overall while

        //Page* p = new Page(titles[j], ids[j]);
        //pages.push_back(p);

     }//overall for

    wordAVL.print(cout);
    //table.printTrees();

}//end getInput

AVL2 DocumentParser::getwordAVL()
{
    return wordAVL;
}


void DocumentParser::stripUnicode(string& temp)
{
    temp.erase(remove_if(temp.begin(), temp.end(), InvalidChar()), temp.end());
}

DocumentParser::~DocumentParser()
{

}


