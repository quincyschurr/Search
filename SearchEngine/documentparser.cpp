#include "documentparser.h"

DocumentParser::DocumentParser()
{
}

void DocumentParser::getInput() {
    char * text = "books.xml";
    rapidxml::file<> xmlFile(text);
    rapidxml::xml_document<> doc;    // character type defaults to char
    doc.parse<0>(xmlFile.data());    // 0 means default parse flags

    cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

    rapidxml::xml_node<> *node = doc.first_node("foobar");
    cout << "Node foobar has value " << node->value() << "\n";
    for (rapidxml::xml_attribute<> *attr = node->first_attribute();
         attr; attr = attr->next_attribute())
    {
        cout << "Node foobar has attribute " << attr->name() << " ";
        cout << "with value " << attr->value() << "\n";
    }
    //sourceforge.net/p/rapidxml/bugs/16

    std::cout << doc;
}
