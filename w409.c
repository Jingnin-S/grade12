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
void ReverseLinkList_L(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    (*L)->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=(*L)->next;
        (*L)->next=p;
        p=q;
    }
}
void LinkedListPrint(LinkList L)
{
    LinkList p;
    p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    LinkList L;
    int i,n,a[10];
    if (!InitList_L(&L))
        return ERROR;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateList_L(&L,a,n);
    ReverseLinkList_L(&L);
    LinkedListPrint(L);
}