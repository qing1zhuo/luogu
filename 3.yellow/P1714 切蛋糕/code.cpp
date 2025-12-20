#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;
const int NUM=500005;
int n,m;
int a[NUM];
long long pre[NUM];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }

    long long ans=-1e9;
    deque<int>q;
    q.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&q.front()<i-m)q.pop_front();//弹出不符合要求的
        ans=max(ans,pre[i]-pre[q.front()]);
        while(!q.empty()&&pre[q.back()]>pre[i])q.pop_back();
        q.push_back(i);
    }
    cout<<ans;
    return 0;
}