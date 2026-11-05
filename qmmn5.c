#include <stdio.h>
#include <string.h>
#include<malloc.h>
#define OK 1
#define ERROR 0

typedef struct node         //二叉树结点类型的定义
{	
     char data;
	 struct node *lchild;	//结点的左孩子指针
	 struct node *rchild;	//结点的右孩子指针
} BinTNode;				

typedef int Status;
typedef BinTNode* ElemType;  //定义单链表的元素类型

typedef struct Lnode{     //单链表结点结构定义
	ElemType  data;     //单链表数据域 
	struct Lnode *next;   //单链表指针域，
}LNode, *LinkList;

typedef struct{
	LinkList front;   //队头指针
	LinkList rear;    //队尾指针
	int length;      //队列长度
}LinkQueue;

//队列初始化，构造一个仅包含头结点的空队列.
//如果成功，返回OK，如果失败，返回ERROR
Status InitQueue(LinkQueue *Q)
{
	Q->front=(LinkList)malloc(sizeof(LNode));
	if(!Q->front)
		return ERROR;
	Q->front->next=NULL;
	Q->rear=Q->front;
	Q->length=0;
	return OK;
}

//队列判空，如果为空，返回true, 否则返回false
Status QueueEmpty(LinkQueue Q)
{
	return (Q.front==Q.rear);
}

//入队操作，
//将元素e插入队尾, 如果成功，返回OK，如果失败，返回ERROR
Status EnQueue(LinkQueue *Q, ElemType e)
{
//★★★请补全代码
    LinkList p=(LinkList)malloc(sizeof(LNode));
    if(!p) /* 存储分配失败 */
        exit(-1);
    p->data=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;

    
}

//出队列操作，
//删除队头元素并通过参数e返回队首元素值，如果成功，返回OK，如果失败，返回ERROR  
Status DeQueue(LinkQueue *Q, ElemType *e)
{
	if(Q->front==Q->rear)
		return ERROR;
	LinkList p;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(p==Q->rear)
		Q->rear=Q->front;
	free(p);
	Q->length--;
	return OK; 
}

 
BinTNode *CreateBinTree()  //输入二叉树的先序遍历的扩展序列，创建二叉链表
{   
	 BinTNode *t;
	 char ch;
	 ch=getchar();
	 if (ch=='0')             //如果读入0，创建空树
		t=NULL;
	 else
	 {	
		t=(BinTNode *)malloc(sizeof(BinTNode));	//申请根结点*t空间
		t->data=ch;                                  //将结点数据ch放入跟结点的数据域
		t->lchild=CreateBinTree();			    //建左子树
		t->rchild=CreateBinTree();			    //建右子树
	 } 
    return t;
}

//对二叉树进行中序遍历并打印。
void inorder(BinTNode *t) 
{
//★★★请补全代码
    if(t)
    {
        inorder(t->lchild);
        //cout<<t->data;
        printf("%C ",t->data);
        inorder(t->rchild);
    }


} 

//对二叉树进行层序遍历并打印输出。
void levelorder(BinTNode *t) {

//★★★请补全代码
    LinkQueue Q;
    ElemType T;
    if(!t)
        return 0;
    InitQueue(&Q);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,&T->data);
        printf("%C ",T->data);
        if(T->lchild)
            EnQueue(Q,T->);
    }


} 

int main()
{    

     char a;
	 BinTNode *t=NULL;
	 printf("输入先序序列的扩展序列,虚结点用0表示：\n");
	 t=CreateBinTree();
	 printf("\n二叉树的中序遍历结果为:\n");
	 inorder(t); 
	 printf("\n二叉树的层序遍历结果为:\n");
	 levelorder(t);	 	                    

}

