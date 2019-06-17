//作者：罗通侯君
//时间：2019年6月7日
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
typedef int SElemType; //ElemType可根据实际情况调整类型，如char, float等

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//栈的定义
typedef struct Sqstack{
    SElemType *base; //栈底指针
    SElemType *top;  //栈顶指针
    int stacksize;
}Sqstack;
//base==NULL则栈不存在；base==top则栈为空
//对于非空栈，top始终位于栈顶元素的下一位
//注意，栈顶指针的位置不等于栈的大小

//栈的初始化
Status InitStack(Sqstack S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

//获取栈顶元素
SElemType GetTop(Sqstack S){
    if (S.top == S.base)
        return ERROR;

    return *(S.top-1);
}

//入栈操作
//入栈过程中，如果遇到栈满，应首先增加栈的容量
Status Push(Sqstack S, SElemType e){
    if (S.top-S.base >= S.stacksize) {
        S.base = (SElemType *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));

        if (!S.base)
            exit(OVERFLOW);

        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;

    return OK;
}

//出栈操作
Status Pop(Sqstack S, SElemType e){
    if (S.top == S.base)
        return ERROR;

    e = *(S.top-1);
    S.top--;
}


//清空栈内数据
void ClearStack(Sqstack S){
    if (S.top == S.base)
        exit(ERROR);
    else
        S.top = S.base;
    }

//删除栈
void DestroyStack(Sqstack S){
    free(S.base);
}

//括号匹配检验
void bracket_check(Sqstack S){
    InitStack(S);
    SElemType bracket, e;
    bracket = getchar();
    Push(S, bracket);
    while (S.top != S.base)
    {
        bracket = getchar();
        if (bracket == *(S.top-1))
        {
            Pop(S, e);
        }
        else
        {
            Push(S, bracket);
        }
    }
}

//行编辑程序
void LineEdit(Sqstack S){
    InitStack(S);
    SElemType ch = getchar(), c;

    while (ch != EOF)
    {
        while (ch != EOF && ch != '\n'){
            switch (ch)
            {
            case '#': Pop(S, c);
                break;
            case '@': ClearStack(S);
                break;
            default: Push(S, ch);
                break;
            }
            ch = getchar();
        }
        ClearStack(S);
        if (ch != EOF)
            ch =getchar();        
    }
    DestroyStack(S);
}