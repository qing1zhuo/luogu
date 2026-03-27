#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int m,n;
class Trie
{
private:
    class Node
    {
    public:
        bool isEnd;
        int End_cnt;//以这个节点为结束的字符串数量
        int Pass_cnt;//经过这个节点的字符串数量
        Node* child[2];
        Node():End_cnt(0),Pass_cnt(0),isEnd(false){child[0]=child[1]=nullptr;}
    };
    Node*root;
public:
    Trie(){root=new Node;}
    void insert(string&str)
    {
        Node*cur=root;
        int len=str.size();
        for(int i=0;i<len;i++){
            int index=str[i]-'0';
            if(cur->child[index]==nullptr){
                cur->child[index]=new Node;
            }
            cur=cur->child[index];
            cur->Pass_cnt++;
        }
        cur->isEnd=true;
        cur->End_cnt++;
    }
    int common_prefix(string&str){
        Node*cur=root;
        int len=str.size();
        int ans=0;
        for(int i=0;i<len;i++){
            int index=str[i]-'0';
            if(!cur->child[index]){
                break;
            }
            cur=cur->child[index];
            if(cur->isEnd&&i!=len-1)//如果存在以这个节点结束的字符串
            {
                ans+=cur->End_cnt;
            }
            else if(i==len-1)//如果str结束了
            {
                ans+=cur->Pass_cnt;
            }
        }
        return ans;
    }
};

int main()
{
    Trie t;
    cin>>m>>n;
    string s;

    int b;int x;
    while(m--){
        cin>>b;
        while(b--){
            cin>>x;
            s+=(char)(x+'0');
        }
        t.insert(s);
        s="";
    }

    int c;
    while(n--){
        cin>>c;
        while(c--){
            cin>>x;
            s+=(char)(x+'0');
        }
        int res=t.common_prefix(s);
        cout<<res<<endl;
        s="";
    }
}