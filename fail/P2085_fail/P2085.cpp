#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long llu;
llu n,m;
llu f[10005][4];
llu ans[30005];
llu len=0;
llu x=0;
llu func(llu,llu);
int main()
{
    cin>>n>>m;
    for(llu i=1;i<=n;i++)
    {
        for(llu j=1;j<=3;j++)
        {
            scanf("%llu",&f[i][j]);
        }
    }
    while(len<=n+m)
    {
        x++;
        for(llu i=1;i<=n;i++)
        {
            llu y=func(i,x);
            len++;
            ans[len]=y;
        }
    }
    sort(ans+1,ans+m+n+2);
    for(llu i=1;i<=m;i++)printf("%llu ",ans[i]);
    return 0;
}

llu func(llu k,llu x)
{
    return x*x*f[k][1]+x*f[k][2]+f[k][3];
}