#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int QElemType;  
typedef int Status;

// definition of array based queue

#define MAXQSIZE  100   // maximum length
typedef struct {

   QElemType     *base;   //pointer the allocated memory

   int  front;                    //front indicator

   int  rear;                     //rear indicator

}SqQueue; 

 

 

//========================================== 

// initialization of array-based queue

//=========================================== 

Status InitQueue (SqQueue *Q)
{
    (*Q).base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!(*Q).base) /* 存储分配失败 */
        exit(-1);
    (*Q).front=(*Q).rear=0;
    return OK;
   

}//InitQueue

 

//========================================

//Test empty queue

//========================================

Status QueueEmpty (SqQueue Q)
{
if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;

    

}

 

//===============================================

// Get the length of a queue

//==============================================

int QueueLength (SqQueue Q){

    return(Q.rear-Q.front);

}

 

//=====================================

// Get front item of a queue

//====================================

Status GetHead (SqQueue Q, QElemType *e){
    if(Q.front==Q.rear) /* 队列空 */
 return ERROR;
 *e=*(Q.base+Q.front);
 return OK;
 

}

 

//===================================================

// Delete an item from the queue

//====================================================

Status DeQueue(SqQueue *Q,QElemType *e)
{
    if((*Q).front==(*Q).rear) /* 队列空 */
    return ERROR;
    *e=(*Q).base[(*Q).front];
    (*Q).front=((*Q).front+1)%MAXQSIZE;
    return OK;
  

}

 

//======================================

// Insert an item into the queue

//=======================================

Status EnQueue (SqQueue *Q, QElemType e){
     if(((*Q).rear+1)%MAXQSIZE==(*Q).front) /* 队列满 */
    return ERROR;
    (*Q).base[(*Q).rear]=e;
    (*Q).rear=((*Q).rear+1)%MAXQSIZE;
    return OK;
 

}

 

//========================================

//Clear a Queue

//===========================================

Status ClearQueue (SqQueue *Q){

    if((*Q).base)
    free((*Q).base);
    (*Q).base=NULL;
    (*Q).front=(*Q).rear=0;
    return OK;

}

 

//======================================

// Print the elements in a queue

//=======================================

void PrintQueue (SqQueue S)
{
    int i=0;
   if(S.front!=S.rear)
   {
       for(i=0;i<QueueLength(S);i++)
       {
           printf("%d ",S.base[S.front+i]);
       }
   }
       

 

}

 

int main()  

{  
    int i;
    QElemType d,a;
    SqQueue S,e;

    InitQueue(&S);
    do
    {
        scanf("%d",&d);
        if(d==-1)
            break;
        i++;
    EnQueue(&S,d);
    }while(i<MAXQSIZE-1);
    PrintQueue(S);
    printf("\n");
    printf("%d\n",QueueLength(S));
    int b=QueueLength(S);
    scanf("%d",&a);
    while(QueueLength(S)>b-a)
    {
        DeQueue(&S,&d);
    }
    PrintQueue(S);


}