/* bo6-5.c 树的⼆叉链表(孩⼦－兄弟)存储(存储结构由c6-5.h定义)的基本操作(17个) */
 Status InitTree(CSTree *T)
 { /* 操作结果: 构造空树T */
 *T=NULL;
 return OK;
 }
void DestroyTree(CSTree *T)
 { /* 初始条件: 树T存在。操作结果: 销毁树T */
 if(*T)
 {
 if((*T)->firstchild) /* T有⻓⼦ */
 DestroyTree(&(*T)->firstchild); /* 销毁T的⻓⼦为根结点的⼦树 */
 if((*T)->nextsibling) /* T有下⼀个兄弟 */
 DestroyTree(&(*T)->nextsibling); /* 销毁T的下⼀个兄弟为根结点的⼦树 */
 free(*T); /* 释放根结点 */
 *T=NULL;
 }
 }
 typedef CSTree QElemType; /* 定义队列元素类型 */
#include"c3-2.h" /* 定义LinkQueue类型 */
#include"bo3-2.c" /* LinkQueue类型的基本操作 */
 Status CreateTree(CSTree *T)
 { /* 构造树T */
 char c[20]; /* 临时存放孩⼦结点(设不超过20个)的值 */
 CSTree p,p1;
 LinkQueue q;
 int i,l;
 InitQueue(&q);
 printf("请输⼊根结点(字符型,空格为空): ");
 scanf("%c%*c",&c[0]);
 if(c[0]!=Nil) /* ⾮空树 */
 {
 *T=(CSTree)malloc(sizeof(CSNode)); /* 建⽴根结点 */
 (*T)->data=c[0];
 (*T)->nextsibling=NULL;
 EnQueue(&q,*T); /* ⼊队根结点的指针 */
 while(!QueueEmpty(q)) /* 队不空 */
 {
 DeQueue(&q,&p); /* 出队⼀个结点的指针 */
 printf("请按⻓幼顺序输⼊结点%c的所有孩⼦: ",p->data);
 gets(c);
 l=strlen(c);
 if(l>0) /* 有孩⼦ */
 {
 p1=p->firstchild=(CSTree)malloc(sizeof(CSNode)); /* 建⽴⻓⼦结点 */
 p1->data=c[0];
 for(i=1;i<l;i++)
 {
 p1->nextsibling=(CSTree)malloc(sizeof(CSNode)); /* 建⽴下⼀个兄弟结点 */
 EnQueue(&q,p1); /* ⼊队上⼀个结点 */
 p1=p1->nextsibling;
 p1->data=c[i];
 }
 p1->nextsibling=NULL;
 EnQueue(&q,p1); /* ⼊队最后⼀个结点 */
 }
 else
 p->firstchild=NULL;
 }
 }
 else
 *T=NULL;
 return OK;
 }
#define ClearTree DestroyTree /* ⼆者操作相同 */
 Status TreeEmpty(CSTree T)
 { /* 初始条件: 树T存在。操作结果: 若T为空树,则返回TURE,否则返回FALSE */
 if(T) /* T不空 */
 return FALSE;
 else
 return TRUE;
 }
