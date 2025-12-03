#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
#define inf INT_MAX
typedef unsigned long long ull;

struct edge
{
    int dest;
    ull weight;
};
vector<edge> g[1000001];
vector<edge> g_rev[1000001];
ull dist1[1000001];
bool mark1[1000001];
ull dist2[1000001];
bool mark2[1000001];

int main()
{
    ios::sync_with_stdio(false);  // 关闭输入输出同步，加速cin/cout
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;ull w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g_rev[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        dist1[i]=inf;dist2[i]=inf;
        mark1[i]=false;mark2[i]=false;
    }
    dist1[1]=dist2[1]=0;

    //正向图dijsktra
    for(int i=1;i<=n;i++){
        int u=-1;
        int min_dis=inf;
        for(int j=1;j<=n;j++){
            if(mark1[j]==false&&dist1[j]<min_dis){
                u=j;min_dis=dist1[j];
            }
        }

        if(u!=-1)mark1[u]=true;

        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].dest;
            ull w=g[u][i].weight;
            dist1[v]=min(dist1[v],dist1[u]+w);
        }
    }
    
    //反向图dijsktra
    for(int i=1;i<=n;i++){
        int u=-1;
        int min_dis=inf;
        for(int j=1;j<=n;j++){
            if(mark2[j]==false&&dist2[j]<min_dis){
                u=j;min_dis=dist2[j];
            }
        }

        if(u!=-1)mark2[u]=true;

        for(int i=0;i<g_rev[u].size();i++)
        {
            int v=g_rev[u][i].dest;
            ull w=g_rev[u][i].weight;
            dist2[v]=min(dist2[v],dist2[u]+w);
        }
    }

    ull ans=0;
    for(int i=1;i<=n;i++){
        ans+=dist1[i]+dist2[i];
    }

    cout<<ans;
    return 0;
}