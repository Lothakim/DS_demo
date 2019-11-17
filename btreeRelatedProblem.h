/*--------------------------------------------------------*/

/* Breadth first search recursive approach */
int height(btree *root);

void printGivenLevel(btree *root, int level);

void BFSRecursive(btree *root) {
    int h = height(root);
    int i;

    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(btree *root, int level) {
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d ", root->data);

    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(btree *root) {
    if (root == NULL)
        return 0;
    else {
        int lh = height(root->left);
        int rh = height(root->right);

        return (lh > rh) ? lh + 1 : rh + 1;
    }
}
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/*Find the maximum length between the leaf node
 * of left subtree and right subtree*/

/*Analysis: the key is to find the height of the tree.
 * The maximum length is the height of the left subtree
 * plus the height of the right subtree*/

int maxDistance(btree *root){
    return height(root->left)+height(root->right);
}
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/* Switch the left and right subtree of a binary tree */

/* Recursive approach */
void swapSubtree(btree *root){
    btree *tempNode;

    if(!root->left && !root->right)
        return;

    swapSubtree(root->left);
    swapSubtree(root->right);

    tempNode=root->left;
    root->left=root->right;
    root->right=tempNode;
}

/* Non-recursive approach */
void swapSubtree2(btree *root){

}