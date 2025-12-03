#include<iostream>
using namespace std;
int _v[1001][1001];
int _w[1001][1001];
int cnt[1001];

bool vis[1001];
int dis[1001];
int ans=0;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        cnt[x]++;
        _v[x][cnt[x]]=y;
        _w[x][cnt[x]]=t;
        cnt[y]++;
        _v[y][cnt[y]]=x;
        _w[y][cnt[y]]=t;
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
    }dis[1]=0;

    for(int i=1;i<=n;i++)
    {
        int u=-1,minn=1e9;
        //找未被访问过且dis最小
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                u=j;
            }
        }
        if(u==-1)
        {
            cout<<-1;return 0;
        }
        vis[u]=true;
        for(int i=1;i<=cnt[u];i++)
        {
            int v=_v[u][i];
            int w=_w[u][i];
            if(!vis[v]&&dis[v]>w)
            {
                dis[v]=w;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans<dis[i])ans=dis[i];
    }
    cout<<ans<<endl;
    return 0;
}