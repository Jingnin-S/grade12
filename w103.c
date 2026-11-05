#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,flag=0;
    char a[100];
    scanf("%s",a);
    int b[100];
    for(i=0;i<strlen(a);i++)
    {
        b[i]=0;
        for(j=0;j<strlen(a);j++)
        {
            if(a[i]==a[j])
            {
                b[i]++;
                flag=1;
            }
        }
        if(b[i]==1)
        {
            printf("%d",i);
            break;
        }
    }
    if(b[0]==(strlen(a)))
    printf("-1");
}