#include<iostream>
#include<queue>
using namespace std;
#define maxn 100005
#define ll long long
ll a[maxn],b[maxn],n;
int main()
{   
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    priority_queue<ll>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll x=a[i]+b[j];
            if(i==1)q.push(x);
            else{
                if(x<q.top()){
                    q.push(x);
                    q.pop();
                }
                else break;
            }
        }
    }
    ll ans[maxn];
    for(int i=1;i<=n;i++){
        ans[i]=q.top();
        q.pop();
    }
    for(int i=n;i;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}