#include "stdio.h"
#define OK 1
int b[]={1,2,3,4,5};

int visit(int a)
{
  printf("this is the test %d\n", a);
  return OK;
}

void ListTraverse(int a[], int n, int(*visit)(int ))
{
    for(int i=0;i<n;i++)
    {
        visit(a[i]);
    }
}

int main()
{  
    ListTraverse(b,5,visit);
}