int TreeDepth(CSTree T)
 { /* 初始条件: 树T存在。操作结果: 返回T的深度 */
 CSTree p;
 int depth,max=0;
 if(!T) /* 树空 */
 return 0;
 if(!T->firstchild) /* 树⽆⻓⼦ */
 return 1;
 for(p=T->firstchild;p;p=p->nextsibling)
 {
 depth=TreeDepth(p);
 if(depth>max)
 max=depth;
 }
 return max+1;
 }
 TElemType Value(CSTree p)
 { /* 返回p所指结点的值 */
 return p->data;
 }
 TElemType Root(CSTree T)
 { /* 初始条件: 树T存在。操作结果: 返回T的根 */
 if(T)
 return Value(T);
 else
 return Nil;
 }
 CSTree Point(CSTree T,TElemType s)
 { /* 返回⼆叉链表(孩⼦－兄弟)树T中指向元素值为s的结点的指针。另加 */
 LinkQueue q;
 QElemType a;
 if(T) /* ⾮空树 */
 {
 InitQueue(&q); /* 初始化队列 */
 EnQueue(&q,T); /* 根结点⼊队 */
 while(!QueueEmpty(q)) /* 队不空 */
 {
 DeQueue(&q,&a); /* 出队,队列元素赋给a */
 if(a->data==s)
 return a;
 if(a->firstchild) /* 有⻓⼦ */
 EnQueue(&q,a->firstchild); /* ⼊队⻓⼦ */
 if(a->nextsibling) /* 有下⼀个兄弟 */
 EnQueue(&q,a->nextsibling); /* ⼊队下⼀个兄弟 */
 }
 }
 return NULL;
 }
 Status Assign(CSTree *T,TElemType cur_e,TElemType value)
 { /* 初始条件: 树T存在,cur_e是树T中结点的值。操作结果: 改cur_e为value */
 CSTree p;
 if(*T) /* ⾮空树 */
 {
 p=Point(*T,cur_e); /* p为cur_e的指针 */
 if(p) /* 找到cur_e */
 {
 p->data=value; /* 赋新值 */
 return OK;
 }
 }
 return Nil; /* 树空或没找到 */
 }
 TElemType Parent(CSTree T,TElemType cur_e)
 { /* 初始条件: 树T存在,cur_e是T中某个结点 */
 /* 操作结果: 若cur_e是T的⾮根结点,则返回它的双亲,否则函数值为＂空＂ */
 CSTree p,t;
 LinkQueue q;
 InitQueue(&q);
 if(T) /* 树⾮空 */
 {
 if(Value(T)==cur_e) /* 根结点值为cur_e */
 return Nil;
 EnQueue(&q,T); /* 根结点⼊队 */
 while(!QueueEmpty(q))
 {
 DeQueue(&q,&p);
 if(p->firstchild) /* p有⻓⼦ */
 {
 if(p->firstchild->data==cur_e) /* ⻓⼦为cur_e */
 return Value(p); /* 返回双亲 */
 t=p; /* 双亲指针赋给t */
 p=p->firstchild; /* p指向⻓⼦ */
 EnQueue(&q,p); /* ⼊队⻓⼦ */
 while(p->nextsibling) /* 有下⼀个兄弟 */
 {
 p=p->nextsibling; /* p指向下⼀个兄弟 */
 if(Value(p)==cur_e) /* 下⼀个兄弟为cur_e */
 return Value(t); /* 返回双亲 */
 EnQueue(&q,p); /* ⼊队下⼀个兄弟 */
 }
 }
 }
 }
 return Nil; /* 树空或没找到cur_e */
 }
 TElemType LeftChild(CSTree T,TElemType cur_e)
 { /* 初始条件: 树T存在,cur_e是T中某个结点 */
 /* 操作结果: 若cur_e是T的⾮叶⼦结点,则返回它的最左孩⼦,否则返回＂空＂ */
 CSTree f;
 f=Point(T,cur_e); /* f指向结点cur_e */
 if(f&&f->firstchild) /* 找到结点cur_e且结点cur_e有⻓⼦ */
 return f->firstchild->data;
 else
 return Nil;
 }
 TElemType RightSibling(CSTree T,TElemType cur_e)
 { /* 初始条件: 树T存在,cur_e是T中某个结点 */
 /* 操作结果: 若cur_e有右兄弟,则返回它的右兄弟,否则返回＂空＂ */
 CSTree f;
 f=Point(T,cur_e); /* f指向结点cur_e */
 if(f&&f->nextsibling) /* 找到结点cur_e且结点cur_e有右兄弟 */
 return f->nextsibling->data;
 else
 return Nil; /* 树空 */
 }
 Status InsertChild(CSTree *T,CSTree p,int i,CSTree c)
 { /* 初始条件: 树T存在,p指向T中某个结点,1≤i≤p所指结点的度+1,⾮空树c与T不相交 */
 /* 操作结果: 插⼊c为T中p结点的第i棵⼦树 */
 /* 因为p所指结点的地址不会改变，故p不需是引⽤类型 */
 int j;
 if(*T) /* T不空 */
 {
 if(i==1) /* 插⼊c为p的⻓⼦ */
 {
 c->nextsibling=p->firstchild; /* p的原⻓⼦现是c的下⼀个兄弟(c本⽆兄弟) */
 p->firstchild=c;
 }
 else /* 找插⼊点 */
 {
 p=p->firstchild; /* 指向p的⻓⼦ */
 j=2;
 while(p&&j<i)
 {
 p=p->nextsibling;
 j++;
 }
 if(j==i) /* 找到插⼊位置 */
 {
 c->nextsibling=p->nextsibling;
 p->nextsibling=c;
 }
 else /* p原有孩⼦数⼩于i-1 */
 return ERROR;
 }
 return OK;
 }
 else /* T空 */
 return ERROR;
 }
 Status DeleteChild(CSTree *T,CSTree p,int i)
 { /* 初始条件: 树T存在,p指向T中某个结点,1≤i≤p所指结点的度 */
 /* 操作结果: 删除T中p所指结点的第i棵⼦树 */
 /* 因为p所指结点的地址不会改变，故p不需是引⽤类型 */
 CSTree b;
 int j;
 if(*T) /* T不空 */
 {
 if(i==1) /* 删除⻓⼦ */
 {
 b=p->firstchild;
 p->firstchild=b->nextsibling; /* p的原次⼦现是⻓⼦ */
 b->nextsibling=NULL;
 DestroyTree(&b);
 }
 else /* 删除⾮⻓⼦ */
 {
 p=p->firstchild; /* p指向⻓⼦ */
 j=2;
 while(p&&j<i)
 {
 p=p->nextsibling;
 j++;
 }
 if(j==i) /* 找到第i棵⼦树 */
 {
 b=p->nextsibling;
 p->nextsibling=b->nextsibling;
 b->nextsibling=NULL;
 DestroyTree(&b);
 }
 else /* p原有孩⼦数⼩于i */
 return ERROR;
 }
 return OK;
 }
 else
 return ERROR;
 }
void PreOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { /* 先根遍历孩⼦－兄弟⼆叉链表结构的树T */
 if(T)
 {
 Visit(Value(T)); /* 先访问根结点 */
 PreOrderTraverse(T->firstchild,Visit); /* 再先根遍历⻓⼦⼦树 */
 PreOrderTraverse(T->nextsibling,Visit); /* 最后先根遍历下⼀个兄弟⼦树 */
 }
 }
void PostOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { /* 后根遍历孩⼦－兄弟⼆叉链表结构的树T */
 CSTree p;
 if(T)
 {
 if(T->firstchild) /* 有⻓⼦ */
 {
 PostOrderTraverse(T->firstchild,Visit); /* 后根遍历⻓⼦⼦树 */
 p=T->firstchild->nextsibling; /* p指向⻓⼦的下⼀个兄弟 */
 while(p)
 {
 PostOrderTraverse(p,Visit); /* 后根遍历下⼀个兄弟⼦树 */
 p=p->nextsibling; /* p指向再下⼀个兄弟 */
 }
 }
 Visit(Value(T)); /* 最后访问根结点 */
 }
 }
void LevelOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { /* 层序遍历孩⼦－兄弟⼆叉链表结构的树T */
 CSTree p;
 LinkQueue q;
 InitQueue(&q);
 if(T)
 {
 Visit(Value(T)); /* 先访问根结点 */
 EnQueue(&q,T); /* ⼊队根结点的指针 */
 while(!QueueEmpty(q)) /* 队不空 */
 {
 DeQueue(&q,&p); /* 出队⼀个结点的指针 */
 if(p->firstchild) /* 有⻓⼦ */
 {
 p=p->firstchild;
 Visit(Value(p)); /* 访问⻓⼦结点 */
 EnQueue(&q,p); /* ⼊队⻓⼦结点的指针 */
 while(p->nextsibling) /* 有下⼀个兄弟 */
 {
 p=p->nextsibling;
 Visit(Value(p)); /* 访问下⼀个兄弟 */
 EnQueue(&q,p); /* ⼊队兄弟结点的指针 */
 }
 }
 }
 }
 }