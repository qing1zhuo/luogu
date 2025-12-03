#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
#define MOD 10007
namespace dec
{
    int node[100010][2];
    vector<int>color1[100010];//even
    vector<int>color2[100010];//odd
    int n,m;
    unsigned long long ans=0;
}using namespace dec;
int main()
{
    // ifstream fcin;
    // fcin.open("P2671_8.in");
    // fcin>>n>>m;
    // for(int i=1;i<=n;i++)fcin>>node[i][0];
    // for(int i=1;i<=n;i++)fcin>>node[i][1];

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>node[i][0];
    for(int i=1;i<=n;i++)cin>>node[i][1];
    for(int i=1;i<=n;i+=2)
    {
        int col=node[i][1];
        color1[col].push_back(i);
    }
    for(int i=2;i<=n;i+=2)
    {
        int col=node[i][1];
        color2[col].push_back(i);
    }

    //handle even
    for(int i=1;i<=m;i++)
    {
        int size=color1[i].size();
        for(int p=0;p<size-1;p++)
        {
            int l=color1[i][p];
            for(int q=p+1;q<size;q++)
            {
                int r=color1[i][q];
                ans=ans%MOD+((l+r)%MOD*(node[l][0]+node[r][0])%MOD)%MOD;
                ans%=MOD;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int size=color2[i].size();
        for(int p=0;p<size-1;p++)
        {
            int l=color2[i][p];
            for(int q=p+1;q<size;q++)
            {
                int r=color2[i][q];
                ans=ans%MOD+((l+r)%MOD*(node[l][0]+node[r][0])%MOD)%MOD;
                ans%=MOD;
            }
        }
    }
    cout<<ans;
    return 0;
}

//ans=ans%MOD+((l+r)%MOD*(num[l]+num[r])%MOD)%MOD;
//ans%=MOD;