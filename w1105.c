#include<stdio.h>

#include<malloc.h>
#include <string.h>


#define OK 1

#define ERROR 0



typedef int TElemType;



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

Status CreateBiTree1(BiTree *T, int a[], int n)

{
if(count>=n)
        return OK;
    if(a[count]==-1)
    {
        (*T)=ERROR;
        count++;
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
        printf("%d ",T->data);
        PrintBiTree(T->leftchild);
        PrintBiTree(T->rightchild);
    }


}



//求二叉树的所有路径的数字之和

//参数totalSum为所有路径的总和

void sumofAllPaths(BiTree T,int sum,int *totalSum)

{
    if(T)
    {
        if(T->leftchild==NULL&&T->rightchild==NULL)
        {
            sum=T->data+10*sum;
            *totalSum=*totalSum+sum;
            sum=0;
        }
        else
        {
            sum=T->data+10*sum;
            sumofAllPaths(T->leftchild,sum,totalSum);
            sumofAllPaths(T->rightchild,sum,totalSum);
        }
    }


} 



int main()

{
    BiTree T;
    int a[20],i,n;
    char b[20];
    int sum=0,totalsum=0;
    
    gets(b);
    
    for(i=0;i<strlen(b);i++)
    {
        if(b[i]!='#')
            a[i]=(int)b[i]-'0';
        else 
            a[i]=-1;
    }
    CreateBiTree1(&T,a,strlen(b));
    sumofAllPaths(T,sum,&totalsum);
    printf("%d\n",totalsum);




}