#include<iostream>
#include<algorithm>
using namespace std;
int pa[2501][2501];
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pa[i][j]=1e9;
            if(i==j)pa[i][i]=0;
        }
    }

    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w<pa[u][v]){
            pa[u][v]=w;
            pa[v][u]=w;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pa[i][j]=min(pa[i][j],pa[i][k]+pa[k][j]);
            }
        }
    }

    cout<<pa[s][t];
    return 0;
}