/* c3-3.h 队列的顺序存储结构(可⽤于循环队列和⾮循环队列) */
#define MAXQSIZE 5 /* 最⼤队列⻓度(对于循环队列，最⼤队列⻓度要减1) */
typedef struct
 {
 QElemType *base; /* 初始化的动态分配存储空间 */
 int front; /* 头指针,若队列不空,指向队列头元素 */
 int rear; /* 尾指针,若队列不空,指向队列尾元素的下⼀个位置 */
 }SqQueue;