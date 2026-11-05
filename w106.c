#include <stdio.h>
int main()
{
    int n,i,t,flag=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        if(a[i]>=a[i+1])
        {
            t=i;
            flag++;
            break;
        }  
    }
    for(i=t;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
        {
            flag++;
            
        }
    }
    if(flag>=2||flag==0)
    {
        printf("flase");
    }
    else
    {
        printf("true");
    }
}