#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 600005
struct Node
{
    int cnt;
    Node*next[2];
    Node(){next[0]=next[1]=nullptr;cnt=0;}
};
Node* insert(Node*pre_root,int x)
{
    Node*pre=pre_root;
    Node*cur=new Node();
    Node*res=cur;

    for(int i=31;i>=0;i--){
        int bit=(x>>i)&1;
        int rev=bit^1;
        //新建节点
        cur->next[bit]=new Node();
        //节点复用
        if(pre){
            cur->next[rev]=pre->next[rev];
            if(pre->next[bit])cur->next[bit]->cnt=pre->next[bit]->cnt;
        }
        cur->next[bit]->cnt++;
        //节点后移
        if(pre)pre=pre->next[bit];
        cur=cur->next[bit];
    }
    return res;
}
int query(Node*L_root,Node*R_root,int target)
{
    Node *cur_L=L_root,*cur_R=R_root;
    int res=0;
    for(int i=31;i>=0;i--){
        if(!cur_R) break;
        int bit=(target>>i)&1;
        int rev=bit^1;

        int r_cnt=cur_R->next[rev]?cur_R->next[rev]->cnt:0;
        int l_cnt=(cur_L&&cur_L->next[rev])?cur_L->next[rev]->cnt:0;

        if(r_cnt-l_cnt>0) {
            res |= (1 << i);
            cur_R = cur_R->next[rev];
            cur_L = cur_L ? cur_L->next[rev] : nullptr;
        } else {
            // 否则选bit位
            cur_R = cur_R->next[bit];
            cur_L = cur_L ? cur_L->next[bit] : nullptr;
        }
    }
    return res;
}
int n,m;
int cnt=0;
Node*root[maxn];
int pre[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    root[0]=insert(nullptr,0);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;++cnt;
        pre[cnt]=x^pre[cnt-1];
        root[cnt]=insert(root[cnt-1],pre[cnt]);
    }
    for(int i=1;i<=m;i++){
        char opt;cin>>opt;
        if(opt=='A'){
            int x;cin>>x;++cnt;
            pre[cnt]=x^pre[cnt-1];
            root[cnt]=insert(root[cnt-1],pre[cnt]);
        }
        else{
            int l,r,x;cin>>l>>r>>x;
            l--,r--;
            Node*l_root=(l>=1)?root[l-1]:nullptr;
            Node*r_root=root[r];
            int ans=query(l_root,r_root,x^pre[cnt]);
            cout<<ans<<endl;
        }
    }
    return 0;
}