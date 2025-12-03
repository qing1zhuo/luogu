#include<iostream>
using namespace std;
#include<algorithm>
#include<string.h>
/*变量*/
int n;
int matrix[10][10];//记录原始矩阵
int map[10][10];//记录该矩阵路线
int path[10][10];//1表示从上面来，-1表示从左边来
/*函数*/
void MapSet();//地图初始化与路径记录
void print();//打印
void clean(int,int);//清理matrix

int main()
{
    cin>>n;
    memset(matrix,0,sizeof(matrix));
    memset(map,0,sizeof(map));
    int t=1;
    while(t)
    {
        int x,y,p;
        cin>>x>>y>>p;
        matrix[x][y]=p;
        if(x==0)t=0;
    }
    int ans1=0,ans2=0;

    MapSet();
    //print();
    ans1=map[n][n];
    clean(n,n);
    //print();
    MapSet();
    //print();
    ans2=map[n][n];
    cout<<ans1+ans2;
    return 0;
}

void clean(int x,int y)
{
    if(path[x][y]==0)matrix[x][y]==0;
    else if(path[x][y]==1){matrix[x][y]=0;clean(x-1,y);}
    else if(path[x][y]==-1){matrix[x][y]=0;clean(x,y-1);}
}

void MapSet()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            map[i][j]=matrix[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1)//第一行
            {
                map[i][j]+=map[i][j-1];
                path[i][j]=-1;
            }
            else if(j==1)//第一列
            {
                map[i][j]+=map[i-1][j];
                path[i][j]=1;
            }
            else
            {
                if(map[i][j-1]>=map[i-1][j])//左边大于上面，选左边
                {
                    map[i][j]+=map[i][j-1];
                    path[i][j]=-1;
                }
                else if(map[i][j-1]<map[i-1][j])//左边大于上面，选左边
                {
                    map[i][j]+=map[i-1][j];
                    path[i][j]=1;
                }
            }
            path[1][1]=0;
        }
    }
}

void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }  
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<map[i][j]<<" ";
        }    
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<path[i][j]<<" ";
        }    
        cout<<endl;
    }
}