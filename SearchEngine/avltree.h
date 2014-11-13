#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

using namespace std;

//good website for the traversal
//http://www.sanfoundry.com/cpp-program-implement-avl-trees/

class AVLTree
{
private:
    class AVLNode
    {
    public:
        int height;
        string element;
        AVLNode* left;
        AVLNode* right;
        //AVLNode(string word, AVLNode* l, AVLNode* r, int h) : element(word), left(l), right(r), height(h) {}
        AVLNode(string word, AVLNode* l, AVLNode* r) : element(word), left(l), right(r) {}
        ~AVLNode(){}

    };

    AVLNode* root;
public:
    void insert(string word, AVLNode*& t);
    int height(AVLNode* t);
    void rotateWithLeftChild(AVLNode*& alpha);
    void doubleWithLeftChild(AVLNode*& t);
    void rotateWithRightChild(AVLNode*& alpha);
    void doubleWithRightChild(AVLNode*& t);

    AVLTree();
    ~AVLTree();
};

#endif // AVLTREE_H
