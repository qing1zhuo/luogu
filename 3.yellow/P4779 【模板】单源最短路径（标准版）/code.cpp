#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define maxn 100005
#define inf 1e10

vector<int>_v[maxn],_w[maxn],cnt(maxn);
vector<bool>vis(maxn);
vector<long long>dist(maxn);

struct node{
    long long dis;
    int index;
    bool operator<(const node&other)const{
        return dis>other.dis;
    }
};
priority_queue<node>pq;

int n,m,st;

void dijkstra(int n,int start,                                  //节点数量，开始节点
            vector<long long>&dist,                             //dist_i=i节点到起始节点距离
            vector<bool>&vis,                                   //vis_i=i节点是否访问
            vector<int>*_v,vector<int>*_w,vector<int>&cnt,      //节点i的终点/边权/边数
            priority_queue<node>&pq                             //小根堆
            )
{
    //初始化
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[start]=0;
    pq.push({0,start});
    //开始dijkstra
    while(!pq.empty()){
        //取出当前距离最近节点
        int u=pq.top().index;
        pq.pop();
        //检查是否访问
        if(vis[u])continue;
        else vis[u]=true;
        //松弛各边
        for(int i=0;i<cnt[u];i++){
            int v=_v[u][i],w=_w[u][i];
            if(!vis[v]&&dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    cin>>n>>m>>st;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        _v[u].push_back(v),_w[u].push_back(w);
        cnt[u]++;
    }
    dijkstra(n,st,dist,vis,_v,_w,cnt,pq);
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    return 0;
}