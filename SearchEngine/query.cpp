#include "query.h"

Query::Query()
{

}

void Query::buildIndex()
{
    string indexType = "";
    //cout << "How would you like to build the index? Using an AVL Tree ('A') or a Hash Table('H')?";
    //cin >> indexType;

    /*if(indexType == "A" || indexType == "a")
    {
        ifstream fin("output2.txt");
        ifstream fin2("output3.txt");
        string word = "";
        string text = "";
        string text1 = "";
        string text2 = "";
        string text3 = "";
        string text4 = "";
        string pageTitle = "";
        int pageId = 0;
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
            //cout << word << ": " << "[" << numOfPages << "] ";
            for(int b = 0; b < numOfPages; b++)
            {
                fin >> pageNum;
                fin.ignore();
                fin >> frequency;
                fin.ignore(3);
                w->addPages(pageNum);
                w->addToMap(pageNum, frequency);
                tree.insert(w);
                //cout << pageNum << "(" << frequency << "), ";
            }
            //cout << endl;

        }

        while(!fin2.eof())
        {
            fin2 >> pageTitle;
            fin2.ignore(3);
            fin2 >> pageId;
            /*getline(fin2, text, '$');
            getline(fin2, text1, '#');
            if(text1 == "$")
            {
                getline(fin2, text2, '*');
                if(text2 == "#")
                {
                    getline(fin2, text3, '*');
                    if(text3 == "*")
                    {
                        getline(fin2, text4, '%');
                        if(text4 == "*")
                        {
                            break;
                        }
                        else
                            text = text + text1 + text2 + text3 + text4;
                    }
                    else
                        text = text + text1 + text2 + text3;
                }
                else
                    text = text + text1 + text2;
            }
            else
                text = text + text1;

            getline(fin2, text4, '%');

            /*cout << "PAGE TITLE: " << pageTitle << endl;
            cout << "PAGE NUMBER:" << pageId << endl;
            cout << "TEXT: " << text << endl;
            Page* p = new Page(pageTitle, pageId, text);
            pageIndex.insert2(p);
        }
    }*/

    //else if(indexType == "H" || indexType == "h")
    //{
        ifstream fin("output2.txt");
        ifstream fin2("output3.txt");
        string word = "";
        string text = "";
        string text1 = "";
        string text2 = "";
        string text3 = "";
        string text4 = "";
        string pageTitle = "";
        int pageId = 0;
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
            //cout << word << ": " << "[" << numOfPages << "] ";
            for(int b = 0; b < numOfPages; b++)
            {
                fin >> pageNum;
                fin.ignore();
                fin >> frequency;
                fin.ignore(3);
                w->addPages(pageNum);
                w->addToMap(pageNum, frequency);
                table.addWord(w);
                //cout << pageNum << "(" << frequency << "), ";
            }
            //cout << endl;
        }

        while(!fin2.eof())
        {
            fin2 >> pageTitle;
            fin2.ignore(3);
            fin2 >> pageId;
            /*getline(fin2, text, '$');
            getline(fin2, text1, '#');
            if(text1 == "$")
            {
                getline(fin2, text2, '*');
                if(text2 == "#")
                {
                    getline(fin2, text3, '*');
                    if(text3 == "*")
                    {
                        getline(fin2, text4, '%');
                        if(text4 == "*")
                        {
                            break;
                        }
                        else
                            text = text + text1 + text2 + text3 + text4;
                    }
                    else
                        text = text + text1 + text2 + text3;
                }
                else
                    text = text + text1 + text2;
            }
            else
                text = text + text1;

            getline(fin2, text4, '%');*/

            //cout << "PAGE TITLE: " << pageTitle << endl;
            //cout << "PAGE NUMBER:" << pageId << endl;
           // cout << "TEXT: " << text << endl;*/
            Page* p = new Page(pageTitle, pageId);
            pageIndex.insert2(p);
        }

    //}
}

