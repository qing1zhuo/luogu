#include<iostream>
using namespace std;
int n,m;//n为总钱数，m为物品数量
int v[30],p[30];
int dp[30005];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>p[i];
        p[i]=p[i]*v[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+p[i]);
        }
    }
    cout<<dp[n];
    return 0;
}