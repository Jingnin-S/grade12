#include<stdio.h>
#include <string.h>
#include<malloc.h>



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
        (*T)=ERROR;
        count++;
        t=1;
    }
    else
    {
        (*T)=(BiTree)malloc(sizeof(TNode));
        if(!(*T))
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
        printf("%d",T->data);
        PrintBiTree(T->leftchild);
        PrintBiTree(T->rightchild);
    }
    else
        return ;


}



// 打印从根结点到叶子结点的所有路径

void printAllPaths(BiTree T)

{
    int top=0;
    BiTree b[20];
    BiTree p=T,q=NULL;
    while(p||top!=0)
    {
        if(p)
        {
            b[++top]=p;
            p=p->leftchild;
        }
        else if(top>0)
        {
            p=b[top];
            if(p->rightchild==q||!(p->rightchild))
            {
                if(!p->rightchild&&!p->leftchild)
                {
                    for(int i=1;i<=top;i++)
                    {
                        printf("%c",b[i]->data);
                    }
                    printf("\n");
                }
                top--;
                q=p;
                p=NULL;
            }
            else
            {
                p=p->rightchild;
            }
        }
    }






} 



int main()

{
    char a[100];
    gets(a);
    int n=strlen(a);
    BiTree T;
    CreateBiTree1(&T,a,n);
    printAllPaths(T);
    return 0;



}