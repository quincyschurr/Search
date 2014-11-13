#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

using namespace std;

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
        AVLNode(string word, AVLNode* l, AVLNode* r, int h) : element(word), left(l), right(r), height(h) {}
        ~AVLNode(){}

    };
public:
    ~AVLTree();
    AVLTree();
};

#endif // AVLTREE_H
