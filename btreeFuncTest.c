#include <stdio.h>
#include "binarytree.h"
#include "btreeRelatedProblem.h"

int main()
{
    btree *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    swapSubtree(root);
    BFSViaQueue(root);

    return 0;
}