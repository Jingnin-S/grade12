/* c7-2.h 图的邻接表存储表示 */
#define MAX_VERTEX_NUM 20
typedef enum{DG,DN,AG,AN}GraphKind; /* {有向图,有向⽹,⽆向图,⽆向⽹} */
typedef struct ArcNode
 {
 int adjvex; /* 该弧所指向的顶点的位置 */
 struct ArcNode *nextarc; /* 指向下⼀条弧的指针 */
 InfoType *info; /* ⽹的权值指针） */
 }ArcNode; /* 表结点 */
typedef struct
 {
 VertexType data; /* 顶点信息 */
 ArcNode *firstarc; /* 第⼀个表结点的地址,指向第⼀条依附该顶点的弧的指针 */
 }VNode,AdjList[MAX_VERTEX_NUM]; /* 头结点 */
typedef struct
 {
 AdjList vertices;
 int vexnum,arcnum; /* 图的当前顶点数和弧数 */
 int kind; /* 图的种类标志 */
 }ALGraph;