#include<iostream>
#include<queue>
using namespace std;

namespace declaration
{
    int n,p;
    int path[105][105];
    int weight[105][105];
    int cnt[105];
    int indegree[105];
    int outdegree[105];
    queue<int>q;
    struct Node
    {
        long long c,u;
    };
    Node node[105];
}using namespace declaration;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>p;
    //初始化每个节点
    for(int i=1;i<=n;i++)
    {
        cin>>node[i].c>>node[i].u;
    }
    //存图
    for(int i=1;i<=p;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        cnt[u]++;
        path[u][cnt[u]]=v;
        weight[u][cnt[u]]=w;
        outdegree[u]++,indegree[v]++;
    }
    //存储入度为0的节点
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            node[i].u=0;
        }
    }
    //拓扑排序
    while(!q.empty())
    {
        int u=q.front();q.pop();
        node[u].c-=node[u].u;
        for(int i=1;i<=cnt[u];i++)
        {
            int v=path[u][i];
            int w=weight[u][i];
            if(node[u].c>0)
            {
                node[v].c+=node[u].c*w;
            }
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }
    }
    //输出
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(outdegree[i]==0)
        {
            if(node[i].c>0)
            {
                flag=true;
                cout<<i<<" "<<node[i].c<<endl;
            }
        }
    }
    if(!flag)cout<<"NULL"<<endl;
    return 0;
}