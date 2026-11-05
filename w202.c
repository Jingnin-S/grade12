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

// Get the maximum element of sequential list L
Status MaxList_Sq(SqList L)
{    
    int i,max=0,k=0;
    int p;
    p=L.elem[0];
    for(i=0;i<L.length;i++)
    {
        if(p<L.elem[i] )
        {
            p=L.elem[i];
            k=i;
        }

    }
    printf("%d %d",p,k+1);

         

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
    MaxList_Sq(L);


}