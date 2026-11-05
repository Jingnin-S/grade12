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
int Bin2Dec_L(LinkList L)
{
    LinkList p,q;
    int i=0,n=0,j=1;
    p=L->next;
    L->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
    p=L->next;
    while(p)
    {
        if(i!=0)
            j=j*2;
        n=(p->data)*j+n;
        p=p->next;
        i++;
    }
    return n;
}
int main()
{
    LinkList L;
    int i,n,a[30];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    if(!InitList_L(&L))
        return ERROR;
    CreateList_L(&L,a,n);
    printf("%d\n",Bin2Dec_L(L));
}