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
void Merge_L(LinkList *La,LinkList *Lb, LinkList *Lc)
{
    LinkList pa,pb,pc;
    pa=(*La)->next;
    pb=(*Lb)->next;
    pc=*Lc=*La;
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    if(pb)
        pc->next=pb;
    else if(pa)
        pc->next=pa;
    free(*Lb);
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
    LinkList La,Lb,Lc;
    int n,i;
    int a[10];
    if((!InitList_L(&La))||(!InitList_L(&Lb))||(!InitList_L(&Lc)))
        return ERROR;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateList_L(&La,a,n);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateList_L(&Lb,a,n);
    Merge_L(&La,&Lb,&Lc);
    LinkedListPrint(Lc);
}