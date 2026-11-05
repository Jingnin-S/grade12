#include "stdio.h"
#include "stdlib.h"   

#define OK 1
#define ERROR 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

//==========================
//打印单链表
//==========================
void ListTraverse(LinkList L)
{
    LinkList p=L->next;

    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
//=======================================
//初始化单链表
//=======================================
Status InitList(LinkList *L) 
{ 

/***补全函数***/
    *L=(LinkList)malloc(sizeof(Node));
  	if(*L==NULL)
  	{
		  printf("内存创建失败\n");
  		  return ERROR;
  	}
  	(*L)->next=NULL;
}

int ListLength(LinkList L)
{
    int i=0;
    LinkList p;
    p=L->next;

    while(p!=NULL)                        
    {
        
        p=p->next;
        i++;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
/***补全函数***/
    LinkList p;
    p=(*L).next;
    int j=1;
    while(p&&j<i)
    {
        j++;
        p=p->next;
    }
    while(!p||j>i)
        return ERROR;
    *e=p->data;
    return OK;
    

}

Status ListInsert(LinkList *L, int i, ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;

	while (p && j < i)
	{
		p = p->next;
		j=j+1;
	}

	if (!p || j > i) 
		return ERROR;

	s = (LinkList)malloc(sizeof(Node));
    if(!(s))
        return ERROR;

	s->data = e;  
	s->next = p->next;
	p->next = s;
	return OK;
}
//=========================================================
//求单链表所有元素的累加和，并将该累加和作为一个新的结点插在单链表的尾部
//=========================================================
Status AddSumForChecking(LinkList *L)
{
/***补全函数***/
    int i,a=0;
    Status j;
    LinkList p;
    p=(*L)->next;
    while (p)
    {
        a+=p->data;
        p=p->next;
    }
    //printf("%d\n",a);
    ListInsert(L,6,a);
    return OK;

}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k,l;

    i=InitList(&L);
	if(i==ERROR)
    {
        return 0;
	}

	printf("Please input the length of frame:\n");
	scanf("%d", &k);

	if (k > 0)
        printf("Please input the element of frame one by one:\n");
    for(j=1;j<=k;j++)
	{
	    scanf("%d", &l);
        i=ListInsert(&L,1,l);
	}
    printf("The frame is: ");
    ListTraverse(L); 

    printf("The length of the frame is: %d \n",ListLength(L));

	if(OK==AddSumForChecking(&L))
	{
		GetElem(L, ListLength(L), &e);
		printf("The checksum added is: %d\n", e); 
	    printf("The length of the frame added checksum is: %d \n",ListLength(L));
        printf("The frame added checksum is: ");
        ListTraverse(L);
	}

    return 0;
}
