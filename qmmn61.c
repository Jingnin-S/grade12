#define MAX_NAME 5 /* 顶点字符串的最大长度+1 */
#define MAX_INFO 20 /* 相关信息字符串的最大长度+1 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define M 4
#define N 6

typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];  /*顶点类型，每个顶点名称为一个字符串*/
 
typedef enum{DG,DN,UDG,UDN}GraphKind; /* {有向图,有向网,无向图,无向网} */
typedef struct
{
    VRType adj;  /* 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否； */
                /* 对带权图，c则为权值类型 */
    InfoType *info; /* 该弧相关信息的指针(可无) */
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    char vexs[MAX_VERTEX_NUM][MAX_NAME];  /* 顶点数组 */
    AdjMatrix arcs;     /* 邻接矩阵 */
    int vexnum,arcnum; /* 图的当前顶点数和弧数 */
    GraphKind kind;   /* 图的种类标志 */
}MGraph;

int visited[MAX_VERTEX_NUM];  /*顶点访问标记数组，初始化为0 */

/* 初始化*/
void InitUDG(MGraph *G, int vexnum, int cvexnum)
{
    int i,j;
    G->vexnum = vexnum;
    for(i=0;i<G->vexnum;++i)  /* 构造顶点向量 */
    {
      if(i<cvexnum)
        sprintf(G->vexs[i], "%c%d",'c',i+1);
      else
        sprintf(G->vexs[i], "%c%d",'d',i+1-cvexnum);
    }
    for(i=0;i<G->vexnum;++i) /* 初始化邻接矩阵 */
      for(j=0;j<G->vexnum;++j)
      {
        G->arcs[i][j].adj=0;  /* 图 */
        G->arcs[i][j].info=NULL;
      }
    G->arcnum=0;    
    G->kind=UDG;
}

/*创建邻接矩阵*/
void CreateAdjArray(MGraph *G, int *h, int m, int n)
{
  int i, j;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      if(*(h+i*n+j)==1){
        G->arcs[i][m+j].adj=1;
        G->arcs[m+j][i].adj=1;
      }
    }
  }  
}

/*输出图的顶点和邻接矩阵*/
/*具体格式参见问题（1）*/
void Display(MGraph G)
{
 //★★★请补全代码
 
}

/* 根据邻接矩阵，计算无向图的边的数目并更新G.arcnum*/
/* 参见问题（2）说明*/
void UpdateArcNum(MGraph *G)
{
 //★★★请补全代码
    
}

void DFS(MGraph G,int v)
{ /* 从第v个顶点出发递归地深度优先遍历图G */
  int w;
  visited[v]=TRUE; /* 设置访问标志为TRUE(已访问) */
  printf("%s-", G.vexs[v]);
  for(w=0;w<G.vexnum;w++)
   	if(G.arcs[v][w].adj==1)
       if(!visited[w])
          DFS(G,w); /* 对v的尚未访问的序号为w的邻接顶点递归调用DFS */
}

int visited[MAX_VERTEX_NUM];  /*顶点访问标记数组，应初始化为FALSE */
void DFSTraverse(MGraph G)
{ /* 初始条件: 图G存在,Visit是顶点的应用函数。 */
  /* 操作结果: 从第1个顶点起,深度优先遍历图G */

  int v;
  printf("深度优先遍历结果：");

//★★★请补全代码
 
}

int main()
{
    int i;
    MGraph G;
    int arcnum;
    int H[M][N]={
      {1,1,0,1,0,0},{0,1,1,0,1,0},{1,0,0,0,1,1},{0,0,1,1,0,1}
    };

    InitUDG(&G,  M+N, M);
    CreateAdjArray(&G, &H[0][0], M, N);
    Display(G);
    UpdateArcNum(&G);
    printf("图的边数为:%d\n", G.arcnum);
    DFSTraverse(G);
}
