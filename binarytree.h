/*作者：罗通侯君*/
/*二叉树的定义及基本操作*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*二叉树的链式存储结构*/
typedef struct BitNode {
    int data;
    struct BitNode *left;
    struct BitNode *right;
} btree;

/*辅助函数，用于构造一个二叉树*/
btree *newNode(int data) {
    btree *node = (btree *) malloc(sizeof(btree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*--------------------------------------------------------*/
/*辅助数据结构*/

/*定义栈*/
typedef struct StackNode {
    btree *t;
    struct StackNode *next;
} stack;

/*栈的相关函数*/
void push(stack **s, btree *t);

btree *pop(stack **s);

bool isEmpty(stack *s);

void push(stack **s, btree *t) {
    stack *new_StackNode = (stack *) malloc(sizeof(stack));

    if (!new_StackNode) {
        printf("Stack Overflow\n");
        exit(0);
    }

    new_StackNode->t = t;
    new_StackNode->next = *s;
    *s = new_StackNode;
}

bool isEmpty(stack *s) {
    return (s == NULL) ? 1 : 0;
}

btree *pop(stack **s) {
    btree *res;
    stack *top;

    if (isEmpty(*s)) {
        printf("Stack Underflow \n");
        exit(0);
    } else {
        top = *s;
        res = top->t;
        *s = top->next;
        free(top);
        return res;
    }
}

/* 队列的定义及相关函数 */
btree **initQueue(int *, int *);

void enQueue(btree **, int *, btree *);

btree *deQueue(btree **, int *);

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
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/*层序遍历的实现*/

/*借助队列实现层序遍历*/
void BFSViaQueue(btree *root) {
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

/* 用递归的方式实现层序遍历 */
int height(btree *root);

void printGivenLevel(btree *root, int level);

void BFSRecur(btree *root) {
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
/* 递归方式实现二叉树深度优先搜索 */

/* 前序遍历 */
void PreOrder(btree *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    PreOrder(root->left);

    PreOrder(root->right);
}

/* 中序遍历 */
void InOrder(btree *root) {
    if (root == NULL)
        return;

    InOrder(root->left);

    printf("%d ", root->data);

    InOrder(root->right);
}

/* 后序遍历 */
void PostOrder(btree *root) {
    if (root == NULL)
        return;

    PostOrder(root->left);

    PostOrder(root->right);

    printf("%d ", root->data);
}
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/*借助栈实现非递归深度优先搜索*/

/*前序非递归遍历算法*/
void PreOrder2(btree *root) {
    if (root == NULL)
        return;

    btree *current = root;
    stack *s = NULL;

    push(&s, current);
    while (!isEmpty(s)) {
        current = pop(&s);
        printf("%d ", current->data);

        if (current->right)
            push(&s, current->right);
        if (current->left)
            push(&s, current->left);
    }
}

/*中序非递归遍历算法*/
void InOrder2(btree *root) {
    btree *current = root;
    stack *s = NULL;

    while (current || !isEmpty(s)) {
        if (current) {
            push(&s, current);
            current = current->left;
        } else {
            current = pop(&s);
            printf("%d ", current->data);
            current = current->right;
        }
    }
}

/*后序非递归遍历算法*/
void PostOrder2(btree *root) {
    if (root == NULL)
        return;

    btree *current = root;
    stack *s1 = NULL;
    stack *s2 = NULL;

    push(&s1, current);
    while (!isEmpty(s1)) {
        current = pop(&s1);
        push(&s2, current);

        if (current->left)
            push(&s1, current->left);
        if (current->right)
            push(&s1, current->right);
    }
    while (!isEmpty(s2)) {
        printf("%d ", pop(&s2)->data);
    }
}
/*--------------------------------------------------------*/