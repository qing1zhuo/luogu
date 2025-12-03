#include<iostream>
using namespace std;
#include<algorithm>
int m,n;
int w[10005];int v[10005];
int dp[10005];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=w[i];j<=m;j++)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m];
    return 0;
}