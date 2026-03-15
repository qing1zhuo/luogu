#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SegmentTree
{
private:
    struct node{
        int l,r;    //左右边界
        int color;  //拥有的颜色，每一位表示第i+1种颜色
        int tag;    //是否被修改颜色
    };
    vector<node>w;
    void push_up(int u){
        w[u].color=w[2*u].color|w[2*u+1].color;
    }
    void push_down(int u){
        if(w[u].tag==0)return;
        
        w[2*u].color=1<<(w[u].tag-1);
        w[2*u].tag=w[u].tag;
        w[2*u+1].color=1<<(w[u].tag-1);
        w[2*u+1].tag=w[u].tag;

        w[u].tag=0;
    }
    void make_tag(int u,int k){
        w[u].tag=k;
        w[u].color=1<<(k-1);
    }
    bool in_range(int u,int L,int R){
        return (w[u].l>=L)&&(w[u].r<=R);
    }
    bool out_range(int u,int L,int R){
        return (w[u].r<L)||(w[u].l>R);
    }
    void build_tree(int u,int L,int R){
        w[u].l=L,w[u].r=R,w[u].tag=0;
        if(L==R){
            w[u].color=1;
            return;
        }
        int M=(L+R)/2;
        build_tree(2*u,L,M),build_tree(2*u+1,M+1,R);
        push_up(u);
        return;
    }
public:
    SegmentTree(int L){
        w.resize(4*L+10);
        build_tree(1,1,L);
    }
    void update(int u,int L,int R,int C){
        if(in_range(u,L,R)){
            make_tag(u,C);
        }
        else if(!out_range(u,L,R)){
            push_down(u);
            update(2*u,L,R,C),update(2*u+1,L,R,C);
            push_up(u);
        }
    }
    int query(int u,int L,int R){
        if(in_range(u,L,R))return w[u].color;
        else if(!out_range(u,L,R)){
            push_down(u);
            return query(2*u,L,R)|query(2*u+1,L,R);
        }
        else return 0;
    }
};
int check(int color){
    int res=0;
    while(color){
        res+=color%2;
        color/=2;
    }
    return res;
}
void swap(int&A,int&B){
    int tmp=A;
    A=B;
    B=tmp;
}
int main()
{
    int L,T,O;
    cin>>L>>T>>O;
    SegmentTree st(L);
    while(O--){
        char ch;cin>>ch;
        if(ch=='C'){
            int A,B,C;cin>>A>>B>>C;
            if(A>B)swap(A,B);
            st.update(1,A,B,C);
        }
        else{
            int A,B;cin>>A>>B;
            if(A>B)swap(A,B);
            int color=st.query(1,A,B);
            cout<<check(color)<<endl;
        }
    }
    return 0;
}