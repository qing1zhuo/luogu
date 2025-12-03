#include<iostream>
using namespace std;
#include<algorithm>

int num[45];
int n;unsigned long long K;
unsigned long long dp[45][10];//dp[i][j]前i位数中插入j个x所得最大值
unsigned long long a[45][45];//a[i][j]从第i位到第j位的数字合成的数
unsigned long long tran(int,int);

int main()
{
    cin>>n>>K;
    for(int i=1;i<=n;i++)
    {
        scanf("%1d",&num[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            a[i][j]=tran(i,j);
        }
        dp[i][0]=a[1][i];//前i个数插入0个乘号就是第1~i位数合成的数字；
    }
    /*前i位数字中放入k个乘号，即对所有的属于[k,i-1]的j，在第j和j+1中放入一个乘号，考虑其中最大的j*/
    for(int k=1;k<=K;k++)
    {
        for(int i=k+1;i<=n;i++)
        {
            for(int j=k;j<i;j++)
            {
                dp[i][k]=max(dp[i][k],dp[j][k-1]*a[j+1][i]);
            }
        }
    }
    printf("%llu",dp[n][K]);
    return 0;
}

unsigned long long tran(int left,int right)
{
    unsigned long long x=0;
    for(int i=left;i<=right;i++)
    {
        x=x*10+num[i];
    }
    return x;
}