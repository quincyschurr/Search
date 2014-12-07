#ifndef AVL2_H
#define AVL2_H

#include <cstring>
#include <iostream>
#include "word.h"
#include "AVLNODE.h"

using namespace std;

class AVL2
{
private:
    AVLNODE* root;
    void insert(Word*& x, AVLNODE*& root);
    void makeEmpty(AVLNODE*&);
    void print(ostream& out, AVLNODE* p) const;
    Word* returnWord(string& test, AVLNODE*& root);


public:
    AVLNODE* getRoot();
    int height(AVLNODE*& n);
    void insert(Word*& x);
    bool isEmpty() const;
    void makeEmpty();
    Word* returnWord(string& test);
    void rotateWithLeftChild(AVLNODE*& al);
    void rotateWithRightChild(AVLNODE*& ar);
    void doubleWithLeftChild(AVLNODE*& k3);
    void doubleWithRightChild(AVLNODE*& k2);
    void print(ostream& out) const;
    bool searchFor(string& x, AVLNODE* root);


    AVL2();
    ~AVL2();
    AVL2(const AVL2&);

};



#endif // AVL2_H