void Query::startQuery()
{
    int count = 0;

    //before starting query we have to get the index
    buildIndex();
    cout << "Enter E to quit" << endl;
    string input = "";
    string temp = "";
    cin.ignore();

    while(input != "E" || input != "e") {

//http://www.codecogs.com/library/computing/stl/algorithms/set/set_union.php
    //good for parameters for a set
    cout << "To start a query please enter the words you would like to search for: " << endl;
    getline(cin, input);
    if(input == "E" || input == "e")
    {
        break;
    }
    stringstream ss(input);

    while(ss >> temp)
    {
        if(temp != "AND" && temp != "OR" && temp != "NOT")
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        char* arr = new char[temp.length() + 1];
        strcpy(arr, temp.c_str());
        int x = stem(arr, 0, strlen(arr)-1);
        arr[x+1] = '\0';
        temp = arr;
        searchWords.push_back(temp);
        //try to separate the string into vector or array
        count++;
    }
    Word * word1;
    Word * word2;
    Word * word3;
    vector<int> word1Pages;
    map <int, int> freqMap;
    map <int, int> freqMap2;
    int totalFrequency = 0;
    vector<int> totalWordFrequency;
    AVLTree <Page*> pageTitleResults;
    vector<int> pageResults;
    if(count  == 1)
    {
        word1 = table.returnWord(searchWords[0]);
        //word1 = tree.returnWord(searchWords[0]);
        if(word1 == NULL)
        {
            cout << "word does not exist" << endl;
        }
        else
        {
            pageResults = word1->getPages();
            for(int b = 0; b < pageResults.size(); b++)
            {
                int oPage = pageResults[b];
                freqMap = word1->getInfo();
                totalFrequency = freqMap[oPage];
                totalWordFrequency.push_back(totalFrequency);
                cout << "PAGE: " << pageResults[b] << " TOTAL FREQUENCY: " << totalFrequency << endl;
            }
        }

    }
    else if(searchWords[0] == "AND")
    {
        word1 = table.returnWord(searchWords[1]);
        word2 = table.returnWord(searchWords[2]);
        //word1 = tree.returnWord(searchWords[1]);
        //word2 = tree.returnWord(searchWords[2]);
        if(word1 == NULL || word2 == NULL)
        {
            cout << "word does not exist" << endl;
        }
        else
        {
        word1Pages = word1->getPages();
        vector<int> word2Pages = word2->getPages();
        pageResults = qAND(word1Pages, word2Pages);
        if(count == 5)
        {
            word3 = table.returnWord(searchWords[4]);
            //word3 = tree.returnWord(searchWords[4]);
            if(word3 == NULL)
            {
                cout << "word does not exist" << endl;
            }
            else
            {
            vector<int> word3Pages = word3->getPages();
            pageResults = qNOT(pageResults, word3Pages);
            } //end else
        }

        for(int b = 0; b < pageResults.size(); b++)
        {
            int oPage = pageResults[b];
            if(oPage == 0)
                break;
            else
            {
                freqMap = word1->getInfo();
                freqMap2 = word2->getInfo();
                totalFrequency = freqMap[oPage] + freqMap2[oPage];
                totalWordFrequency.push_back(totalFrequency);
                cout << "PAGE: " << pageResults[b] << " TOTAL FREQUENCY: " << totalFrequency << endl;
            }
        }
        }//end else
    }

    else if(searchWords[0] == "OR")
    {
        word1 = table.returnWord(searchWords[1]);
        word2 = table.returnWord(searchWords[2]);
        //word1 = tree.returnWord(searchWords[1]);
        //word2 = tree.returnWord(searchWords[2]);
        if(word1 == NULL || word2 == NULL)
        {
            cout << "word does not exist" << endl;
        }
        else
        {
        word1Pages = word1->getPages();
        vector<int> word2Pages = word2->getPages();
        pageResults = qOR(word1Pages, word2Pages);
        if(count == 5)
        {
            word3 = table.returnWord(searchWords[4]);
            //word3 = tree.returnWord(searchWords[4]);
            if(word3 == NULL)
            {
                cout << "word does not exist" << endl;
            }
            else
            {
            vector<int> word3Pages = word3->getPages();
            pageResults = qNOT(pageResults, word3Pages);
            }//end else
        }

        for(int b = 0; b < pageResults.size(); b++)
        {
            int oPage = pageResults[b];
            if(oPage == 0)
                break;
            else
            {
                freqMap = word1->getInfo();
                freqMap2 = word2->getInfo();
                totalFrequency = freqMap[oPage] + freqMap2[oPage];
                totalWordFrequency.push_back(totalFrequency);
                cout << "PAGE: " << pageResults[b] << " TOTAL FREQUENCY: " << totalFrequency << endl;
            }

        }//end else
    }
    else
    {
        word1 = table.returnWord(searchWords[0]);
        word2 = table.returnWord(searchWords[2]);
        //word1 = tree.returnWord(searchWords[0]);
        //word2 = tree.returnWord(searchWords[2]);
        if(word1 == NULL || word2 == NULL)
        {
            cout << "word does not exist" << endl;
        }
        else
        {
        word1Pages = word1->getPages();
        vector<int> word2Pages = word2->getPages();
        pageResults =  qNOT(word1Pages, word2Pages);
        }//end else
    }

    Page * x;
    for(int i = 0; i < pageResults.size(); i++)
    //to return the top 15 items
    //for(int i = 0; i < 15; i++)
    {
        if(pageResults[i] == 0)
            break;
        //cout << pageResults[i] << endl;
        x = pageIndex.returnObject(pageResults[i]);
        pageTitleResults.insert(x);
    }
        cout << "Pages on which your search appears:" << endl;
        pageTitleResults.print4(cout);
    searchWords.clear();
    }//end main while loop
}

vector<int> Query::qOR(vector<int> a, vector<int> b)
{
    vector<int> result(a.size()+b.size());
    set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    return result;
}

vector<int> Query::qAND(vector<int> a, vector<int> b)
{
    vector<int> result(a.size()+b.size());
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    return result;
}

vector<int> Query::qNOT(vector<int> a, vector<int> b)
{
    vector<int> result(a.size()+b.size());
    set_difference(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    return result;
}

Query::~Query()
{

}
