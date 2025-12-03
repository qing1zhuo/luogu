#include<iostream>
using namespace std;
#include<algorithm>
int m,n;
int v[65],p[65],q[65];
int attach[65][65];//attach[i][j]=k表示第i个物品的第j个附件为k
int dp[32005];
int main()
{
    /*存数据*/
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>p[i]>>q[i];
        p[i]=p[i]*v[i];
        if(q[i])
        {
            attach[q[i]][0]++;
            int k=attach[q[i]][0];
            attach[q[i]][k]=i;
        }
    }
    /*对每个附件作01背包整理*/
    for(int i=1;i<=n;i++)
    {
        if(attach[i][0]);
    }
    return 0;
}