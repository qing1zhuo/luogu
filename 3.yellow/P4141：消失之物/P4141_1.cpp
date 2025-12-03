#include<stdio.h>
int n,m;
int good[2005];
int dp[2005][2005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&good[i]);
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;//丢失第i件物品但容量为0
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            else{
                for(int k=m;k>=good[j];k--)
                {
                    dp[i][k]=(dp[i][k]+dp[i][k-good[j]])%10;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d",dp[i][j]%10);
        }
        printf("\n");
    }
    return 0;
}