#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
typedef int SElemType; 
typedef int Status;

typedef struct
{
    SElemType *base;
    int *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack *S)
{
    S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base)
        exit -1;
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;

}
Status DestroyStack(SqStack *S)
{
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->stacksize=0;
    return OK;
}
Status ClearStack(SqStack *s)
{
    S.top=S.base;
    return OK;
}
Status StackEmpty(SqStack S)
{
    return (S.top==S.base);
}
Status StackLength(SqStack S)
{
    return (S.top-S.base);
}
Status GetTop(SqStack S,SElemType *e)
{
    if(S.top==S.base)
        return ERROR;
    e=*(S.top-1);
    return OK;
}
Status Pop(SqStack *S,SElemType *e)
{
    if(S->top==S->base)
        return ERROR;
    e=*--S->top;
    return OK;

}
Status Push(SqStack *S,SElemType e)
{
    if(S->top-S->base>=S->stacksize)
    {
        S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S->base)
            return ERROR;
        S->top=S->base+S->stacksize;
        S->stacksize+=STACKINCREMENT;
    }
    *S->top++=e;
    return OK;
}
Status StackTraverse(SqStack S,Status (*visit)(ElemType)*p)
{
    for(p=S.base;p<S.top;p++)
    {
        if(!visit*p)
            return ERROR;
    }
    return OK;
} 
Status visit(ElemType e)
{
    printf(¡°The value of the element is %d\n¡±, (int) e);
    return OK;
}




