#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

#define ERROR -1
#define OK 1

typedef struct Lnode
{
	int data;
 	struct Lnode *next;
}LNode,*LinkList;

/***************链表初始化**********************/
int InitList(LinkList *L)
{
  	*L=(LinkList)malloc(sizeof(LNode));
  	if(L==NULL)
  	{
		  printf("内存创建失败\n");
  		  return ERROR;
  	}
  	(*L)->next=NULL;
    //根据键盘值构造链表
	LinkList r;
	r=L;
	int x;
	int i;
	for(i=0;;i++)
	{
		scanf("%d",&x);
		if(x==-1)
		break;
		LinkList p=(LinkList)malloc(sizeof(LNode));
		if(!p) 
		{
			printf("初始化失败");
		    return ERROR;
		}
		p->data=x;
		p->next= NULL;
		r->next=p;
		r=p;
	}
 	return OK;
}
/******************打印单链表*****************/
void ListPrint(LinkList L)
{
	//★★★请补全代码
	LinkList p;
    p=(*L).next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
/****************求单链表的长度******************/
int ListLength(LinkList L)
{
	//★★★请补全代码
    int i=0;
    LinkList p;
    p=(*L).next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i+1;
}

/*********元素交换*********************/
int Exchange(LinkList *L)
{
	//★★★请补全代码
	LinkList p,q,r;
    p=(*L)->next;
	int t,a=p->data;
    q=p;
    int i,j=ListLength(L);
    if(j%2==0)
    {
        while ((j/2)>1)
        {
            q=q->next;
            j--;
        }
        printf("%d %d",p->data,q->data);
		int b=q->data;
		t=a;
		a=b;
		b=t;
       
    }
    else
    {
        while ((j/2)+1>1)
        {
            q=q->next;
            j--;
        }
        printf("%d %d",p->data,q->data);
		int b=q->data;
		t=a;
		a=b;
		b=t;
    }
    return OK;
}

/************主函数******************/
int main()
{
	int length;
	LinkList L;
	InitList(&L);
	ListPrint(L);
	length=ListLength(L);
	printf("%d\n", length);
	Exchange(&L);
	ListPrint(L);
	return 0;
}
