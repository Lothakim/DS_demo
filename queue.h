//作者：罗通侯君
//时间：2019年6月18日
//内容基于《数据结构（C语言版）》（严蔚敏）

//栈的相关定义和基本操作

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int QElemType; //QlemType可根据实际情况调整类型，如char, float等


//队列的链式存储结构定义
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//初始化队列
Status InitQueue(LinkQueue Q){

    Q.front = (QueuePtr)malloc(sizeof(QNode));
    Q.rear = Q.front;

    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;

    return OK;
}

//销毁队列
Status DestroyQueue(LinkQueue Q){
    while (Q.front){
        Q.rear = Q.front->next; //使尾指针指向头指针的下一位
        free(Q.front);          //释放头指针指向位置的内存
        Q.front = Q.rear;       //将尾指针赋值给头指针，进入下个循环
    }
    return OK;
}

//队尾插入元素
Status EnQueue(LinkQueue Q, QElemType e){
    QNode *p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(OVERFLOW);
    Q.rear->next = p; //使当前队尾元素的下一位指向p
    p->data = e;
    p->next = NULL;
    Q.rear = p;       //使队尾指针指向p
}

//队首删除元素
Status DeQueue(LinkQueue Q, QElemType e){
    if (Q.front == Q.rear)
        return ERROR;

    QNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next; //使队首指针指向被删除元素的下一位

    if (Q.rear == Q.front)   //若删除之后队列为空，则尾指针将丢失，需重新赋值
        Q.rear = Q.front;

    free(p);

    return OK;
}

//循环队列
#define MAXSIZE 100

//循环队列中有一个元素弃置不用，即实际上队满时只有MAXSIZE-1个元素
typedef struct SqQueue {
    QElemType *base;
    int front; //队首指针，指向队列头元素
    int rear;  //队尾指针，指向队尾元素下一位；当队尾指针下一位指向队首指针时，队满
}SqQueue;

//初始化循环队列
Status InitCircularQueue(SqQueue Q){
    Q.base = (QElemType *)malloc(MAXSIZE* sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = 0;
    Q.rear = 0;
    return OK;
}

//返回循环队列的长度
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//插入元素
Status EnCircularQueue(SqQueue Q, QElemType e){
    if ((Q.rear+1)%MAXSIZE == Q.front) //队列判满
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXSIZE;

    return OK;
}

//删除元素
Status DeCircularQueue(SqQueue Q, QElemType e){
    if (Q.front == Q.rear) //队列判空
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1)%MAXSIZE;

    return OK;
}