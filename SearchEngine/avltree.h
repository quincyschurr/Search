#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <cstring>
#include <iostream>
#include "page.h"
using namespace std;

//good website for the traversal
//http://www.sanfoundry.com/cpp-program-implement-avl-trees/
//DOCUMENTATION:
//http://www.cs.uah.edu/~rcoleman/Common/CodeVault/Code/Code203_Tree.html


template <typename T> class AVLTree
{
private:
    class AVLNode
    {
    public:
        T element;
        int height;
        AVLNode* left;
        AVLNode* right;

        AVLNode(const T& theElem, AVLNode* l, AVLNode* r, int h = 0) : element(theElem), left(l), right(r), height(h) { }
        ~AVLNode()
        {
            delete left;
            delete right;
        }

    };

    AVLNode* root;

    void insert(T x, AVLNode*& t)
    {
        if(t == NULL)
            t = new AVLNode(x, NULL, NULL);
        else if(x < t->element)
        {
            insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->element)
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        }

        else if(x > t->element)
        {
            insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->element)
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
    }


    void insert2(T x, AVLNode*& t)
    {
        if(t == NULL)
            t = new AVLNode(x, NULL, NULL);
        else if(x->getId() < t->element->getId())
        {
            insert2(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x->getId() < t->left->element->getId())
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        }

        else if(x->getId() > t->element->getId())
        {
            insert2(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x->getId() > t->right->element->getId())
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
    }

    void print4(ostream &out, AVLNode* r) const
    {
        if(r != NULL)
        {
            print4(out, r->left);
            out << r->element->getTitle() << ": " << r->element->getId() <<  endl;
            print4(out, r->right);
        }
    }

    void print3(ostream &out, AVLNode* r) const
    {
        if(r != NULL)
        {
            print3(out, r->left);
            out << r->element->getTitle() << " : " << r->element->getId() << endl;//" " << r->element->getText() << endl << "$#**%" << endl;
            print3(out, r->right);
        }
    }

    void print2(ostream &out, AVLNode* p) const
    {
        if(p != NULL)
        {
            print2(out, p->left);
            out << p->element << ",";
            print2(out, p->right);

        }
    }

    void print(ostream& out, AVLNode* p) const
    {
        if(p != NULL)
        {
            print(out, p->left);
            out << p->element << endl;
            print(out, p->right);
        }
    }

    T& returnObject(int& test, AVLNode*& root)
    {
        if(root == NULL)
        {
            throw(strerror);
        }
        else if(test == root->element->getId())
        {
            return root->element;//this should be returning a Word object
        }
        else if(test < root->element->getId())
        {
            //this statement is stopping the debugger
            return returnObject(test, root->left);
        }
        else if(test > root->element->getId())
        {
            return returnObject(test, root->right);
        }
    }

public:
    AVLTree()
    {
        this->root = NULL;
    }

    T& find(const T& x, AVLNode* root)
    {
        if(root == NULL)
        {
            throw(strerror);
        }
        else if (x == root->element)
        {
            return root->element;
        }
        else if(x < root->element)
        {
            return find(x, root->left);
        }
        else if(x > root->element)
        {
            return find(x, root->right);
        }
    }

    T& returnObject(int& test)
    {
        return returnObject(test, root);
    }



    int height(AVLNode*& n)
    {
        if(n == NULL)
            return 0;
        else
            return n->height;
    }

    void insert(const T& x)
    {
        insert(x, root);
    }

    void insert2(const T& x)
    {
        insert2(x, root);
    }

    bool isEmpty() const
    {
        if(root == NULL)
            return true;
        else
            return false;
    }

    void rotateWithLeftChild(AVLNode*& al)//al = alpha left
    {
        AVLNode* temp = al->left;
        al->left = temp->right;
        temp->right = al;
        al->height = max(height(al->left), height(al->right)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        al = temp;
    }
    void rotateWithRightChild(AVLNode*& ar)
    {
        AVLNode* temp = ar->right;
        ar->right = temp->left;
        temp->left = ar;
        ar->height = max(height(ar->left), height(ar->right)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        ar = temp;
    }
    void doubleWithLeftChild(AVLNode*& k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AVLNode*& k2)
    {
        rotateWithLeftChild(k2->right);
        rotateWithRightChild(k2);
    }

    void print4(ostream& out) const
    {
        print4(out, root);
    }

    void print3(ostream& out) const
    {
        print3(out, root);
    }

    ostream& print2(ostream &out) const
    {
        print2(out, root);
    }

    void print(ostream& out) const
    {
        //out << "ROOT " << root->element << endl;
        print(out, root);
    }

    bool search (T& x, AVLNode* root)
    {
        if(root == NULL)
            return false;
        else if(x == root->element)
            return true;
        else if(x < root->element)
            return search(x, root->left);
        else if(x > root->element)
            return search(x, root->right);
        else
            return false;

    }

    ~AVLTree()
    {
        delete root;
    }

    friend bool operator> (const string& lhs, const string& rhs)
    {
        if(strcmp(lhs.c_str(), rhs.c_str()) > 0)
        {
            return true;
        }
        else
            return false;

    }

    friend bool operator< (const string& lhs, const string& rhs)
    {
        if(strcmp(lhs.c_str(), rhs.c_str()) < 0)
        {
            return true;
        }
        else
            return false;
    }

    friend bool operator==(const string& lhs, const string& rhs)
    {
        if(strcmp(lhs.c_str(), rhs.c_str()) == 0)
        {
            return true;
        }
        else
            return false;
    }

    AVLNode* getRoot()
    {
        return root;
    }
};

#endif // AVLTREE_H
