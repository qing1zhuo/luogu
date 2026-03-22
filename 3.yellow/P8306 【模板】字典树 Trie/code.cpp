#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;

class Trie
{
private:
    //树的节点
    struct node
    {
        bool isEnd;
        int cnt;
        node* children[63];
        node():isEnd(false),cnt(0){
            memset(children,0,sizeof(children));
        }
    };
    //字符转数字
    int char2int(char&ch)
    {
        if(islower(ch)){
            return ch-'a'+27;
        }
        if(isupper(ch)){
            return ch-'A'+1;
        }
        if(isdigit(ch)){
            return ch-'0'+53;
        }
        return -1;
    }
    //析构函数组件
    void destroy(node* node)
    {
        if (!node) return; 
        for (int i=0;i<=62;++i){
            destroy(node->children[i]);
        }
        delete node; // 释放当前节点
    }
    //根节点
    node* root;
public:
    Trie(){root=new node;}
    ~Trie(){destroy(root);}
    void insert(string&s){
        node* cur=root;
        for(char ch:s){
            int index=char2int(ch);
            if(!cur->children[index]){
                cur->children[index]=new node;
            }
            cur=cur->children[index];
            cur->cnt++;
        }
        cur->isEnd=true;
    }
    bool search(string&s){
        node* cur=root;
        for(char ch:s){
            int index=char2int(ch);
            if(!cur->children[index]){
                return false;
            }
            cur=cur->children[index];
        }
        return cur->isEnd;
    }
    int prefix(string&s){
        node* cur=root;
        for(char ch:s){
            int index=char2int(ch);
            if(!cur->children[index]){
                return false;
            }
            cur=cur->children[index];
        }
        return cur->cnt;
    }
};

int main()
{
    int T;cin>>T;
    while(T--){
        int n,q;cin>>n>>q;
        string s;
        Trie t;
        while(n--){
            cin>>s;
            t.insert(s);
        }
        while(q--){
            cin>>s;
            cout<<t.prefix(s)<<endl;
        }
    }
    return 0;
}