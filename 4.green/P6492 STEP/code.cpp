#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 200005
#define inf 1000000000
class SegmentTree
{
private:
    struct node{
        long long left_l=0,right_l=0,max_l=0;
        int left_t=0,right_t=0;
        bool tag=0;
        int l,r;
    };
    struct Res{
        long long left_l,right_l,max_l;
        int left_t,right_t;
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
            w[u].left_t=w[u].right_t=a[L-1];
            w[u].left_l=w[u].right_l=w[u].max_l=1;
            return;
        }
        int M=(L+R)/2;
        build(2*u,L,M,a),build(2*u+1,M+1,R,a);
        pushup(u);
        return;
    }
    //节点回溯
    void pushup(int u){
        int ls=2*u,rs=2*u+1;
        //处理左最长
        w[u].left_t=w[ls].left_t;
        if(w[ls].left_l==(w[ls].r-w[ls].l+1)&&w[ls].right_t!=w[rs].left_t){
            w[u].left_l=w[ls].max_l+w[rs].left_l;
        }
        else{
            w[u].left_l=w[ls].left_l;
        }
        //处理右最长
        w[u].right_t=w[rs].right_t;
        if(w[rs].right_l==(w[rs].r-w[rs].l+1)&&w[rs].left_t!=w[ls].right_t){
            w[u].right_l=w[rs].max_l+w[ls].right_l;
        }
        else{
            w[u].right_l=w[rs].right_l;
        }
        //处理最长
        if(w[ls].right_t!=w[rs].left_t){
            w[u].max_l=max(w[ls].right_l+w[rs].left_l,max(w[ls].max_l,w[rs].max_l));
        }
        else{
            w[u].max_l=max(w[ls].max_l,w[rs].max_l);
        }
        return;
    }
    //打tag
    void make_tag(int u){
        w[u].tag^=1;
        w[u].left_t^=1,w[u].right_t^=1;
        return;
    }
    //tag下放
    void push_down(int u){
        if(w[u].tag==0)return;
        make_tag(2*u);
        make_tag(2*u+1);
        w[u].tag=0;
        return;
    }
public:
    //构造函数
    SegmentTree(vector<long long>&a){
        int n=a.size();
        w.resize(4*n+5);
        build(1,1,n,a);
    }
    //区间查询
    Res query_sum(int u,int L,int R){//[L,R]待查询的区间，w[u]被查询的节点
        if(in_range(w[u].l,w[u].r,L,R)){
            return {w[u].left_l,w[u].right_l,w[u].max_l,w[u].left_t,w[u].right_t};
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            Res ls=query_sum(2*u,L,R),rs=query_sum(2*u+1,L,R);
            if(ls.left_t==-1)return rs;
            if(rs.left_t==-1)return ls;

            long long left_l=0,right_l=0,max_l=0;
            int left_t=ls.left_t,right_t=rs.right_t;

            if(ls.left_l==w[2*u].r-w[2*u].l+1&&ls.right_t!=rs.left_t){
                left_l=ls.max_l+rs.left_l;
            }
            else{
                left_l=ls.left_l;
            }

            if(rs.right_l==w[2*u+1].r-w[2*u+1].l+1&&rs.left_t!=ls.right_t){
                right_l=rs.max_l+ls.right_l;
            }
            else{
                right_l=rs.right_l;
            }

            if(rs.left_t!=ls.right_t){
                max_l=max(rs.left_l+ls.right_l,max(ls.max_l,rs.max_l));
            }
            else{
                max_l=max(ls.max_l,rs.max_l);
            }

            return {left_l,right_l,max_l,left_t,right_t};
        }
        else{
            return {0,0,0,-1,-1};
        }
    }
    //区间修改
    void update(int u,int L,int R){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag(u);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            update(2*u,L,R),update(2*u+1,L,R);
            pushup(u);
        }
    }
};

int main()
{
    int n,q;cin>>n>>q;
    vector<long long>a(n);
    for(int i=0;i<n;i++)a[i]=0;
    SegmentTree st(a);
    while(q--){
        int x;cin>>x;
        st.update(1,x,x);
        cout<<st.query_sum(1,1,n).max_l<<endl;
    }
    return 0;
}