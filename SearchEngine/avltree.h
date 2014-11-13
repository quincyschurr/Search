#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

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
public:
    AVLTree()
    {
        this->root = NULL;
    }

    void clearTree()
    {
        delete root;
    }

    int height(AVLNode*& n)
    {
        if(n == NULL)
            return 0;
        else
            return n->height;
    }

    void insert(T x, AVLNode*& t)
    {
        if(t == NULL)
            t = new AVLNode(x, NULL, NULL);
        else if(x < t->left)
        {
            insert(x, t->element);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->element)
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
        }

        else if(x > t->left)
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
        temp-height = max(height(temp->left), height(temp->right)) + 1;
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

    void print(ostream& out) const
    {
        print(out, root);
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

    ~AVLTree()
    {
        //clear the tree
        //deallocate

        delete root;
    }
};

#endif // AVLTREE_H
