#include "avl2.h"
#include "AVLNODE.h"
using namespace std;

AVL2::AVL2()
{
    this->root = NULL;
}

AVL2::AVL2(const AVL2 & c)
{
    this->root = NULL;
    *this = c;
}

AVL2::~AVL2()
{
    makeEmpty();
}

AVLNODE* AVL2::getRoot()
{
    return root;
}

int AVL2::height(AVLNODE*& n)
{
    if(n == NULL)
        return 0;
    else
        return n->height;
}

void AVL2::insert(Word*& x)
{
    insert(x, root);
}

void AVL2::insert(Word*& x, AVLNODE*& root)
{
    if(root == NULL)
        root = new AVLNODE(x, NULL, NULL);
    else if(x->getWord() < root->element->getWord())
    {
        insert(x, root->left);
        if(height(root->left) - height(root->right) == 2)
        {
            if(x->getWord() < root->left->element->getWord())
                rotateWithLeftChild(root);
            else
                doubleWithLeftChild(root);
        }
    }
    else if(x->getWord() > root->element->getWord())
    {
        insert(x, root->right);
        if(height(root->right) - height(root->left) == 2)
        {
            if(x->getWord() > root->right->element->getWord())
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

void AVL2::makeEmpty()
{
    makeEmpty(root);
}

void AVL2::makeEmpty(AVLNODE *& c)
{
    if(c != NULL)
    {
        makeEmpty(c->left);
        makeEmpty(c->right);
        delete c;
    }
    c = NULL;
}

Word* AVL2::returnWord(string& test)
{
    return returnWord(test, root);
}

Word* AVL2::returnWord(string& test, AVLNODE*& root)
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

void AVL2::rotateWithLeftChild(AVLNODE*& al)
{
    AVLNODE* temp = al->left;
    al->left = temp->right;
    temp->right = al;
    al->height = max(height(al->left), height(al->right)) +1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    al = temp;
}

void AVL2::rotateWithRightChild(AVLNODE*& ar)
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
    print(out, root);
}

void AVL2::print(ostream& out, AVLNODE* p) const
{
    if(p != NULL)
    {
        print(out, p->left);
        out << p->element->getWord() << " : ";
        out << "[" << p->element->getNumPages() << "] ";
        p->element->getPageTree(out);
        out << endl;
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
