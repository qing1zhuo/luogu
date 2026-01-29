#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 200010

int n;
long long a[maxn];
long long pre[maxn];
long long ans=-1e9;

void divide(int l,int r)
{
    if(l==r){
        ans=max(ans,a[l]);
        return;
    }
    int mid=(l+r)/2;
    divide(l,mid),divide(mid+1,r);
    long long before=-1e9,after=-1e9;
    for(int i=mid;i>=l;i--){
        before=max(before,pre[mid]-pre[i-1]);
    }
    for(int i=mid+1;i<=r;i++){
        after=max(after,pre[i]-pre[mid]);
    }
    ans=max(ans,before+after);
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    divide(1,n);
    cout<<ans;
    return 0;
}