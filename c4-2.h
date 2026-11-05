/* c4-2.h 串的堆分配存储 */
typedef struct
 {
 char *ch; /* 若是⾮空串,则按串⻓分配存储区,否则ch为NULL */
 int length; /* 串⻓度 */
 }HString;