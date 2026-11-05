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

   LinkList  Head;  //head pointer

   int  length;  //length

}LinkStack;
//========================================== 

// initialization of linked list based stack

//=========================================== 

Status InitStack(LinkList *S)
{
    (*S)->data=(SElemType*)malloc(100*sizeof(SElemType));
    if(!(*S)->data)
        return 0;
    //(*S)->next=NULL;
    return OK;
}

 

//========================================

//Test empty stack

//========================================

Status StackEmpty (LinkList S)
{
    if(!S->next)
     return TRUE;


}

 

//===============================================

// Get the length of a stack

//==============================================

int StackLength (LinkList S)
{
    int i=0;
    while(S->next)
    ++i;
    return i;
                            

}

 

//=====================================

// Get top item of a stack

//====================================

Status GetTop(LinkList S)
{
    if(S!=NULL)
        return (S->data);


}

 

//===================================================

// Delete an item from the stack

//====================================================

Status Pop(LinkList *S, SElemType *e)
{
    if(S==NULL)
        return ERROR;
    e=(*S)->data;
    LinkList p;
    p=(*S);
    S=(*S)->next;
    free(p);
    return OK;
}

 

//======================================

// Insert an item into the stack

//=======================================

Status Push(LinkList *S, SElemType e)
{
    LinkList p;
    p=(SElemType*)malloc(10*sizeof(SElemType));
    p->data=e;
    p->next=S;
    S=p;
    return OK;

}

 

//======================================

// Print the elements in a stack

//=======================================

void PrintStack (LinkList S)
{
    int n=StackLength(S);
    LinkList e;
    for(int i=0;i<n;i++)
    {
        printf("%d ",GetTop(S));
        Pop(&S,&e);
    }
}




//======================================

// 删除堆栈中值为x的元素（可能有多个），返回堆栈的长度

//=======================================

int DeleteElem(LinkList *S, SElemType x)
{
    LinkStack p;
    while((*S)->next)
    {
    if((*S)->data==x)
    {
        Pop(&S,&p);
    }
    }
    return StackLength(S);
    

}

int main()  

{  
    int n,i,x;
    LinkList S;
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
    DeleteElem(&S,x);
    PrintStack(S);







} 