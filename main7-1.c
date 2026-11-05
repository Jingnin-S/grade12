/* main7-1.c 检验bo7-1.c的主程序 */
#define MAX_NAME 5 /* 顶点字符串的最⼤⻓度+1 */
#define MAX_INFO 20 /* 相关信息字符串的最⼤⻓度+1 */
 typedef int VRType;
 typedef char InfoType;
 typedef char VertexType[MAX_NAME];
#include"c1.h"
#include"c7-1.h"
#include"bo7-1.c"
 Status visit(VertexType i)
 {
 printf("%s ",i);
 return OK;
 }
int main()
{
 int i,j,k,n;
 VertexType v1,v2;
 MGraph g;
 CreateFAG(&g);
 Display(g);
 printf("修改顶点的值，请输⼊原值 新值: ");
 scanf("%s%s",v1,v2);
 PutVex(&g,v1,v2);
 printf("深度优先搜索的结果:\n");
 DFSTraverse(g,visit);
 printf("⼴度优先搜索的结果:\n");
 BFSTraverse(g,visit);
 printf("删除⼀条边或弧，请输⼊待删除边或弧的弧尾 弧头：");
 scanf("%s%s",v1,v2);
 DeleteArc(&g,v1,v2);
 Display(g);
 DestroyGraph(&g);
 printf("请顺序选择有向图,有向⽹,⽆向图,⽆向⽹\n");
 for(i=0;i<4;i++) /* 验证4种情况 */
 {
 CreateGraph(&g);
 Display(g);
 printf("插⼊新顶点，请输⼊顶点的值: ");
 scanf("%s",v1);
 InsertVex(&g,v1);
 printf("插⼊与新顶点有关的弧或边，请输⼊弧或边数: ");
 scanf("%d",&n);
 for(k=0;k<n;k++)
 {
 printf("请输⼊另⼀顶点的值: ");
 scanf("%s",v2);
 if(g.kind<=1) /* 有向 */
 {
 printf("对于有向图或⽹，请输⼊另⼀顶点的⽅向(0:弧头 1:弧尾): ");
 scanf("%d",&j);
 if(j)
 InsertArc(&g,v2,v1);
 else
 InsertArc(&g,v1,v2);
 }
 else /* ⽆向 */
 InsertArc(&g,v1,v2);
 }
 Display(g);
 printf("删除顶点及相关的弧或边，请输⼊顶点的值: ");
 scanf("%s",v1);
 DeleteVex(&g,v1);
 Display(g);
 DestroyGraph(&g);
 }
 return OK;
}