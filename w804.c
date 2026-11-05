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
int Index(SString S,SString T,int pos)
{
    int i,j;
    if(pos>=1&&pos<=S[0])
    {
        i=pos;
        j=1;
        while(i<=S[0]&&j<=T[0])
        {
            if(S[i]==T[i])
            {
                ++i;
                ++j;
            }
            else{
                i=i-j+2;
                j=1;
            }
        }
        if(j>T[0])
            return i-T[0];
        else
            return 0;
    }
    else
        return 0;
}
int MaxEqual1(char *str)
{
    int max=0;
    char c;
    if(*str == 0)
    {
        return -1;
    }
    int count = 1;
    char *p = str;
    while(*p != '\0')
    {
        if(*p == *(p+1))
        {
            count++;
            c=*p;
        }
        else
        {
            max = max>count?max:count;
            count = 1;
        }
        p++;
    }
    //return max;
    if(max==0)
        printf("no");
    else
    {  
        if(c=='a')
            c='n';
        if(c=='=')
            {
                printf("no");
                return OK;
            }
        for(int i=0;i<max;i++)
        {
            printf("%c",c);
        }
    }
    
    return OK;
}
int Search(char* str) {
    char* longest;
    int   longlen = 0;
    int   len = 0;
    char* c;
    while (1){
        if (*str == 0 || *str == ' ') {
            if (len > longlen) {
                longlen = len;
                longest = c;
            }
            if (*str == 0 ) break;
            len = 0;
        }
        else if (len != -1){
            if (len == 0) {c = str; len++;}
            else if (*str == *c) len++;
            else len = -1;
        }
        str++;
    } 
    if (longlen >1) {
        while (longlen-- > 0) {
            printf("%c", *(longest++));
        }
    }
    else printf("no");
    printf("\n");
}
int main()
{
    int i,j;
    Status k;
    char c[MAXSTRLEN+1];
    SString s1;
    int *t;
    gets(c);
    c[strlen(c)-1]='\0';
    k=StrAssign(s1,c);
    if(!k)
    {
        printf("error\n");
        exit(0);
    }
    //StrPrint(s1);
    t=MaxEqual1(s1);
    /*for(i=t;i<s1[0];i++)
    {
        printf("%c",s1[i]);
    }*/
    //Search(s1);
}