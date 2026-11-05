/* bo6-2.c ⼆叉树的⼆叉链表存储(存储结构由c6-2.h定义)的基本操作(22个) */
 Status InitBiTree(BiTree *T)
 { /* 操作结果: 构造空⼆叉树T */
    *T=NULL;
    return OK;
 }
void DestroyBiTree(BiTree *T)
 { /* 初始条件: ⼆叉树T存在。操作结果: 销毁⼆叉树T */
    if(*T) /* ⾮空树 */
    {
        if((*T)->lchild) /* 有左孩⼦ */
            DestroyBiTree(&(*T)->lchild); /* 销毁左孩⼦⼦树 */
        if((*T)->rchild) /* 有右孩⼦ */
            DestroyBiTree(&(*T)->rchild); /* 销毁右孩⼦⼦树 */
        free(*T); /* 释放根结点 */
        *T=NULL; /* 空指针赋0 */
    }
 }
void CreateBiTree(BiTree *T)
 { /* 算法6.4:按先序次序输⼊⼆叉树中结点的值（可为字符型或整型，在主程中 */
 /* 定义），构造⼆叉链表表示的⼆叉树T。变量Nil表示空（⼦）树。有改动 */
    TElemType ch;
    #ifdef CHAR
        scanf("%c",&ch);
    #endif
    #ifdef INT
        scanf("%d",&ch);
    #endif
    if(ch==Nil) /* 空 */
        *T=NULL;
     else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch; /* ⽣成根结点 */
    CreateBiTree(&(*T)->lchild); /* 构造左⼦树 */
    CreateBiTree(&(*T)->rchild); /* 构造右⼦树 */
    }
 }
 Status BiTreeEmpty(BiTree T)
 { /* 初始条件: ⼆叉树T存在 */
 /* 操作结果: 若T为空⼆叉树,则返回TRUE,否则FALSE */
    if(T)
        return FALSE;
    else
        return TRUE;
 }
