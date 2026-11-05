/* c6-1.h ⼆叉树的顺序存储表示 */
#define MAX_TREE_SIZE 100 /* ⼆叉树的最⼤结点数 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点 */
typedef struct
 {
 int level,order; /* 结点的层,本层序号(按满⼆叉树计算) */
 }position;