#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define STUDENT_NUMBER 5 //排序对象个数

struct STUDENT_STRU
{
	char name[10];
	unsigned int score;
};

//划分函数
//按学生成绩排序
int PartitionScore(struct STUDENT_STRU a[], int low, int high)
{
	struct STUDENT_STRU x = a[low];//记录关键字
	while (low<high)
	{
		while (low<high&&a[high].score>=x.score)
		{
			high--;
		}
		if (low<high)
		{
			a[low] = a[high];
			low++;
		}

		while (low<high&&a[low].score<=x.score)
		{
			low++;
		}
		if (low < high)
		{
			a[high] = a[low];
			high--;
		}
	}
	a[low] = x;
	return low;
}

void QSort(struct STUDENT_STRU a[], int low, int high)
{
//★★★请补全代码


}

int main()
{
	int  i;
	int stuNum;
	struct STUDENT_STRU StudentStru[10];
	
	printf("请输入待排序记录的条数以及排序的列号：");
	scanf("%d", &stuNum);
	
	printf("请输入学生姓名和分数：\n");
	for(i = 0; i < stuNum; i++)
	{
		scanf("%s %d", StudentStru[i].name, &StudentStru[i].score);
	}
	printf("\n");

	//成绩非递减（递增）排序
	QSort(StudentStru, 0, stuNum-1);
	printf("成绩非递减（递增）排序后数据：\n");
	//打印排序结果
	for (i = 0; i < stuNum; i++)
	{
		printf("%s %d\n", StudentStru[i].name, StudentStru[i].score);
	}
	
	return 0;
}
