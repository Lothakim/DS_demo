//
// Created by lotha on 2019/6/6.
//
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//线性表顺序存储结构声明
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;

//构造一个空的线性表L
Status InitList_Sq(SqList L){
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE* sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

//顺序存储结构线性表的插入操作
Status ListInsert_Sq(SqList L, int i, ElemType e){
    if (i<1||i>L.length+1)
        return ERROR;
    if(L.length>=L.listsize){
        ElemType *newbase=(ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT)* sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        L.elem=newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType *q= &(L.elem[i-1]); //q为指向插入位置的指针
    for (ElemType *p = &(L.elem[L.length-1]); p >= q; --p) { //初始化指针p，使其指向原表最后一位，并依次回退直到q
        *(p+1)=*p; //将p指向的地址的值赋予其后一位
    }
    *q=e;
    ++L.length;

    return OK;
}

//顺序存储结构线性表的删除操作
Status ListDelete_Sq(SqList L, int i, ElemType e){
    if (i<1||i>L.length+1)
        return ERROR;
    ElemType *p = &(L.elem[i-1]); //指针p指向即将被删除的元素的位置
    e = *p;
    ElemType *q = L.elem+L.length-1; //指针q指向原表最后一位
    for (; p < q; ++p) {
        *p=*(p+1); //从被删除的元素开始，将后一位的值赋予指向地址的值
    }
    --L.length;

    return OK;
}