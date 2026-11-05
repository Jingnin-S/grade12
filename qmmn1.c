#include <stdlib.h>
#include <stdio.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

/*定义结点结构体*/
typedef struct Node
{
    ElemType data;            /*单链表中的数据域 */
    struct Node *next;          /*单链表的指针域*/
}LNode;

/*定义链表类型*/
typedef  LNode * LinkList;

//  建立带表头结点的单链线性表L（尾插法） 
Status CreateListTail(LinkList *L)
{
    LinkList p = NULL;
    LinkList tail = NULL;
    int e=0;

    *L = (LNode *)malloc(sizeof(LNode));
if(*L==NULL)
return ERROR;
    (*L)->next = NULL;

    tail= *L;
    scanf("%d", &e);
    while(e != -1)
    {
        p = (LNode *)malloc(sizeof(LNode)); /*  生成新结点 */
if(!p)
return ERROR;
        p->data = e;
        tail->next=p;                  /* 将表尾终端结点的指针指向新结点 */
        tail = p;                      /* 将当前的新结点定义为表尾终端结点 */

        scanf("%d", &e);
    }

    tail->next = NULL;                       /* 表示当前链表结束 */
return OK;
}

// 求链表长度, 如果是空链表，返回0
int Length_LList(LinkList L)
{
//★★★请补全代码
    LinkList p=L->next;\
    int i=0;
    if(!p)
        return 0;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;

}



//  该函数返回单链表的倒数第k个元素值
//  如果存在，函数返回OK，并将倒数第k个元素的值通过参数e返回
//  如果不存在，则函数返回ERROR
Status invertLocate(LinkList L,  int k,  ElemType *e)
{
//★★★请补全代码
    int n=Length_LList(L);
    int i=1;
    LinkList p=L->next;
    while(i!=n-k-1&&p)
    {
       
        p=p->next;
        i++;
    }
    if(!p||i>n)
    return ERROR;
    
    *e=p->data;
    return OK;



}

int main()
{
    LinkList list;
    int length = 0;
    int invertIndex = 0;
    int invElem = -1;
    if(CreateListTail(&list)==ERROR)
	{
	    printf("ERROR in creating linklist\n");
	    return ERROR;
	}
    length=Length_LList(list);
    printf("length = %d\n", length);
    scanf("%d", &invertIndex);
    if (invertLocate(list, invertIndex,  invElem) == ERROR){
        printf("ERROR!\n");
        return ERROR;
    }
    printf("%d\n", invElem);
    return OK;
}


