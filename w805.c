#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define OK 1
#define ERROR 0
#define INIT_SIZE 100
#define LISTINCREMENT 10  
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN];
typedef int Status; 
typedef int ElemType;
typedef char SElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
Status InitList_Sq(SqList *L)
{
    (*L).elem=(ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem)
    exit(-2);
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
void PrintList_Sq(SqList L)
{ 
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.elem[i]);
    }
}
Status StrAssign(SString T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSTRLEN)
        return ERROR;
    else{
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
        }
        return OK;
    }
}
void StrPrint(SString S)
{
        int i;
        for(i=1;i<S[0];i++)
        {
            printf("%c",S[i]);

        }
        printf("\n");
}

void Max(SString s,int *i,int *j)
{
    int idx,max=1;
    char c=s[0];
    i=0;j=1;
    for (idx = 1; s[idx] != '\0'; idx++) 
    {
		if (c == s[idx])	//当字符串连续相同时记录长度
			max++;
		else if (max > j) 
        {	//当当前连续子串比最长子串要长时，改变i和j的值
			i = idx - max;
			j = max;
			max = 1;
		}
		else 
        {	//否则清空长度
			max = 1;
		}
		c = s[idx];
	}
	if (max > j) 
    {	//判断最后一个连续串
		i = idx - max;
		j = max;
	}
}
int main()
{
    int i,j;
    SString S;
    char c[MAXSTRLEN+1];
    gets(c);
    if(!StrAssign(S,c))
    {
        printf("error");
        exit(0);

    }
    Max(S,&i,&j);
    printf("%d %d",i,j);
    /*for(int g=i;g<j;g++)
    {
        printf("%c",S[g]);
    }*/
}