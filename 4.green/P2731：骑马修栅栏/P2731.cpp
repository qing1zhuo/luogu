#include<iostream>
#include<algorithm>
using namespace std;
int map[501][501];//map[i][j]表示i到j的边数
int degree[501];//degree[i]表示i的度数
int maxn=0;//图中最大的顶点编号
int minn=501;//图中最小的顶点编号
int path[1000];//存储路径
int p=0;
int m;

void dfs(int v)
{
    for(int i=minn;i<=maxn;i++)
    {
        while(map[v][i]>0)//如果v到i有边
        {
            map[v][i]--;
            map[i][v]--;
            dfs(i);
        }
    }
    path[++p]=v;//将当前节点加入路径
}
int main()
{
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b]++;
        map[b][a]++;
        degree[a]++;
        degree[b]++;
        maxn=max(maxn,max(a,b));
        minn=min(minn,min(a,b));
    }
    int start=minn;
    for(int i=minn;i<=maxn;i++)
    {
        if(degree[i]%2==1)
        {
            start=i;
            break;
        }
    }
    dfs(start);
    for(int i=p;i>=1;i--)
    {
        cout<<path[i]<<endl;
    }
    return 0;
}