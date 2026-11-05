#include "stdio.h"
int main()
{
  int a,i,j,z,flag=0;
  scanf("%d",&a);
  int b[a],c[a];
  for(i=0;i<a;i++)
  {
    scanf("%d",&b[i]);
    c[i]=1;
  } 
  for(i=0;i<a;i++)
  {
    z=b[i];
    
    for(j=0;j<a;j++)
    {
      if(b[j]==z)
      {
        c[i]++;
      }
    }
    if(c[i]==2)
    {
        printf("%d ",z);
        flag=1;
    }
  }
  if(flag==0)
  printf("false");

}