#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
#define maxn 105
int n,k,m,s,t;
//bool must_learn[maxn][maxn];//must_learn_ij表示到第i座城市是否学了第j种文化
int path[maxn][maxn];//path_ij表示i和j城市的距离
int dist[maxn];//dist_i表示i城市到起点的最短距离
int cul[maxn];//cul_i表示i城市拥有的文化
int hate[maxn][maxn];//hate_ij表示i文化讨厌j文化

int main()
{
    cin>>n>>k>>m>>s>>t;
    //读取每个城市的文化，并初始化dist
    for(int i=1;i<=n;i++){
        cin>>cul[i];
        dist[i]=1e9;
    }
    dist[s]=0;
    //读取文化的讨厌关系
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            cin>>hate[i][j];
        }
    }
    //读取道路关系
    for(int i=1;i<=m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        path[u][v]=d,path[v][u]=d;
    }
    return 0;
}