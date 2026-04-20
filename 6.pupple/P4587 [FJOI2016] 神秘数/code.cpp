#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005

struct Node{
    int l,r;
    int sum;
    Node* lc,*rc;
    Node(){l=r=sum=0,lc=rc=nullptr;}
};

Node* root[maxn];
int n,m;
vector<int>a(maxn),b(maxn),c(maxn);
bool in_range(int l,int r,Node node){
    return l<=node.l&&node.r<=r;
}
bool out_range(int l,int r,Node node){
    return r<node.l||l>node.r;
}
Node* init_tree(int L,int R){
    Node*cur=new Node();
    cur->l=L,cur->r=R,cur->sum=0;
    if(L!=R){
        int M=(L+R)/2;
        cur->lc=init_tree(L,M);
        cur->rc=init_tree(M+1,R);
    }
    return cur;
}
Node* update(int L,int R,Node*before,int val,int rank){
    Node*cur=new Node();
    cur->l=L,cur->r=R;cur->sum=before->sum+val;
    if(L==R)return cur;
    int M=(L+R)/2;
    if(rank>M){//若在右边，复用左边
        cur->lc=before->lc;
        cur->rc=update(M+1,R,before->rc,val,rank);
    }
    else{
        cur->rc=before->rc;
        cur->lc=update(L,M,before->lc,val,rank);
    }

    return cur;
}
int query(Node*cur,int ans_rank){
    if(in_range(1,ans_rank,*cur))return cur->sum;
    else if(!out_range(1,ans_rank,*cur))return query(cur->lc,ans_rank)+query(cur->rc,ans_rank);
    else return 0;
}
int main()
{
    cin>>n;
    root[0]=init_tree(1,n);
    for(int i=1;i<=n;i++){
        cin>>a[i];b[i]=a[i];
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    b.push_back(1e9);
    for(int i=1;i<=n;i++){
        //查询a[i]的大小在b中的位次
        int rank=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        root[i]=update(1,n,root[i-1],a[i],rank);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        int ans=1;
        while(true){
            int ans_rank=upper_bound(b.begin(),b.end(),ans)-b.begin();
            int cur_sum=query(root[r],ans_rank-1)-query(root[l-1],ans_rank-1);
            if(cur_sum<ans)break;
            else ans=cur_sum+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}