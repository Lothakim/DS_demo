#include "binarytree.h"
#include <stdio.h>

int main()
{
    btree *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    btree_bfs_recur(root);

    return 0;
}