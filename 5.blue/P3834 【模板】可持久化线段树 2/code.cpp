#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define maxn 200005

struct Node
{
    int l,r;
    int tot;
    Node*next[2];
    Node(int L,int R,int TOT){l=L,r=R;tot=TOT;next[0]=next[1]=nullptr;}
};
int n,m,cnt;// cnt去重后的元素数量
int a[maxn],b[maxn],c[maxn];//a_i原数据，b_i a排序去重，c_i a_i在b中的索引/排名
Node*root[maxn];
//二分查找
int lower_bound(int l,int r,int val){
    int mid=(l+r)/2;
    if(val==b[mid])return mid;
    else if(val<b[mid])return lower_bound(l,mid,val);
    else return lower_bound(mid+1,r,val);
}
//初始化哈希表，将原数据映射为离散化后数据
int init_unordered_map(){
    sort(b+1,b+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i]!=b[i-1]){
            cnt++;
            b[cnt]=b[i];
        }
    }
    for(int i=1;i<=n;i++){
        c[i]=lower_bound(1,n,a[i]);
    }
    return cnt;
}
//从头建树,因为这里只要对root[0]特别建树，所以全部tot=0
void build(int l,int r,Node** cur){
    *cur=new Node(l,r,0);
    if(l==r)return;
    int mid=(l+r)/2;
    build(l,mid,&((*cur)->next[0])),build(mid+1,r,&((*cur)->next[1]));
}
//在前一个树的基础上新建一棵树
Node* insert_new_tree(Node*before_root,int val){
    Node*pre=before_root;
    Node*res=new Node(1,n,pre->tot+1);
    Node*cur=res;

    
    while(cur->l!=cur->r){
        int l=cur->l,r=cur->r;
        int mid=(l+r)/2;
        int bit=(val<=mid)^1;

        cur->next[!bit]=pre->next[!bit];
        if(bit==0)cur->next[bit]=new Node(l,mid,pre->next[bit]->tot+1);
        else cur->next[bit]=new Node(mid+1,r,pre->next[bit]->tot+1);
        cur=cur->next[bit],pre=pre->next[bit];
    }

    return res;
}
//询问处理函数
int query(int L,int R,int k){
    Node*lr=root[L-1],*rr=root[R];
    while(rr->l!=rr->r){
        int lr_lcnt=lr->next[0]->tot;//左树的左节点数
        int rr_lcnt=rr->next[0]->tot;
        int lcnt=rr_lcnt-lr_lcnt;

        if(lcnt<k){//如果左边差值小于k，则需要往右边走
            lr=lr->next[1],rr=rr->next[1];
            k-=lcnt;
        }
        else{
            lr=lr->next[0],rr=rr->next[0];
        }
    }
    return rr->l;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    b[0]=-10;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    cnt=init_unordered_map();

    build(1,n,&root[0]);
    for(int i=1;i<=n;i++){
        int cur_val=c[i];
        root[i]=insert_new_tree(root[i-1],cur_val);
    }

    int ql,qr,k;
    for(int i=1;i<=m;i++){
        cin>>ql>>qr>>k;
        int ans=query(ql,qr,k);
        cout<<b[ans]<<endl;
    }
    return 0;
}