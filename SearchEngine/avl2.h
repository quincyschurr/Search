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
    class AVLNODE
    {
    public:
        Word* element;
        int height;
        AVLNODE* left;
        AVLNODE* right;

        AVLNODE(const Word*& element, AVLNODE* l, AVLNODE* r, int h = 0) : element(element), left(l), right(r), height(h) {}
        ~AVLNODE()
        {
            delete left;
            delete right;
        }
    };//end NODE declaration

    AVLNODE* root;

    void insert(Word*& x, AVLNODE*& root)
    {
        if(root == NULL)
            root = new AVLNODE(x, NULL, NULL);
        else if(x < root->element)
        {
            insert(x, root->left);
            if(height(root->left) - height(root->right) == 2)
            {
                if(x > root->right->element)
                    rotateWithLeftChild(root);
                else
                    doubleWithLeftChild(root);
            }
        }
        else if(x > root->element)
        {
            insert(x, root->right);
            if(height(root->right) - height(root->left) == 2)
            {
                if(x > root->right->element)
                    rotateWithRightChild(root);
                else
                    doubleWithRightChild(root);
            }
        }

        root->height = max(height(root->left), height(root->right)) +1;
    }

    void print(ostream& out, AVLNODE* p) const
    {
        if(p != NULL)
        {
            print(out, p->left);
            out << p->element << endl;
            print(out, p->right);
        }
    }

    Word*& returnWord(string& test, AVLNODE*& root)
    {
        if(root == NULL)
        {
            throw(strerror);
        }
        else if(test == root->element->getWord())
        {
            return root->element;
        }
        else if(test < root->element->getWord())
        {
            return returnWord(test, root->left);
        }
        else if(test > root->element->getWord())
        {
            return returnWord(test, root->right);
        }

    }

public:
    AVL2();
    Word*& returnWord(string& test);
    int height(AVLNODE*& n);
    void insert(const Word*& x);
    bool isEmpty() const;
    void rotateWithLeftChild(AVLNODE* al);
    void rotateWithRightChild(AVLNODE* ar);
    void doubleWithLeftChild(AVLNODE*& k3);
    void doubleWithRightChild(AVLNODE*& k2);
    void print(ostream& out) const;
    bool searchFor(Word*& x, AVLNODE*& root);
    ~AVL2();
};



#endif // AVL2_H
