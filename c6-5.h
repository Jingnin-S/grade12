/* c6-5.h*/
typedef struct CSNode
 {
 TElemType data;
 struct CSNode *firstchild,*nextsibling;
 }CSNode,*CSTree;