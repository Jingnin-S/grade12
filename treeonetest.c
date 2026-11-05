#include <stdio.h>
#include <stdlib.h>
#include "c3-2.h"
#include "bo3-2.h"


typedef char TElemType;
#define OK 1
#define ERROR 0
TElemType Nil=' ';

typedef struct CSNode{
    TElemType data;
    Struct CNode *firstchild;
    struct CNode *nextibling;
}CNode , *CSTree;

int InitTree(CSTree *T)
{
    *T=NULL;
    return OK;
}

int CreatTree(CSTree *T)
{
    char c[20];/*临时存放孩子节点（奴超过20个*/
    CSTree p,p1;
    int i,t;
    printf("请输入根节点（字符型，空格为空）");
    scanf("%c%*c",&c[0]);
    if(c!=Nil)/*非空格*/
    {
        *T=(CSTree)malloc(sizeof(CSNode));
        (*T)->data=c[0];
        (*T)->nextibling=NULL;
        scanf("%c%*c",&c[0]);
        if(c[0]!=Nil)
        {
            p1=p->firstchild=(CSTree)malloc(sizeof(CSNode));
            CreatTree(&p1);
        }
        else
            (*T)->firstchild=NULL;
        scanf("%c%*c",&c[0]);
        if(c[0]!=Nil)
        {
            p1=p->firstchild=(CSTree)malloc(sizeof(CSNode));
            CreatTree(&p1);
        }
        else
            (*T)->firstchild=NULL;
    }
    else
        *T=NULL;
    return OK;
}

int main()
{
    CSTree T;
    InitTree(&T);
    CreatTree(&T);
}