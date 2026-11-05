#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#include <math.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int SElemType;  
typedef int Status;

typedef struct L_node{
     SElemType     data;  //data field
     struct L_node  *next;   //pointer field
}LNode, *LinkList;

 

typedef struct{
   LinkList  top;  //head pointer
   int  length;  //length
}LinkStack;

 

//========================================== 

// initialization of linked list based stack

//=========================================== 

Status InitStack(LinkStack *S)
{
    S->top=(LinkList*)malloc(sizeof(LNode));
    if(!S->top)
        return FALSE;
    S->top=NULL;
    S->length=0;
    return OK;
   

}

 

//========================================

//Test empty stack

//========================================

Status StackEmpty (LinkStack S)
{
    if(S.length==0)
        return OK;
    else 
        return ERROR;


}

 

//===============================================

// Get the length of a stack

//==============================================

int StackLength (LinkStack S)
{
    return S.length;
                            

}

 

//=====================================

// Get top item of a stack

//====================================

Status GetTop(LinkStack S, SElemType *e)
{
    if (S.top == NULL)
                return 0;
        else
                *e = S.top -> data;
        return OK;
}

 

//===================================================

// Delete an item from the stack

//====================================================

Status Pop(LinkStack *S, SElemType *e)
{
    LinkList p;
    if(S->length==0)
    {
        return 0;
    }
    else
    {
        *e=S->top->data;
        p=S->top;
        S->top=S->top->next;
        free(p);
        S->length--;
        return OK;
    }


}

 

//======================================

// Insert an item into the stack

//=======================================

Status Push(LinkStack *S, SElemType e)
{
    LinkList p=(LinkList*)malloc(sizeof(LNode));
    p->data=e;
    p->next=S->top;
    S->top=p;
    S->length++;
    return OK;
}

 

//======================================

// Print the elements in a stack

//=======================================

void PrintStack (LinkStack S)
{
    LinkList p;
    p=S.top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void num(int num)
{
    LinkStack s;
    SElemType e=0;
    InitStack(&s);
    while(num)
    {
        Push(&s,num%8);
        num=num/8;
    }
    while(!StackEmpty(s))
    {
        Pop(&s,&e);
        printf("%d",e);
    }
    printf("\n");
}
int main()
{
     int n;
    scanf("%d",&n);
    num(n);
}
