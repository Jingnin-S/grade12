#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>

 

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;  
typedef int Status;

 

 

// definition of node structure of singly linked list

typedef struct L_node

{  

    ElemType data;           // data field
    struct node *next;       // pointer field
}LNode, *LinkList;

 

//========================================== 

// initialization of singly linked list L with head node

//=========================================== 

Status InitList_L(LinkList *L)

{
    
    L=(LinkList)malloc(sizeof(LNode)); /* 产�9�1头结点,并使L指向此头结点 */
    if(!*L) /* 存储分配失败 */
    exit(-1);
    (*L)->next=NULL; /* 指针域为空 */
    return OK;

}



 

//===========================================

// Create a singly linked list L with head node, and with n elements

//===========================================

Status CreateList_L(LinkList *L, int a[ ],  int n)

{
    
    //p=(struct node*)malloc(sizeof(LNode));
    

    for(int i=0;i<n;i++)
    {
        
        L[i]->data=a[i];
        L[i]->next=L[i+1];

    }
}

 

//=========================================

// Get the length of a singly linked list with head node

//=========================================

int ListLength_L(LinkList L)
{

 int i=0;
    LinkList p = L;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;

 }

 

//========================================

// Get the ith element of a singly linked list

//========================================

Status GetElem_L (LinkList L, int  i,  ElemType *e)
{
    LinkList p = L;
    int j=1;
    while(p->next)
    {
        if(j==i)
        {
            //printf("%d",L->date);
            return p;
        } 
        j++;  
    }
    return -1;

}

 

//===============================================

// search for an element in a singly linked list and return its position starting from 1

//==============================================

int LocateElem_L (LinkList L, ElemType e)

{
    int i=0;
    LinkList p = L;
    while(p->next)
    {
        if(p->data==e)
        return i;
        ++i;
    }
    return -1;

}

//=====================================

// Insert element e at the ith position of a singly linked list

//====================================

Status ListInsert_L(LinkList *L, int i, ElemType e)

{
    LinkList p=L;
    LinkList c=NULL;
    int j;
    for(j=0;j<i;j++)
    {
        if(p==NULL)
        return L;
        p=p->next;
    }
    c=(LinkList *)malloc(sizeof(LNode));
    c->data=e;
    c->next=p->next;
    p->next=c;
    return L;
  

}

 

//===================================================

// Delete the ith elment from the list

//====================================================

Status ListDelete_L(LinkList *L,int i,ElemType *e)

{
    LinkList p=L;
    int j=0;
    while((p->next)&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1)
    return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    free(q);
    return L;
  

}

 

//======================================

// Print the elements in a list

//=======================================

void LinkedListPrint(LinkList L)

{
    LinkList p=L;
    while(p->next)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

 

int main()  

{  
    LNode *L=NULL;
    int n,i,*e,x,y,z,q,m;
    InitList_L(L);
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]); 
    }
    CreateList_L(L,a,n);
    LinkedListPrint(L);
    scanf("%d",&x);
    GetElem_L (&L,x,&e);
    scanf("%d %d",&y,&z);
    ListInsert_L(&L,y,z);
    LinkedListPrint(L);
    scanf("%d",&q);
    ListDelete_L(&L,q,&e);
    LinkedListPrint(L);
    scanf("%d",&m);
    LocateElem_L (&L,m);


} 