#define ClearBiTree DestroyBiTree
int BiTreeDepth(BiTree T)
 { /* 初始条件: ⼆叉树T存在。操作结果: 返回T的深度 */
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i=BiTreeDepth(T->lchild);
    else
        i=0;
    if(T->rchild)
        j=BiTreeDepth(T->rchild);
    else
        j=0;
    return i>j?i+1:j+1;
 }
 TElemType Root(BiTree T)
 { /* 初始条件: ⼆叉树T存在。操作结果: 返回T的根 */
    if(BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
 }
 TElemType Value(BiTree p)
 { /* 初始条件: ⼆叉树T存在，p指向T中某个结点 */
 /* 操作结果: 返回p所指结点的值 */
    return p->data;
 }
void Assign(BiTree p,TElemType value)
 { /* 给p所指结点赋值为value */
    p->data=value;
 }
 typedef BiTree QElemType; /* 设队列元素为⼆叉树的指针类型 */
#include"c3-2.h"
#include"bo3-2.c"
 TElemType Parent(BiTree T,TElemType e)
 { /* 初始条件: ⼆叉树T存在,e是T中某个结点 */
 /* 操作结果: 若e是T的⾮根结点,则返回它的双亲,否则返回＂空＂ */
    LinkQueue q;
    QElemType a;
    if(T) /* ⾮空树 */
    {
        InitQueue(&q); /* 初始化队列 */
        EnQueue(&q,T); /* 树根⼊队 */
        while(!QueueEmpty(q)) /* 队不空 */
        {
            DeQueue(&q,&a); /* 出队,队列元素赋给a */
            if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)
            /* 找到e(是其左或右孩⼦) */
            return a->data; /* 返回e的双亲的值 */
            else /* 没找到e,则⼊队其左右孩⼦指针(如果⾮空) */
            {
                if(a->lchild)
                    EnQueue(&q,a->lchild);
                if(a->rchild)
                    EnQueue(&q,a->rchild);
            }
        }
    }  
    return Nil; /* 树空或没找到e */
 }
 BiTree Point(BiTree T,TElemType s)
 { /* 返回⼆叉树T中指向元素值为s的结点的指针。另加 */
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
            if(a->lchild) /* 有左孩⼦ */
                EnQueue(&q,a->lchild); /* ⼊队左孩⼦ */
            if(a->rchild) /* 有右孩⼦ */
                EnQueue(&q,a->rchild); /* ⼊队右孩⼦ */
        }
    }
    return NULL;
 }
 TElemType LeftChild(BiTree T,TElemType e)
 { /* 初始条件: ⼆叉树T存在,e是T中某个结点 */
 /* 操作结果: 返回e的左孩⼦。若e⽆左孩⼦,则返回＂空＂ */
    BiTree a;
    if(T) /* ⾮空树 */
    {
        a=Point(T,e); /* a是结点e的指针 */
        if(a&&a->lchild) /* T中存在结点e且e存在左孩⼦ */
            return a->lchild->data; /* 返回e的左孩⼦的值 */
    }
    return Nil; /* 其余情况返回空 */
 }
 TElemType RightChild(BiTree T,TElemType e)
 { /* 初始条件: ⼆叉树T存在,e是T中某个结点 */
 /* 操作结果: 返回e的右孩⼦。若e⽆右孩⼦,则返回＂空＂ */
    BiTree a;
    if(T) /* ⾮空树 */
    {
        a=Point(T,e); /* a是结点e的指针 */
        if(a&&a->rchild) /* T中存在结点e且e存在右孩⼦ */
            return a->rchild->data; /* 返回e的右孩⼦的值 */
    }
    return Nil; /* 其余情况返回空 */
 }
 TElemType LeftSibling(BiTree T,TElemType e)
 { /* 初始条件: ⼆叉树T存在,e是T中某个结点 */
 /* 操作结果: 返回e的左兄弟。若e是T的左孩⼦或⽆左兄弟,则返回＂空＂ */
    TElemType a;
    BiTree p;
    if(T) /* ⾮空树 */
    {
        a=Parent(T,e); /* a为e的双亲 */
        p=Point(T,a); /* p为指向结点a的指针 */
    if(p->lchild&&p->rchild&&p->rchild->data==e) /* p存在左右孩⼦且右孩⼦是e */
        return p->lchild->data; /* 返回p的左孩⼦(e的左兄弟) */
    }
    return Nil; /* 树空或没找到e的左兄弟 */
 }
 TElemType RightSibling(BiTree T,TElemType e)
 { /* 初始条件: ⼆叉树T存在,e是T中某个结点 */
 /* 操作结果: 返回e的右兄弟。若e是T的右孩⼦或⽆右兄弟,则返回＂空＂ */
    TElemType a;
    BiTree p;
    if(T) /* ⾮空树 */
    {
        a=Parent(T,e); /* a为e的双亲 */
        p=Point(T,a); /* p为指向结点a的指针 */
        if(p->lchild&&p->rchild&&p->lchild->data==e) /* p存在左右孩⼦且左孩⼦是e */
            return p->rchild->data; /* 返回p的右孩⼦(e的右兄弟) */
    }
    return Nil; /* 树空或没找到e的右兄弟 */
 }
 Status InsertChild(BiTree p,int LR,BiTree c) /* 形参T⽆⽤ */
 { /* 初始条件: ⼆叉树T存在,p指向T中某个结点,LR为0或1,⾮空⼆叉树c与T */
 /* 不相交且右⼦树为空 */
 /* 操作结果: 根据LR为0或1,插⼊c为T中p所指结点的左或右⼦树。p所指结点的 */
 /* 原有左或右⼦树则成为c的右⼦树 */
    if(p) /* p不空 */
    {
        if(LR==0)
        {
            c->rchild=p->lchild;
            p->lchild=c;
        }
        else /* LR==1 */
        {
            c->rchild=p->rchild;
            p->rchild=c;
        }  
        return OK;
    }
    return ERROR; /* p空 */
 }
 Status DeleteChild(BiTree p,int LR) /* 形参T⽆⽤ */
 { /* 初始条件: ⼆叉树T存在,p指向T中某个结点,LR为0或1 */
 /* 操作结果: 根据LR为0或1,删除T中p所指结点的左或右⼦树 */
    if(p) /* p不空 */
    {
        if(LR==0) /* 删除左⼦树 */
            ClearBiTree(&p->lchild);
        else /* 删除右⼦树 */
            ClearBiTree(&p->rchild);
        return OK;
    }
    return ERROR; /* p空 */
 }
