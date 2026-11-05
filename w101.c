#include <stdio.h>
#include <string.h>
int main()
{
    int a=0,b=0,c=0,i;
    char x[100];
    scanf("%s",x);
    for(i=0;i<strlen(x);i++)
    {
        if(x[i]=='A'||x[i]=='a'||x[i]=='E'||x[i]=='e'||x[i]=='I'||x[i]=='i'||x[i]=='o'||x[i]=='O'||x[i]=='U'||x[i]=='u')
        a++;
        else
        b++;
        if(x[i]==' ')
        c++;

    }
    printf("%d\n\n%d",a,b-c);
    return 0;
}