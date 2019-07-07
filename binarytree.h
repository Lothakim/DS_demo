#include <stdio.h>
#include <stdlib.h>


//二叉树的链式存储结构
typedef struct BitNode {
    int data;
    struct BitNode *left;
    struct BitNode *right;
} btree;


//辅助函数，用于构造一个二叉树
btree *newNode(int data) {
    btree *node = (btree *) malloc(sizeof(btree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


/* 用队列实现层序遍历 */
btree **initQueue(int *, int *);

void enQueue(btree **, int *, btree *);

btree *deQueue(btree **, int *);

void btree_bfs_queue(btree *root) {
    int rear, front;
    btree **Q = initQueue(&front, &rear);
    btree *temp_node = root;

    while (temp_node) {
        printf("%d ", temp_node->data);

        if (temp_node->left)
            enQueue(Q, &rear, temp_node->left);

        if (temp_node->right)
            enQueue(Q, &rear, temp_node->right);

        temp_node = deQueue(Q, &front);
    }
}

btree **initQueue(int *front, int *rear) {
    btree **Q = (btree **) malloc(sizeof(btree) * 500);
    *front = *rear = 0;

    return Q;
}

void enQueue(btree **Q, int *rear, btree *node) {
    Q[*rear] = node;
    (*rear)++;
}

btree *deQueue(btree **Q, int *front) {
    (*front)++;
    return Q[*front - 1];
}


/* 用递归的方式实现层序遍历 */
int height(btree *root);

void printGivenLevel(btree *root, int level);

void btree_bfs_recur(btree *root) {
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
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}



/* 递归方式实现二叉树遍历 */

/* 前序遍历 */
void printPreorder(btree *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    printPreorder(root->left);

    printPreorder(root->right);
}

/* 中序遍历 */
void printInorder(btree *root) {
    if (root == NULL)
        return;

    printInorder(root->left);

    printf("%d ", root->data);

    printInorder(root->right);
}

/* 后序遍历 */
void printPostorder(btree *root) {
    if (root == NULL)
        return;

    printPostorder(root->left);

    printPostorder(root->right);

    printf("%d ", root->data);
}