#include<iostream>
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
        node* children[26];
        node():isEnd(false),cnt(0){
            memset(children,0,sizeof(children));
        }
    };
    //字符转数字
    int char2int(char&ch)
    {
        if(islower(ch)){
            return ch-'a';
        }
        return -1;
    }
    //析构函数组件
    void destroy(node* node)
    {
        if (!node) return; 
        for (int i=0;i<26;++i){
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
        }
        cur->isEnd=true;
    }
    int search(string&s){
        node* cur=root;
        for(char ch:s){
            int index=char2int(ch);
            if(!cur->children[index]){
                return 0;
            }
            cur=cur->children[index];
            cur->cnt++;
        }
        if(cur->isEnd)return cur->cnt;
        else return 0;
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
    Trie t;
    string s;
    int n;cin>>n;
    while(n--){
        cin>>s;
        t.insert(s);
    }
    int m;cin>>m;
    while(m--){
        cin>>s;
        int cnt=t.search(s);
        if(cnt==0){
            cout<<"WRONG\n";
        }
        else if(cnt==1){
            cout<<"OK\n";
        }
        else{
            cout<<"REPEAT\n";
        }
    }
    return 0;
}