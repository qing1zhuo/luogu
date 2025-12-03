#include<iostream>
#include<climits>
using namespace std;
#include<algorithm>
int a[305][305];
int m[305];
int pre[305];
int n;
void print();
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
        pre[i]=pre[i-1]+m[i];
    } 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=INT_MAX;
        }
        a[i][i]=0;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=i;k<=j-1;k++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k+1][j]+pre[j]-pre[i-1]);
            }
        }   
    } 
    cout<<a[1][n];
    return 0;
}
