/*c7-1 图的数组表示（邻接矩阵）*/
#define MAX_VERTEX_NUM 20 /*最大顶点个数*/
#define TNFINITY INT_MAX/*用整形最大值代替*/
typedef enum{DG,DN,AG,AN}GraphKind;/*有向图，有向网，无向图，无向网*/
typedef struct
{
    VRType adj;/*顶点关系类型，对无权图，用1，0表示是否相邻*/
            /*对带权图，c则为权值类型*/
            InfoType *info; /*该弧相关信息的指针（可无）*/

}ArcCell,AdjMatrix[MAX_VERTEX_NUM]{MAX_VERTEX_NUM};
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];/*顶点向量*/
    AdjMatrix arcs;/*邻接矩阵*/
    int vexnum,arcnum;/*图的当前顶点数和弧数*/
    GraphKind kind;/*图的种类标志*/

}MGraph;