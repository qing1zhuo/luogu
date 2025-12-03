#include<iostream>
using namespace std;
int n,s;
unsigned long long ans=0;
int tree[100005][3];//0:weight;1:parent;2:pre_sum
void dfs(int,int);
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>tree[i][0];
    tree[1][1]=0;tree[1][2]=tree[1][0];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;cin>>a>>b;
        tree[b][1]=a;
        tree[b][2]=tree[a][2]+tree[b][0];
    }
    for(int i=n;i>=1;i--)
    {
        if(tree[i][2]<s)continue;
        if(tree[i][2]==s){ans++;continue;}
        dfs(i,tree[i][1]);
    }
    cout<<ans;
    return 0;
}

void dfs(int end,int start)
{
    if(start<=0)return;
    if(tree[end][2]-tree[start][2]>s)return;
    if(tree[end][2]-tree[start][2]==s){ans++;return;}
    dfs(end,tree[start][1]);
}