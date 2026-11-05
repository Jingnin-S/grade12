#include <stdio.h>
#define N 9
#define TRUE 1
#define FALSE 0
typedef int InfoType; /* 定义其它数据项的类型 */
typedef int KeyType; /* 定义RedType类型的关键字为整型 */
typedef struct
{
    KeyType key; /* 关键字项 */
    InfoType otherinfo; /* 其它数据项 */
}RedType; 

void initlist(RedType b[], int a[], int n)
{
    int i;
    for(i=0; i<n; i++){
        b[i].key = a[i];
        b[i].otherinfo = i;
    }
}

/*打印列表*/
/*具体格式参见题目要求*/
void printList(RedType b[], int n)
{
    /*补全函数*/
int i;
    for(i=0; i<n; i++)
        printf("%d-%d\n", b[i].key, b[i].otherinfo);
}

// 将数组a中记录按关键字自小至大排序 
void d_bubble_sort(RedType a[], int n)
{
//★★★请补全代码
 
}

int main()
{
    int a[N]={38, 49, 65, 76, 13, 27, 49, 97,12};
    RedType b[N]; 
    initlist(b, a, N);
    printf("the original list:\n");
    printList(b, N);
    printf("the ordered list:\n");
    d_bubble_sort(b, N);
    printList(b, N);
}
