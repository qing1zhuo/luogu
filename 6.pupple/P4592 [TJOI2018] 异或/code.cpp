#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 100005
struct Node{
    int cnt;
    Node*next[2];
    Node(){cnt=0;next[0]=next[1]=nullptr;}
};
class Trie
{
    public:
        Node* root;
        Trie(){root=new Node();}
        void insert(int x){
            Node*cur=root;
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                if(cur->next[bit]==nullptr){
                    cur->next[bit]=new Node();
                }
                cur=cur->next[bit];
                cur->cnt++;
            }
        }
        void make_new(Trie&before,int x){
            Node*cur=root;
            Node*pre=before.root;
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                int rev=bit^1;
                cur->next[bit]=new Node();
                if(pre){
                    cur->next[rev]=pre->next[rev];
                    if(pre->next[bit]!=nullptr){
                        cur->next[bit]->cnt=pre->next[bit]->cnt;
                    }
                }
                cur->next[bit]->cnt++;
                cur=cur->next[bit];
                if(pre)pre=pre->next[bit];
            }
        }
};
int n,q;
//权值
int val[maxn];
//邻接表
int head[2*maxn];//head_u u开头的第一条边
int to[2*maxn];//to_i 第i条边连接的终点
int rext[2*maxn];//rext_i 第i条边后下一条边是哪个
int edge_num;
//时间戳,即按照树上遍历的顺序重新编号
int l[maxn];//l_i 以i为起点的子树的起始编号
int r[maxn];//r_i 以i为起点的子树的结束编号
int dfs_val[maxn];
int time_num;//总的编号
//树相关
int dep[maxn];//dep_i i的深度
int fa[maxn];//fa_i i的父亲
//字典树
Trie tree1[maxn];//用于询问1的tree
Trie tree2[maxn];
//公共祖先处理
int grandpa[20][maxn];//grandpa_ij 第j个节点往上走2^i个是谁

//用于新加边
void add(int u,int v)
{
    edge_num++;
    to[edge_num]=v;
    rext[edge_num]=head[u];
    head[u]=edge_num;
}
//用于按照dfs序重新编号，给init_tree1做准备;同时明确父子关系;同时建tree2;同时初始化LCA数组
void dfs(int cur,int father){
    grandpa[0][cur]=father;

    tree2[cur]=Trie();
    tree2[cur].make_new(tree2[father],val[cur]);

    fa[cur]=father;
    dep[cur]=dep[father]+1;

    time_num++;
    l[cur]=time_num;
    dfs_val[time_num]=val[cur];

    for(int i=head[cur];i!=0;i=rext[i]){
        int v=to[i];
        if(v==father)continue;
        dfs(v,cur);
    }
    r[cur]=time_num;
}
//初始化tree1
void init_tree1()
{
    tree1[0]=Trie();
    tree1[0].insert(0);
    for(int i=1;i<=n;i++){
        tree1[i]=Trie();
        tree1[i].make_new(tree1[i-1],dfs_val[i]);
    }
}
//进一步初始化LCA数组
void init_LCA()
{
    for(int i=1;i<20;i++){
        for(int j=0;j<=n;j++){
            grandpa[i][j]=grandpa[i-1][grandpa[i-1][j]];
        }
    }
}
//寻找公共祖先
int LCA(int x,int y){
    while(dep[x]>dep[y]){
        for(int i=19;i>=0;i--){
            if(dep[grandpa[i][x]]>=dep[y])x=grandpa[i][x];
        }
    }
    while(dep[x]<dep[y]){
        for(int i=19;i>=0;i--){
            if(dep[grandpa[i][y]]>=dep[x])y=grandpa[i][y];
        }
    }

    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(grandpa[i][x]!=grandpa[i][y]){
            x=grandpa[i][x];
            y=grandpa[i][y];
        }
    }
    return grandpa[0][x];
}
//已知想要的字典树R,不要的字典树L,以及目标z,求最大异或值
int xor_max(Node*R,Node*L,int z){
    int res=0;
    for(int i=31;i>=0;i--){
        if(!R)break;
        int bit=(z>>i)&1;
        int rev=bit^1;

        int r_cnt=(R->next[rev])?R->next[rev]->cnt:0;
        int l_cnt=(L&&L->next[rev])?L->next[rev]->cnt:0;

        if(r_cnt>l_cnt){
            res|=(1<<i);
            R=R->next[rev];
            L=(L)?L->next[rev]:nullptr;
        }
        else{
            R=R->next[bit];
            L=(L)?L->next[bit]:nullptr;
        }
    }
    return res;
}
int query1(int x,int z){
    Node* L=tree1[l[x]-1].root;Node* R=tree1[r[x]].root;
    return xor_max(R,L,z);
}
int query2(int x,int ances,int z){
    Node*R=tree2[x].root,*L=tree2[fa[ances]].root;
    return xor_max(R,L,z);
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        add(u,v),add(v,u);
    }

    grandpa[0][0]=0;
    tree2[0]=Trie();tree2[0].insert(0);
    dfs(1,0);
    init_tree1();
    init_LCA();

    for(int i=1;i<=q;i++){
        int opt=0;
        cin>>opt;
        if(opt==1){
            int x,z;cin>>x>>z;
            cout<<query1(x,z)<<endl;
        }
        else{
            int x,y,z;cin>>x>>y>>z;
            int ancestor=LCA(x,y);
            cout<<max(query2(x,ancestor,z),query2(y,ancestor,z))<<endl;
        }
    }
    return 0;
}