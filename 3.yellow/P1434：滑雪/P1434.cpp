#include<iostream>
#include<algorithm>
using namespace std;
int a[105][105];
int r, c;
int mark[105][105];
int path[105][105];
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
int dfs(int x, int y) {
    for (int i = 1; i <= 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (a[tx][ty] < a[x][y] && tx <= r && tx >= 1 && ty >= 1 && ty <= c) {
            if (mark[tx][ty]) {
                path[x][y]=max(path[x][y], path[tx][ty] + 1);
            }
            else {
                mark[tx][ty] = 1;
                path[x][y]=max(path[x][y], dfs(tx, ty) + 1);
            }
        }
    }
    return path[x][y];
}
int main()
{
    int maxx = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            path[i][j] = 1;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            mark[i][j] = 1;
            path[i][j] = dfs(i, j);
            if (path[i][j] > maxx)maxx = path[i][j];
        }
    }
    cout << maxx;
    return 0;
}