#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef char QElemType;  

// definition of array based queue

#define MAXQSIZE  100   // maximum length
typedef struct {
   QElemType     *base;   //pointer the allocated memory
   int  front;                    //front indicator
   int  rear;                     //rear indicator
}SqQueue; 
typedef char SElemType; 
typedef int Status;
typedef struct L_node
{
    SElemType data;  //data field
    struct L_node *next;   //pointer field
}LNode, *LinkList;
typedef struct
{
   LinkList  Head;  //head pointer
   int  length;  //length
}LinkStack;
Status InitStack(LinkStack *S)
{
    S->Head=(LinkList)malloc(sizeof(LNode));
    if(!S->Head)
        return ERROR;
    S->Head->next=NULL;
    S->length=0;
    return OK;
}
Status Pop(LinkStack *S, SElemType *e)
{
    if(S->Head->next==NULL)
        return ERROR;
    S->Head=S->Head->next;
    *e=S->Head->data;
    S->length--;
    return OK;
}
Status Push(LinkStack *S, SElemType e)
{
    LinkList p;
    p=(LinkList)malloc(sizeof(LNode));
    if(!p)
        return ERROR;
    S->length++;
    p->data=e;
    p->next=S->Head->next;
    S->Head->next=p;
    return OK;
}
Status StackEmpty (LinkStack S)
{
    if(S.Head->next==NULL)
        return TRUE;
    else
        return FALSE;
}
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

int QueueLength (SqQueue Q)
{
    return(Q.rear-Q.front);
                       

}

//=====================================



// Get front item of a queue



//====================================



Status GetHead (SqQueue Q, QElemType *e)
{
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



Status EnQueue (SqQueue *Q, QElemType e)
{
    if(((*Q).rear+1)%MAXQSIZE==(*Q).front) /* 队列满 */
    return ERROR;
    (*Q).base[(*Q).rear]=e;
    (*Q).rear=((*Q).rear+1)%MAXQSIZE;
    return OK;
}



//========================================

//Clear a Queue

//===========================================

Status ClearQueue (SqQueue *Q)
{
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
Status JudgeHuiwen ( )//huiwen
{
	SqQueue Q;
    LinkStack S;
    QElemType a;
    SElemType b;
    InitQueue(&Q);
	InitStack(&S);
    char c;
	while((c=getchar())!='\n')
    {
		Push(&S, c);
		EnQueue(&Q,c);
	}
	while(!StackEmpty(S)){
		Pop(&S, &a);
		DeQueue(&Q, &b);
		if(a!=b) return FALSE;	
	}  
	return TRUE;
}


int main()  

{  
    int t;
    t=JudgeHuiwen();
    if(t>0)
        printf("True");
    else
        printf("False");
}