#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 1000005

class Trie
{
private:
    class Node
    {
    public:
        bool isEnd;
        int cnt;
        Node* child[2];
        Node():cnt(0),isEnd(false){child[0]=child[1]=nullptr;}
    };
    Node*root;
    int dfs(Node*cur,int i,int k)
    {
        if(cur==nullptr)return 0;
        if(i<0)return cur->cnt;

        int bit_k=(k>>i)&1;
        Node*child0=cur->child[0];int cnt0=child0?child0->cnt:0;
        Node*child1=cur->child[1];int cnt1=child1?child1->cnt:0;

        if(bit_k){//k的第i位是1，则往下怎么走都可以
            int res0=cnt0+dfs(child1,i-1,k);
            int res1=cnt1+dfs(child0,i-1,k);
            return max(res0,res1);
        }
        else{//k的第i位是0，则a的k位必须和当前节点相同，则a_k被固定死了，所以要分别往下探索两路
            int res0=dfs(child0,i-1,k);
            int res1=dfs(child1,i-1,k);
            return max(res0,res1);
        }
    }
public:
    Trie(){root=new Node;}
    void insert(int a)
    {
        Node*cur=root;
        for(int i=22;i>=0;i--){
            int index=(a>>i)&1;
            if(cur->child[index]==nullptr){
                cur->child[index]=new Node;
            }
            cur=cur->child[index];
            cur->cnt++;
        }
        cur->isEnd=true;
    }
    int query(int k)
    {
        return dfs(root,22,k);
    }
};

int n,k;
int main()
{
    Trie t;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        t.insert(a);
    }
    cout<<t.query(k)<<endl;
    return 0;
}