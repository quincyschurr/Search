#include "documentparser.h"

DocumentParser::DocumentParser()
{
}

bool DocumentParser::checkForWordAVL(string& temp)
{
    AVLNODE* temp2 = wordAVL.getRoot();
    if(wordAVL.searchFor(temp, temp2) == true)
        return true;
    else
        return false;
}

bool DocumentParser::checkForWordHash(string& temp)
{
    AVLNODE* temp2 = table.getRoot(temp);
    if(table.searchFor(temp, temp2) == true)
        return true;
    else
        return false;
}

void DocumentParser::getInputAVL()
{
    xml_document<> doc;

    //std::ifstream file("smallwiki.xml");
    std::ifstream file("enwikibooks-20141026-pages-meta-current.xml");

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]); //parse_fastest

    xml_node<> * root_node;
    root_node = doc.first_node("mediawiki");
    xml_node<> * page_node;
    page_node = root_node->first_node("page");

    xml_node<> * curPage;
    curPage = page_node;
    xml_node<> * curTitle;
    xml_node<> * curText;
    xml_node<> * curID;
    vector<string> titles;
    vector<int> ids;
    vector<string> texts;
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

    StopWord* sw = new StopWord();
    sw->createArray();
    string testBuffer = "";
    string temp = "";
    for(int j = 0; j < texts.size(); j++)
    {//start overall for
        temp = "";
        testBuffer = "";
        testBuffer = texts[j];
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
                    if(checkForWordAVL(temp) == true)
                    {//if it exists

                        Word* x = wordAVL.returnWord(temp);
                        if(x->lookForPage(ids[j]) == true)
                        {
                            x->increaseFrequency(ids[j]);
                        }
                        else
                        {
                            x->addPages(ids[j]);
                            x->addToMap(ids[j], 1);
                        }

                    }

                    else
                    {
                        Word* w = new Word(temp);
                        w->addPages(ids[j]);
                        w->addToMap(ids[j], 1);
                        wordAVL.insert(w);
                    }
                }
            }
         }//overall while

        string pageTitle = titles[j];
        pageTitle.erase(remove_if(pageTitle.begin(), pageTitle.end(), ::isspace), pageTitle.end());
        Page* p = new Page(pageTitle, ids[j], texts[j]);
        pages.insert(p);
        string name;
        stringstream s2;
        int fileNum = page % 100;
        s2 << fileNum;
        s2 << ".txt";
        s2 >> name;
        ofstream fout(name, ios::app);
        p->print(fout);

     }//overall for

    //pages.print3(cout);


}//end getInput

void DocumentParser::getInputHash()
{
    xml_document<> doc;

    //std::ifstream file("smallwiki.xml");
    std::ifstream file("enwikibooks-20141026-pages-meta-current.xml");

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
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
    vector<string> titles;
    vector<int> ids;
    vector<string> texts;
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

    //use these for outputting to different txt files

    StopWord* sw = new StopWord();
    sw->createArray();
    string testBuffer = "";
    string temp = "";
    for(int j = 0; j < texts.size(); j++)
    {//start overall for
        temp = "";
        testBuffer = "";
        testBuffer = texts[j];
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
                    if(checkForWordHash(temp) == true)
                    {//if it exists

                        Word* x = table.returnWord(temp);
                        if(x->lookForPage(ids[j]) == true)
                        {
                            x->increaseFrequency(ids[j]);
                        }
                        else
                        {
                            x->addPages(ids[j]);
                            x->addToMap(ids[j], 1);
                        }

                    }

                    else
                    {
                        Word* w = new Word(temp);
                        w->addPages(ids[j]);
                        w->addToMap(ids[j], 1);
                        table.addWord(w);
                    }
                }
            }
         }//overall while

        string pageTitle = titles[j];
        int page = ids[j];
        pageTitle.erase(remove_if(pageTitle.begin(), pageTitle.end(), ::isspace), pageTitle.end());
        Page* p = new Page(pageTitle, ids[j], texts[j]);
        pages.insert(p);
        string name;
        stringstream s2;
        int fileNum = page % 100;
        s2 << fileNum;
        s2 << ".txt";
        s2 >> name;
        ofstream fout(name, ios::app);
        p->print(fout);

     }//overall for

    //pages.print3(cout);
}

AVLTree <Page*> DocumentParser::getPageAVL()
{
    return pages;
}

HashTable DocumentParser::getTable()
{
    return table;
}

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


