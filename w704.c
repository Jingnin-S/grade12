#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int QElemType;  
typedef int Status;

typedef struct Qnode{

   QElemType   data;

   struct Qnode  *next;

}QNode, *QueuePtr;

typedef struct {

   QueuePtr  front;  //front pointer

   QueuePtr  rear;   //rear pointer

}LinkQueue; 

 

//========================================== 

// initialization of linked list based queue

//=========================================== 

Status InitQueue(LinkQueue *Q)
{
    Q->front=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next=NULL;
    Q->rear=NULL;
    return OK;
 

}

 

//========================================

//Test empty queue

//========================================

Status QueueEmpty (LinkQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else 
        return FALSE;
  

}

 

//===============================================

// Get the length of a queue

//==============================================

int QueueLength (LinkQueue Q)
{
    return(Q.rear-Q.front);


}

 

//=====================================

// Get front item of a queue

//====================================

Status GetHead (LinkQueue Q, QElemType *e)
{
    QueuePtr p;
    if(Q.front==Q.rear)
    return ERROR;
    p=Q.front->next;
    *e=p->data;
    return OK;

}

 

//===================================================

// Delete an item from the queue

//====================================================

Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if((*Q).front==(*Q).rear)
    return ERROR;
    p=(*Q).front->next;
    *e=p->data;
    (*Q).front->next=p->next;
    if((*Q).rear==p)
    (*Q).rear=(*Q).front;
    free(p);
    return OK;
}

 

//======================================

// Insert an item into the queue

//=======================================

Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) /* 存储分配失败 */
    return ERROR;
     p->data=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;


}

 

//======================================

// Print the elements in a queue

//=======================================

int PrintQueue (LinkQueue S)
{
    QueuePtr p;
    p=S.front->next;
    if(!p)
        return ERROR;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;

}



//==================================

// 打印输出杨辉三角的第N行元素

// ================================


void PrintYangHuiTriangle(int N)

{
    LinkQueue Q;
    InitQueue(&Q); 
    EnQueue(&Q,1);             //第1行元素入队
	QElemType temp,x;
    for(int n=2; n<=N; n++)
    {    //产生第i行元素并入队，同时打印第i-1行元素
		EnQueue(&Q, 1);
		for(int i=1; i<=n-2; i++)
        {//利用第n-1行元素产生第n行的中间n-2个元素
		    DeQueue(&Q, &temp);  
            //printf("%d\n", temp);
		    GetHead(Q, &x);
		    temp=temp + x;
		    EnQueue(&Q, temp);
	       }
	       DeQueue(&Q, &x);  
           //printf("%d\n",x);   //打印第N-1行的最后一个元素
	       EnQueue(&Q, 1);                             //第N行的最后一个元素入队
        }	 
        while(!QueueEmpty(Q)){        //打印最后一行元素
		   DeQueue(&Q, &x);   
           printf("%d\n", x);
	}


}

 

int main()  

{  
    int n;
    scanf("%d",&n);
    PrintYangHuiTriangle(n);


 

} 