#ifndef AVLNODE_H
#define AVLNODE_H

struct AVLNODE
{
    Word* element;
    int height;
    AVLNODE* left;
    AVLNODE* right;


    AVLNODE(Word* elementp, AVLNODE *l, AVLNODE *r, int h = 0) : element(elementp), left(l), right(r), height(h) {}
    ~AVLNODE()
    {

        cout << "nodes are destructed" << endl;
        delete left;
        delete right;
    }
};

#endif // AVLNODE_H
