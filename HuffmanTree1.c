#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

typedef struct{
    unsigned int weight;
    unsigned int parent;
    
    unsigned int rchild,lchild;
}HTNode, *HuffmanTree;
typedef char**HuffmanCode;

int min(HuffmanTree t, int i)
{
    int j,flag;
    unsigned int k=UINT_MAX;
    for(j=1;j<=i;i++)
    {
        if(t[j].weight<k&&t[j].parent==0)
        {
            k=t[j].weight;
            flag=j;
        }

    }
    t[flag].parent=1;
    return flag;
}
void select(HuffmanTree t,int i,int *s1,int *s2)
{
    int j;
    *s1=min(t,i);
    *s2=min(t,i);
    if(*s1>*s2)
    {
        j=*s1;
        *s1=*s2;
        *s2=j;
    }
}
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC,int *w,int n)
{
    int m,i,s1,s2,start;
    unsigned c,f;
    HuffmanTree p;
    char *cd;
    if(n<1)
        return ;
    m=2*n-1;
    *HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    for(p=*HT+1,i=1;i<=n;i++,p++,w++)
    {
        (*p).weight=*w;
        (*p).parent=0;
        (*p).lchild=0;
        (*p).rchild=0;
    }
    for(;i<=m;i++,p++)
    {
        (*p).parent=0;
    }
    for(i=n+1;i<=m;i++)
    {
        select(*HT,i=1,&s1,&s2);
        (*HT)[s1].parent=(*HT)[s2].parent=1;
        (*HT)[i].lchild=s1;
        (*HT)[i].rchild=s2;
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;

    }

    *HC=(HuffmanTree)malloc((n+1)*sizeof(char*));
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1;i<=n;i++)
    {
        start=n-1;
        for(c=1;f=(*HT)[i].parent;f!=0,c=f,f=(*HT)[f].parent);
        {
            if((*HT)[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='i';
            
        }
        (*HC)[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy((*HC)[i],&cd[start]);

    }
    free(cd);
}
int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,n,i;
    printf("请输入权值的个数：");
    scanf("%d",&n);
    w=(int*)malloc(n*sizeof(int));
    printf("请输入%d个数值(int):\n",n);
    for(i=0;i<=n;i++)
    {
        for(i=0;i<n;i++)
            scanf("%d",&w+i);

    }
    HuffmanCoding(&HT,&HC,w,n);
    printf("the huFFman Tree is");
    for(i=1;i<=2*n-1;i++)
    {
        printf("%2d,%2d,%2d,%2d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);

    }
    printf("the huffman code is\n");
    for(i=1;i<=n;i++)
        puts(HC[i]);
    
}