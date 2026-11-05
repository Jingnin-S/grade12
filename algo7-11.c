#include"c1.h"
#define MAX_NAME 3 /* 顶点字符串的最⼤⻓度+1 */
#define MAX_NODE 20
 typedef int InfoType; /* 存放⽹的权值 */
 typedef char VertexType[MAX_NAME]; /* 字符串类型 */
#include"c7-2.h"
#include"bo7-2.c"
void visit(char *i)
 {
 printf("%s ",i);
 }
void CreateGraphF(ALGraph *G)
{ // 采⽤邻接表存储结构，由⽂件构造没有相关信息图或⽹G(⽤⼀个函数构造4种图) 
 int i,j,k,w; // w是权值
 VertexType va,vb; // 连接边或弧的2顶点
 ArcNode *p;
 char filename[13];
 FILE *graphlist;
 printf("请输⼊数据⽂件名(f7-1.txt或f7-2.txt):");
 scanf("%s",filename); printf("请输⼊图的类型(有向图:0,有向⽹:1,⽆向图:2,⽆向⽹:3): "); 
 scanf("%d",&(*G).kind);
 graphlist=fopen(filename,"r"); // 以读的⽅式打开数据⽂件，并以graphlist表示
 fscanf(graphlist,"%d",&(*G).vexnum);
 fscanf(graphlist,"%d",&(*G).arcnum);
 for(i=0;i<(*G).vexnum;++i) // 构造顶点向量
 {
 fscanf(graphlist,"%s",(*G).vertices[i].data);
 (*G).vertices[i].firstarc=NULL; // 初始化与该顶点有关的出弧链表
 }
 for(k=0;k<(*G).arcnum;++k) /* 构造表结点链表 */
 {
 if((*G).kind==1||(*G).kind==3) /* ⽹ */
 fscanf(graphlist,"%d%s%s",&w,va,vb);
 else /* 图 */
 fscanf(graphlist,"%s%s",va,vb);
 i=LocateVex(*G,va); /* 弧尾 */
 j=LocateVex(*G,vb); /* 弧头 */
 p=(ArcNode*)malloc(sizeof(ArcNode));
 p->adjvex=j;
 if((*G).kind==1||(*G).kind==3) /* ⽹ */
 {
 p->info=(int *)malloc(sizeof(int));
 *(p->info)=w;
 }
 else
 p->info=NULL; /* 图 */
 p->nextarc=(*G).vertices[i].firstarc; /* 插在表头 */
 (*G).vertices[i].firstarc=p;
 if((*G).kind>=2) /* ⽆向图或⽹,产⽣第⼆个表结点 */
 {
 p=(ArcNode*)malloc(sizeof(ArcNode));
 p->adjvex=i;
 if((*G).kind==3) /* ⽆向⽹ */
 {
 p->info=(int*)malloc(sizeof(int));
 *(p->info)=w;
 }
 else
 p->info=NULL; /* ⽆向图 */
 p->nextarc=(*G).vertices[j].firstarc; /* 插在表头 */
 (*G).vertices[j].firstarc=p;
 }
 }
 fclose(graphlist); // 关闭数据⽂件
}
Boolean visited[MAX_VERTEX_NUM]; /* 访问标志数组(全局量) */
void isConnected(ALGraph G, int v1, int v2, int *flag) {
 int w;
 VertexType w1;
 VertexType tmp;
 if(v1==v2) 
 *flag = TRUE;
 if(*flag) 
 return;
 visited[v1]=TRUE;
 for(w=FirstAdjVex(G, strcpy(tmp,*GetVex(G,v1))); w>=0; w=NextAdjVex(G, strcpy(tmp,*GetVex(G,v1)), strcpy(w1,*GetVex
 {
 if(!visited[w]) 
 isConnected(G, w, v2, flag);
 }
}
int main() 
{
 ALGraph g;
 CreateGraphF(&g); // 利⽤数据⽂件创建⽆向图，在bo7-2.cpp中
 Display(g); // 输出⽆向图，在bo7-2.cpp中
 printf("深度优先搜索的结果:\n");
 DFSTraverse(g,visit); // 调⽤算法7.4，在bo7-2.cpp中
 // DFSTraverse1(g,visit); // 另⼀种⽅法，在bo7-2.cpp中
 printf("⼴度优先搜索的结果:\n");
 BFSTraverse(g,visit); // 调⽤算法7.6，在bo7-2.cpp中
 // BFSTraverse1(g,visit); // 另⼀种⽅法，在bo7-2.cpp中
 int flag=FALSE;
 int v, v1, v2;
 for(v=0;v<g.vexnum;v++)
 visited[v]=FALSE; /* 访问标志数组初始化 */
 printf("Please input two node index: ");
 scanf("%d%d", &v1, &v2);
 isConnected(g, v1, v2, &flag);
 if (flag)
 printf("node %d and %d is connected.\n", v1, v2);
 else
 printf("node %d and %d is not connected.\n", v1, v2);
 DestroyGraph(&g); // 销毁图g 
}