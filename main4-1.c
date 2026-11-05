/* main4-1.c 检验bo4-1.c的主程序 */
#include"c1.h"
#include"c4-1.h"
#include"bo4-1.c"
int main()
 {
 int i,j;
 Status k;
 char s,c[MAXSTRLEN+1];
 SString t,s1,s2;
 printf("请输⼊串s1: ");
 gets(c);
 k=StrAssign(s1,c);
 if(!k)
 {
 printf("串⻓超过MAXSTRLEN(=%d)\n",MAXSTRLEN);
 exit(0);
 }
 printf("串⻓为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
 StrCopy(s2,s1);
 printf("拷⻉s1⽣成的串为: ");
 StrPrint(s2);
 printf("请输⼊串s2: ");
 gets(c);
 k=StrAssign(s2,c);
 if(!k)
 {
 printf("串⻓超过MAXSTRLEN(%d)\n",MAXSTRLEN);
 exit(0);
 }
 i=StrCompare(s1,s2);
 if(i<0)
 s='<';
 else if(i==0)
 s='=';
 else
 s='>';
 printf("串s1%c串s2\n",s);
 k=Concat(t,s1,s2);
 printf("串s1联接串s2得到的串t为: ");
 StrPrint(t);
 if(k==FALSE)
 printf("串t有截断\n");
 ClearString(s1);
 printf("清为空串后,串s1为: ");
 StrPrint(s1);
 printf("串⻓为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
 printf("求串t的⼦串,请输⼊⼦串的起始位置,⼦串⻓度: ");
 scanf("%d,%d",&i,&j);
 k=SubString(s2,t,i,j);
 if(k)
 {
 printf("⼦串s2为: ");
 StrPrint(s2);
 }
 printf("从串t的第pos个字符起,删除len个字符，请输⼊pos,len: ");
 scanf("%d,%d",&i,&j);
 StrDelete(t,i,j);
 printf("删除后的串t为: ");
 StrPrint(t);
 i=StrLength(s2)/2;
 StrInsert(s2,i,t);
 printf("在串s2的第%d个字符之前插⼊串t后,串s2为:\n",i);
 StrPrint(s2);
 i=Index(s2,t,1);
 printf("s2的第%d个字⺟起和t第⼀次匹配\n",i);
 SubString(t,s2,1,1);
 printf("串t为：");
 StrPrint(t);
 Concat(s1,t,t);
 printf("串s1为：");
 StrPrint(s1);
 Replace(s2,t,s1);
 printf("⽤串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
 StrPrint(s2);
 }