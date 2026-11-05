#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100
typedef int Status;
typedef char SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//初始化顺序栈
Status InitStack(SqStack *S)	
{
	S->base = (SElemType*)malloc(sizeof(SElemType)*MAXSIZE);
	if(!S->base)
		return OVERFLOW;
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;

}
//入栈
Status Push(SqStack *S,SElemType e)		{
	if(S->top-S->base==S->stacksize)
		return ERROR;
	*(S->top++) = e;
	return OK;
}

//出栈
Status Pop(SqStack *S,SElemType *e)		{
	if(S->base == S->top)
		return ERROR;
	*e = *(--S->top);
	return OK;
}

//销毁顺序栈
Status DestroyStack (SqStack *S){
	//★★★请补全代码
    S->base=S->top;
    return OK;
}

//判断字符序列是否为“回文”, 如果是返回1，否则返回0 
//提示：需要调用堆栈的基本操作来实现，如果未使用堆栈，答题无效。
int IsPalindrome(char *t)	{
	//★★★请补全代码
    SqStack s;
    SElemType p;
    InitStack(&s);
    int i,flag=0;
    for(i=0;i<strlen(t)/2;i++)
    {
        Push(&s,t[i]);
    }
    for(i=strlen(t)/2;i<strlen(t);i++)
    {
        Pop(&s,&p);
        if(p==t[i])
            flag=1;
        else
            flag=0;
    }
    DestroyStack(&s);
    if(flag==1)
        return OK;
    else
        return ERROR;

}

int main()
{
	char p[MAXSIZE];
	scanf("%s",p);
	if(IsPalindrome(p)) 
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
