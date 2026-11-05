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
int Delete_L(LinkList *L, int val)
{
    LinkList p,s;
    p=*L;
    int i=0;
    while(p)
    {
        if(p->next==NULL)
            break;
        if(p->next->data==val)
        {
            s=p->next;
            p->next=s->next;
            i++;
        }
        else
        p=p->next;
    }
    return i;
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
    int i,n,val;
    int a[10];
    LinkList L;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(!InitList_L(&L))
        return ERROR;
    CreateList_L(&L,a,n);
    scanf("%d",&val);
    val=Delete_L(&L,val);
    LinkedListPrint(L);
    printf("%d\n",val);
}