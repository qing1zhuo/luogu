#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define SIZE 105
int indegree[SIZE];
int cnt[SIZE];
vector<int>_v[SIZE];
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int u=i;
        int v;cin>>v;
        while(v!=0)
        {
            cnt[u]++;
            _v[u].push_back(v);
            indegree[v]++;
            cin>>v;
        }
    }

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int cur_u=q.front();
        q.pop();
        for(int i=0;i<cnt[cur_u];i++)
        {
            int cur_v=_v[cur_u][i];
            indegree[cur_v]--;
            if(indegree[cur_v]==0)q.push(cur_v);
        }
        cout<<cur_u<<" ";
    }
    return 0;
}