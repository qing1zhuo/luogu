#include<iostream>
#include<cstring>
using namespace std;
int _v[5001][5001];
int cnt[5001];
bool con[5001][5001];
int mark[5001];

void dfs(int x,int start)
{
    for(int i=1;i<=cnt[x];i++){
        int next=_v[x][i];
        if(!mark[next]){
            mark[next]=1;
            con[start][next]=1;
            dfs(next,start);
        }
    }
}
int main()
{
    int n,m,p;
    cin>>n>>m>>p;

    //初始化
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        cnt[a]++;
        _v[a][cnt[a]]=b;

        cnt[b]++;
        _v[b][cnt[b]]=a;
    }
    
    for(int i=1;i<=n;i++)
    {
        con[i][i]=1;
        memset(mark,0,sizeof(mark));
        mark[i]=1;
        dfs(i,i);
    }

    for(int i=1;i<=p;i++)
    {
        int x,y;
        cin>>x>>y;
        if(con[x][y])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}