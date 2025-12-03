#include<iostream>
#include<algorithm>
using namespace std;

struct edge
{
    int u,v;
};
edge E[3001];
int parent[3001];
int urank[3001];
bool mark[3001];
int n,m;

void work();
void init(int n);
int find(int x);
void unionn(int x,int y);
void init_mark(int n);

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        E[i].u=u;E[i].v=v;
    }
    init_mark(n);
    for(int i=1;i<=n;i++)
    {
        init(n);
        work();
        int x;cin>>x;
        mark[x]=false;
    }
    return 0;
}

void work()
{
    //对现存的牧场进行合并
    for(int i=1;i<=m;i++)
    {
        int u=E[i].u,v=E[i].v;
        if(mark[u]&&mark[v])
        {
            unionn(u,v);
        }
    }
    //寻找是否有两个不同的并查集
    bool flag=true;
    int pre=-1;
    for(int i=1;i<=n;i++)
    {
        if(mark[i])
        {
            if(pre==-1)
            {
                pre=find(i);
            }
            else
            {
                if(pre!=find(i))
                {
                    flag=false;
                    break;
                }
            }
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

void init_mark(int n)
{
    for(int i=1;i<=n;i++)
    {
        mark[i]=true;
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        urank[i]=0;
    }
}
int find(int x)
{
    if(x!=parent[x])parent[x]=find(parent[x]);
    return parent[x];
}
void unionn(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    if(urank[fx]==urank[fy])
    {
        parent[fy]=fx;
        urank[fx]=urank[fy]+1;
    }
    else if(urank[fx]<urank[fy])
    {
        parent[fx]=fy;
        urank[fx]=urank[fy]-1;
    }
    else if(urank[fx]>urank[fy])
    {
        parent[fy]=fx;
        urank[fy]=urank[fx]-1;
    }
}

