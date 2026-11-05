#include <stdio.h>
#include <string.h>
struct word
{
    char w[100];
};
int main()
{
    int n,i,j,t=0,k;
    int p,q;
    scanf("%d",&n);
    struct word words[n];
    for(i=0;i<n;i++)
    {
        gets(words[i].w);
    }
    char order[26];
    scanf("%s",order);
    for(i=0;i<100;i++)
    {
        if(words[t].w[i]!=words[t+1].w[i])
        {
            k=i;
            j=t;
            break;
        }
        else
        ++t;
    }
    for(i=0;i<26;i++)
    {
        if(words[j].w[k]==order[i])
        {
            p=i;
        }
        else if(words[j+1].w[k]==order[i])
        {
            q=i;
        }
        else if(words[j].w[k]=='\0')
        {
            printf("false");
            break;
        }
        else if(words[0].w[0]=='\0')
        {
            printf("true");
            break;
        }
        else if(words[j+1].w[k]=='\0')
        {
            printf("true");
            break;
        }
        if(p<q)
        {
            printf("true");
            break;
        }
        else 
        {
            printf("false");
            break;
        }

    }
}