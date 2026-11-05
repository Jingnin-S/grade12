/* c6-2.h ⼆叉树的⼆叉链表存储表示 */
typedef struct BiTNode
 {
 TElemType data;
 struct BiTNode *lchild,*rchild; /* 左右孩⼦指针 */
 }BiTNode,*BiTree;