#ifndef AVL2_H
#define AVL2_H

#include <string>
#include <cstring>
#include <iostream>
#include "word.h"

using namespace std;



class AVL2
{
private:
    struct AVLNODE
    {
        Word* element;
        int height;
        AVLNODE* left;
        AVLNODE* right;

        AVLNODE(const Word*& element,AVLNODE *l, AVLNODE *r, int h) : element(element), left(l), right(r), height(h) {}
        ~AVLNODE()
        {
            delete left;
            delete right;
        }
    };

    AVLNODE* root;
    void insert(Word*& x, AVLNODE*& root);
    void print(ostream& out, AVLNODE* p) const;
    Word*& returnWord(string& test, AVLNODE*& root);

public:
    int height(AVLNODE*& n);
    void insert(const Word*& x);
    bool isEmpty() const;
    Word*& returnWord(string& test);
    void rotateWithLeftChild(AVLNODE* al);
    void rotateWithRightChild(AVLNODE* ar);
    void doubleWithLeftChild(AVLNODE*& k3);
    void doubleWithRightChild(AVLNODE*& k2);
    void print(ostream& out) const;
    bool searchFor(Word*& x, AVLNODE*& root);
    AVL2();
    ~AVL2();
};



#endif // AVL2_H
