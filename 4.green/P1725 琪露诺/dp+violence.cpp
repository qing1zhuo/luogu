#include<iostream>
#include<algorithm>
using namespace std;
#define N 200005
#define LOG 18
int n, l, r;
int ice[N];//存储冰冻值
bool mark[N];//标记某个位置能不能被走到
int dp[N];//动态规划数组
int le[N], ri[N];//存储区间
int cnt;//区间数量

int find(int a, int b)
{
    int maxn=-1e9; 
    for(int i=a;i<=b;i++)maxn=max(maxn,dp[i]);
    return maxn;
}

int main()
{
    //存储数据
    cin >> n >> l >> r;
    //存储每个区间
    while(ri[cnt]<=n)
    {
        cnt++;
        le[cnt]=le[cnt-1]+l;
        ri[cnt]=ri[cnt-1]+r;
        for(int i=le[cnt];i<=ri[cnt];i++)mark[i]=true;
    }
    for (int i = 0; i <= n; i++)
    {
        cin >> ice[i];
        if(!mark[i])ice[i]=-1e9;//若这个地方根本走不到，就认为其冰冻值极小，避免干扰后续求解
    }ice[0]=0;
    //枚举每个区间
    for(int i=1;i<=cnt;i++)
    {
        int cur_left=le[i],cur_right=min(n,ri[i]);
        if(cur_left>n)break;

        for(int j=cur_left;j<=cur_right;j++)
        {
            int before_l=max(0,j-r),before_r=max(0,j-l);
            dp[j]=find(before_l,before_r)+ice[j];
        }
    }
    //求解
    int ans=-1e9;
    for(int i=n;i>=n-r+1;i--)
    {
        if(mark[i])ans=max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}

