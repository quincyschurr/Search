#include "documentparser.h"

DocumentParser::DocumentParser()
{
}

void DocumentParser::getInput() {
    /*char * text = "books.xml";
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
    //unordered hash map

    cout << doc;*/

    std::ifstream fin("books.xml");
    std::stringstream ss;
    ss << fin.rdbuf();
    std::string xml = ss.str();

    // string to dynamic cstring
    std::vector<char> stringCopy(xml.length(), '\0');
    std::copy(xml.begin(), xml.end(), stringCopy.begin());
    char *cstr = &stringCopy[0];

    // create xml document object and parse cstring
    // character type defaults to char
    rapidxml::xml_document<> parsedFromFile;
    // 0 means default parse flags
    try
    {
        parsedFromFile.parse<0>(cstr);

        rapidxml::xml_node<> *addressNode = parsedFromFile.first_node("Address");
        //outputAddress(*addressNode);

        // Print to stream using operator <<
        std::cout << parsedFromFile;

        // Print to stream using print function, specifying printing flags
        // 0 means default printing flags
        rapidxml::print(std::cout, parsedFromFile, 0);
    }
    catch(const rapidxml::parse_error &e)
    {
        std::cout << "Parse error due to " << e.what() << std::endl;
    }

    // ---- create from scratch ----
    rapidxml::xml_document<> fromScratch;
    rapidxml::xml_node<> *addressNode = fromScratch.allocate_node(rapidxml::node_element, "Address");
    rapidxml::xml_node<> *recipientNode =
        fromScratch.allocate_node(rapidxml::node_element, "Recipient", "Mr Malcolm Reynolds");
    rapidxml::xml_node<> *houseNode =
        fromScratch.allocate_node(rapidxml::node_element, "House", "3");
    rapidxml::xml_node<> *streetNode =
        fromScratch.allocate_node(rapidxml::node_element, "Street", "Serenity");
    rapidxml::xml_node<> *townNode =
        fromScratch.allocate_node(rapidxml::node_element, "Town", "Space");
    rapidxml::xml_node<> *postCodeNode =
        fromScratch.allocate_node(rapidxml::node_element, "PostCode", "DE18 5HI");
    //rapidxml::xml_document<> fromScratch;

    addressNode->append_node(recipientNode);
    addressNode->append_node(houseNode);
    addressNode->append_node(streetNode);
    addressNode->append_node(townNode);
    addressNode->append_node(postCodeNode);

    fromScratch.append_node(addressNode);

    //outputAddress(*addressNode);

    // ---- output to file ----

    //std::ofstream fout("test.xml");
    cout << fromScratch;
}

void DocumentParser::makeLowerCase(char *& word) {
    tolower(word[0]);
}


