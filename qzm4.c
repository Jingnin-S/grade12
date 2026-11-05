#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack)
{
	int full = 0;
    full = (stack->top == (int)stack->capacity - 1)?1:0;
	return full;
} 

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
} 

void push(struct Stack* stack, char item)
{
  /***补全函数****/
    if(stack->top == -1)
    {
        return -1;
    }
    
    stack->array[stack->top+1]=item;
    stack->top++;
}

char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return CHAR_MIN;
    return stack->array[stack->top--];
}

void reverseStr(char str[])
{
/***补全函数****/
    struct Stack* p;
    createStack(p);
    int i;
    if(isEmpty)
        return -1;
    for(i=0;i<strlen(str);i++)
    {
        push(p,str[i]);

    }
    for(i=0;i<strlen(str);i++)
    {
        str[i]=pop(p);
    }
    //createStack(str);


}

int main()
{
    char str[] = "ILoveChina, ILoveBJTU, ILoveGJCXSJXL";
    printf("The given string %s has %d characters.\n", str, strlen(str));

    reverseStr(str);
    printf("Reversed string is %s\n", str);

    return 0;
}