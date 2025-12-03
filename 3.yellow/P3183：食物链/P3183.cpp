#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

namespace declaration
{
    int n,m;
    vector<int>vec[100001];
    stack<int>st;
    int aov[100001];
    int pt=0;
    int cnt[100001]={0};
    int indegree[100001]={0};
    int outdegree[100001]={0};
    bool mark[100001];
    unsigned long long ans[100001]={0};
}using namespace declaration;


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;//b吃a
        vec[b].push_back(a);
        cnt[b]++;
        indegree[a]++;
        mark[a]=true;//表明有入度
        outdegree[b]++;
    }
    //将初始入度为0的节点压栈
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            st.push(i);
            ans[i]=1;
        }
    }
    //拓扑排序
    while(!st.empty())
    {
        int u=st.top();st.pop();
        for(int i=0;i<cnt[u];i++)
        {
            int v=vec[u][i];
            indegree[v]--;
            ans[v]+=ans[u];
            if(indegree[v]==0)
            {
                st.push(v);
            }
        }
        aov[pt]=u;
        pt++;
    }
    unsigned long long tot=0;
    for(int i=0;i<n;i++)
    {
        if(outdegree[i]==0&&mark[i])
        {
            tot+=ans[i];
        }
    }
    cout<<tot;
    return 0;
}