#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100010
struct RAILWAY{int a,b,c;};
int n,m;
int p[MAXN];
long long f[MAXN];
RAILWAY railway[MAXN];
long long ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>p[i];
    for(int i=1;i<n;i++)cin>>railway[i].a>>railway[i].b>>railway[i].c;
    

    for(int i=1;i<m;i++){
        int start=p[i],end=p[i+1];
        f[min(start,end)]++;
        f[max(start,end)]--;
    }

    for(int i=1;i<n;i++){
        f[i]+=f[i-1];
        ans+=min(f[i]*railway[i].a,f[i]*railway[i].b+railway[i].c);
    }
    
    cout<<ans;
    return 0;
}