#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 50
typedef int Status;
typedef int ElemType;

typedef struct//定义
{
    ElemType *elem;
    //ElemType *e;
    int length;
    int listsize;
}SqList;
SqList L;

Status InitList_Sq(SqList *L)
{
   L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L->elem)  
   return ERROR;      //存储分配失败
   L->length=0;                     //空表长度为0
   L->listsize=LIST_INIT_SIZE;      //初始存储容量
   return OK;
}//初始化
Status DestroyList_Sq(SqList *L){//销毁
    if(L->elem)   free(L->elem); // 释放分配的存储空间  
    L->elem=NULL; 
    L->length=0;                 
    L->listsize=0; 
    return OK;
}
Status ClearList_Sq(SqList*L)//清空
{
    L->length=0;
    return OK;

}
Status ListEmpty_Sq(SqList *L)//判空
{
    return (L->length==0);
}
int  ListLength_Sq(SqList *L)//求长度
{
    return (L->length);                             
}
Status GetElem_Sq(SqList *L,int i, ElemType *e)//取值
{
    if(i<1||i>L->length+1)
        return ERROR;
    e=L->elem[i-1];
    return OK;
}
int LocateElem_Sq(SqList *L,ElemType e,Status(*compare)(ElemType,ElemType))//查找
{
    for(int i=0;i<L->length;i++)
    {
        if(L->elem[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}
Status PriorElem_Sq (SqList *L, ElemType cur_e, ElemType *pre_e, Status(*compare)(ElemType,ElemType))
{
   for(int i =1; i <=L->length; i ++)
   {
        if((*compare)(L->elem [i-1],cur_e) && (i!=1)) 
        {
            pre_e=L->elem[i-2];
            return OK;
	    }
   }
   return ERROR;
}//找前驱
Status NextElem_Sq (SqList *L, ElemType cur_e, ElemType *next_e, Status(*compare)(ElemType,ElemType))
{
    int i =1;  
    int p=L->elem;
    while((i<=L->length)&&!(*compare)(p++,cur_e))  i++; 
    if((i>1) && (i<L->length))
    {
	next_e=L->elem[i]; 
	return OK;
    }
    else 
      return ERROR;
} // 找后继

Status ListInsert_Sq(SqList *L,int i, ElemType e)
{
    if(i<1||i>L->length+1)  
    {
        return ERROR;
    }    
   if(L->length>=L->listsize)
   {                       //当前存储空间已满,增加分配
    int newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)* sizeof(ElemType));
    if(!newbase) 
    {
        return ERROR;      //存储分配失败
    }
    L->elem=newbase;                               //新基址
    L->listsize+=LISTINCREMENT;       //增加存储容量
}//插入
Status ListDelete_Sq(SqList *L,int i,ElemType *e)
{
    if(i<1 || (i>L->length))
    {
        return ERROR;     //i值不合法
    }
    p=&(L->elem[i-1]);                                 //p为被删除元素的位置
    e=*p;                                                     //被删除元素的值赋给e
    q=L->elem+L->length-1;                          //表尾元素的位置
    for(++p; p<=q; ++p)  
    {
        *(p-1)=*p;          //被删除之后的元素前移
    }
    --L->length;                                            //表长减1
    return OK;
}//删除
Status ListTraverse (SqList L, Status (*visit)(ElemType)) 
{
      for(i=1;i<=L->length;i++)
          if(!visit(L->elem[i-1])) 
          return ERROR;
}// 遍历1
Status visit(ElemType e){
    printf(" The value of the element is %d\n", (int)e);
}//遍历2



    






