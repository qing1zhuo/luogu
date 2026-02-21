#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 100005
#define ll long long

struct node{
    ll w,h;
};
bool operator<(node a,node b)
{
    if(a.w!=b.w)return a.w>b.w;
    else return a.h>b.h;
}
priority_queue<node>q;

int main()
{
    int n,k;
    cin>>n>>k;
    ll ans=0,wi;

    for(int i=1;i<=n;i++){
        cin>>wi;
        q.push({wi,1});
    }
    if((n-1)%(k-1)!=0){//如果最后不够
        for(int i=1;i<=k-1-(n-1)%(k-1);i++){//补充权重为0的节点
            q.push({0,1});
        }
    }
    while(q.size()!=1){
        node temp;
        ll sum=0,maxh=0;
        for(int i=1;i<=k;i++){//找k次最小
            temp=q.top();
            sum+=temp.w;
            maxh=max(maxh,temp.h);
            q.pop();
        }
        ans+=sum;
        q.push(node{sum,maxh+1});
    }
    cout<<ans<<endl<<q.top().h-1;
    return 0;
}