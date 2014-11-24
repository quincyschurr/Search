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

<<<<<<< HEAD
        AVLNODE(Word*& element,AVLNODE *l, AVLNODE *r, int h) : element(element), left(l), right(r), height(h) {}
=======
        AVLNODE(Word*& element, AVLNODE *l, AVLNODE *r, int h = 0) : element(element), left(l), right(r), height(h) {}
>>>>>>> 0f5cb85caf0354f02d77df900d17fd34ddc32ff2
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
    AVLNODE* getRoot();
    int height(AVLNODE*& n);
    void insert(Word*& x);
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
