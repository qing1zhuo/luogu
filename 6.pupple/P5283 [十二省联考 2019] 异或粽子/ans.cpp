#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 500005
#define ll long long

// 优先队列的节点结构
struct Node {
    int id, rk; // id: prexor的下标, rk: 第rk大的异或值
    ll w;       // 异或值
    // 重载<，使priority_queue成为大根堆（C++默认是大根堆，此处反向比较）
    bool operator < (const Node &a) const {
        return w < a.w;
    }
};

class Trie
{
private:
    struct node
    {
        node* children[2];
        int size; // 新增：子树中节点的数量，用于找第rk大
        node(){
            memset(children, 0, sizeof(children));
            size = 0; // 初始化size为0
        }
    };
    void destroy(node* node)
    {
        if (!node) return; 
        for (int i=0;i<2;++i){
            destroy(node->children[i]);
        }
        delete node;
    }
    node* root;
public:
    Trie(){root=new node;}
    ~Trie(){destroy(root);}
    
    // 修改insert：维护每个节点的size
    void insert(ll x){
        node* cur=root;
        cur->size++; // 根节点size+1
        for(int i=32;i>=0;i--){
            ll bit=(x>>i)&1;
            if(!cur->children[bit]){
                cur->children[bit]=new node;
            }
            cur=cur->children[bit];
            cur->size++; // 路径上的节点size+1
        }
    }

    // 新增query：查询与x异或的第rk大的值
    ll query(ll x, int rk) {
        node* cur = root;
        ll res = 0;
        for(int i=32;i>=0;i--) {
            ll bit = (x >> i) & 1;
            // 优先走与当前位不同的路径（异或值更大）
            if (cur->children[bit ^ 1]) {
                if (cur->children[bit ^ 1]->size >= rk) {
                    // 第rk大在该子树，走此路径，该位异或为1
                    res |= (1LL << i);
                    cur = cur->children[bit ^ 1];
                } else {
                    // 第rk大不在该子树，减去该子树大小，走另一条路径
                    rk -= cur->children[bit ^ 1]->size;
                    cur = cur->children[bit];
                }
            } else {
                // 无相反位的子树，只能走相同位
                cur = cur->children[bit];
            }
            if (!cur) break; // 防御性判断
        }
        return res;
    }
};

int n, k;
ll a[maxn];
ll prexor[maxn] = {0};
Trie t;
priority_queue<Node> q; // 大根堆

// 快速读入（适配大数据量）
ll getin() {
    ll x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main()
{
    n = getin(), k = getin();
    for(int i=1;i<=n;i++){
        a[i] = getin();
        prexor[i] = prexor[i-1] ^ a[i];
    }
    // 先插入所有前缀异或（注意顺序：先插再查，避免自己异或自己）
    for(int i=0;i<=n;i++) {
        t.insert(prexor[i]);
    }
    // 初始化堆：每个prexor[i]的第1大异或值入堆
    for(int i=0;i<=n;i++) {
        ll w = t.query(prexor[i], 1);
        q.push({i, 1, w});
    }
    // 取k次最大的异或值
    ll ans = 0;
    int m = k * 2; // 对应ans.cpp的去重逻辑
    for(int i=1;i<=m;i++) {
        Node tmp = q.top();
        q.pop();
        ans += tmp.w;
        // 若还有下一个更大的，入堆
        if (tmp.rk < n) {
            ll w = t.query(prexor[tmp.id], tmp.rk + 1);
            q.push({tmp.id, tmp.rk + 1, w});
        }
    }
    // 去重：每个对被计算了两次，除以2
    cout << (ans >> 1) << endl;
    return 0;
}