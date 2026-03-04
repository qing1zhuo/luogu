#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
class SegmentTree
{
private:
    struct node{
        long long sum;
        long long tag;
        int l,r;
    };
    vector<node>w;
    //判断是否在区间内/区间外
    bool in_range(int l,int r,int L,int R){//[l,r]in[L,R]?
        return (L<=l)&&(r<=R);
    }
    bool out_range(int l,int r,int L,int R){//[l,r]out[L,R]?
        return (r<L)||(l>R);
    }
    //建树函数
    void build(int u,int L,int R,vector<long long>&a){
        w[u].l=L,w[u].r=R;w[u].tag=0;
        if(L==R){
            w[u].sum=a[L];
            return;
        }
        int M=(L+R)/2;
        build(2*u+1,L,M,a),build(2*u+2,M+1,R,a);
        pushup(u);
        return;
    }
    //打tag
    void make_tag(int u,long long k){
        w[u].tag+=k;
        w[u].sum+=k*(w[u].r-w[u].l+1);
        return;
    }
    //tag下放
    void push_down(int u){
        make_tag(2*u+1,w[u].tag);
        make_tag(2*u+2,w[u].tag);
        w[u].tag=0;
        return;
    }
    //节点回溯
    void pushup(int u){
        w[u].sum=w[2*u+1].sum+w[2*u+2].sum;
        return;
    }
public:
    //构造函数
    SegmentTree(vector<long long>&a){
        int n=a.size();
        w.resize(4*n+5);
        build(0,0,n-1,a);
    }
    //区间查询
    long long query_sum(int u,int L,int R){//[L,R]待查询的区间，w[u]被查询的节点
        if(in_range(w[u].l,w[u].r,L,R)){
            return w[u].sum;
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            return query_sum(2*u+1,L,R)+query_sum(2*u+2,L,R);
        }
        else{
            return 0;
        }
    }
    //区间修改
    void update(int u,int L,int R,long long k){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag(u,k);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            update(2*u+1,L,R,k),update(2*u+2,L,R,k);
            pushup(u);
        }
    }
};

int main()
{
    int n,m;cin>>n>>m;
    vector<long long>a;
    while(n--){
        long long x;cin>>x;
        a.push_back(x);
    }
    SegmentTree st(a);
    while(m--){
        int op;cin>>op;
        if(op==1){
            int x,y;long long k;cin>>x>>y>>k;
            st.update(0,x-1,y-1,k);
        }
        else{
            int x,y;cin>>x>>y;
            long long sum=st.query_sum(0,x-1,y-1);
            cout<<sum<<endl;
        }
    }
    return 0;
}