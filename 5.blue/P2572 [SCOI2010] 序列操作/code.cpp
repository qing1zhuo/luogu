#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100005
void swap(int&a,int&b){
    int tmp=a;
    a=b;
    b=tmp;
}
struct node
{
    int l,r;
    bool tag_rever;                      //反转懒标记
    int tag_set;                        //重置懒标记

    int tot_one;                        //1总数
    int max_one,left_one,right_one;     //最长连续1，最长左连续1，最长右连续1

    int tot_zero;
    int max_zero,left_zero,right_zero;

    int l_val,r_val;                    //左边值，右边值
};
struct res_node
{
    int len;
    int max_one,left_one,right_one;
    int l_val,r_val;
};

vector<node>w(4*maxn+10);
vector<int>a(maxn);
bool in_range(int l,int r,int L,int R);
bool out_range(int l,int r,int L,int R);
void push_up(int u);
void push_down(int u);
void set_tag(int u,int k);
void rever_tag(int u);
void build(int u,int l,int r);
void set(int u,int l,int r,int k);
void rever(int u,int l,int r);
int query_tot(int u,int l,int r);
res_node query_max(int u,int l,int r);

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--){
        int op;cin>>op;
        if(op==0){
            int l,r;cin>>l>>r;
            set(1,l+1,r+1,0);
        }
        if(op==1){
            int l,r;cin>>l>>r;
            set(1,l+1,r+1,1);
        }
        if(op==2){
            int l,r;cin>>l>>r;
            rever(1,l+1,r+1);
        }
        if(op==3){
            int l,r;cin>>l>>r;
            cout<<query_tot(1,1+l,1+r)<<endl;
        }
        if(op==4){
            int l,r;cin>>l>>r;
            cout<<query_max(1,l+1,r+1).max_one<<endl;
        }
    }
}


bool in_range(int l,int r,int L,int R){//[l,r]in[L,R]?
    return (L<=l)&&(r<=R);
}
bool out_range(int l,int r,int L,int R){//[l,r]out[L,R]?
    return (r<L)||(l>R);
}

void push_up(int u)
{
    int li=2*u,ri=2*u+1;
    //1总数合并
    w[u].tot_one=w[li].tot_one+w[ri].tot_one;
    //左右值合并
    w[u].l_val=w[li].l_val,w[u].r_val=w[ri].r_val;
    //左最长合并
    int len=w[li].r-w[li].l+1;
    if(len==w[li].left_one&&w[li].r_val==w[ri].l_val){
        w[u].left_one=w[li].left_one+w[ri].left_one;
    }
    else{
        w[u].left_one=w[li].left_one;
    }
    //右最长合并
    len=w[ri].r-w[ri].l+1;
    if(len==w[ri].right_one&&w[li].r_val==w[ri].l_val){
        w[u].right_one=w[ri].right_one+w[li].right_one;
    }
    else{
        w[u].right_one=w[ri].right_one;
    }
    //最长连续合并
    if(w[li].r_val==w[ri].l_val&&w[li].r_val==1){
        w[u].max_one=max(max(w[li].max_one,w[ri].max_one),w[li].right_one+w[ri].left_one);
    }
    else{
        w[u].max_one=max(w[li].max_one,w[ri].max_one);
    }

    //0总数合并
    w[u].tot_zero=w[li].tot_zero+w[ri].tot_zero;
    //左最长合并
    len=w[li].r-w[li].l+1;
    if(len==w[li].left_zero&&w[li].r_val==w[ri].l_val){
        w[u].left_zero=w[li].left_zero+w[ri].left_zero;
    }
    else{
        w[u].left_zero=w[li].left_zero;
    }
    //右最长合并
    len=w[ri].r-w[ri].l+1;
    if(len==w[ri].right_zero&&w[li].r_val==w[ri].l_val){
        w[u].right_zero=w[ri].right_zero+w[li].right_zero;
    }
    else{
        w[u].right_zero=w[ri].right_zero;
    }
    //最长连续合并
    if(w[li].r_val==w[ri].l_val&&w[li].r_val==0){
        w[u].max_zero=max(max(w[li].max_zero,w[ri].max_zero),w[li].right_zero+w[ri].left_zero);
    }
    else{
        w[u].max_zero=max(w[li].max_zero,w[ri].max_zero);
    }
}
void push_down(int u)
{
    int li=2*u,ri=2*u+1;
    if(w[u].tag_set!=-1){
        set_tag(li,w[u].tag_set);
        set_tag(ri,w[u].tag_set);
        w[u].tag_set=-1;
    }
    if(w[u].tag_rever==true){
        rever_tag(li),rever_tag(ri);
        w[u].tag_rever^=1;
    }
}

