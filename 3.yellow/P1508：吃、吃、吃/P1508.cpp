#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int dy[4]={0,0,-1,1};
int dp[205][205];
int a[205][205];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            dp[i][j]=a[i][j];
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int p=1;p<=3;p++)
            {
                int tx=i-1;int ty=j+dy[p];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
                {
                    dp[i][j]=max(dp[i][j],dp[tx][ty]+a[i][j]);
                }
            }
        }
    }
    for(int i=1;i<=3;i++)
    {
        int ty=(m+1)/2+dy[i];
        dp[n+1][(m+1)/2]=max(dp[n+1][(m+1)/2],dp[n][ty]);
    }
    cout<<dp[n+1][(m+1)/2];
    return 0;
}