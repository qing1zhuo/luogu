#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;cin>>n;
    int ans=-100000000;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        f=max(a,f+a);
        ans=max(f,ans);
    }
    cout<<ans;
    return 0;
}