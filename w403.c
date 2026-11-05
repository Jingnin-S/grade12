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
Status ListInsert_L(LinkList *L, ElemType e)
{
    LinkList p,s;
    p=*L;
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    while(p)
    {
        if(p->next==NULL)
        {
            s->next=p->next;
            p->next=s;
            break;
        }
        if((p->next->data)>=s->data)
        {
            s->next=p->next;
            p->next=s;
            break;
        }
        p=p->next;
    }
    return OK;
}
Status Listdelete(LinkList *L,int m,int n)
{
    LinkList p,s;
    p=*L;
    while(p)
    {
        if(p->next==NULL)
            break;
        if(p->next->data>m&&p->next->data<n)
        {
            s=p->next;
            p->next=s->next;
            free(s);
        }
        else
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
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{  
    int i,n,m;
    int a[10];
    LinkList L;
    ElemType e;
    if(!InitList_L(&L))
        return ERROR;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateList_L(&L,a,n);
    scanf("%d",&e);
    ListInsert_L(&L,e);
    LinkedListPrint(L);
    scanf("%d %d",&m,&n);
    Listdelete(&L,m,n);
    LinkedListPrint(L);
}