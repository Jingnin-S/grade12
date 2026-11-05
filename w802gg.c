#include<stdio.h>
#include<string.h>
int main()
{
    int c,s[26],i,max,j;
    char str[1000];
    scanf("%d",&c);
    while(c>0)
    {
       scanf("%s",str);
       for(i=0;i<26;i++)
           s[i]=0;
       for(i=0;i<strlen(str);i++)
           s[str[i]-'a']++;
       max=0;
       for(i=1;i<26;i++)
       {
           if(s[i]>s[max])
              max=i;  
       }
       for(j=1;j<26;j++)
            {
                if(s[j]==s[max]&&j<max)
                    max=j;
                    break;
            }
           printf("%c %d\n",max+'a',s[max]);
           c--;
    }
}
