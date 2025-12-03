#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define inf INT_MAX
int n,m;
int v1[1001][1001];
int w1[1001][1001];
int cnt1[1001];
bool mark1[1001];
int dist1[1001];

int v2[1001][1001];
int w2[1001][1001];
int cnt2[1001];
bool mark2[1001];
int dist2[1001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cnt1[u]++;
        v1[u][cnt1[u]]=v;
        w1[u][cnt1[u]]=w;

        cnt2[v]++;
        v2[v][cnt2[v]]=u;
        w2[v][cnt2[v]]=w;
    }

    for(int i=1;i<=n;i++){
        dist1[i]=inf;dist2[i]=inf;
        mark1[i]=false;mark2[i]=false;
    }
    dist1[1]=0;dist2[1]=0;
    for(int i=1;i<=n;i++){
        int u=0,min_dis=inf;
        for(int j=1;j<=n;j++){
            if(mark1[j]==false&&min_dis>dist1[j]){
                min_dis=dist1[j];
                u=j;
            }
        }
        if(u==0)break;
        mark1[u]=true;
        for(int j=1;j<=cnt1[u];j++){
            int v=v1[u][j];
            int w=w1[u][j];
            dist1[v]=min(dist1[v],dist1[u]+w);
        }
    }
    for(int i=1;i<=n;i++){
        int u=0;int min_dis=inf;
        for(int j=1;j<=n;j++){
            if(mark2[j]==false&&min_dis>dist2[j]){
                min_dis=dist2[j];u=j;
            }
        }
        if(u==0)break;
        mark2[u]=true;
        for(int j=1;j<=cnt2[u];j++){
            int v=v2[u][j];int w=w2[u][j];
            dist2[v]=min(dist2[v],dist2[u]+w);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=dist1[i]+dist2[i];
    }
    cout<<ans;
    return 0;
}