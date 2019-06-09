//作者：罗通侯君
//时间：2019年6月7日
//内容基于《数据结构（C语言版）》（严蔚敏）

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType; //ElemType可根据实际情况调整类型，如char, float等

//线性表的单链表存储结构
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//注意，链表的头指针本身不存储数据，只是指向第一个元素

//单链表的初始化
//逆序输入，每输入一个数，分配一个新节点，并插入头节点之后
void CreateList_L(LinkList L, int n){
    //L为带头节点的单链表的头指针
    L = (LinkList)malloc(sizeof(LNode)); //为头节点分配空间
    L->next=NULL;                        //建立头指针

    for (int i = n; i > 0; i--) {
        LNode *p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

//单链表取得元素的操作
Status GetElem_L(LinkList L, int i, ElemType e){
    //L为带头节点的单链表的头指针
    LNode *p = L->next; //p指向第一个节点
    int j = 1; //计数器

    while (p && j<i){   //使p指向第i个节点
        p = p->next;
        j++;
    }

    if (!p || j>i)
        return ERROR;

    e=p->data;

    return OK;
}

//单链表插入元素的操作
Status ListInsert_L(LinkList L, int i, ElemType e){
    //L为带头节点的单链表的头指针
    LNode *p = L; //p指向头节点
    int j = 0;
    while(p && j<i-1){// 使p指向第i-1个节点
        p = p->next;
        j++;
    }

    if (!p || j>i-1)
        return ERROR;

    LNode *s = (LinkList) malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = e;

    return OK;
}

//单链表删除元素操作
Status ListDelete_L(LinkList L, int i){
    //L为带头节点的单链表的头指针
    LNode *p = L; //p指向头节点
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    if(!p || j>j-1)
        return ERROR;

    LNode *q = p->next;
    p->next = q->next;
    free(q);

    return OK;
}

//合并两个有序单链表
//以下链表均带有头指针
//与顺序存储不同的是，对于链式存储的表，只需将表Lb的节点插入到表La中正确的位置即可
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc){
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    Lc = La;
    LNode *pc = Lc;
    while(pa && pb){
        if(pa->data >= pb->data){
            pc->next = pb; //使pc指向pb
            pc = pb;       //使pc指向下一位
            pb = pb->next;
        }
        else{
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
    }
    pc->next = pa?pa:pb;
    free(Lb);               //释放Lb的头指针
}

//带头节点的双向链表的定义与基本操作

typedef struct DulNode {
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
}DulNode, *DuLinkList;

DulNode *GetElemP_Dul(DuLinkList L, int i){
    DulNode *p = L->next;
    int j = 1;
    while (p && j<i){
        p = p->next;
        j++;
    }

    if (!p || j>i)
        return ERROR;
    else
        return p;
}

Status ListInsert_Dul(DuLinkList L, int i, ElemType e){
    DulNode *p = GetElemP_Dul(L, i);
    if (!p)
        return ERROR;

    DulNode *s = (DuLinkList)malloc(sizeof(DulNode));
    if (!s)
        return ERROR;

    p->prior->next = s;  //使节点p的前一个节点的next指针指向s
    s->prior = p->prior; //使节点s的prior指针指向节点p的前一个节点
    p->prior = s;        //使节点p的prior指针指向节点s
    s->next = p;         //使节点s的next指针指向节点p
}

Status ListDelete_Dul(DuLinkList L, int i){
    DulNode *p = GetElemP_Dul(L, i);
    if (!p)
        return  ERROR;

    p->prior->next = p->next;  //使节点p的前一个节点的next指针指向节点p的后一个节点
    p->next->prior = p->prior; //使节点p的后一个节点的prior指针指向节点p的前一个节点
    free(p);

    return OK;
}