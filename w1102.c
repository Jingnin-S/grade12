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
int temp=1;
if(count>=n)
        return OK;
    if(a[count]=='#')
    {
        *T=NULL;
        count++;
    }
    else
    {
        (*T)=(BiTree)malloc(sizeof(TNode));
        if(!*T)
            return ERROR;
        (*T)->data=a[count];
        count++;
        
        CreateBiTree1(&((*T)->leftchild),a,n);
        CreateBiTree1(&((*T)->rightchild),a,n);
    }
    return OK;

} 



//打印二叉树

void PrintBiTree(BiTree T)

{
    if(!T)
        return ;
    printf("%c",T->data);
    PrintBiTree(T->leftchild);
    PrintBiTree(T->rightchild);

}



//求二叉树的双亲结点值

//参数 parent 为双亲结点的值，flag为查找成功标志，flag=1,  找到双亲，flag=0, 未找到双亲

int CountNode(BiTree T,TElemType e, TElemType *parent, int *flag)

{
    if(!T)
        return ERROR;
    if(T->leftchild!=NULL)
    {
        if(T->leftchild->data==e)
        {

            *flag=1;
            *parent=T->data;
            return OK;
        }
    }
    else if(T->rightchild!=NULL)
    {
        if(T->rightchild->data==e)
        {
            *parent=T->data;
            *flag=1;

            return OK;
        }
    }
    else{
    CountNode(T->leftchild,e,parent,flag);
    CountNode(T->rightchild,e,parent,flag);
    }
    return 1;
} 



int main()

{
    BiTree T;
    char a[100];
    gets(a);
    int n=strlen(a);
    CreateBiTree1(&T,a,n);
    TElemType e,parent;
    int flag=0;
    
    scanf("%c",&e);
    
    CountNode(T,e,&parent,&flag);
    if(flag==1)
        printf("%c",parent);
    else
        printf("no parent\n");
}