#include<iostream>
#include<algorithm>
using namespace std;
int m,k;
int book[505];
int pre[505];
int dp[505][505];//dp[i][j]表示前i本书由j个人抄写
int main()
{
    for(int i=1;i<=505;i++)
    {
        for(int j=1;j<=505;j++)
        {
            dp[i][j]=100000000;
        }
    }
    cin>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>book[i];
        pre[i]=pre[i-1]+book[i];
        dp[i][1]=pre[i];
    }

    for(int j=2;j<=k;j++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int t=1;t<=j-1;t++)
            {
                dp[i][j]=min(dp[i][j],max(dp[t][j-1],pre[i]-pre[t]));
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

