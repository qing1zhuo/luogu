#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
int n,m;
vector<int>_v[maxn];
vector<int>ans(maxn);

void dfs(int cur_max,int cur){
    if(ans[cur]>=cur_max)return;
    ans[cur]=cur_max;
    for(int i=0;i<_v[cur].size();i++){
        dfs(cur_max,_v[cur][i]);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        _v[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        ans[i]=0;
    }
    for(int i=n;i;i--){
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}