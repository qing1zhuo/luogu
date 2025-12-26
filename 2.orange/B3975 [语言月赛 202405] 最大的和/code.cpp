#include<iostream>
using namespace std;
int a[2005][2005];
int n;
long long maxn=-1e18;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    //处理每一行、列
    for(int i=1;i<=n;i++)
    {
        long long cur1=0,cur2=0;
        for(int j=1;j<=n;j++)
        {
            cur1+=a[i][j];
            cur2+=a[j][i];
        }
        if(cur1>maxn)maxn=cur1;
        if(cur2>maxn)maxn=cur2;
    }

    for(int i=2;i<=2*n;i++)
    {
        long long cur=0;
        if(i<=n)
        {
            for(int j=1;j<i;j++)
            cur+=a[j][i-j];
        }
        else
        {
            for(int j=i-n;j<=n;j++)
            {
                cur+=a[j][i-j];
            }
        }
        if(cur>maxn)maxn=cur;
    }

    for(int i=n-1;i>=0;i--)
    {
        long long cur1=0,cur2=0;
        for(int j=1;j<=n-i;j++)
        {
            cur1+=a[j][i+j];
            cur2+=a[i+j][j];
        }
        if(cur1>maxn)maxn=cur1;
        if(cur2>maxn)maxn=cur2;
    }

    cout<<maxn;
    return 0;
}