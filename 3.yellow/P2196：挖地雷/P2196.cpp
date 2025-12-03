#include<stdio.h>
#include<string.h>
int n;
int dijiao[25][25];//[i][0]表示i号地窖的地雷数
int sum[25];//sum[i]表示i号地窖可以获得的最多地雷数
int path[25];

int main()
{
    memset(dijiao,0,sizeof(dijiao));
    memset(sum,0,sizeof(sum));
    memset(path,0,sizeof(path));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&dijiao[i][0]);
        sum[i]=dijiao[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&dijiao[i][j]);
        }
    }

    sum[n]=dijiao[n][0];
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(dijiao[i][j]==1&&sum[i]<sum[j]+dijiao[i][0])
            {
                sum[i]=sum[j]+dijiao[i][0];
                path[i]=j;
            }
        }
    }

    int x=1;
    for(int i=1;i<=n;i++)
    {
        if(sum[x]<sum[i])x=i;
    }
    int ans=sum[x];

    while(x)
    {
        if(path[x])printf("%d ",x);
        else printf("%d",x);
        x=path[x];
    }
    printf("\n%d",ans);
    return 0;
}