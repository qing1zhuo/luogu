#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
#define inf 1000000000
long long my_max(long a,long b,long c){
    return max(a,max(b,c));
}

template<typename type>
class SegmentTree
{
private:
    struct node{
        type left_val,right_val,max_val;
        type sum;
        type tag;
        int l,r;
    };
    struct res_node{
        type left_val,right_val,max_val;
        type sum;
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
    void build(int u,int L,int R,vector<type>&a){
        w[u].l=L,w[u].r=R;w[u].tag=0;
        if(L==R){
            w[u].sum=w[u].max_val=w[u].left_val=w[u].right_val=a[L-1];
            return;
        }
        int M=(L+R)/2;
        build(2*u,L,M,a),build(2*u+1,M+1,R,a);
        pushup(u);
        return;
    }
    //节点回溯
    void pushup(int u){
        int le=2*u,ri=2*u+1;
        w[u].sum=w[le].sum+w[ri].sum;
        w[u].max_val=my_max(w[le].max_val,w[ri].max_val,w[le].right_val+w[ri].left_val);
        w[u].left_val=max(w[le].left_val,w[le].sum+w[ri].left_val);
        w[u].right_val=max(w[ri].right_val,w[ri].sum+w[le].right_val);
        return;
    }
    //打tag
    void make_tag(int u,type k){
        w[u].tag=k;
        int len=w[u].r-w[u].l+1;
        w[u].sum=k*len;
        if(k>0)w[u].left_val=w[u].right_val=w[u].max_val=k*len;
        if(k<0)w[u].left_val=w[u].right_val=w[u].max_val=k;
        return;
    }
    //tag下放
    void push_down(int u){
        if(w[u].tag==0)return;
        make_tag(2*u,w[u].tag);
        make_tag(2*u+1,w[u].tag);
        w[u].tag=0;
        return;
    }
public:
    //构造函数
    SegmentTree(vector<type>&a){
        int n=a.size();
        w.resize(4*n+5);
        build(1,1,n,a);
    }
    //区间查询
    res_node query_sum(int u,int L,int R){//[L,R]待查询的区间，w[u]被查询的节点
        if(in_range(w[u].l,w[u].r,L,R)){
            return {w[u].left_val,w[u].right_val,w[u].max_val,w[u].sum};
        }
        if(out_range(w[u].l,w[u].r,L,R)){
            return {-inf,-inf,-inf,0};
        }
        push_down(u);
        res_node left_res=query_sum(2*u,L,R),right_res=query_sum(2*u+1,L,R);
        res_node final_res;
        final_res.left_val=max(left_res.left_val,left_res.sum+right_res.left_val);
        final_res.right_val=max(right_res.right_val,right_res.sum+left_res.right_val);
        final_res.max_val=my_max(left_res.max_val,right_res.max_val,left_res.right_val+right_res.left_val);
        final_res.sum=left_res.sum+right_res.sum;
        return final_res;
    }
    //区间修改
    void update(int u,int L,int R,type k){
        if(in_range(w[u].l,w[u].r,L,R)){
            make_tag(u,k);
        }
        else if(!out_range(w[u].l,w[u].r,L,R)){
            push_down(u);
            update(2*u,L,R,k),update(2*u+1,L,R,k);
            pushup(u);
        }
    }
};

int main()
{
    int n,m;cin>>n>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    SegmentTree<long long>st(a);
    while(m--){
        int op;cin>>op;
        if(op==1){
            int a,b;cin>>a>>b;
            if(a>b){
                int tmp=a;
                a=b;
                b=tmp;
            }
            cout<<st.query_sum(1,a,b).max_val<<endl;
        }
        else{
            int p,s;cin>>p>>s;
            st.update(1,p,p,s);
        }
    }
    return 0;
}