void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* 初始条件: ⼆叉树T存在,Visit是对结点操作的应⽤函数。算法6.1，有改动 */
 /* 操作结果: 先序递归遍历T,对每个结点调⽤函数Visit⼀次且仅⼀次 */
    if(T) /* T不空 */
    {
        Visit(T->data); /* 先访问根结点 */
        PreOrderTraverse(T->lchild,Visit); /* 再先序遍历左⼦树 */
        PreOrderTraverse(T->rchild,Visit); /* 最后先序遍历右⼦树 */
    }
 }
void InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* 初始条件: ⼆叉树T存在,Visit是对结点操作的应⽤函数 */
 /* 操作结果: 中序递归遍历T,对每个结点调⽤函数Visit⼀次且仅⼀次 */
    if(T)
    {
        InOrderTraverse(T->lchild,Visit); /* 先中序遍历左⼦树 */
        Visit(T->data); /* 再访问根结点 */
        InOrderTraverse(T->rchild,Visit); /* 最后中序遍历右⼦树 */
    }
 }
typedef BiTree SElemType; /* 设栈元素为⼆叉树的指针类型 */
#include"c3-1.h"
#include"bo3-1.c"
Status InOrderTraverse1(BiTree T,Status(*Visit)(TElemType))
{ /* 采⽤⼆叉链表存储结构，Visit是对数据元素操作的应⽤函数。算法6.3 */
 /* 中序遍历⼆叉树T的⾮递归算法(利⽤栈)，对每个数据元素调⽤函数Visit */
    SqStack S;
    InitStack(&S);
    while(T||!StackEmpty(S))
    {
        if(T)
        { /* 根指针进栈,遍历左⼦树 */
            Push(&S,T);
            T=T->lchild;
        }
        else
        { /* 根指针退栈,访问根结点,遍历右⼦树 */
            Pop(&S,&T);
            if(!Visit(T->data))
            return ERROR;
            T=T->rchild;
        }
    }
    printf("\n");
    return OK;
 }
 Status InOrderTraverse2(BiTree T,Status(*Visit)(TElemType))
 { /* 采⽤⼆叉链表存储结构，Visit是对数据元素操作的应⽤函数。算法6.2 */
 /* 中序遍历⼆叉树T的⾮递归算法(利⽤栈)，对每个数据元素调⽤函数Visit */
    SqStack S;
    BiTree p;
    InitStack(&S);
    Push(&S,T); /* 根指针进栈 */
    while(!StackEmpty(S))
    {
        while(GetTop(S,&p)&&p)
            Push(&S,p->lchild); /* 向左⾛到尽头 */
        Pop(&S,&p); /* 空指针退栈 */
        if(!StackEmpty(S))
        { /* 访问结点,向右⼀步 */
            Pop(&S,&p);
            if(!Visit(p->data))
                return ERROR;
            Push(&S,p->rchild);
        }
    }
    printf("\n");
    return OK;
 }
void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* 初始条件: ⼆叉树T存在,Visit是对结点操作的应⽤函数 */
 /* 操作结果: 后序递归遍历T,对每个结点调⽤函数Visit⼀次且仅⼀次 */
    if(T) /* T不空 */
    {
        PostOrderTraverse(T->lchild,Visit); /* 先后序遍历左⼦树 */
        PostOrderTraverse(T->rchild,Visit); /* 再后序遍历右⼦树 */
        Visit(T->data); /* 最后访问根结点 */
    }
}
void LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* 初始条件：⼆叉树T存在,Visit是对结点操作的应⽤函数 */
 /* 操作结果：层序递归遍历T(利⽤队列),对每个结点调⽤函数Visit⼀次且仅⼀次 */
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(&q);
        EnQueue(&q,T);
        while(!QueueEmpty(q))
        {
            DeQueue(&q,&a);
            Visit(a->data);
            if(a->lchild!=NULL)
                EnQueue(&q,a->lchild);
            if(a->rchild!=NULL)
            EnQueue(&q,a->rchild);
        }
        printf("\n");
    }
 }