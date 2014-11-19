#include "documentparser.h"
using namespace std;
using namespace rapidxml;

DocumentParser::DocumentParser()
{
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
    int page = 1;
    while(curPage != 0) {
        cout << "page " << page++ << endl;
        curTitle = curPage->first_node("title");
        cout << "title " << curTitle->value() << endl;
        curID = curTitle->next_sibling("id");
        cout << "id " << curID->value() << endl;
        curText = curID->next_sibling("revision");
        curText = curText->first_node("text");
        cout << curText->value() << endl << endl;
        curPage = curPage->next_sibling();
    }


}

void DocumentParser::makeLowerCase(char *& word) {
    tolower(word[0]);
}


