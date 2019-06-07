//
// Created by lotha on 2019/6/7.
//

#ifndef DT_STR_LINKLIST_DEFINITION_H
#define DT_STR_LINKLIST_DEFINITION_H

#endif //DT_STR_LINKLIST_DEFINITION_H

#include "sqlist_definition.h"

//线性表的单链表存储结构
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//单链表取得元素的操作
Status GetElem_L(LinkList L, int i, ElemType e){
    LNode *p = L->next; //p指向第一个节点
    int j=1;
    while (p&&j<i){
        p=p->next;
        j++;
    }
    if (!p||j>i)
        return ERROR;
    e=p->data;

    return OK;
}

//单链表插入元素的操作
Status ListInsert_L(LinkList L, int i, ElemType e){
    LNode *p = L;
    int j = 0;
    while(p && j<i-1){
        p = p->next;
        j++;
    }
    if (!p||j>i-1)
        return ERROR;

    LNode *s = (LinkList) malloc(sizeof(LNode));
    s->next=p->next;
    p->next=s;
    s->data=e;

    return OK;
}