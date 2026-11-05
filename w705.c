#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0


//定义队列元素类型
typedef struct {

    char name;    //元素名称

    int arriveTime;  //到达时间

} QElemType;

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
 return (Q.front == NULL);
  

}

 

//===============================================

// Get the length of a queue

//==============================================

int QueueLength (LinkQueue Q)
{

    QueuePtr p;
    p=Q.front->next;
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

 

//=====================================

// Get front item of a queue

//====================================

Status GetHead (LinkQueue Q, QElemType *e){

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

Status EnQueue(LinkQueue *Q, QElemType e){
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

void PrintQueue (LinkQueue S)
{
    QueuePtr p;
    p=S.front;
    while(p)
    {
        printf("(%c,%d)\n",p->data.name,p->data.arriveTime);
        p=p->next;
    }
    printf("\n");
       



}



//=========================
//合并两个队列, 得到一个新的队列,  新队列的所有结点都重新生成
//=========================
void mergeQueue (LinkQueue Q1, LinkQueue Q2, LinkQueue *Q3)
{
    int m,n,i;
     QElemType a,b;
    scanf("%d",&m);
    for(i=0;i<m;i++)
       {
           getchar();
           scanf("%c %d",&a.name,&a.arriveTime);
           EnQueue(&Q1,a);
       }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        getchar();
        scanf("%c %d",&a.name,&a.arriveTime);
        EnQueue(&Q2,b);
    }
    QueuePtr pa,pb,pc;
    pa=Q1.front->next;
    pb=Q2.front->next;
    pc=Q3->front=Q1.front;
    QElemType e;
    while(pa&&pb)
    {
       if(pa->data.arriveTime<=pb->data.arriveTime)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else if(pa->data.arriveTime>pb->data.arriveTime)
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }

    }
     if(pb)
    {
        pc->next=pb;
        Q3->rear=Q2.rear;
    }
    else if(pa)
    {
        pc->next=pa;
        Q3->rear=Q1.rear;
    }
    free(Q2.front);

}



int main()  

{  
    LinkQueue Q1,Q2,Q3;
    if((!InitQueue(&Q1))||(!InitQueue(&Q2))||(!InitQueue(&Q3)))
        return ERROR;
    mergeQueue(Q1,Q2,&Q3);
    PrintQueue(Q3);


 

} 

