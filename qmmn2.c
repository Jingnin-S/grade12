#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType; 
typedef int Status;
#define OK 1
#define ERROR 0
typedef struct
{
	ElemType *elem;  //顺序表的存储基地址
	int length;        //顺序表的长度
	int listsize;       //顺序表的容量
} SqList;

//初始化顺序表
//如果操作成功，返回OK，否则返回ERROR
Status Initlist(SqList *L)
{
L->elem = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
	if (!L->elem) return ERROR;
	L->length = 0;
	L->listsize = INIT_SIZE;
	return OK;
}

//创建长度为n的顺序表
void Createlist(SqList *L, int n)//输入函数
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L->elem[i]);
	}
	L->length = n;
}

//遍历顺序线性表并输出所有元素
void Print_Sq(SqList L)
{
//★★★请补全代码
    int i=0;
    for(i=0;i<L.length;i++)
    {
        printf("%d ",L.elem[i]);
    }

}

//删除顺序表L中最小值元素，通过参数value返回该最小值，并将顺序表的最后一个元素填补到空出的位置。 
//若删除成功，则函数返回值为OK，否则返回ERROR
Status delMin(SqList *L, ElemType *value)
{
//★★★请补全代码
    if(L->listsize==0)
        return 0;
    int min=100;
    int i,k=0;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]<min)
        {
            min=L->elem[i];
            *value=min;
            k=i;
        }
    }
    if(k!=L->length-1)
    {
    L->elem[k]=L->elem[L->length-1];
    L->elem[L->length-1]=NULL;
    L->length--;
    return OK;
    }
    else
    {
        L->elem[L->length-1]=NULL;
        L->length--;
        return OK;
    }

}


int main( )
{
	int m;
	SqList Lq;
	int min;
	printf("请依次输入表A的元素个数\n");
	scanf("%d", &m);
	Initlist(&Lq);
	printf("请依次输入表A中的元素\n");
	Createlist(&Lq, m);

	if (delMin(&Lq, &min) == OK)
	{
		printf("删除的最小元素为：%d\n", min);
		Print_Sq(Lq);
	}
	else
	{
	   printf("删除失败");
	
	}
	return 0;
}
