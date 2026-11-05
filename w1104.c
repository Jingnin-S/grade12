#include<stdio.h>

#include<malloc.h>
#include "string.h"


#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0



typedef char TElemType;

#define MAXQSIZE 100


typedef int Status;



typedef struct Tnode{

TElemType data;

struct Tnode *leftchild;

struct Tnode *rightchild;

}TNode, *BiTree;  
typedef struct 
{
   BiTree *base;   
   int front;                   
   int rear;                   
}SqQueue;
Status InitQueue(SqQueue *Q)
{
    Q->base=(BiTree *)malloc(MAXQSIZE*sizeof(BiTree));
    if(!Q->base)
        return ERROR;
    Q->front=Q->rear=0;
    return OK;
}
Status QueueEmpty(SqQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

Status EnQueue(SqQueue *Q,BiTree e)
{
    if((Q->rear+1)%MAXQSIZE==Q->front)
        return ERROR;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    return OK;
}
Status DeQueue(SqQueue *Q,BiTree *e)
{
    if(Q->front==Q->rear)
        return ERROR;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;
    return OK;
}

//根据先序扩展序列构建二叉链表

//a[ ]为先序扩展序列数组，n为数组长度

//

int count=0;

Status CreateBiTree1(BiTree *T, char a[], int n)

{
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
    if(T)
    {
        printf("%c",T->data);
        PrintBiTree(T->leftchild);
        PrintBiTree(T->rightchild);
    }


}



//按层序遍历打印二叉树

void LevelOrderTraverse(BiTree T)

{
SqQueue Q;
    BiTree a;
    if(T)
    {
        InitQueue(&Q);
        EnQueue(&Q,T);
        while(!QueueEmpty(Q))
        {
            DeQueue(&Q,&a);
            printf("%c",a->data);
            if(a->leftchild)
                EnQueue(&Q,a->leftchild);
            else if(a->rightchild)
                EnQueue(&Q,a->rightchild);
        }
    }


} 



//自行补充循环队列的基本操作（初始化，入队列，出队列，取队头元素，判空等）



int main()

{
    BiTree T;
    char a[100];
    scanf("%s",a);
    int n;
    n=strlen(a);
    CreateBiTree1(&T,a,n);
    LevelOrderTraverse(T);




}



