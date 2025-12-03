#include<iostream>
using namespace std;

int n,m;
int map[15][15];
int hp=6;
int path[100][4];//1为x坐标，2为y坐标，3表示从哪里来

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            cin>>map[i][j];
        }
    }
    
    return 0;
}