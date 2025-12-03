#include<cstdio>
#include<iostream>
using namespace std;
const int N=11;
int dp[N][N][N][N];
int a[N][N];
int n,x,y,z;
int main()
{
	scanf("%d",&n);
	for(;;)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==0)
		{
			break;
		}
		else
		{
			a[x][y]=z;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=n;l++)
				{
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                    /*max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1])*/
                    /*max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])*/
                    /*a[i][j]+a[k][l]*/
					if(i==k&&l==j)dp[i][j][k][l]-=a[i][j];//注意判断这个点走过几次并处理 
				}
			}
		}
	}
	printf("%d",dp[n][n][n][n]);
	return 0;
}
