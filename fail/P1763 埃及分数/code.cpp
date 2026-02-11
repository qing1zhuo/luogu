#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long

bool flag=false;
int dep=0;
ll ans[50],cur[50];

ll gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

void dfs(ll a,ll b,int x)
{
    if(x>dep)return;
    //找到可行解
    if(a==1&&b>cur[x-1]){
        cur[x]=b;
        //如果是第一次找到解 或 当前解更优，则更新答案
        if(flag==false||ans[x]>cur[x]){
            for(int i=1;i<=dep;i++){
                ans[i]=cur[i];
            }
        }
        flag=true;
        return;
    }

    //分别考虑左右边界
    ll left=max(b/a,cur[x-1]+1);
    ll right=(dep-x+1)*b/a;
    //剪枝，如果右边界过小（分母过大），pass
    if(flag&&ans[dep]<=right){
        right=ans[dep]-1;
    }
    for(ll i=left;i<right;i++){
        cur[x]=i;
        ll gc=gcd(a*i-b,b*i);
        dfs((a*i-b)/gc,b*i/gc,x+1);
    }

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll a,b;
    cin>>a>>b;
    ll c=gcd(a,b);
    a/=c,b/=c;
    cur[0]=1;
    for(dep=1;dep<=15;dep++){
        dfs(a,b,1);
        if(flag){
            for(int i=1;i<=dep;i++)cout<<ans[i]<<" ";
            break;
        }
    }
    return 0;
}