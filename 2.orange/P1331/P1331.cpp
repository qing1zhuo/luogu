#include<iostream>
#include<climits>
#include<string.h>
using namespace std;
int r,c;
char sea[1005][1005];
int dx[9]={0,0,0,1,1,1,-1,-1,-1};
int dy[9]={0,1,-1,1,0,-1,1,0,-1};
int path[1000005][3];
int leftup_x,leftup_y;//左上
int leftdown_x,leftdown_y;//左下
int rightdown_x,rightdown_y;//右下
int rightup_x,rightup_y;//右上
int head,tail;
void bfs(int);
int check();
int main()
{
    int flag=0;//假定没有船相邻
    int sum=0;
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>sea[i][j];
        }
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(sea[i][j]=='#')
            {
                memset(path,0,sizeof(path));
                leftup_x=i;leftup_y=j;
                leftdown_x=i;leftdown_y=j;
                rightdown_x=i;rightdown_y=j;
                rightup_x=i;rightup_y=j;
                head=1;tail=1;
                sea[i][j]='*';
                path[1][1]=i;path[1][2]=j;
                bfs(1);
                sum++;
                flag=check();
                if(flag)break;
            }
        }
    }

    if(flag)cout<<"Bad placement.\n";
    else printf("There are %d ships.\n",sum);

    return 0;
}

void bfs(int k)
{
    while(head<=tail)
    {
        for(int i=1;i<=8;i++)
        {
            int tx=path[head][1]+dx[i];
            int ty=path[head][2]+dy[i];
            if(sea[tx][ty]=='#')
            {
                tail++;
                path[tail][1]=tx;path[tail][2]=ty;
                sea[tx][ty]='*';
                if(leftup_x>tx||leftup_y>ty)//左上检查
                {
                    leftup_x=tx;leftup_y=ty;
                }
                if(rightdown_x<tx||rightdown_y<ty)//右下检查
                {
                    rightdown_x=tx;rightdown_y=ty;
                }
                if(leftdown_x<tx||leftdown_y>ty)//左下检查
                {
                    leftdown_x=tx;leftdown_y=ty;
                }
                if(rightup_x>tx||rightup_y<ty)//右上检查
                {
                    rightup_x=tx;rightup_y=ty;
                }
            }
        }
        head++;
        bfs(head);
    }
}

int check()
{
    for(int i=leftup_x;i<=rightdown_x;i++)
    {
        for(int j=leftup_y;j<=rightdown_y;j++)
        {
            if(sea[i][j]=='.')return 1;
        }
    }
    for(int i=leftdown_x;i>=rightup_x;i--)
    {
        for(int j=leftdown_y;j<=rightup_y;j++)
        {
            if(sea[i][j]=='.')return 1;
        }
    }
    return 0;
}