#include<iostream>
#include<cstring>
using namespace std;
int _v[5001][5001];
int cnt[5001];
int mark[5001];
int block[5001][5001];
int t=0;
void dfs(int x)
{
    for(int i=1;i<=cnt[x];i++){
        int next=_v[x][i];
        if(!mark[next]){
            mark[next]=1;
            block[t][0]++;
            block[t][block[t][0]]=next;
            dfs(next);
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
        if(!mark[i]){
            t++;
            block[t][0]++;
            block[t][block[t][0]]=i;
            mark[i]=1;
            dfs(i);
        }
        
    }
    int belong[5001];
    for(int i=1;i<=t;i++){
        for(int j=1;j<=block[i][0];j++){
            belong[block[i][j]]=i;
        }
    }
    for(int i=1;i<=p;i++)
    {
        int a,b;
        cin>>a>>b;
        if(belong[a]==belong[b]){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}