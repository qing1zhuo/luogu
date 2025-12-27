#include<iostream>
using namespace std;
#define MAXN 1005
int map[MAXN][MAXN];
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
        for(int x=x1;x<=x2;x++)
        {
            for(int y=y1;y<=y2;y++)
            {
                map[x][y]++;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}