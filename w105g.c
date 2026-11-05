#include <string.h>
#include <stdio.h>
int main()
{
    int n,i,t=0,k=0;
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            b[k]=a[i];
            ++k;
        }
        else
        {
            t++;
        }
    }
    if(t!=0)
    {
        for(i=0;i<t;i++)
        {
            printf("0 ");
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",b[i]);
        }
    }
    else
    {
        printf("false");
    }

}