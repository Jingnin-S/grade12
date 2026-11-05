/* c10-1.h 待排记录的数据类型 */
#define MAXSIZE 20 /* ⼀个⽤作示例的⼩顺序表的最⼤⻓度 */
typedef int KeyType; /* 定义关键字类型为整型 */
typedef struct
 {
 KeyType key; /* 关键字项 */
 InfoType otherinfo; /* 其它数据项，具体类型在主程中定义 */
 }RedType; /* 记录类型 */
typedef struct
 {
 RedType r[MAXSIZE+1]; /* r[0]闲置或⽤作哨兵单元 */
 int length; /* 顺序表⻓度 */
 }SqList; /* 顺序表类型 */