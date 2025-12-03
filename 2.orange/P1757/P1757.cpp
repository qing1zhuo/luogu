#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
int a[1005],b[1005];
int team[1005][1005];
int dp[1005];
int main()
{
    cin>>m>>n;
    int team_num=0;
    for(int i=1;i<=n;i++)
    {
        int p=0;
        cin>>a[i]>>b[i]>>p;
        team[p][++team[p][0]]=i;
        team_num=max(team_num,p);
    }

    for(int i=1;i<=team_num;i++)//表示第i组
    {
        for(int j=m;j>=0;j--)//表示背包容量最大为j
        {
            for(int k=1;k<=team[i][0];k++)//表示第i组的第k个
            {
                int thing=team[i][k];
                if(j>=a[thing])
                {
                    dp[j]=max(dp[j],dp[j-a[thing]]+b[thing]);
                }
            }
        }
    }
    cout<<dp[m];

    return 0;
}