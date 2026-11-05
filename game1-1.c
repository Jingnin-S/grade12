#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int i,j;
    int x=5,y=10;
    char input;
    while(1)
    {
        system("cls");//清屏函数
        for(i=0;i<x;i++)
        {
            printf("\n");
        }
        for(j=0;j<y;j++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
        if(kbhit())
        //scanf("%c",&input);
        {
            input=getch();//不需要回车就可以得到的输入的控制字符
            if(input=='a')
            y--;
            if(input=='d')
            y++;
            if(input=='w')
            x--;
            if(input=='s')
            x++;
        }
    }
    return 0;
}