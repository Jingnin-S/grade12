#include "c1.h"
#include "c2-1.h"
#include "bo2-1.c"
typedef int ElemType;

Status equal(ElemType c1,ElemType c2)
{
    if(c1==c2)
    {
        return TRUE;
    }
    else
    return FALSE;
}
void Union(SqList *La,SqList Lb) /* 算法2.1 */
{ /* 将所有在线性表Lb中但不在La中的数据元素插⼊到La中 */
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len=ListLength(*La); /* 求线性表的⻓度 */
    Lb_len=ListLength(Lb);
    for(i=1;i<=Lb_len;i++)
    {
    GetElem(Lb,i,&e); /* 取Lb中第i个数据元素赋给e */
    if(!LocateElem(*La,e,equal)) /* La中不存在和e相同的元素,则插⼊之 */
        ListInsert(La,++La_len,e);
    }
}
int main()
{
    SqList la,lb;
    Status i;
    int j;
    i=InitList(&la);
    if(i==1)
    {
        for(j=1;j<=5;j++)
        {
            i=ListInsert(&la,j,j);
        }
    }
    printf("la== ");
    ListTraverse(la);
    Union(&la,lb);
    printf("new la= ");
    ListTraverse(la);
}
