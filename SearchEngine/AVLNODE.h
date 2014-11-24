#ifndef AVLNODE_H
#define AVLNODE_H

struct AVLNODE
{
    Word* element;
    int height;
    AVLNODE* left;
    AVLNODE* right;


    AVLNODE(Word*& element, AVLNODE *l, AVLNODE *r, int h = 0) : element(element), left(l), right(r), height(h) {}
    ~AVLNODE()
    {
        cout << "NODE destructor called" << endl;
        delete left;
        delete right;
    }
};

#endif // AVLNODE_H
