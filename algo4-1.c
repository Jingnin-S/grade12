#include "c1.h"
#include "c4-1.h"
#include "bo4-1.c"

void get_next(SString T,int next[])
{
    int j=1;
    next[1]=0;
    int k=0;
    while(j<T[0])
    {
        if(k==0||T[j]==T[k])
        {
            ++j;
            ++k;
            next[j]=k;

        }
        else{
            k=next[k];
        }
    }
}
int Index_kmp(SString S,SString T,int pos,int next[])
{
    int i=pos,j=1;
    while(i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j])
        {
            ++i;++j;

        }
        else
        {
            j=next[j];
        }

    }
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}
void get_nextval(SString T,int nextval[])
{   
    int j=1,k=0;
    nextval[1]=0;
    while(j<T[0])
    {
        if(k==0||T[j]==T[k])
        {
            ++j;++k;
            if(T[j]!=T[k])
                nextval[j]=k;
            else
                nextval[j]=nextval[k];
        }
        else 
            k=nextval[k];
    }
}
int main()
{
    int i,j,*p;
    SString S1,S2;
    StrAssign(S1,"acabaabaabcacaabc");
    printf("main string is:");
    //StrPrint(S1);
    StrAssign(S2,"abaabcac");
    printf("partern string is:");
    StrPrint(S2);
    i=StrLength(S2);
    p=(int*)malloc((i+1)*sizeof(int));
    get_nextval(S2,p);
    printf("next arrays is:");
    for(j=1;j<=i;j++)
        printf("%d",*(p+j));
    printf("\n");
    i=Index_kmp(S1,S2,1,p);
    if(i)
        printf("the pos is%d\n",i);
    else
        printf("no\n");
}