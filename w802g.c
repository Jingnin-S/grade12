#include "stdio.h"
#include "string.h"
int main()
{
    int i,j,flag=0;
    char c[100];
    scanf("%s",c);
    //int a[strlen(c)];
    for(i=0;i<strlen(c);i++)
    {
        for(j=i;j<strlen(c);j++)
        {
            if(c[i]==c[j])
            {
                printf("%d",i);
                flag=1;
                goto pos;
            }
        }
    }
    pos:
    if(flag==0)
        printf("-1");
}