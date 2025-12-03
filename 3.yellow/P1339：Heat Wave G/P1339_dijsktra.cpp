#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//void print_road(int t);
#define inf INT_MAX;

int _v[2501][2501];//_v[i][k]：i节点的第k个终点
int _w[2501][2501];//_w[i][k]:i节点的第k个边
int cnt[2501];
int dist[2501];
bool mark[2501];
//int pre[2501];

int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;

    //存储数据
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        
        cnt[u]++;
        _v[u][cnt[u]]=v;
        _w[u][cnt[u]]=w;

        cnt[v]++;
        _v[v][cnt[v]]=u;
        _w[v][cnt[v]]=w;
    }

    //初始化路径长度
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[s]=0;

    //初始化是否访问
    for(int i=1;i<=n;i++){
        mark[i]=false;
    }
    
    //
    for(int i=1;i<=n;i++){
        int u=-1;
        int min_dis=inf;
        for(int j=1;j<=n;j++){
            if(mark[j]==0&&dist[j]<min_dis){
                min_dis=dist[j];
                u=j;
            }
        }

        if(u!=-1)mark[u]=true;

        if(u==t)break;

        for(int k=1;k<=cnt[u];k++){
            int v=_v[u][k];
            int w=_w[u][k];
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                //pre[v]=u;
            }
        }
    }

    cout<<dist[t]<<endl;
    //print_road(t);
    return 0;
}

// void print_road(int t)
// {
//     if(pre[t]!=0){
//         print_road(pre[t]);
//     }
//     cout<<t<<" ";
// }