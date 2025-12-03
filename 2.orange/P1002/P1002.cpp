#include<stdio.h>

int main()
{
    long long a[30][30]={0};
    long long n,m,x,y;
    scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            a[i][j]=1;
        }
    }
    a[x][y]=0;
    if(x+2<=n&&y-1>=0){a[x+2][y-1]=0;}
    if(x+2<=n&&y+1<=m){a[x+2][y+1]=0;}
    if(x-2>=0&&y-1>=0){a[x-2][y-1]=0;}
    if(x-2>=0&&y+1<=m){a[x-2][y+1]=0;}
    if(x+1<=n&&y-2>=0){a[x+1][y-2]=0;}
    if(x+1<=n&&y+2<=m){a[x+1][y+2]=0;}
    if(x-1>=0&&y-2>=0){a[x-1][y-2]=0;}
    if(x-1>=0&&y+2<=m){a[x-1][y+2]=0;}
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0&&j==0)
            {
                continue;
            }
            if(a[i][j]==0)
            {
                continue;
            }
            if(i==0)
            {
                a[i][j]=a[i][j-1];
            }
            else if(j==0)
            {
                a[i][j]=a[i-1][j];
            }
            else
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
    }
    printf("%lld\n",a[n][m]);
    return 0;
}