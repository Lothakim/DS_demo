/* Author: Lot hakim */
/* Definition of binary tree and basic operation */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_Q_SIZE 50

/* Definition of binary tree */
typedef struct BitNode {
    int data;
    struct BitNode *left;
    struct BitNode *right;
} btree;

/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
btree *newNode(int data) {
    btree *node = (btree *) malloc(sizeof(btree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*--------------------------------------------------------*/
/* Helper data structure */

/* Definition of stack */
typedef struct StackNode {
    btree *t;
    struct StackNode *next;
} stack;

/* Basic operation of stack */
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

/* Queue and basic operation */
btree **initQueue(int *front, int *rear) {
    btree **Q = (btree **) malloc(sizeof(btree) * MAX_Q_SIZE);
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
/* Breadth first search with queue */

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
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/* Depth first search recursive */

void PreOrder(btree *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    PreOrder(root->left);

    PreOrder(root->right);
}

void InOrder(btree *root) {
    if (root == NULL)
        return;

    InOrder(root->left);

    printf("%d ", root->data);

    InOrder(root->right);
}

void PostOrder(btree *root) {
    if (root == NULL)
        return;

    PostOrder(root->left);

    PostOrder(root->right);

    printf("%d ", root->data);
}
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/*Depth first search non-recursive with stack*/

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