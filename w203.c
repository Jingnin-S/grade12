#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE  0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define INIT_SIZE 100
#define LISTINCREMENT 10  
typedef int ElemType;

typedef struct{

    ElemType *elem;

    int length;

    int listsize;

}SqList;

// Create an empty list

Status InitList_Sq(SqList *L)

{
    (*L).elem=(ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
   exit(OVERFLOW);
   (*L).length=0; 
   (*L).listsize=INIT_SIZE; 
   return OK;


}



//Create an array based list with n elements

Status CreateList_Sq(SqList *L, int a[], int n)

{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        L->elem[i]=a[i];
        L->length++;
    }


}



// Insert the elements into the sequential list L at specific position

Status InsertList_Sq(SqList *L, int i, ElemType e)

{    
    ElemType *newbase,*q,*p;
    if(i<1||i>(*L).length+1) /* i值不合法 */
    return ERROR;
    if((*L).length>=(*L).listsize) /* 当前存储空间已满,增加分配 */
    {
        newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW); /* 存储分配失败 */
        (*L).elem=newbase; /* 新基址 */
        (*L).listsize+=LISTINCREMENT; /* 增加存储容量 */
    }
    q=(*L).elem+i-1; /* q为插?9?2位置 */
    for(p=(*L).elem+(*L).length-1;p>=q;--p) /* 插?9?2位置及之后的元素右移 */
        *(p+1)=*p;
    *q=e; /* 插?9?2e */
    ++(*L).length; /* 表?9?7增1 */
    return OK;
         

}

//print out all elements

void PrintList_Sq(SqList L)

{ 
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%d ",L.elem[i]);
    }


}





int main()



{ 
    int t,n,i,k;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    SqList L;
    InitList_Sq(&L);
    CreateList_Sq(&L,a,n);
    scanf("%d",&t);
    scanf("%d",&k);
    InsertList_Sq(&L,k,t);
    PrintList_Sq(L);


}

