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
<<<<<<< HEAD
        cout << "NODE destructor called" << endl;
=======
        cout << "nodes are destructed" << endl;
>>>>>>> c1e47c0d6da9cd54173d3c39ad8865241c6039c4
        delete left;
        delete right;
    }
};

#endif // AVLNODE_H
