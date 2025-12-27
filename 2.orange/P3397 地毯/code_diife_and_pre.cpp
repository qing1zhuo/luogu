#include<iostream>
using namespace std;
#define MAXN 1005
int map[MAXN][MAXN];
int diffe[MAXN][MAXN];
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int x1,y1,x2,y2;
    for(int i=1;i<=m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        diffe[x1][y1]++;
        diffe[x2+1][y2+1]++;
        diffe[x2+1][y1]--;
        diffe[x1][y2+1]--;
    }

    int minn=1e5;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            map[i][j]=diffe[i][j]-map[i-1][j-1]+map[i][j-1]+map[i-1][j];
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}