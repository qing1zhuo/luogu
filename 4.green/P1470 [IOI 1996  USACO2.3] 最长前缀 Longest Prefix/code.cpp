#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define maxn 200005
class Trie
{
private:
    //树的节点
    struct node
    {
        bool isEnd;
        node* children[26];
        node():isEnd(false){
            memset(children,0,sizeof(children));
        }
    };
    //字符转数字
    int char2int(char&ch)
    {
        if(isupper(ch)){
            return ch-'A';
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
    bool find(string&s){
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
};
Trie Dictionary;
bool dp[maxn]={true};
int main()
{
    string str,S;
    while(1){
        cin>>str;
        if(str==".")break;
        Dictionary.insert(str);
    }
    while(cin>>str){
        S=S+str;
    }
    int n=S.size();
    for(int i=0;i<n;i++){
        for(int j=i;j>=max(i-10,0);j--){
            string s=S.substr(j,i-j+1);
            if(dp[j]&&Dictionary.find(s)){
                dp[i+1]=true;
                break;
            }
        }
    }
    int maxl=0;
    for(int i=1;i<=n;i++){
        if(i>maxl&&dp[i])maxl=i;
    }
    cout<<maxl;
    return 0;
}