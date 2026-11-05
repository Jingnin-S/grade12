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
int Initlist(LinkList *L)
{
  	(*L)=(LinkList)malloc(sizeof(LNode));
  	if(L==NULL)
  	{
		  printf("内存创建失败\n");
  		  return ERROR;
  	}
  	(*L)->next=NULL;
    //根据键盘值构造链表
	LinkList r;
	r=*L;
	int x;
	int i;
	for(i=0; ; i++)
	{
		scanf("%d",&x);
		if(x==-1)
		break;
		LNode *p=(LinkList)malloc(sizeof(LNode));
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
    p=L->next;
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
    LinkList p;
    int i=0;
    p=L->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

/****************查找最小值结点，并删除最小值结点*********************/
/* 删除的最小结点值通过参数e 返回，其位置通过参数pos返回 */
int DeleteMinValue (LinkList *L, int *e, int *pos)
{
	//★★★请补全代码
	if((*L)->next==NULL)
    {
        return ERROR;
    }
	int a=(*L)->next->data;
    int i=1,k=1;
    LinkList q=(*L);
	LinkList p=(*L)->next->next;
	while(p!=NULL)
    {
        i++;
        if(a>p->data)
        {
            a=p->data;
            k=i;
            q=p;
        }
        p=p->next;
    }
    p=(*L);
    while(p->next!=q)
    {
        p=p->next;
    }
    p->next=q->next;
    free(q);
    (*e)=a;
    (*pos)=k;
    return OK;


}

/************主函数******************/
int main()
{
	int length;
	int min,pos;
	LinkList L;
	Initlist(&L);
	ListPrint(L);
	length=ListLength(L);
	printf("%d\n",length);
	DeleteMinValue(&L,&min,&pos);
    printf("%d %d\n",min, pos);
	ListPrint(L);
	return 0;
}
