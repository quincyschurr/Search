#ifndef AVL2_H
#define AVL2_H

#include <string>
#include <cstring>
#include <iostream>
#include "word.h"
#include "AVLNODE.h"

using namespace std;

class AVL2
{
private:
    /*struct AVLNODE
    {
        Word* element;
        int height;
        AVLNODE* left;
        AVLNODE* right;


        AVLNODE(Word*& element, AVLNODE *l, AVLNODE *r, int h = 0) : element(element), left(l), right(r), height(h) {}
        ~AVLNODE()
        {
            delete left;
            delete right;
        }
    };*/

    AVLNODE* root;
    void insert(Word* x, AVLNODE*& root);
    void print(ostream& out, AVLNODE* p) const;
    Word* returnWord(string& test, AVLNODE* root);
    void makeEmpty(AVLNODE*&);

public:
    AVLNODE* getRoot();
    int height(AVLNODE*& n);
    void insert(Word* x);
    bool isEmpty() const;
    Word* returnWord(string& test);
    void rotateWithLeftChild(AVLNODE*& al);
    void rotateWithRightChild(AVLNODE*& ar);
    void doubleWithLeftChild(AVLNODE*& k3);
    void doubleWithRightChild(AVLNODE*& k2);
    void print(ostream& out) const;
    bool searchFor(string& x, AVLNODE* root);
    bool searchFor(Word*& x, AVLNODE* root);
    void makeEmpty();

    AVL2();
    ~AVL2();
    AVL2(const AVL2&);

};



#endif // AVL2_H
