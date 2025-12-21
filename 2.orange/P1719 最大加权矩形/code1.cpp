#include<iostream>
#include<algorithm>
using namespace std;
int n;
int map[125][125];
long long pre[125][125];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+map[i][j];        
        }
    }

    long long ans=-1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int p=0;p<=i;p++)
            {
                for(int q=0;q<=j;q++)
                {
                    ans=max(ans,pre[i][j]+pre[p][q]-pre[i][q]-pre[p][j]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}