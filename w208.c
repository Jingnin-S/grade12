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
    int i=0;
    for(i=0;i<n;i++)
    {
        L->elem[i]=a[i];
        L->length++;
    }

    //printf("%d\n",L->length);
}



// Sort the elements of sequential list L into ascending order
Status DeleteList_Sq(SqList *L, int i, ElemType *e)
{
    ElemType *p,*q;
    if(i<1||i>(*L).length) /* i值不合法 */
        return ERROR;
    p=(*L).elem+i-1; /* p为被删除元素的位置 */
    *e=*p; /* 被删除元素的值赋给e */
    q=(*L).elem+(*L).length-1; /* 表尾元素的位置 */
    for(++p;p<=q;++p) /* 被删除元素之后的元素左移 */
        *(p-1)=*p;
    (*L).length--; /* 表?9?7减1 */
    return OK;
    

         

}



//print out all elements

void PrintList_Sq(SqList *L)

{ 
    for(int i=0;i<L->length;i++)
    {
        printf("%d ",L->elem[i]);
    }


}





int main()



{ 
    int t,n,i,k,h;
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
    for(i=t;i<k;i++)
    {
    DeleteList_Sq(&L,t,&h);
    }
    PrintList_Sq(&L);


}