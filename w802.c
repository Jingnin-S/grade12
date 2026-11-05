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
    int i,t,j,a,p;
    Status k;
    char c[MAXSTRLEN+1];
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {   
        int max=0;
        SString S;
        gets(c);
        k=StrAssign(S,c);
        if(!k)
            {  
                printf("False");
                exit(0);
            }
        int b[S[0]];
        for(j=1;j<S[0];j++)
        {
            for(t=1;t<S[0];t++)
            {
                if(S[j]==S[t])
                {
                    b[j]++;
                }
            }
        }
        for(j=1;j<S[0];j++)
        {
            if(b[j]>=max)
            {
                max=b[j];
                p=j;
            }
        }
        printf("%c %d\n",S[p],max);
        
    }
}