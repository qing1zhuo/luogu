#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef struct file {
    int w, v;
}file;
file f[1005];
int n, s;
long long p;
long long dp[1005];//dp[j]表示容量为j时的最大价值
int path[1005];
int cmp(const void* a, const void* b)
{
    file* x = (file*)a;
    file* y = (file*)b;
    return x->w - y->w;
}
int main()
{
    cin >> n >> p >> s;
    for (int i = 1; i <= n; i++) cin >> f[i].w >> f[i].v;
    qsort(f + 1, n, sizeof(file), cmp);
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        int tt = 0;
        for (int j = s; j >= f[i].w; j--)
        {
            if (dp[j] < dp[j - f[i].w] + f[i].v)
            {
                dp[j] = dp[j - f[i].w] + f[i].v;
                tt = 1;
            }
        }
        if(tt)
        {
            path[0]++; path[path[0]] = f[i].w;
        }
        if (dp[s] >= p)
        {
            flag = 1; break;
        }
    }
    if (flag)
    {
        cout << path[path[0]];
    }
    else cout << "No Solution!";
    return 0;
}
