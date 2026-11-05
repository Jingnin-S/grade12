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



//Get Element

Status GetElem(SqList *L, int i, int *e)

{
    if(i<1||i>L->length){
		printf("位置错误!\n");
		exit(OVERFLOW);
	}
	*e = L->elem[i-1];
	return OK;


}



//Insert

Status ListInsert(SqList *L, int i, int e)

{
    if(i<1||i>L->length+1){
		printf("插入位置有误！\n");
		exit(OVERFLOW);
	}
	if(L->length==L->listsize){
		int *newbase;
		newbase = (int *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase){
			printf("存储空间分配失败！\n");
			exit(OVERFLOW);
		}
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	L->elem[i-1] = e;
	L->length++;
	return OK;


}

// Combine two sequential lists 

Status MergeList_Sq(SqList *a, SqList *b,SqList *c)

{    
    
    int *pa,*pb,*pc,*pa_last,*pb_last;
	
	pa = a->elem; pb = b->elem; pa_last = pa+a->length-1; pb_last = pb+b->length-1;
	c->length = a->length+b->length;//C顺序表示要存储a b两个表中的数据的 所以存储空间应该是二者的和 由此来申请C的存储空间
	c->listsize = c->length;
	
	c->elem = (int *)malloc(c->listsize*sizeof(int));
	if(!c->elem){
		printf("合并后的顺序表申请内存失败！\n");
		exit(OVERFLOW); 
	}
	pc = c->elem;
	
	while(pa<=pa_last&&pb<=pb_last){//归并 
		if(*pa<=*pb){
			*pc++ = *pa++;
		}	
		else{
			*pc++ = *pb++;
		}
	}
	
	while(pa<=pa_last) *pc++ = *pa++;//插入顺序表a剩下的元素 
	while(pb<=pb_last) *pc++ = *pb++;//插入顺序表b剩下的元素
	 
	return OK;
         

}

//print out all elements

void PrintList_Sq(SqList *L)

{ 
    for(int i=0;i<L->length;i++) 
    printf("%d ",L->elem[i]);
	printf("\n");


}



int main()

{ 
    int a_length,b_length;
	SqList a,b,c;
	
	InitList_Sq(&a);
	//printf("第一个顺序表你想输入多少个元素？\n");
	scanf("%d",&a_length);
	int x[a_length];
    for(int i=0;i<a_length;i++)
    {
        scanf("%d",&x[i]);
    }
	CreateList_Sq(&a,x,a_length);
	
	
	InitList_Sq(&b);
	//printf("\n第二个顺序表你想输入多少个元素？\n");
	scanf("%d",&b_length);
	int y[b_length];
    for(int i=0;i<b_length;i++)
    {
        scanf("%d",&y[i]);
    }
	CreateList_Sq(&b,y,b_length);
	
	
    MergeList_Sq(&a,&b,&c);
	PrintList_Sq(&c);

}