void set_tag(int u,int k)
{
    w[u].tag_rever=false;
    w[u].tag_set=k;
    w[u].r_val=w[u].l_val=k;
    int len=w[u].r-w[u].l+1;
    if(k==1){
        w[u].tot_one=w[u].max_one=w[u].left_one=w[u].right_one=len;
        w[u].tot_zero=w[u].max_zero=w[u].left_zero=w[u].right_zero=0;
    }
    else if(k==0){
        w[u].tot_one=w[u].max_one=w[u].left_one=w[u].right_one=0;
        w[u].tot_zero=w[u].max_zero=w[u].left_zero=w[u].right_zero=len;
    }
}
void rever_tag(int u)
{
    int len=w[u].r-w[u].l+1;
    w[u].tag_rever^=1;
    w[u].r_val^=1,w[u].l_val^=1;

    swap(w[u].tot_one,w[u].tot_zero);
    swap(w[u].left_one,w[u].left_zero);
    swap(w[u].right_one,w[u].right_zero);
    swap(w[u].max_one,w[u].max_zero);
}

void build(int u,int l,int r)
{
    w[u].l=l,w[u].r=r;
    w[u].tag_set=-1;
    w[u].tag_rever=false;
    if(l==r){
        w[u].l_val=w[u].r_val=a[l];
        w[u].tot_one=w[u].max_one=w[u].left_one=w[u].right_one=a[l];
        w[u].tot_zero=w[u].max_zero=w[u].left_zero=w[u].right_zero=1-a[l];
        return;
    }

    int m=(l+r)/2;
    build(2*u,l,m),build(2*u+1,m+1,r);
    push_up(u);
}

void set(int u,int l,int r,int k)
{
    if(in_range(w[u].l,w[u].r,l,r)){
        set_tag(u,k);
    }
    else if(!out_range(w[u].l,w[u].r,l,r)){
        push_down(u);
        set(2*u,l,r,k),set(2*u+1,l,r,k);
        push_up(u);
    }
}
void rever(int u,int l,int r)
{
    if(in_range(w[u].l,w[u].r,l,r)){
        rever_tag(u);
    }
    else if(!out_range(w[u].l,w[u].r,l,r)){
        push_down(u);
        rever(2*u,l,r),rever(2*u+1,l,r);
        push_up(u);
    }
}

int query_tot(int u,int l,int r)
{
    if(in_range(w[u].l,w[u].r,l,r)){
        return w[u].tot_one;
    }
    else if(!out_range(w[u].l,w[u].r,l,r)){
        push_down(u);
        return query_tot(2*u,l,r)+query_tot(2*u+1,l,r);
    }
    else return 0;
}
res_node query_max(int u,int l,int r)
{
    if(in_range(w[u].l,w[u].r,l,r)){
        return {w[u].r-w[u].l+1,
            w[u].max_one,w[u].left_one,w[u].right_one,
            w[u].l_val,w[u].r_val
        };
    }
    else if(!out_range(w[u].l,w[u].r,l,r)){
        push_down(u);
        res_node ls=query_max(2*u,l,r),rs=query_max(2*u+1,l,r);
        if(ls.l_val==-1)return rs;   
        if(rs.l_val==-1)return ls;
        res_node res;
        res.len=ls.len+rs.len;
        res.l_val=ls.l_val,res.r_val=rs.r_val;

        if(ls.len==ls.left_one&&ls.r_val==rs.l_val){
            res.left_one=ls.left_one+rs.left_one;
        }
        else res.left_one=ls.left_one;

        if(rs.len==rs.right_one&&ls.r_val==rs.l_val){
            res.right_one=rs.right_one+ls.right_one;
        }
        else res.right_one=rs.right_one;

        if(ls.r_val==rs.l_val&&ls.r_val==1){
            res.max_one=max(max(ls.max_one,rs.max_one),ls.right_one+rs.left_one);
        }
        else res.max_one=max(ls.max_one,rs.max_one);

        return res;
    }
    else return {0,0,0,0,-1,-1};
}

