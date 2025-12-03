#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
char a[1010][1010];
long long h[1010][1010],l[1010][1010],r[1010][1010];
unsigned long long ans[1010][1010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            h[i][j]=1;
            l[i][j]=r[i][j]=j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(a[i][j]=='F'&&a[i][j-1]=='F')
            {
                l[i][j]=l[i][j-1];
            }
        }
        for(int j=m-1;j>=1;j--)
        {
            if(a[i][j]=='F'&&a[i][j+1]=='F')
            {
                r[i][j]=r[i][j+1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='F')
            {
                if(a[i-1][j]=='F')
                {
                    //如果上方可以走，则悬线高度加一
                    h[i][j]=h[i-1][j]+1;
                    if(l[i-1][j]>l[i][j])
                    {
                        //如果上方左边界更小，则更新
                        l[i][j]=l[i-1][j];
                    }
                    if(r[i-1][j]<r[i][j])
                    {
                        //如果上方右边界更小，则更新
                        r[i][j]=r[i-1][j];
                    }
                }
                ans[i][j]=(r[i][j]-l[i][j]+1)*h[i][j];
            }
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ans[i][j]>maxn)maxn=ans[i][j];
        }
    }
    cout<<3*maxn;
    //print();
    return 0;
}