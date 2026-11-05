#include <stdio.h>
#include <stdlib.h>
#include <bo3-3.c>
#include <bo3-2.c>
#include <c3-3.h>
#include <c3-2.h>

typedef int Status;
typedef int QElemType;

void YangHuiTriangle(int N)
{
	LinkQueue Q;
    InitQueue(Q);  EnQueue(Q,1);             //第1行元素入队
	for(int n=2; n<=N; n++){    //产生第i行元素并入队，同时打印第i-1行元素
		EnQueue(Q, 1);
		for(int i=1; i<=n-2; i++){//利用第n-1行元素产生第n行的中间n-2个元素
		    DeQueue(Q, temp);   printf("%d\n", temp);
		    GetHead(Q, x);
		    temp=temp + x;
		    EnQueue(Q, temp);
	       }
	       DeQueue(Q, x);  printf("%d\n",x);   //打印第N-1行的最后一个元素
	       EnQueue(Q, 1);                             //第N行的最后一个元素入队
        }	 
        while(!QueueEmpty(Q)){        //打印最后一行元素
		   DeQueue(Q, x);   printf("%d\n", x);
	}
}
Status JudgeHuiwen ( )//huiwen
{
	InitQueue(Q);
	InitStack(S);
	while((c=getchar())!='@')
    {
		Push(S, c);
		EnQueue(Q,c)
	};
	while(!StackEmpty(S)){
		Pop(S, a);
		DeQueue(Q, b);
		if(a!=b) return FALSE;	
	}  
	return TRUE;
}
void SeeDoctor ( )
{
	InitQueue(Q); int flag =1;
	while(flag){
		printf(“\n请输入命令:”);char ch=getchar();
		switch(ch){
		    case 'a': printf("\n病历号:");scanf("%d",&n);
			      EnQueue(Q,n);  break;
		    case 'n': if(!QueueEmpty(Q)){
			            DeQueue(Q,n); 
				printf(“\n病历号为%d的病人就诊”,n):   		 
                                }
			      else  printf("\n无病人等待就诊");break;
            case 'q': printf("\n今天停止挂号,下列病人依次就诊"：):
                                 while(QueueEmpty(Q)){
                                       DeQueue(Q, n); printf(“%d ”, n);
	                           }
                                 flag=0;  break;
		        default:  break;
           }
   }			
int main()
{
    int n;
    scanf("%d",&n);
    YangHuiTriangle(n);
    JudgeHuiwen ();
    SeeDoctor ( );
}
