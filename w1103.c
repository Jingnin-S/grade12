#include<stdio.h>
#include<malloc.h>
#include "string.h"
#define OK 1
#define ERROR 0
typedef char TElemType;
typedef int Status;
typedef struct Tnode{
TElemType data;

struct Tnode *leftchild;

struct Tnode *rightchild;
}TNode, *BiTree;  

//根据先序扩展序列构建二叉链表

//a[ ]为先序扩展序列数组，n为数组长度

//

int count=0;


Status CreateBiTree1(BiTree *T, char a[], int n)

{
    int t=0;
    if(count>=n)
        return OK;
    if(a[count]=='#')
    {
        *T=NULL;
        count++;
        t=1;
    }
    else
    {
        (*T)=(BiTree)malloc(sizeof(TNode));
        if(!*T)
            return ERROR;
        (*T)->data=a[count];
        count++;
        t=1;
        CreateBiTree1(&((*T)->leftchild),a,n);
        CreateBiTree1(&((*T)->rightchild),a,n);
    }
    return OK;


} 



//打印二叉树

void PrintBiTree(BiTree T)

{
    if(T)
    {
        printf("%c",T->data);
        PrintBiTree(T->leftchild);
        PrintBiTree(T->rightchild);
    }


}



//求二叉树的最大层次

//参数maxlevel 返回二叉树的最大层次

void malLevel(BiTree T,int level,int *maxLevel)
{
    if(!T)
    {
        if(level>*maxLevel)
            *maxLevel=level;
        level=0;
        return ;
    }
    level++;
    malLevel(T->leftchild,level,maxLevel);
    malLevel(T->rightchild,level,maxLevel);


} 



int main()

{
    BiTree T;
    char a[100];
    scanf("%s",a);
    int n=strlen(a);
    
    
    CreateBiTree1(&T,a,n);
    int level=0,maxlevel=0;
    malLevel(T,level,&maxlevel);
    printf("%d",maxlevel);




}

