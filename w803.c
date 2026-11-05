#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define OK 1
#define ERROR 0

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN];
typedef int Status; 


Status StrAssign(SString T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSTRLEN)
        return ERROR;
    else{
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
        }
        return OK;
    }
}
void StrPrint(SString S)
{
        int i;
        for(i=1;i<S[0];i++)
        {
            printf("%c",S[i]);

        }
        printf("\n");
}
int main()
{
    int i,j,flag=0;
    SString s;
    char c[MAXSTRLEN+1];
    gets(c);
    if(!StrAssign(s,c))
        exit(0);
    int f[s[0]];
    for(i=0;i<s[0];i++)
        f[i]=0;
    for(i=1;i<s[0];i++)
    {
        for(j=1;j<s[0];j++)
        {
            if(s[i]==s[j])
            {
                f[i]++;
            }
        }
    }
    for(i=0;i<s[0];i++)
    {
        if(f[i]==1)
        {
            printf("%d",i-1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("-1");
}