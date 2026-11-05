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

    //printf("%d\n",L->length);
}



// Sort the elements of sequential list L into ascending order
Status ReverseList_Sq(SqList *L)
{    
    int i,t,j;
    j=L->length-1;
    for(i=0;i<(L->length)/2;i++)
    {
       t=L->elem[i];
       L->elem[i]=L->elem[j-i];
       L->elem[j-i]=t; 
    }
   

         

}



//print out all elements

void PrintList_Sq(SqList L)

{ 
    for(int i=0;i<L.length;i++)
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
    //scanf("%d",&t);
    scanf("%d",&k);
    ReverseList_Sq(&L); 
    PrintList_Sq(L);


}