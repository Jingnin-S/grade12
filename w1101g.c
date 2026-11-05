#include<stdio.h>
#include "string.h"
#include<malloc.h>
#define OK 1
#define ERROR 0
typedef int TElemType;
typedef int Status;
typedef struct Tnode
{
    TElemType data;
    struct Tnode *leftchild;
    struct Tnode *rightchild;
}TNode,*BiTree;
/*鏍规嵁鍏堝簭鎵╁睍搴忓垪鏋勫缓浜屽弶閾捐〃*/
//a[ ]涓哄厛搴忔墿灞曞簭鍒楁暟缁勶紝n涓烘暟缁勯暱搴�
int count=0;
Status CreateBiTree1(BiTree *T, int a[], int n)
{
    int temp;
    if(count>= n)
        return OK;
    if(a[count]==-1)
    {
        *T=NULL;
        count++;
        return OK;
    }
    (*T)=(BiTree)malloc(sizeof(TNode));
    if(!(*T))
        return ERROR;
    (*T)->data=a[count++];
    if(CreateBiTree1((&(*T)->leftchild),a,n))
        if(CreateBiTree1(&((*T)->rightchild),a,n))
            return OK;
    return ERROR;
}
//鎵撳嵃浜屽弶鏍�
void PrintBiTree(BiTree T)
{
    if(T)
    {
        printf("%d",T->data);
        PrintBiTree(T->leftchild);
        PrintBiTree(T->rightchild);
    }
    else 
        return ;
}
/*姹備簩鍙夋爲鐨勭粨鐐规€绘暟*/
int CountNode(BiTree T)
{
    if(!T)
        return 0;
    if(T)
    {
        count++;
        CountNode(T->leftchild);
        CountNode(T->rightchild);
    }
}
//姹備簩鍙夋爲鐨勯珮搴�
int GetHeight(BiTree T)

{
/* 初始条件: 树T存在。操作结果: 返回T的深度 */
  int i,j;
    if(!T)
        return 0;
    if(T->leftchild)
        i=GetHeight(T->leftchild);
    else
        i=0;
    if(T->rightchild)
        j=GetHeight(T->rightchild);
    else
        j=0;
    return i>j?i+1:j+1;



} 
//姹備簩鍙夋爲鐨勫彾瀛愮粨鐐逛釜鏁�
int CountLeaveNode(BiTree T)
{
    int i,j;
    if(!T)
        return 0;
    if(T->leftchild==NULL&&T->rightchild==NULL)
        return 1;
    i=CountLeaveNode(T->leftchild);
    j=CountLeaveNode(T->rightchild);
    return (i+j);
} 
int main()
{
    BiTree T;
    char a[20];
    scanf("%s",a);
    int n=strlen(a);
    int i,b[n];
    for(i=0;i<n;i++)
    {
        if(a[i]=='#')
            b[i]=-1;
        else
            b[i]=(int)a[i];
    }
    CreateBiTree1(&T,b,n);
    count=0;
    CountNode(T);
    printf("%d\n",count);
    printf("%d\n",CountLeaveNode(T));
    printf("%d\n",GetHeight(T));
}