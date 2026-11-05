#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define LIST_size 100
typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
LNode *p;
int j;
Status InitList(LinkList *L,ElemType data)
{
    L=(LinkList)malloc(sizeof(LNode));		//此处注意强制类型转换
    if(!*L)
    return ERROR;
    *L->next=NULL;
    return OK;
}//初始化
Status ListEmpty_L(LinkList L)
{
    return (L->next==NULL);                             
}// 判空
int  ListLength_L(LinkList L)
{
    p=L->next;        //p指向第一个结点
    int i=0;             
    while(p)
    {           //遍历单链表,统计结点数
       i++;
       p=p->next;
    } 
    return i;                             
}// 求长度

Status GetElem(LinkList L,int i,ElemType *e)
{
    p=L->next;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;

    }
    if(!p||j>i)
    return ERROR;

    e=p->data;
    return OK;
    
}//取值
LNode *LocateElem(LinkList L,ElemType e)
{
    p=L->next;
    while(p&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}//查找
 Status PriorElem_L (LinkList L, ElemType cur_e, ElemType *pre_e,Status(*compare)(ElemType,ElemType))
 {
    p=L; j=1;
    while(p->next && !(*compare)(p->next->data,cur_e))
    {
        p=p->next; 
        j++;
    }
    if(!p->next || j==1)  return ERROR;
    pre_e=p->data;
    return OK;
}  // 找前驱
Status NextElem_L (LinkList L, ElemType cur_e,  ElemType *next_e,Status(*compare)(ElemType,ElemType)){
    p=L->next; 
    while(p && !(*compare)(p->data,cur_e))
        p=p->next; 
    }
    if(!p||!p->next)  
        return ERROR;
    
    next_e=p->next->data;
    return OK;
}//找后继

Status ListInsert(LinkList *L,int i,ElemType e)
{
    p=L;
    j=0;
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
    {
        return ERROR;
    }
    s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}//插入

Status ListDelete(LinkList *L,int i)
{
    p=L;
    j=0;
    while(p->next && j<i-1)
    {                   //寻找第i个结点,并令p指向其前驱 
      p=p->next;
      ++j;
    }
   if(!(p->next && j<i-1) 
   return ERROR;  //删除位置不合理
   q=p->next; 
   p->next=q->next;           //删除并释放结点
   e=q->data; 
   free(q);
   return OK;
}//删除
void  ListTraverse_L (LinkList L, Status (*visit)(ElemType)) {
    p=L->next;
    while(p)
    {
      visit(p->data); p=p->next;
    }
 }// ListTraverse_L
 
 Status visit(ElemType e)
{
    printf("The value of the element is %d\n", (int) e);
    return OK;
}




