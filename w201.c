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



// Search an element in the list, if found, return the position of the element, otherwise return 0; 

int LocateElem_Sq(SqList L, ElemType e)
{    
    
    ElemType *p;
    int i=1; /* i的初值为第1个元素的位序 */
    p=L.elem; /* p的初值为第1个元素的存储位置 */
    while(i<=L.length&&((*p++)!=e))
    ++i;
    if(i<=L.length)
    return i;
    else
    return 0;
}

//print out all elements

void PrintList_Sq(SqList L)

{ 
    ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<=L.length;i++)
        printf("%d",p++);
    printf("\n");
    


}





int main()
{ 
    SqList L;
    int n,p;
    scanf("%d",&n);
    InitList_Sq(&L);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
    CreateList_Sq(&L,a,n);
    int t;
    scanf("%d",&t);
    p=LocateElem_Sq(L, t);
    printf("%d",p);
    
    


}

