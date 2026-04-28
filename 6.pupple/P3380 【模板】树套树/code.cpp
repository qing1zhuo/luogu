/*
1. 先将原数组离散化，将原数据映射为排名c[i]的rank (最大为cnt)
2. 每棵线段树表示[1,cnt]
3. root[i]表示c[1~i]构成的线段树
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 200005
#define inf 2147483647
struct Node{
    int l,r;
    Node *lc,*rc;
    int sum;
    Node(int L,int R){l=L,r=R,sum=0;lc=rc=nullptr;}
};
struct Query{
    int opt;
    int l,r;
    int pos,k;
};
int a[maxn],b[2*maxn],c[2*maxn];//原始数据，排序去重后的数据，原始数据对应的排名
vector<int>all_num;
Query q[maxn];
Node* root[2*maxn];
int n,m,cnt;

//树状数组low_bit
int low_bit(int x){return x&(-x);}
//区间判断
bool out_range(int l,int r,int L,int R){//[l,r]不在[L,R]
    return r<L||R<l;
}
bool in_range(int l,int r,int L,int R){//[l,r]在[L,R]
    return L<=l&&r<=R;
}
int my_binary_down(int val){
    int l=1,r=cnt;
    int res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(b[mid]<=val){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}


//更新线段树
Node* update_tree(Node*cur,int index,int val,int L,int R){
    if(cur==nullptr){
        cur=new Node(L,R);
    }
    cur->sum+=val;
    if(L==R)return cur;

    int M=(L+R)/2;
    if(index<=M){
        cur->lc=update_tree(cur->lc,index,val,L,M);
    }
    else{
        cur->rc=update_tree(cur->rc,index,val,M+1,R);
    }
    return cur;
}
//更新树状数组
void update_root(int index,int val){
    for(int i=index;i<=n;i+=low_bit(i)){
        root[i]=update_tree(root[i],c[index],val,1,cnt);
    }
}

//查询在某个线段树中小于x的总数
int query_less_tree(int x,Node*root){
    Node*cur=root;
    int res=0;
    while(cur!=nullptr&&cur->l!=cur->r){
        int m=(cur->l+cur->r)/2;
        if(m<x){
            res+=(cur->lc==nullptr)?0:cur->lc->sum;
            cur=cur->rc;
        }
        else if(x<=m){
            cur=cur->lc;
        }
    }
    if(cur!=nullptr&&cur->l==cur->r&&cur->r<x){
        res+=cur->sum;
    }
    return res;
}
//查询在某个线段树中大于x的总数
int query_more_tree(int x,Node*root){
    Node*cur=root;
    int res=0;
    while(cur!=nullptr&&cur->l!=cur->r){
        int m=(cur->l+cur->r)/2;
        if(m>=x){
            res+=(cur->rc==nullptr)?0:cur->rc->sum;
            cur=cur->lc;
        }
        else{
            cur=cur->rc;
        }
    }
    if(cur!=nullptr&&cur->l==cur->r&&cur->l>x){
        res+=cur->sum;
    }
    return res;   
}
//查询某棵线段中[ql,qr]的总和值
int query_sum_tree(int ql,int qr,Node*cur){
    if(cur==nullptr||out_range(cur->l,cur->r,ql,qr))return 0;
    if(in_range(cur->l,cur->r,ql,qr))return cur->sum;
    else return query_sum_tree(ql,qr,cur->lc)+query_sum_tree(ql,qr,cur->rc);
}
//查询树状数组中[1,index]中<=val的数的总和
int query_sum_root(int index,int val){
    int res=0;
    for(int i=index;i>0;i-=low_bit(i)){
        res+=query_sum_tree(1,val,root[i]);
    }
    return res;
}
//离散化
int discrete(){
    sort(all_num.begin(),all_num.end());
    all_num.erase(unique(all_num.begin(), all_num.end()), all_num.end());
    int len_after_unique=all_num.size();
    for(int i=1;i<=len_after_unique;i++)b[i]=all_num[i-1];
    return len_after_unique;
}


int opt1(int l,int r,int k){//已知数据，求排名
    int ans=0;
    for(int i=r;i;i-=low_bit(i))ans+=query_less_tree(k,root[i]);
    for(int i=l-1;i;i-=low_bit(i))ans-=query_less_tree(k,root[i]);
    return ans+1;
}
// 区间 [l,r] 第 k 小：把树状数组对应的所有线段树根一起带着往下走
// 时间 O(log n * log V)，相比原"值域二分套区间求和"的 O(log n * log^2 V) 更快
int opt2(int l,int r,int k){
    // rs：r 这条 BIT 链上的所有 root，相加贡献为 +
    // ls：l-1 这条 BIT 链上的所有 root，相加贡献为 -
    Node* rs[20]; Node* ls[20];
    int rs_n=0, ls_n=0;
    for(int i=r;   i; i-=low_bit(i)) rs[rs_n++]=root[i];
    for(int i=l-1; i; i-=low_bit(i)) ls[ls_n++]=root[i];

    int L=1, R=cnt;
    while(L<R){
        // sl = 当前层左子树里 [l,r] 内元素个数 = sum(rs.lc) - sum(ls.lc)
        int sl=0;
        for(int i=0;i<rs_n;i++) if(rs[i]&&rs[i]->lc) sl += rs[i]->lc->sum;
        for(int i=0;i<ls_n;i++) if(ls[i]&&ls[i]->lc) sl -= ls[i]->lc->sum;
        int M=(L+R)/2;
        if(k<=sl){
            // 第 k 小落在左子树，所有指针同步走 lc
            for(int i=0;i<rs_n;i++) rs[i]=rs[i]?rs[i]->lc:nullptr;
            for(int i=0;i<ls_n;i++) ls[i]=ls[i]?ls[i]->lc:nullptr;
            R=M;
        } else {
            // 否则去右子树，扣掉左子树已统计的 sl 个
            k-=sl;
            for(int i=0;i<rs_n;i++) rs[i]=rs[i]?rs[i]->rc:nullptr;
            for(int i=0;i<ls_n;i++) ls[i]=ls[i]?ls[i]->rc:nullptr;
            L=M+1;
        }
    }
    return L; // 走到叶子，返回的是离散化后的下标，调用方再用 b[L] 还原
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    //收集原始数据
    for(int i=1;i<=n;i++){
        cin>>a[i];b[i]=a[i];
        all_num.push_back(a[i]);
    }
    //收集询问
    for(int i=1;i<=m;i++){
        int opt;cin>>opt;
        if(opt==3){q[i].opt=3;
            cin>>q[i].pos>>q[i].k;
            all_num.push_back(q[i].k);
        }
        else{q[i].opt=opt;
            cin>>q[i].l>>q[i].r>>q[i].k;
        }
    }
    //离散化
    cnt=discrete();
    //将a中数据映射成排名
    for(int i=1;i<=n;i++){
        c[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
        update_root(i,1);
    }
    for(int i=1;i<=m;i++){
        int opt=q[i].opt;
        if(opt==1){//已知数，求排名
            int l=q[i].l,r=q[i].r,k=q[i].k;
            k=lower_bound(b+1,b+1+cnt,k)-b;//把k从原数据变成离散化后数据
            cout<<opt1(l,r,k)<<"\n";
        }
        if(opt==2){//已知排名，求数据
            int l=q[i].l,r=q[i].r,k=q[i].k;
            cout<<b[opt2(l,r,k)]<<"\n";
        }
        if(opt==3){
            int pos=q[i].pos,k=q[i].k;
            update_root(pos,-1);
            a[pos]=k;
            c[pos]=lower_bound(b+1,b+1+cnt,a[pos])-b;
            update_root(pos,1);
        }
        if(opt==4){
            int l=q[i].l,r=q[i].r,k=q[i].k;
            k=lower_bound(b+1,b+1+cnt,k)-b;//把k从原数据变成离散化后数据

            int rk_k=opt1(l,r,k)-1;//区间内小于k的数的数量
            if(rk_k==0){
                cout<<-inf<<endl;
            }
            else{
                int ans_ind=opt2(l,r,rk_k);
                if(ans_ind==-1)cout<<-inf<<endl;
                else cout<<b[ans_ind]<<"\n";
            }
        }
        if(opt==5){
            int l=q[i].l,r=q[i].r,k=q[i].k;
            k=my_binary_down(k);//把k从原数据变成离散化后数据

            int more=0;int tot=r-l+1;
            for(int i=r;i;i-=low_bit(i))more+=query_more_tree(k,root[i]);
            for(int i=l-1;i;i-=low_bit(i))more-=query_more_tree(k,root[i]);

            if(more==0)cout<<inf<<endl;
            else{
                int ans_ind=opt2(l,r,tot-more+1);
                cout<<b[ans_ind]<<"\n";
            }
        }
    }
    return 0;
}