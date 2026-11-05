#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int SElemType;  

typedef int Status;

// definition of array based stack
#define STACK_INIT_SIZE   100          //Initial size for memory allocation
#define STACKINCREMENT  10          //incremental size

typedef struct
{
   SElemType  *base;    //base pointer
   SElemType  *top;      //top pointer
   int        stacksize;     //current size
}SqStack;
//========================================== 

// initialization of array-based stack

//=========================================== 

Status InitStack(SqStack *S)
{
    S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base)
        return ERROR;
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}

 

//========================================

//Test empty stack

//========================================

Status StackEmpty (SqStack *S)
{
    if(S->top==S->base)
        return TRUE;
    else
        return FALSE;

}

 

//===============================================

// Get the length of a stack

//==============================================

int StackLength (SqStack S)
{
    return (S.top-S.base);
}

 

//=====================================

// Get top item of a stack

//====================================

Status GetTop(SqStack S)
{
    int e;
    if(S.top==S.base)
        return ERROR;
    e=*(S.top-1);
    return e;
}

 

//===================================================

// Delete an item from the stack

//====================================================

Status Pop(SqStack *S,SElemType *e)
{
    if(S->top==S->base)
        return ERROR;
    e=*--S->top;
    return OK;
 

}

 

//======================================

// Insert an item into the stack

//=======================================

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

 

//======================================

// Print the elements in a stack

//=======================================

void PrintStack (SqStack S)
{
    int n=StackLength(S);
    SqStack e;
    for(int i=0;i<n;i++)
    {
        printf("%d ",GetTop(S));
        Pop(&S,&e);
    }

}

 

//======================================

// 逆序输出堆栈的所有元素，并返回输出元素的个数

//=======================================

int  reverseOutput(SqStack S)

{
    PrintStack(S);
    printf("\n");
    printf("%d",StackLength(S));

}



int main()  

{  
    int i,n;
    SqStack S,e;
    InitStack(&S);
    //StackEmpty(&S);
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        Push(&S,a[i]);
    }
    int p=StackLength(S);
    for(i=0;i<n;i++)
    {
        printf("%d ",GetTop(S));
        Pop(&S,&e);
    }
    //PrintStack(&S);
    printf("\n");
    printf("%d",p);

    




 } 