#include<iostream>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200005
#define LOG 18
int n, l, r;
int ice[N];//存储冰冻值
int dp[N];//动态规划数组
deque<int>q;
int main()
{
    memset(dp,128,sizeof(dp));
    dp[0]=0;
    //存储数据
    cin >> n >> l >> r;
    //存储每个区间
    for (int i = 0; i <= n; i++)
    {
        cin >> ice[i];
    }
    //枚举每个区间
    int ans=-1e9;
    for(int i=l;i<=n;i++)
    {
        int before_r=i-l;
        while(!q.empty()&&dp[q.back()]<=dp[before_r])q.pop_back();
        q.push_back(before_r);
        while(!q.empty()&&q.front()+r<i)q.pop_front();
        dp[i]=dp[q.front()]+ice[i];

        if(i+r>n)ans=max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}

