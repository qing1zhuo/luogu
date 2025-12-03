#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define inf INT_MAX;
int _v[2001][2001];
double _w[2001][2001];
double dist[2001];
int cnt[2001];
bool mark[2001];
int n,m;
int a,b;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int p,q;
        double w;
        cin>>p>>q>>w;
        cnt[p]++;cnt[q]++;
        _v[p][cnt[p]]=q;_w[p][cnt[p]]=w;
        _v[q][cnt[q]]=p;_w[q][cnt[q]]=w;
    }
    cin>>a>>b;
    for(int i=1;i<=n;i++){
        dist[i]=inf;
        mark[i]=false;
    }
    dist[b]=100;

    for(int i=1;i<=n;i++){
        int u=-1;
        int min_dist=inf;
        for(int j=1;j<=n;j++){
            if(mark[j]==false&&dist[j]<min_dist){
                u=j;
                min_dist=dist[j];
            }
        }
        if(u==-1)break;
        else mark[u]=true;

        for(int j=1;j<=cnt[u];j++){
            int v=_v[u][j];
            double w=_w[u][j];
            if(dist[v]>dist[u]/(1-w/100))dist[v]=dist[u]/(1-w/100);
        }
    }

    printf("%.8lf",dist[a]);
    return 0;
}