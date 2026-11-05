// algo7-10.cpp 检验深度优先和⼴度优先的程序(邻接矩阵存储结构) 
#include"c1.h"
#define MAX_NAME 5 // 顶点字符串的最⼤⻓度+1
#define MAX_INFO 20 // 相关信息字符串的最⼤⻓度+1
typedef int VRType; // 顶点关系类型
typedef char InfoType; // 相关信息类型
typedef char VertexType[MAX_NAME]; // 顶点类型
#include"c7-1.h" // 邻接矩阵存储结构
#include"bo7-1.c" // 邻接矩阵存储结构的基本操作
Status visit(VertexType i)
{
 printf("%s ",i);
 return OK;
}
int main()
{
 MGraph g;
 VertexType v1,v2;
 CreateFAG(&g); // 利⽤数据⽂件创建⽆向图，在bo7-1.cpp中
 Display(g); // 输出⽆向图,在bo7-1.cpp中
 printf("深度优先搜索的结果:\n");
 DFSTraverse(g,visit); // 在bo7-1.cpp中
 printf("修改顶点的值，请输⼊原值 新值: "); 
 scanf("%s%s",v1,v2);
 PutVex(&g,v1,v2); // 在bo7-1.cpp中
 printf("删除⼀条边或弧，请输⼊待删除边或弧的弧尾 弧头:"); 
 scanf("%s%s",v1,v2);
 DeleteArc(&g,v1,v2); // 在bo7-1.cpp中
 printf("⼴度优先搜索的结果:\n");
 BFSTraverse(g,visit); // 在bo7-1.cpp中
}