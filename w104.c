#include <stdio.h>
int main()
{
    int x,i,j,t,p=0;
    scanf("%d",&x);
    int a[100];
    for(i=0;i<x;i++)
    {
        scanf("%d ",&a[i]);
    }
    for(i=0;i<x;i++)
    {
        if(a[i]==0)
        {
            a[x+p]=0;
            for(j=i+1;j<=x;j++)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            for(j=0;j<i;j++)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            ++p;
        }
    }
    for(i=0;i<x;i++)
    {
        printf("%d ",a[i]);
    }
}