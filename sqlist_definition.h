//
// Created by lothakim on 2019/6/6.
//
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType; //ElemType可根据实际情况调整类型，如char, float等

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

//定位顺序存储结构线性表元素的操作
int LocateElem_Sq(SqList L, ElemType e, Status (* compare)(ElemType, ElemType)){
    int i=1;
    ElemType *p=L.elem;
    while(i<=L.length&&!(*compare)(*p++,e))
        i++;
    if (i<=L.length)
        return i;
    else
        return 0;
}

//顺序表合并操作，已知原表按非递减次序排列
void MergeList_Sq(SqList La, SqList Lb, SqList Lc){
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;

    Lc.length = La.length+Lb.length;
    Lc.listsize = Lc.length;
    Lc.elem = (ElemType *)malloc(Lc.listsize* sizeof(ElemType));
    ElemType *pc = Lc.elem;
    if(!Lc.elem)
        exit(OVERFLOW);

    ElemType *pa_last = La.elem+La.length-1;
    ElemType *pb_last = Lb.elem+Lb.length-1;

    while(pa<=pa_last&&pb<=pb_last){
        if(*pa>=*pb){ //若pa指向的值大于等于pb，则取pb的值，并使pb指向下一位
            *pc=*pb;
            pb++;
        }
        else{ //反之，则取pa的值，并使pa指向下一位
            *pc=*pa;
            pa++;
        }
        pc++; //每个循环后，pc必定获得一个值，然后使其指向下一位
    }

    while(pa<=pa_last)
        *pc++=*pa++;

    while (pb<pb_last)
        *pc++=*pb++;
}