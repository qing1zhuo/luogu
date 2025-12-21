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
    long long sum=0;
    for(int i=1;i<=n;i++)//上边界
    {
        for(int j=i;j<=n;j++)//下边界
        {
            sum=0;
            for(int k=1;k<=n;k++)
            {
                sum+=pre[j][k]+pre[i-1][k-1]-pre[j][k-1]-pre[i-1][k];
                if(ans<sum)ans=sum;
                if(sum<0)sum=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}