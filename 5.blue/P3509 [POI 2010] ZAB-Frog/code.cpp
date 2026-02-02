#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000005
#define ull unsigned long long
int n,k;ull m;
ull a[maxn];
int after[maxn],cur_jump[maxn],next_jump[maxn],ans[maxn];
void pre_next()
{
    int l=1,r=k+1;
    for(int i=1;i<=n;i++){
        while(r<=n&&a[r+1]-a[i]<a[i]-a[l]){
            r++,l++;
        }
        ull dis_l=a[i]-a[l],dis_r=a[r]-a[i];
        if(dis_l>=dis_r)after[i]=l;
        else after[i]=r;
    }
}
void pre_jump(int num)
{   
    for(int i=1;i<=n;i++)cur_jump[i]=after[i];
    for(int k=1;k<=num;k++){
        for(int i=1;i<=n;i++){
            next_jump[i]=cur_jump[cur_jump[i]];
        }
        for(int i=1;i<=n;i++){
            cur_jump[i]=next_jump[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //读入数据
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=i;
    }
    //预处理每个i位置离他第k近的石头
    pre_next();
    //预处理跳了2^t次

    //求解答案
    ull tot=m;
    for(int t=59;t>=0;t--){
        ull cur=(unsigned long long)1<<t;
        if(tot<cur)continue;
        pre_jump(t);
        tot-=cur;
        for(int i=1;i<=n;i++){
            ans[i]=cur_jump[ans[i]];
        }
    }
    //输出答案
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}