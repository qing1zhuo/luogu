#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int T,num;
int t[10005],v[10005];
ull dp[10000007];
int main()
{
    cin>>T>>num;
    for(int i=1;i<=num;i++)
    {
        cin>>t[i]>>v[i];
    }
    for(int i=1;i<=num;i++)
    {
        for(int j=t[i];j<=T;j++)
        {
            dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
        }
    }
    cout<<dp[T];
    return 0;
}