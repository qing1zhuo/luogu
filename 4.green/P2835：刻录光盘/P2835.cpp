#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//正图
int a[201][201];
int cnt[201];
//反图
int b[201][201];
int cnt_r[201];
//连通块
int block[201][201];//block[i][]表示第i个连通块包含的节点
int t=0;//连通块数
//标记某一节点是否被访问
bool mark[201];
//记录节点退出顺序
int path[201];
int num=0;//记录路径节点数

int ans;
int n;

void dfs(int k)
{
    for(int i=1;i<=cnt[k];i++)
    {
        int cur=a[k][i];
        if(!mark[cur])
        {
            mark[cur]=1;
            dfs(cur);
        }
    }
    path[++num]=k;
}
void dfs_r(int k)
{
    for(int i=1;i<=cnt_r[k];i++)
    {
        int cur=b[k][i];
        if(!mark[cur])
        {
            block[t][0]++;
            block[t][block[t][0]]=cur;
            mark[cur]=1;
            dfs_r(cur);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        while(x)
        {
            cnt[i]++;
            a[i][cnt[i]]=x;
            cnt_r[x]++;
            b[x][cnt_r[x]]=i;
            cin>>x;
        }
    }

    //dfs正图找退出顺序
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            mark[i]=1;
            dfs(i);
        }
    }
    memset(mark,0,sizeof(mark));
    //dfs反图找强连通块
    for(int i=num;i>=1;i--)
    {
        int k=path[i];
        if(!mark[k])
        {   
            t++;
            block[t][0]++;
            block[t][block[t][0]]=k;
            mark[k]=1;
            dfs_r(k);
        }
    }

    //计算每个节点所属的连通块
    int belong[201]={0};
    for(int i=1;i<=t;i++){
        for(int j=1;j<=block[i][0];j++){
            int cur=block[i][j];
            belong[cur]=i;
        }
    }

    //计算入度
    int indegree[201]={0};
    int edge[201][201]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt[i];j++){
            int scc_u=belong[i];
            int scc_v=belong[a[i][j]];
            if(scc_u!=scc_v&&!edge[scc_u][scc_v]){
                indegree[scc_v]++;
                edge[scc_u][scc_v]=1;
            }
        }
    }
    //计算入度为0的连通块数
    for(int i=1;i<=t;i++){
        if(indegree[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}