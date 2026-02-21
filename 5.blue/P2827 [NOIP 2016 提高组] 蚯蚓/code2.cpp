#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
bool cmp(ll x,ll y){return x>y;}
ll find_max(queue<ll>&q1,queue<ll>&q2,queue<ll>&q3)
{
    ll max_x,x1,x2,x3;
    if(!q1.empty())x1=q1.front();
    else x1=-1e18;
    if(!q2.empty())x2=q2.front();
    else x2=-1e18;
    if(!q3.empty())x3=q3.front();
    else x3=-1e18;

    if(x1>=x2&&x1>=x3){
        max_x=x1;q1.pop();
    }
    else if(x2>=x1&&x2>=x3){
        max_x=x2;q2.pop();
    }
    else if(x3>=x1&&x3>=x2){
        max_x=x3,q3.pop();
    }
    return max_x;
}
int main()
{
    int n,m,q,t;
    ll u,v;
    ll cur_delta=0;
    cin>>n>>m>>q>>u>>v>>t;
    queue<ll>q1,q2,q3;
    ll a[100005]={0};

    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)q1.push(a[i]);

    for(int i=1;i<=m;i++){
        ll top=find_max(q1,q2,q3)+cur_delta;
        ll top1=top*u/v,top2=top-top1;
        cur_delta+=q;
        top1-=cur_delta,top2-=cur_delta;
        q2.push(top1);
        q3.push(top2);
        if(i%t==0)cout<<top<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n+m;i++){
        ll cur=find_max(q1,q2,q3)+cur_delta;
        if(i%t==0)cout<<cur<<" ";
    }
    return 0;
}