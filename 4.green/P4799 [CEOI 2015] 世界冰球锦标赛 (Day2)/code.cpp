#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

int n;//比赛数量
ll m;//总预算
ll ans=0;//答案
ll a[45];//每场比赛
unordered_map<ll,ll>half_map[2];//key:当前总花费;value:该花费的方案数。0 left, 1 right
vector<pair<ll,ll>>half_vec[2];//first:总花费;second:该花费的方案数
vector<unsigned long long>pre_right;

void dfs(int cur,int end,ll sum,int direct)
{
    if(cur>end){
        half_map[direct][sum]+=1;
        return;
    }
    if(sum+a[cur]<=m)dfs(cur+1,end,sum+a[cur],direct);
    dfs(cur+1,end,sum,direct);
}
ll binary_search(vector<pair<ll,ll>>&right_vec,ll target,ll right_size)
{
    ll res=0;
    ll l=0,r=right_size-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(right_vec[mid].first<=target){
            l=mid+1;
            res=mid;
        }
        else{
            r=mid-1;
        }
    }
    return res;
}
int main()
{
    //数据读取
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    //深搜
    int mid=n/2;
    dfs(1,mid,0,0);
    dfs(mid+1,n,0,1);
    //转换为vector并排序
    for(int i=0;i<2;i++){
        for(const auto& pair:half_map[i]){
            half_vec[i].push_back(pair);
        }
        sort(half_vec[i].begin(),half_vec[i].end());
    }
    ll left_size=half_vec[0].size(),right_size=half_vec[1].size();
    //给右数组做前缀和
    ll pre_sum=0;
    for(ll i=0;i<right_size;i++){
        pre_sum=pre_sum+half_vec[1][i].second;
        pre_right.push_back(pre_sum);
    }
    //合并左右vector答案
    for(ll i=0;i<left_size;i++){//遍历左边所有选择
        ll left_sum=half_vec[0][i].first;
        ll left_ans=half_vec[0][i].second;
        //找出不大于m-left_sum的最大值在右vec的索引
        ll right_index=binary_search(half_vec[1],m-left_sum,right_size);
        //计算答案
        ans+=left_ans*pre_right[right_index];
    }
    cout<<ans;
    return 0;
}