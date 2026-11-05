/* c2-1.h 线性表动态分配顺序存储结构*/
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;