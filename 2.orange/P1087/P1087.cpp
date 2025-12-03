#include<iostream>
#include<string.h>
using namespace std;

typedef struct tree
{
    char s[1050];
    int len;
    char ch;
    int lchild;
    int rchild;
}tree;
tree t[3000];
int n,num;

int trans(int);//将n转化为2^n
char check(char*,int);//检查长度为n的字符串属于哪种类型
void print(int);

int main()
{
    cin>>n;
    num=trans(n)-1;//有子节点的节点数量
    scanf("%s",t[1].s);
    t[1].len=strlen(t[1].s);
    t[1].ch=check(t[1].s,t[1].len);

    for(int i=1;i<=num;i++)
    {
        int left=2*i;int right=2*i+1;
        t[i].lchild=left;t[i].rchild=right;

        strncpy(t[left].s,t[i].s,t[i].len/2);
        t[left].len=strlen(t[left].s);
        t[left].ch=check(t[left].s,t[left].len);

        strncpy(t[right].s,t[i].s+(t[i].len/2),t[i].len/2);
        t[right].len=strlen(t[right].s);
        t[right].ch=check(t[right].s,t[right].len);
    }

    print(1);
    
    return 0;
}

void print(int k)
{
    if(t[k].ch)
    {
        print(t[k].lchild);
        print(t[k].rchild);
        cout<<t[k].ch;
    }
}

int trans(int k)
{
    int ans=1;
    while(k)
    {
        ans*=2;k--;
    }
    return ans;
}

char check(char*str,int len)
{
    int flag1=0;int flag0=0;//假定一开始没有1也没有0
    for(int i=0;i<len;i++)
    {
        if(str[i]=='1')flag1=1;
        if(str[i]=='0')flag0=1;
    }
    if(flag1==1&&flag0==1)return 'F';
    else if(flag1==1)return 'I';
    else return 'B';
}