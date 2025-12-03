#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
int a[1010][1010];
int h[1010][1010],r[1010][1010],l[1010][1010];
unsigned long long ans=0;
void ddzl(int i);
void ddzr(int i);
void print();
void read();

int main()
{
    cin>>n>>m;
    read();
    for(int i=1;i<=n;i++)
    {
        ddzl(i);
        ddzr(i);
    }
    //print();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])ans+=(r[i][j]-j)*(j-l[i][j])*h[i][j];
        }
    }
    cout<<ans;
    return 0;
}

void read()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;cin>>ch;
            if(ch=='.')a[i][j]=1;
            else a[i][j]=0;
            
            //处理h数组
            if(a[i-1][j]==1&&a[i][j]==1)h[i][j]=h[i-1][j]+1;//上面和自己都是1
            else if(a[i][j]==1)h[i][j]=1;//上面不是1，自己是1
            else h[i][j]=0;//自己是0
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
}
void ddzl(int i)
{
    stack<int>s;
    for(int j=m;j>=1;j--)
    {
        while(!s.empty()&&h[i][s.top()]>h[i][j])
        {
            l[i][s.top()]=j;
            s.pop();
        }
        s.push(j);
    }
    while(!s.empty())
    {
        l[i][s.top()]=0;
        s.pop();
    }
}
void ddzr(int i)
{
    stack<int>s;
    for(int j=1;j<=m;j++)
    {
        while(!s.empty()&&h[i][s.top()]>=h[i][j])
        {
            r[i][s.top()]=j;
            s.pop();
        }
        s.push(j);
    }
    while(!s.empty())
    {
        r[i][s.top()]=m+1;
        s.pop();
    }    
}