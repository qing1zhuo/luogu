#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
class SegmentTree
{
private:
    struct node{
        long long sum=0;
        bool tag=0;
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
    void make_tag(int u){
        w[u].tag=!w[u].tag;
        w[u].sum=(w[u].r-w[u].l+1)-w[u].sum;
        return;
    }
    //tag下放
    void push_down(int u){
        if(w[u].tag==0)return;
        make_tag(2*u+1);
        make_tag(2*u+2);
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
    void update(int u,int L,int R){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag(u);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            update(2*u+1,L,R),update(2*u+2,L,R);
            pushup(u);
        }
    }
};

int main()
{
    int n,m;cin>>n>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++)a[i]=0;
    SegmentTree st(a);
    while(m--){
        int op,a,b;cin>>op>>a>>b;
        if(op==0){
            st.update(0,a-1,b-1);
        }
        else if(op==1){
            cout<<st.query_sum(0,a-1,b-1)<<endl;
        }
    }
    return 0;
}