#include "documentparser.h"

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
    StopWord* sw = new StopWord();

    /*if(sw->isStopWord(w->getWord()) == true)
    {
        //stemWord
        //add a parameter to this argument
        //w.addFrequency();
    }

    else
    {
        //stemWord
        //words.push_back(w);
    }*/
}

void DocumentParser::getInput() {
    //unordered hash map


    //might be faster

    /*    xml_document<> doc;
        xml_node<> * root_node;
        // Read the xml file into a vector
        ifstream theFile ("books.xml");
        vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
        buffer.push_back('\0');
        // Parse the buffer using the xml file parsing library into doc
        doc.parse<0>(&buffer[0]);*/
        // Find our root node
    xml_document<> doc;
    std::ifstream file("smallwiki.xml");
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
    vector<char*> texts(0); //probably need to dynamically allocate
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

    //for(int k = 0; k < page-1; k++)
    //{

        char* testBuffer = "This is a test string to see if I can split words";
        //int size = sizeof(buffer);
        char** singleWord;
        //for loop. Every time I replace with null terminal. Vector or char*
        //look at the lab2 for this
        singleWord = splitWords(testBuffer, 201);
        Word* w = new Word(singleWord, 1);
        cout << "CREATED NEW WORD" << endl;
        addWord(w);
    //}
    for(int i = 0; i < page-1; i++)
    {
        cout << "page " << i+1 << endl;
        cout << titles[i] << endl;
        cout << ids[i] << endl;
        cout << texts[i] << endl << endl;
    }

    for(int j = 0; j < page-1; j++)
    {
        Page* p = new Page(titles[j], ids[j], texts[j]);
        addPage(p);
    }

}

void DocumentParser::makeLowerCase(char *& word)
{
    tolower(word[0]);
}

char** DocumentParser::splitWords(char* buffer, int size)
{
    char** builder = new char*[size];
    char* bufferPtr = buffer;
    int index = 0;

    do
    {
       if(*buffer != '\0')
       {
           buffer++;
           bufferPtr = buffer;

           while(*buffer != ' ')
           {
               ++buffer;
           }

           //this next line causes it to stop
           *(buffer++) = '\0';
           builder[index] = new char[strlen(bufferPtr) + 1];
           strcpy(builder[index++], bufferPtr);

           buffer++; //ignores next space
           bufferPtr = buffer;
       }

       else if(*(buffer+1) == '\0')
       {
           ++buffer;

           builder[index] = new char[strlen(bufferPtr) + 1];
           strcpy(builder[index++], bufferPtr);

           bufferPtr = buffer;
       }

       else
           ++buffer;
    }while(*buffer != '\0');

    return builder;

}

DocumentParser::~DocumentParser()
{

}


