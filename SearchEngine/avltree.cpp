#include "avltree.h"

AVLTree::AVLTree()
{

}

int AVLTree::height(AVLNode* t)
{
    if(t == NULL)
        return -1;
    else
        return t->height;
}

void AVLTree::insert(string word, AVLNode*& t)
{
    if(t == NULL)
    {
        t = new AVLNode(word, NULL, NULL);
        //how to add the height?
    }

    else if(word < t->element)
    {
        insert(word, t->left);
        if(height(t->left) - height(t->right) == 2)
        {
            if(word < t->left->element)
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
    }

    else if(word > t->element)
    {
        insert(word, t->right);
        if(height(t->left) - height(t->right) == 2)
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);
    }

    t->height = max(height(t->left), height(t->right)) +1;
}

AVLTree::~AVLTree()
{

}
