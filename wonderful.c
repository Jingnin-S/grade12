
#include<stdio.h>
#include<stdlib.h>
 
#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5
 
typedef struct{
	int *elem;
	int length;
	int listsize;
}Sqlist;
 
//初始化顺序表
int InitList(Sqlist *l){
	l->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!l->elem){
		printf("存储空间分配失败！\n");
		exit(OVERFLOW);
	}
	l->length = 0;
	l->listsize = LIST_INIT_SIZE;
	return OK;
}
//给顺序表赋值 
int CreatList(Sqlist *l,int length){
	printf("请输入元素:\n");
	for(int i=0;i<length;i++) scanf("%d",l->elem+i);
	l->length = length;
	return OK;
}
//输出顺序表中的元素
void PrintList(Sqlist *l){
	printf("输出结果为：\n");
	for(int i=0;i<l->length;i++) printf("%d ",l->elem[i]);
	printf("\n");
}
 
//得到线性表某位置上的元素 
int GetElem(Sqlist *l,int i,int *p){
	if(i<1||i>l->length){
		printf("位置错误!\n");
		exit(OVERFLOW);
	}
	*p = l->elem[i-1];
	return OK;
}
 
int ListInsert(Sqlist *l,int i,int e){//i是第几个 
	if(i<1||i>l->length+1){
		printf("插入位置有误！\n");
		exit(OVERFLOW);
	}
	if(l->length==l->listsize){
		int *newbase;
		newbase = (int *)realloc(l->elem,(l->listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase){
			printf("存储空间分配失败！\n");
			exit(OVERFLOW);
		}
		l->elem = newbase;
		l->listsize += LISTINCREMENT;
	}
	l->elem[i-1] = e;
	l->length++;
	return OK;
}
 
//是否需要增加分配空间
int IncreaseList(Sqlist *l,int length){
	if(length>l->listsize){
		int *newbase;
		newbase = (int *)realloc(l->elem,(l->listsize+LISTINCREMENT)*sizeof(int));
		if(!newbase){
			printf("存储空间分配失败！\n");
			exit(OVERFLOW);
		}
		l->elem = newbase;
		l->listsize += LISTINCREMENT;
	}
	return OK;
} 
 
//将两个无序顺序表连接起来
int UnionWx(Sqlist *a,Sqlist b){
	int a_length = a->length,b_length = b.length;
	for(int i=0;i<b_length;i++){//这里的i是下标 GetElem()里的i是位置 
		int num,flag = 0;
		GetElem(&b,i+1,&num);
		for(int j=0;j<a_length;j++){
			if(num==a->elem[j]) {
				flag = 1;//在a顺序表里找到了相同的元素 
				break;
			}
		}
		if(!flag) ListInsert(a,++a_length,num);
	}
	return OK;
}
 
//将两个有序顺序表连接起来 
int UnionYx(Sqlist *a,Sqlist *b,Sqlist *c){
	int *pa,*pb,*pc,*pa_last,*pb_last;
	
	pa = a->elem; pb = b->elem; pa_last = pa+a->length-1; pb_last = pb+b->length-1;
	c->length = a->length+b->length;//C顺序表示要存储a b两个表中的数据的 所以存储空间应该是二者的和 由此来申请C的存储空间
	c->listsize = c->length;
	
	c->elem = (int *)malloc(c->listsize*sizeof(int));
	if(!c->elem){
		printf("合并后的顺序表申请内存失败！\n");
		exit(OVERFLOW); 
	}
	pc = c->elem;
	
	while(pa<=pa_last&&pb<=pb_last){//归并 
		if(*pa<=*pb){
			*pc++ = *pa++;
		}	
		else{
			*pc++ = *pb++;
		}
	}
	
	while(pa<=pa_last) *pc++ = *pa++;//插入顺序表a剩下的元素 
	while(pb<=pb_last) *pc++ = *pb++;//插入顺序表b剩下的元素
	 
	return OK;
}
 
 
main(){
	int a_length,b_length;
	Sqlist a,b,c;
	
	InitList(&a);
	printf("第一个顺序表你想输入多少个元素？\n");
	scanf("%d",&a_length);
	IncreaseList(&a,a_length);//是否需要增加分配空间
	CreatList(&a,a_length);
	PrintList(&a);
	
	InitList(&b);
	printf("\n第二个顺序表你想输入多少个元素？\n");
	scanf("%d",&b_length);
	IncreaseList(&b,b_length);//是否需要增加分配空间
	CreatList(&b,b_length);
	PrintList(&b);
	printf("合并后");
//无序顺序表的合并	
	UnionWx(&a,b);
	PrintList(&a);
//有序线性表的合并
//	UnionYx(&a,&b,&c);
//	PrintList(&c);
