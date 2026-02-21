#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
struct node
{
    ll w,h;
};
bool operator<(node a,node b)
{
    if(a.w!=b.w)return a.w>b.w;
    else return a.h>b.h;
}

int main()
{
    priority_queue<node>q;
    ll ans=0;
    int n,k;
    cin>>n>>k;
    ll wi;
    for(int i=1;i<=n;i++){
        cin>>wi;
        q.push({wi,1});
    }
    if((n-1)%(k-1)!=0){
        for(int i=1;i<=k-1-(n-1)%(k-1);i++){
            q.push({0,1});
        }
    }
    while(q.size()!=1){
        node tmp;
        ll sum=0,max_h=0;
        for(int i=1;i<=k;i++){
            tmp=q.top();q.pop();
            sum+=tmp.w;
            max_h=max(max_h,tmp.h);
        }
        q.push({sum,max_h+1});
        ans+=sum;
    }
    cout<<ans<<endl<<q.top().h-1;
    return 0;
}
