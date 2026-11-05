#include <stdio.h>
#include <string.h>
struct stdent
{
    char name[20];
    int num;
    char sex[20];
    int chinese;
    int math;
    int eng;
    int sum;
    int high,low;
};
int main()
{
    int i,j,n,t;
    char p[100];
    scanf("%d",&n);
    struct stdent std[n];
    for(i=0;i<n;i++)
    {
        std[i].low=100;
        std[i].high=0;
        scanf("%s %d %s %d %d %d",std[i].name,&std[i].num,std[i].sex,&std[i].chinese,&std[i].math,&std[i].eng);
        std[i].sum=std[i].chinese+std[i].math+std[i].eng;
        if(std[i].chinese<std[i].low)
        std[i].low=std[i].chinese;
        if(std[i].chinese>std[i].high)
        std[i].high=std[i].chinese;
        if(std[i].math<std[i].low)
        std[i].low=std[i].math;
        if(std[i].math>std[i].high)
        std[i].high=std[i].math;
        if(std[i].eng<std[i].low)
        std[i].low=std[i].eng;
        if(std[i].eng>std[i].high)
        std[i].high=std[i].eng;
        
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",std[i].sum);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d %d ",std[i].high,std[i].low);
    }
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(std[j].sum<std[j+1].sum)
            {
                t=std[j].sum;
                std[j].sum=std[j+1].sum;
                std[j+1].sum=t;
                strcpy(p,std[j+1].name); 
                strcpy(std[j+1].name,std[i].name);
                strcpy(std[i].name,p);   
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",std[i].sum);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%s ",std[i].name);
    }



}