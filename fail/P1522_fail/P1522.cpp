#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
int node[200][3];
int n;
int map[200][200];
double maxdis[200];//记录每个点到其他点的最大距离

double dis(int,int);

int main()
{   
    //存数据
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&node[i][1],&node[i][2]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }

    return 0;
}

double dis(int a,int b)
{
    return sqrt((node[a][1]-node[b][1])*(node[a][1]-node[b][1])+(node[a][2]-node[b][2])*(node[a][2]-node[b][2]));
}