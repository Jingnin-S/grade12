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
Status StrCopy(SString T,SString S)
{
    int i;
    for(i=0;i<=S[0];i++)
    {
        T[i]=S[i];
        
    }
    return OK;

}
Status StrLength(SString T)
{
    return T[0];
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
    int i;
    Status k;
    char c[MAXSTRLEN+1],s[MAXSTRLEN+1];
    SString t,s1,s2;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='#')
        c[i+1]='\0';
    }
    k=StrAssign(s2,c);
    if(!k)
    {
        printf("串⻓超过MAXSTRLEN(=%d)\n",MAXSTRLEN);
        exit(0);
    }
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='#')
            s[i]='\0';
    }
    k=StrAssign(s1,s);
    if(!k)
    {
        printf("串⻓超过MAXSTRLEN(=%d)\n",MAXSTRLEN);
        exit(0);
    }
    
    if(s1[0]+s2[0]<=MAXSTRLEN)
    {
        for(i=1;i<=s1[0];i++)
        {
            t[i]=s1[i];
        }
        for(i=1;i<=s2[0];i++)
        {
            t[s1[0]+i]=s2[i];
        }

       t[0]=s1[0]+s2[0];
    }
    
    else
        printf("false");
    StrPrint(t);
    
}
