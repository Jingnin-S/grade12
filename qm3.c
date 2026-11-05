#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define STACK_SIZE 100  //顺序栈容量 
#define  STACKINCRMENT 20
#define OK 1
#define ERROR 0
typedef char SElemType;
typedef struct
{
	SElemType *base;//栈底位置 
	SElemType *top;//栈顶位置
	int stacksize;//存储分配容量，以元素为单位。 
}SqStack;

//初始化 
//如果成功，返回OK，如果失败，返回ERROR
int InitStack(SqStack *S)//初始化
{
	S->base=(SElemType *)malloc(STACK_SIZE*sizeof(SElemType));
	if(!S->base)
	   return ERROR;
	S->top=S->base;
	S->stacksize=STACK_SIZE;
	return OK; 
}

//入栈 
// 如果成功，返回OK，如果失败，返回ERROR
int Push(SqStack*S, SElemType e)//入栈 
{
//★★★请补全代码

    *S->top++=e;
    return OK;
}
int StackEmpty(SqStack S)
{
	return (S.top==S.base);
}
//出栈 
//如果成功，返回OK，如果失败，返回ERROR
int Pop(SqStack *S,SElemType *e)//出栈 
{
	if(S->top==S->base)
	return ERROR;
	*e=*(S->top-1);
	S->top--;
	return OK;
}

// 获取栈顶元素
//如果成功，返回OK，如果失败，返回ERROR
int GetTop(SqStack S, SElemType *e)
{
//★★★请补全代码
    if(S.top==S.base)
        return ERROR;
    *e=*(S.top-1);
    return OK;

}
 
int main()
{
	char str[100];
	gets(str);
	SqStack S;
	InitStack(&S);
	
    /******************删除重复元素，并输出操作后字符串*********************/
    //★★★请补全代码
    int i,j;
    SElemType e;
    
    Push(&S,str[0]);
    for(i=1;i<strlen(str);i++)
    {
        GetTop(S,&e);
       
        if(e==str[i])
        {
            for(j=i-1;j<strlen(str)-1;j++)
            str[j]=str[j+2];
            Pop(&S,&e);
        }
        else
        Push(&S,str[i]);
    }
    printf("%s",str);
    
}