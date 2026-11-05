#include "stdio.h"
#include "stdlib.h"
#define ERROR -1
#define OK 1
typedef struct Lnode
{
	int data;
 	struct Lnode *next;
}LNode,*LinkList;
/***************链表初始化**********************/
// 创建一个带头结点的单链表
int Initlist(LinkList *L)
{
  	(*L)=(LinkList)malloc(sizeof(LNode));
  	if(L==NULL)
  	{
		  printf("memory malloc failure\n");
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
	LNode *p=L->next;
	for(p;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");

}

/* 递归算法写出求链表的最大值*/
int Get_Max(LinkList L)
{
	//★★★请补全代码
    int max=0;
    LinkList p;
    
    p=L;
    if(!p)
    {
        return ERROR;
    }
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;


}

// 求单链表的长度，并将长度值插入到头节点之后
// 如果成功，返回OK，否则，返回ERROR
int InsertLength(LinkList *L)
{
	//★★★请补全代码
    int i=0;
    LinkList p;
    p=(*L)->next;
    if(!p)
        return ERROR;
    while(p)
    {
        i++;
        p=p->next;
    }
    
    LNode *q=(LinkList)malloc(sizeof(LNode));
    q->next=(*L)->next;
    (*L)->next=q;
    q->data=i;
    return OK;

	
}
/************主函数******************/
int main()
{
	int max;
	LinkList L;
	Initlist(&L);
	ListPrint(L);
	max = Get_Max(L->next);
	printf("maxvalue = %d\n",max);
	InsertLength(&L);
	ListPrint(L);
	
	return 0;
}
