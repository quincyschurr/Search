#include "avl2.h"
#include "AVLNODE.h"

AVL2::AVL2()
{
    this->root = NULL;
}

AVL2::~AVL2()
{
    delete root;
}

AVLNODE* AVL2::getRoot()
{
    return root;
}

void AVL2::insert(Word*& x)
{
    insert(x, root);
}

void AVL2::insert(Word*& x, AVLNODE*& root)
{
    if(root == NULL)
        root = new AVLNODE(x, NULL, NULL);
    else if(x < root->element)
    {
        insert(x, root->left);
        if(height(root->left) - height(root->right) == 2)
        {
            if(x < root->left->element)
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

Word*& AVL2::returnWord(string& test, AVLNODE*& root)
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

void AVL2::print(ostream& out, AVLNODE* p) const
{
    if(p != NULL)
    {
        print(out, p->left);
        out << p->element << endl;
        print(out, p->right);
    }
}

bool AVL2::searchFor(string &x, AVLNODE *root)
{
    if(root == NULL)
        return false;
    else if(x == root->element->getWord())
        return true;
    else if(x < root->element->getWord())
        return searchFor(x, root->left);
    else if(x > root->element->getWord())
        return searchFor(x, root->right);
    else
        return false;
}


/*bool AVL2::searchFor(Word*& x, AVLNODE* root)
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
}*/
