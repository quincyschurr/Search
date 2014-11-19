#include "documentparser.h"
using namespace std;
using namespace rapidxml;

DocumentParser::DocumentParser()
{
}

void DocumentParser::getInput() {
    /*char * text = "books.xml";
    ifstream fin(text);
    stringstream buffer;
    buffer << fin.rdbuf();
    fin.close();
    string content(buffer.str());
    cout << content << endl;


    //rapidxml::file<> xmlFile(text);
    rapidxml::xml_document<> doc;    // character type defaults to char
    doc.parse<0>(buffer.str().c_str());    // 0 means default parse flags

    cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    //cout << doc.last_node()->name() << endl;

    if(doc.first_node()->next_sibling() == 0) {
        cout << "0" << endl;
    }
    else
        cout << "true" << endl;

    rapidxml::xml_node<> *curNode = doc.first_node();


    //sourceforge.net/p/rapidxml/bugs/16
    //unordered hash map
    //cout << doc;*/

    /*cout << "Parsing my beer journal..." << endl;
        xml_document<> doc;
        xml_node<> * root_node;
        // Read the xml file into a vector
        ifstream theFile ("beerJournal.xml");
        vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
        buffer.push_back('\0');
        // Parse the buffer using the xml file parsing library into doc
        doc.parse<0>(&buffer[0]);*/
        // Find our root node
    xml_document<> doc;
    std::ifstream file("beerJournal.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    xml_node<> * root_node;
        root_node = doc.first_node("MyBeerJournal");
        // Iterate over the brewerys
        for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
        {
            printf("I have visited %s in %s. ",
                brewery_node->first_attribute("name")->value(),
                brewery_node->first_attribute("location")->value());
                // Interate over the beers
            for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
            {
                printf("On %s, I tried their %s which is a %s. ",
                    beer_node->first_attribute("dateSampled")->value(),
                    beer_node->first_attribute("name")->value(),
                    beer_node->first_attribute("description")->value());
                printf("I gave it the following review: %s", beer_node->value());
            }
            cout << endl;
        }

}

void DocumentParser::makeLowerCase(char *& word) {
    tolower(word[0]);
}


