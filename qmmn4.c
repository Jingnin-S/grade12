#include <stdio.h>
#include <stdlib.h>

//折半查找函数
//int a[ ]:查找表，int n: 查找表长度， int target: 待查找的元素
//如果查找成功，返回元素数组下标（从0开始），如果查找失败，返回-1
int BinarySearch(int a[ ],  int n,  int target) 
{

//★★★请补全代码
   int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(target==a[mid])
            return mid;
        else if(target<a[mid])
        {
            
            {
                high=mid-1;
            }
        }
        else
            low=mid+1;


    }
    return 0;

}

int main( )
 {
	
	int a[10], i, m;
	printf("please enter the elements：");
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	printf("please enter the element to be searched：");
	scanf("%d", &m);
	
	int q;
	q = BinarySearch(a, 10, m);
	if (q != -1) {
		printf("数据在查找表中的位置为：%d", q + 1);
	}
	else {
		printf("查找表中无该元素");
	}
	return 0;
}
