#include<iostream>
#include <cmath>
using namespace std;
int n,k;
unsigned long long ans;
void dfs(int,int,int);
int main()
{
    cin>>n>>k;
    int t=ceil((double)n/k);
    for(int i=n-(k-1);i>=t;i--)//第一个数最大为n-k+1，最小为ceil(n/k)
    {
        dfs(2,i,i);
    }
    cout<<ans;
    return 0;
}

void dfs(int step,int pre_sum,int pre_dig)
{
    if(step<k)
    {
        for(int i=1;i<n-pre_sum;i++)
        {
            if(pre_sum>=n||i>pre_dig)continue;
            dfs(step+1,pre_sum+i,i);
        }
    }
    if(step==k)
    {
        if(n-pre_sum>0&&n-pre_sum<=pre_dig)
        {
            ans++;
        }
    }
}