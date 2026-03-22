#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 100005
class Trie
{
private:
    //树的节点
    struct node
    {
        node* children[2];
        node(){
            memset(children,0,sizeof(children));
        }
    };
    //析构函数组件
    void destroy(node* node)
    {
        if (!node) return; 
        for (int i=0;i<=1;++i){
            destroy(node->children[i]);
        }
        delete node; // 释放当前节点
    }
    //根节点
    node* root;
public:
    Trie(){root=new node;}
    ~Trie(){destroy(root);}
    void insert(unsigned int x){
        node* cur=root;
        for(int i=30;i>=0;i--){
            int ind=(x>>i)&1;
            if(!cur->children[ind]){
                cur->children[ind]=new node();
            }
            cur=cur->children[ind];
        }
    }
    unsigned int query(unsigned int x){
        node* cur=root;
        unsigned int res=0;
        for(int i=30;i>=0;i--){
            int ind=(x>>i)&1;
            int rev=ind^1;
            if(cur->children[rev]){
                cur=cur->children[rev];
                res|=(1<<i);
            }
            else{
                cur=cur->children[ind];
            }
        }
        return res;
    }
};
//处理单源最短路
int n;
vector<int>_v[maxn],_w[maxn],cnt(maxn);
vector<unsigned int>dist(maxn);
vector<bool>vis(maxn);
void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<cnt[u];i++){
        int v=_v[u][i];
        int w=_w[u][i];
        if(!vis[v]){
            dist[v]=dist[u]^w;
            dfs(v);
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;cin>>u>>v>>w;
        _v[u].push_back(v);
        _w[u].push_back(w);
        cnt[u]++;
        _v[v].push_back(u);
        _w[v].push_back(w);
        cnt[v]++;
    }
    dist[1];
    dfs(1);
    Trie t;
    t.insert(dist[1]);
    unsigned int maxo=0;
    unsigned int curo=0;
    for(int i=2;i<=n;i++){
        curo=t.query(dist[i]);
        maxo=max(maxo,curo);
        t.insert(dist[i]);
    }
    cout<<maxo;
    return 0;
}