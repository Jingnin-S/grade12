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
    int temp=0;
    if(count>= n)
        return OK;
    if(a[count]==-1)
    {
        T=NULL;
        count++;
        temp=1;
        return OK;
    }
    (*T)=(BiTree)malloc(sizeof(TNode));
    if(!(*T))

        return ERROR;

    (*T)->data=a[count++];
    if(CreateBiTree1(&(*T)->leftchild,a,n))
        if(CreateBiTree1(&(*T)->rightchild,a,n))
            return OK;

    return 0;

} 



//打印二叉树

void PrintBiTree(BiTree T)

{
  
     
    if(T) /* T不空 */
    {
        
        printf("%d ",T->data);
        PrintBiTree(T->leftchild); /* 再先序遍历左⼦树 */
        
        PrintBiTree(T->rightchild); /* 最后先序遍历右⼦树 */
        
    }
 


}



//求二叉树的结点总数
int count1=0;
int CountNode(BiTree T)
{
    if (!T)
        return ERROR;
    if(T){
        count1++;
        CountNode(T->leftchild);
        CountNode(T->rightchild);
    }
    return OK;
} 



//求二叉树的高度

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



//求二叉树的叶子结点个数
int *p=0;
int CountLeaveNode(BiTree T)

{
    int i,j;
    if(!T)
        return ERROR;
    
    if(T->leftchild==NULL&&T->rightchild==NULL)
        return 1;
    i=CountLeaveNode(T->leftchild);
    j=CountLeaveNode(T->rightchild);
    return (i+j);




} 



int main()

{
   
    char a[50];
    scanf("%s",a);
    int n=strlen(a);
    int b[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]=='#')
            b[i]=-1;
        else
            b[i]=(int)a[i];
    }
    BiTree T;
    CreateBiTree1(&T,b,n);
    CountNode(T);
    printf("%d\n",count1);
    printf("%d\n",CountLeaveNode(T));
    
    printf("%d\n",GetHeight(T));



}