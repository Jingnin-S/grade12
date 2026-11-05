#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;  
typedef int Status;
typedef struct L_node
{
    ElemType data;           // data field
    struct L_node *next;       // pointer field
}LNode, *LinkList;
Status InitList_L(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(LNode));
    if(!*L)
        return 0;
    (*L)->next=NULL;
    return OK;
}
Status CreateList_L(LinkList *L,int a[],int n)
{
    int i;
    LinkList p;
    for(i=n-1;i>=0;i--)
    {
        p=(LinkList)malloc(sizeof(LNode));
        if(!p)
            return ERROR;
        p->data=a[i];
        p->next=(*L)->next;
        (*L)->next=p;
    }
    return OK;
}
int GetMax(LinkList L)
{
    LinkList p;
    ElemType a;
    p=L->next;
    a=p->data;
    while(p)
    {
        if(p->data>a)
            a=p->data;
        p=p->next;
    }
    return a;
}
int isAscendingOrder (LinkList  L)
{
    LinkList p;
    ElemType a;
    p=L->next;
    while(p)
    {
        if(p->next==NULL)
            break;
        a=p->data;
        if(p->next->data<a)
            return 0;
        p=p->next;
    }
    return OK;
}
void LinkedListPrint(LinkList L)
{
    LinkList p;
    p=L->next;
    while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
int main()
{  
    int n,i;
    int a[10];
    LinkList L;
    if(!InitList_L(&L))
        return ERROR;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateList_L(&L,a,n);
    printf("%d\n",GetMax(L));
    printf("%d",isAscendingOrder(L));
} 