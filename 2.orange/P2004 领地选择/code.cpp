#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1010
int a[MAXN][MAXN];
long long sum[MAXN][MAXN];
int n,m,c;int x,y;
long long ans=-1e15;
int main()
{
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sum[i][j]=a[i][j];
            sum[i][j]+=+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    for(int i=1;i<=n-c+1;i++){
        for(int j=1;j<=m-c+1;j++){
            long long cur=sum[i+c-1][j+c-1]+sum[i-1][j-1]-sum[i+c-1][j-1]-sum[i-1][j+c-1];
            if(ans<cur){
                ans=cur;
                x=i,y=j;
            }
        }
    }

    cout<<x<<" "<<y;

    return 0;
}