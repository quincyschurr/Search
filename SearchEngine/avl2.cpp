#include "avl2.h"

AVL2::AVL2()
{
    this->root = NULL;
}

AVL2::~AVL2()
{
    delete root;
}

void AVL2::insert(const Word*& x)
{
    insert(x, root);
}

bool AVL2::isEmpty() const
{
    if(root == NULL)
        return true;
    else
        return false;
}

int AVL2::height(AVLNODE*& n)
{
    if(n == NULL)
        return 0;
    else
        return n->height;
}

Word*& AVL2::returnWord(string& test)
{
    return returnWord(test, root);
}

void AVL2::rotateWithLeftChild(AVLNODE* al)
{
    AVLNODE* temp = al->left;
    al->left = temp->right;
    temp->right = al;
    al->height = max(height(al->left), height(al->right)) +1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    al = temp;
}

void AVL2::rotateWithRightChild(AVLNODE* ar)
{
    AVLNODE* temp = ar->right;
    ar->right = temp->left;
    temp->left = ar;
    ar->height = max(height(temp->left), height(temp->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    ar = temp;
}

void AVL2::doubleWithLeftChild(AVLNODE*& k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void AVL2::doubleWithRightChild(AVLNODE*& k2)
{
    rotateWithLeftChild(k2->right);
    rotateWithRightChild(k2);
}

void AVL2::print(ostream& out) const
{
    out << "ROOT " << root->element << endl;
    print(out, root);
}

bool AVL2::searchFor(Word*& x, AVLNODE*& root)
{
   if(root == NULL)
       return false;
   else if(x == root->element)
       return true;
   else if(x < root->element)
       return searchFor(x, root->left);
   else if(x > root->element)
       return searchFor(x, root->right);
   else
       return false;
}
