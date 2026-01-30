#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
#define maxn 100005
typedef long long ll;
int N,Q;
struct Fountain{ll d,v;};
struct Question{ll i,v;};
Fountain f[maxn];
Question q[2*maxn];
int up[20][maxn];//up_ki表示从第i个圆盘开始跳2^k步后到达哪个圆盘
ll sum[20][maxn];
int afterbig[maxn];//afterbig_i表示第i个喷泉下第一个大于他的

int myfind(ll index,ll water_v);

int main()
{
    //读取数据
    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        cin>>f[i].d>>f[i].v;
    }
    f[N+1].d=1e9+10,f[N+1].v=1e9+10;
    for(int i=1;i<=Q;i++){
        cin>>q[i].i>>q[i].v;
    }
    //通过单调栈求afterbig数组
    stack<int>s;
    for(int i=1;i<=N;i++){
        while(!s.empty()&&f[s.top()].d<f[i].d){
            afterbig[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        afterbig[s.top()]=N+1;
        s.pop();
    }
    //初始化倍增数组
    for(int i=1;i<=N;i++){
        up[0][i]=afterbig[i];
        sum[0][i]=f[i].v;
    }
    for(int k=1;k<=19;k++){
        for(int i=1;i<=N;i++){
            if(up[k-1][i]==N+1){
                up[k][i]=N+1;
                sum[k][i]=sum[k-1][i];
            }
            else{
                up[k][i]=up[k-1][up[k-1][i]];
                sum[k][i]=sum[k-1][i]+sum[k-1][up[k-1][i]];
            }
        }
    }
    //处理询问
    for(int i=1;i<=Q;i++){
        int ans=myfind(q[i].i,q[i].v);
        if(ans==N+1)cout<<0<<endl;
        else cout<<ans<<endl;
    }
    //test();
    return 0;
}

int myfind(ll index,ll water_v)
{
    for(int k=19;k>=0;k--){
        if(up[k][index]<N+1&&sum[k][index]<water_v){
            water_v-=sum[k][index];
            index=up[k][index];
        }
    }
    if(f[index].v>=water_v)return index;
    else{
        return N+1;
    }
}
