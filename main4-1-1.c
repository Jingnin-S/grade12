#include "c1.h"
#include "c4-1.h"
#include "bo4-1.c"

int main()
{
    int i,j;
    Status k;
    char s,c[MAXSTRLEN];
    SString T,S1,S2;
    printf("input:");
    gets(c);
    k=StrAssign(S1,c);
    if(!k)
    {
        printf("out of length%d",MAXSTRLEN);
        exit(0);
    }
    printf("%d %d",StrLength(S1),StrEmpty(S2));
    
}