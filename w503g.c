#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
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




//======================================

// 删除堆栈中值为x的元素（可能有多个），返回堆栈的长度

//=======================================

int DeleteElem(LinkStack *S, SElemType x)

{
    LinkList p,s;
    p=S->top;
    while(p)
    {
        if(p->next==NULL)
            break;
        if(p->next->data==x)
        {
            s=p->next;
            p->next=s->next;
            free(s);
            S->length--;
        }
        else
            p=p->next;
    }
    return (S->length);
}

int main()  

{  
    int n,i,x;
    LinkStack S;
    if(!InitStack(&S))
        return ERROR;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        Push(&S,a[i]);
    }
    scanf("%d",&x);
    x=DeleteElem(&S,x);
    PrintStack(S);
    printf("%d",x);

} 