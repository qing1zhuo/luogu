#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#define maxn 100005
class SegmentTree
{
private:
    struct node{
        long long max;
        long long tag_add;
        long long tag_set;
        bool whether_set=false;
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
        w[u].l=L,w[u].r=R;w[u].tag_add=0,w[u].tag_set=0;
        if(L==R){
            w[u].max=a[L];
            return;
        }
        int M=(L+R)/2;
        build(2*u+1,L,M,a),build(2*u+2,M+1,R,a);
        pushup(u);
        return;
    }
    //打tag
    void make_tag_add(int u,long long k){
        w[u].tag_add+=k;
        w[u].max+=k;
        return;
    }
    void make_tag_set(int u,long long k){
        w[u].tag_add=0;
        w[u].whether_set=true;
        w[u].tag_set=k;
        w[u].max=k;
        return;
    }
    //tag下放
    void push_down(int u){
        if(w[u].whether_set==true){
            make_tag_set(2*u+1,w[u].tag_set);
            make_tag_set(2*u+2,w[u].tag_set);
            w[u].tag_set=0;
            w[u].whether_set=false;
        }
        if(w[u].tag_add!=0){
            make_tag_add(2*u+1,w[u].tag_add);
            make_tag_add(2*u+2,w[u].tag_add);
            w[u].tag_add=0;
        }
        return;
    }
    //节点回溯
    void pushup(int u){
        w[u].max=max(w[2*u+1].max,w[2*u+2].max);
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
    long long query_max(int u,int L,int R){//[L,R]待查询的区间，w[u]被查询的节点
        if(in_range(w[u].l,w[u].r,L,R)){
            return w[u].max;
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            return max(query_max(2*u+1,L,R),query_max(2*u+2,L,R));
        }
        else{
            return LLONG_MIN;
        }
    }
    //区间增加
    void add(int u,int L,int R,long long k){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag_add(u,k);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            add(2*u+1,L,R,k),add(2*u+2,L,R,k);
            pushup(u);
        }
    }
    //区间重置
    void set(int u,int L,int R,long long k){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag_set(u,k);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            set(2*u+1,L,R,k),set(2*u+2,L,R,k);
            pushup(u);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<long long>a;
    for(int i=1;i<=n;i++){
        long long x;cin>>x;
        a.push_back(x);
    }
    SegmentTree st(a);
    while(m--){
        int op;cin>>op;
        if(op==1){
            long long l,r,x;cin>>l>>r>>x;
            st.set(0,l-1,r-1,x);
        }
        else if(op==2){
            long long l,r,x;cin>>l>>r>>x;
            st.add(0,l-1,r-1,x);
        }
        else if(op==3){
            int l,r;cin>>l>>r;
            cout<<st.query_max(0,l-1,r-1)<<endl;
        }
    }
    return 0;
}