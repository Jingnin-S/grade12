
#include<stdio.h>
#include<stdlib.h>

#define TASKMAX 10
#define CYCLEMAX 10
#define TASKINIT 5
#define OK 1
#define ERROR 0

typedef struct{
    int id;   // task id
    int cycle; // task complexity: cpu cycles
    int rescycle;  // count residual cpu cycles
    int wait;  // count the wait times to finish task
}QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
    int len;
} LinkQueue;

/***  create random new task  ***/
int create_task(int id, QElemType *t){
    t->id=id;
    t->cycle=rand()%CYCLEMAX+1;
    t->rescycle=t->cycle;
    t->wait=0;
    return OK;
}

/* Initialize a link queue */
int InitQueue (LinkQueue *Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode)); 
    if(!Q->front) return ERROR;
    Q->front->next=NULL;
    Q->len=0;
    return OK;
} //InitQueue

/* insert element to link queue */
int EnQueue(LinkQueue *Q, QElemType t){
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) 
        exit -1;
    p->data=t;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;
}  
/***补全函数****/

/* delete element from link queue */
int DeQueue(LinkQueue *Q, QElemType *t){
    QueuePtr p;
    if(Q->front==Q->rear) return ERROR;
    p=Q->front->next;
    *t=p->data;
    Q->front->next=p->next;
    Q->len--;
    if(Q->rear==p) 
        Q->rear=Q->front;
    free(p);
    return OK;
}

/* process the task in link queue */
int ProcQueue(LinkQueue *Q, QElemType *t, int N){
  
 /***补全函数****/
    DeQueue(Q,t);
    t->rescycle=t->rescycle-N;
    if(t->rescycle>0)
    {
        EnQueue(&Q, *t);
    }
    else
    {
        t->rescycle=0;
    }

return OK;
}

/* traverse link queue to update the element value of wait by adding one */
int QueueTraverse(LinkQueue *Q){

   /***补全函数****/
   QueuePtr p;
   p=Q->front->next;
   while (p!=NULL)
   {
       /* code */
       p->data.wait++;
       p=p->next;
   }
   

}

int main(){

    int i;
    int N;
    int taskid;
    QElemType t;
    LinkQueue Q;
    InitQueue(&Q);
    for(i=1; i<=TASKINIT; i++){
        create_task(i, &t);
        EnQueue(&Q, t);
    }

    taskid=TASKINIT+1;
    printf("Please input the number of CPU cores of your computer: ");
    scanf("%d", &N);

    while(Q.front!=Q.rear){
        ProcQueue(&Q,&t,N);
        if(t.rescycle==0)
            printf("task %4d with %4d cycles has finished and wait %4d schedule times.\n", t.id, t.cycle, t.wait);

        QueueTraverse(&Q);
        if (taskid<=TASKMAX){
            create_task(taskid, &t);
            EnQueue(&Q,t);
            taskid++;
        }

    }

    return 0;
} 
