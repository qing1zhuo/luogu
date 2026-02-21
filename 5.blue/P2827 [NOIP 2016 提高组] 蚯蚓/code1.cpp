#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long

int main()
{
    int n,m,q,t;
    double u,v,p;
    ll cur_delta=0;//当前偏移量
    cin>>n>>m>>q>>u>>v>>t;
    p=u/v;
    priority_queue<ll>pq;
    ll a;
    for(int i=1;i<=n;i++){
        cin>>a;
        pq.push(a);
    }
    for(int i=1;i<=m;i++){
        ll cur=pq.top()+cur_delta;
        pq.pop();

        ll cur1=p*cur,cur2=cur-cur1;

        cur_delta+=q;
        cur1-=cur_delta,cur2-=cur_delta;

        pq.push(cur1),pq.push(cur2);

        if(i%t==0)cout<<cur<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n+m;i++){
        if(i%t==0){
            cout<<pq.top()+cur_delta<<" ";
        }
        pq.pop();
    }
    return 0;
}