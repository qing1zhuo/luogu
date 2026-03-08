#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
#define MOD 571373
int n,q,m;
class SegmentTree
{
private:
    struct node{
        long long sum=0;
        long long tag_add=0;
        long long tag_mul=1;
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
        w[u].l=L,w[u].r=R;
        if(L==R){
            w[u].sum=a[L]%MOD;
            return;
        }
        int M=(L+R)/2;
        build(2*u+1,L,M,a),build(2*u+2,M+1,R,a);
        pushup(u);
        return;
    }
    //打tag
    void make_tag_add(int u,long long k){
        w[u].tag_add=(w[u].tag_add+k)%MOD;
        w[u].sum=(w[u].sum+k*(w[u].r-w[u].l+1))%MOD;
        return;
    }
    void make_tag_mul(int u,long long k){
        w[u].tag_mul=(w[u].tag_mul*k)%MOD;
        w[u].tag_add=(w[u].tag_add*k)%MOD;
        w[u].sum=(w[u].sum*k)%MOD;
        return;
    }
    //tag下放
    void push_down(int u){
        if(w[u].tag_mul!=1){   
            make_tag_mul(2*u+1,w[u].tag_mul);
            make_tag_mul(2*u+2,w[u].tag_mul);
            w[u].tag_mul=1;
        }
        if(w[u].tag_add!=0){
            make_tag_add(2*u+1,w[u].tag_add);
            make_tag_add(2*u+2,w[u].tag_add);
            w[u].tag_add=0;
        }
    }
    //节点回溯
    void pushup(int u){
        w[u].sum=(w[2*u+1].sum%MOD+w[2*u+2].sum%MOD)%MOD;
        return;
    }
public:
    //构造函数
    SegmentTree(vector<long long>&a){
        int n=a.size();
        w.resize(8*n+5);
        build(0,0,n-1,a);
    }
    //区间查询
    long long query_sum(int u,int L,int R){//[L,R]待查询的区间，w[u]被查询的节点
        if(in_range(w[u].l,w[u].r,L,R)){
            return w[u].sum;
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            return query_sum(2*u+1,L,R)%MOD+query_sum(2*u+2,L,R)%MOD;
        }
        else{
            return 0;
        }
    }
    //区间修改
    void update_add(int u,int L,int R,long long k){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag_add(u,k);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            update_add(2*u+1,L,R,k),update_add(2*u+2,L,R,k);
            pushup(u);
        }
    }
    void update_mul(int u,int L,int R,long long k){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag_mul(u,k);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            update_mul(2*u+1,L,R,k),update_mul(2*u+2,L,R,k);
            pushup(u);
        }
    }
};

int main()
{
    cin>>n>>q>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegmentTree st(a);
    while(q--){
        int op;cin>>op;
        if(op==1){
            long long x,y,k;cin>>x>>y>>k;
            st.update_mul(0,x-1,y-1,k);
        }
        else if(op==2){
            long long x,y,k;cin>>x>>y>>k;
            st.update_add(0,x-1,y-1,k); 
        }
        else if(op==3){
            long long x,y;cin>>x>>y;
            cout<<st.query_sum(0,x-1,y-1)%MOD<<endl;
        }
    }
    return 0;
}