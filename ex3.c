#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

};

int main()
{
    struct node *head,*p,*q;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    /*开一个头节点，并在下面再让一个指针只想头结点并用它做游动指针，
    注意头指针很重要，不要轻易去动头指针*/
    q = head;
    int n;
    scanf("%d",&n);
    while(n--) //建立链表；
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next = NULL;  //开一个节点并放入数据，注意新开节点，指针定义为空；
        q->next = p;//“q”为游动指针，即为只向最后一个的指针，也可以在定义一个专门指向尾结点的指针；
        q = p; //每一次游动指针向后移动一位；
    }

    q = head->next; //输出链表；
    while (q!=NULL)
    {
        if(q->next!= NULL)
            printf("%d ",q->data);
        else printf("%d\n",q->data);
        q = q->next;
    }
    return 0;

}
