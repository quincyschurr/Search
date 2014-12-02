#include "query.h"

Query::Query()
{

}

void Query::buildIndex()
{
    //we don't need these
    //table = dp.getTable();
    //tree = dp.getwordAVL();
    string indexType = "";
    cout << "How would you like to build the index? Using an AVL Tree ('A') or a Hash Table('H')?";
    cin >> indexType;

    if(indexType == "A" || indexType == "a")
    {
        ifstream fin("output2.txt");
        string word = "";
        int numOfPages = 0;
        int pageNum = 0;
        int frequency = 0;

        while(!fin.eof())
        {
            fin >> word;
            fin.ignore(4);
            fin >> numOfPages;
            fin.ignore(2);
            Word* w = new Word(word);
            cout << word << ": " << "[" << numOfPages << "] ";
            for(int b = 0; b < numOfPages; b++)
            {
                fin >> pageNum;
                fin.ignore();
                fin >> frequency;
                fin.ignore(3);
                w->addPages(pageNum);
                w->addToMap(pageNum, frequency);
                tree.insert(w);
                cout << pageNum << "(" << frequency << "), ";
            }
            cout << endl;

        }
    }
    else if(indexType == "H" || indexType == "h")
    {
        ifstream fin("output2.txt");
        string word = "";
        int numOfPages = 0;
        int pageNum = 0;
        int frequency = 0;

        while(!fin.eof())
        {
            fin >> word;
            fin.ignore(4);
            fin >> numOfPages;
            fin.ignore(2);
            Word* w = new Word(word);
            cout << word << ": " << "[" << numOfPages << "] ";
            for(int b = 0; b < numOfPages; b++)
            {
                fin >> pageNum;
                fin.ignore();
                fin >> frequency;
                fin.ignore(3);
                w->addPages(pageNum);
                w->addToMap(pageNum, frequency);
                table.addWord(w);
                cout << pageNum << "(" << frequency << "), ";
            }
            cout << endl;
    }

        //how to loop through getting word and frequency for each word?
        //and how to loop through entire index..eof

    }
}

void Query::startQuery()
{
    int count = 0;

    //before starting query we have to get the index
    buildIndex();

    string input;
    string temp = "";
//http://www.codecogs.com/library/computing/stl/algorithms/set/set_union.php
    //good for parameters for a set
    cout << "To start a query please enter the words you would like to search for: " << endl;
    getline(cin, input);
    stringstream ss(input);

    while(ss >> temp)
    {
        searchWords.push_back(temp);
        //try to separate the string into vector or array
        count++;
    }
    Word * word1;
    Word * word2;
    Word * word3;
    vector<int> word1Pages;
    vector<int> pageResults;
    if(count  == 1) {
        word1 = table.returnWord(searchWords[0]);
        pageResults = word1->getPages();
    }
    else if(searchWords[0] == "AND") {
        word1 = table.returnWord(searchWords[1]);
        word2 = table.returnWord(searchWords[2]);
        word1Pages = word1->getPages();
        vector<int> word2Pages = word2->getPages();
        pageResults = qAND(word1Pages, word2Pages);
        if(count == 5) {
            word3 = table.returnWord(searchWords[4]);
            vector<int> word3Pages = word3->getPages();
            pageResults = qNOT(pageResults, word3Pages);
        }
    }
    else if(searchWords[0] == "OR") {
        word1 = table.returnWord(searchWords[1]);
        word2 = table.returnWord(searchWords[2]);
        word1Pages = word1->getPages();
        vector<int> word2Pages = word2->getPages();
        pageResults = qOR(word1Pages, word2Pages);
        if(count == 5) {
            word3 = table.returnWord(searchWords[4]);
            vector<int> word3Pages = word3->getPages();
            pageResults = qNOT(pageResults, word3Pages);
        }
    }
    else {
        word1 = table.returnWord(searchWords[0]);
        word2 = table.returnWord(searchWords[2]);
        //pageResults =  qNOT(word1, word2);
    }



    //the stl has container classes. Iterators allow algoritms to operate on containers
    //there is a class set, Put the pages in separate set objects, could be vectors of Pages
}

vector<int> Query::qAND(vector<int> a, vector<int> b) {
    vector<int> uni;
    set_union(a.begin(), a.end(), b.begin(), b.end(), uni.begin());
    return uni;
}

vector<int> Query::qOR(vector<int> a, vector<int> b) {
    vector<int> inter;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inter.begin());
    return inter;
}

vector<int> Query::qNOT(vector<int> a, vector<int> b) {
    vector<int> diff;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), diff.begin());
    return diff;
}

Query::~Query()
{

}
