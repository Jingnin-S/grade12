#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 20
#define Width 30

int canvas[High][Width]={0};//二维数组存储游戏画布中对应的元素
//-1边框，-2食物，1蛇头，>1正数为蛇身
int moveDirection;//位置变量
int food_x,food_y;//食物位置


void gotoxy(int x,int y)//将光标移到（x，y）处
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
    
}

void startup()
{
    //system("cls");
    int i,j;
    for(i=0;i<High;i++)
    {
        canvas[i][0]=-1;
        canvas[i][Width-1]=-1;

    }
    for(j=0;j<Width;j++)
    {
        canvas[0][j]=-1;
        canvas[High-1][j]=-1;
    }
    //初始化蛇头位置
    canvas[High/2][Width/2]=1;

    for(i=1;i<=4;i++)
    {
        canvas[High/2][Width/2-i]=i+1;
    }
    moveDirection=4;
    //产生一个新的食物
        food_x=rand()%(High-5)+2;
        food_y=rand()%(Width-5)+2;
        canvas[food_x][food_y]=-2;
}

void show()//显示画面
{
    gotoxy(0,0);
    int i,j;
    for(i=0;j<High;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(canvas[i][j]==0)
            {
                printf(" ");
            }
            else if(canvas[i][j]==-1)
            {
                printf("#");
            }
            else if(canvas[i][j]=1)
            {
                printf("@");
            }
            else if(canvas[i][j]>1)
            {
                printf("*");
            }
            else if(canvas[i][j]==-2)
            {
                printf("F");
            } 
        }
        printf("\n");
    }
    Sleep(100);
}

void moveSnake()//move 核心
{
    int i,j;
    for(i=1;i<High-1;i++)
    {
        for(j=1;j<Width-1;j++)
        {
            if(canvas[i][j]>0)
            canvas[i][j]++;
        }
    }
    int oldTail_i,oldTail_j,oldHead_i,oldHead_j;
    int max=0;

    for(i=1;i<High-1;i++)
    {
        for(j=1;j<Width-1;j++)
        {
            if(canvas[i][j]>0)
            {
                if(max<canvas[i][j])
                {
                    max=canvas[i][j];
                    oldTail_i=i;
                    oldTail_j=j;
                }
                if(canvas[i][j]==2)
                {
                    oldHead_i=i;
                    oldHead_j=j;
                }
            }
        }
    }
    //canvas[oldTail_i][oldTail_j]=0;
    int newhead_i,newhead_j;
    if(moveDirection==1)//向上移动
    {
        //canvas[oldHead_i-1][oldHead_j]=1;//变头
        //判断
        newhead_i=oldHead_i-1;
        newhead_j=oldHead_j;
        
    }
    if(moveDirection==2)//向下移动
    {
        //canvas[oldHead_i+1][oldHead_j]=1;
        newhead_i=oldHead_i+1;
        newhead_j=oldHead_j;
    }
    if(moveDirection==3)//向左移动
    {
        //canvas[oldHead_i][oldHead_j-1]=1;
        newhead_i=oldHead_i;
        newhead_j=oldHead_j-1;
    }
    if(moveDirection==4)//向右移动
    {
        //canvas[oldHead_i][oldHead_j+1]=1;
        newhead_i=oldHead_i;
        newhead_j=oldHead_j+1;
    }
    //吃到食物
    if(canvas[newhead_i][newhead_j]==-2)
    {
        canvas[food_x][food_y]=0;
        //产生一个新的食物
        food_x=rand()%(High-5)+2;
        food_y=rand()%(Width-5)+2;
        canvas[food_x][food_y]=-2;
        //保留原来蛇头，长度加一;

    }
    else
    {
        canvas[oldHead_i][oldHead_j]=0;
    }//否则原来旧蛇尾剪掉，长度不变
    if(canvas[newhead_i][newhead_j]>0||canvas[newhead_i][newhead_j]==-1)
    {
        printf("defeat\n");
        Sleep(2000);
        system("pause");
        exit(0);
    }//判断蛇是否和自身或边框相撞
    else
        canvas[newhead_i][newhead_j]=1;

}



void updateWithoutInput()
{
    moveSnake();
}
void updateWithInput()
{
    char input;
    if(kbhit())//判断是否有输入
    {
        input=getch();
        if(input=='a')
        {
            moveDirection=3;
            moveSnake();
        }
        if(input=='d')
        {
            moveDirection=4;
            moveSnake();
        }
        if(input=='w')
        {
            moveDirection=1;
            moveSnake();
        }
        if(input=='s')
        {
            moveDirection=2;
            moveSnake();
        }
    }
}

int main()
{
    system("cls");
    startup();
    while(1)
    {
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}

