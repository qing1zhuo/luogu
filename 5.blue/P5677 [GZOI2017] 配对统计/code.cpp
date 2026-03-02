#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 300005
#define ll long long

//次数
int n,m;
ll ans=0;

//原数据相关
struct Num{ll num;int pos;}a[maxn];//原数据结构体
bool cmp_Num(Num a,Num b){return a.num<b.num;}//按照num升序排列

//好对相关
struct Gpair{int lpos,rpos;};//好对结构体
vector<Gpair>gp;//存储好对的向量
bool cmp_Gpair(Gpair a,Gpair b){return a.rpos<b.rpos;}//按照右端点升序排列
void push_Gpair(Num a,Num b)//存储好对
{
    int l_pos=min(a.pos,b.pos),r_pos=max(a.pos,b.pos);
    gp.push_back({l_pos,r_pos});
    return;
}

//询问相关
struct Ques{int lpos,rpos,pos;}q[maxn];//询问结构体
bool cmp_Ques(Ques a,Ques b){return a.rpos<b.rpos;}//按照右端点升序排列

//树状数组相关
ll tree[maxn];//树状数组，tree_i表示左端点在[i-low_bit(i)+1,i]内的好对数量
int low_bit(int x)//low_bit计算
{
    return x&(-x);
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=low_bit(i))tree[i]+=k;
    return;
}
ll query(int x)
{
    ll res=0;
    for(int i=x;i;i-=low_bit(i))res+=tree[i];
    return res;
}


void test(){
    for(int i=0;i<gp.size();i++)cout<<gp[i].lpos<<" "<<gp[i].rpos<<endl;
}

int main()
{
    //原数据处理
    cin>>n>>m;
    if(n==1){cout<<0;return 0;}
    for(int i=1;i<=n;i++){
        cin>>a[i].num;a[i].pos=i;
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].lpos>>q[i].rpos;
        q[i].pos=i;
    }
    sort(a+1,a+1+n,cmp_Num);
    sort(q+1,q+1+m,cmp_Ques);
    
    //寻找好对
    push_Gpair(a[1],a[2]),push_Gpair(a[n-1],a[n]);
    for(int i=2;i<n;i++){
        ll l_abs=abs(a[i].num-a[i-1].num),r_abs=abs(a[i].num-a[i+1].num);
        if(l_abs<r_abs)push_Gpair(a[i],a[i-1]);
        else if(l_abs>r_abs)push_Gpair(a[i],a[i+1]);
        else {push_Gpair(a[i],a[i-1]),push_Gpair(a[i],a[i+1]);}
    }
    sort(gp.begin(),gp.end(),cmp_Gpair);

    //对于每个询问，进行处理
    ll gp_pt=0;//好对指针
    for(int i=1;i<=m;i++){
        Ques cur=q[i];
        while(gp_pt<gp.size()&&gp[gp_pt].rpos<=cur.rpos){
            add(gp[gp_pt].lpos,1);
            gp_pt++;
        }
        ans+=cur.pos*(gp_pt-query(cur.lpos-1));
    }
    cout<<ans;
    return 0;
}


