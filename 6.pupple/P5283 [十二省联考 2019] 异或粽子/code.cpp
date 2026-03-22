#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 500005
#define ll long long

struct Node
{
    int id,rk;
    long long w;
    bool operator<(const Node& other)const{
        return w<other.w;
    }
};
class Trie
{
private:
    //树的节点
    struct node
    {
        int cnt;
        node* children[2];
        node():cnt(0){
            children[0]=children[1]=0;
        }
    };
    //析构函数组件
    void destroy(node* node)
    {
        if (!node) return; 
        for (int i=0;i<2;++i){
            destroy(node->children[i]);
        }
        delete node; // 释放当前节点
    }
    //根节点
    node* root;
public:
    Trie(){root=new node;}
    ~Trie(){destroy(root);}
    void insert(ll x){
        node* cur=root;
        cur->cnt++;
        for(int i=32;i>=0;i--){
            ll bit=(x>>i)&1;
            if(!cur->children[bit]){
                cur->children[bit]=new node;
            }
            cur=cur->children[bit];
            cur->cnt++;
        }
    }
    ll query(ll x,int rk){
        node* cur=root;
        ll res=0;
        for(int i=32;i>=0;i--){
            ll bit=(x>>i)&1;
            ll rev=bit^1;
            if(cur->children[rev]){
                if(cur->children[rev]->cnt>=rk){
                    res|=(1LL<<i);
                    cur=cur->children[rev];
                }
                else{
                    rk-=cur->children[rev]->cnt;
                    cur=cur->children[bit];
                }
            }
            else{
                cur=cur->children[bit];
            }
        }
        return res;
    }
};

int n,k;
ll a[maxn];
ll prexor[maxn]={0};
priority_queue<Node>pq;
Trie t;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prexor[i]=prexor[i-1]^a[i];
    }
    for(int i=0;i<=n;i++){
        t.insert(prexor[i]);
    }
    for(int i=0;i<=n;i++){
        pq.push({i,1,t.query(prexor[i],1)});
    }
    ll ans=0;
    for(int i=1;i<=2*k;i++){
        Node tmp=pq.top();
        pq.pop();
        ans+=tmp.w;
        if(tmp.rk<n){
            pq.push({tmp.id,tmp.rk+1,t.query(prexor[tmp.id],tmp.rk+1)});
        }
    }
    cout<<(ans>>1LL);
    return 0;
}