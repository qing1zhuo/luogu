#include<iostream>
using namespace std;
int n,q;
int a[8005];
void work1()
{
    int x,v;cin>>x>>v;
    a[x]=v;
}
int work2()
{
    int x;cin>>x;
    int ans=1;
    for(int i=1;i<x;i++)
    {
        if(a[i]<=a[x])ans++;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(a[i]<a[x])ans++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=q;i++)
    {
        int flag=1;cin>>flag;
        if(flag==1)work1();
        if(flag==2)cout<<work2()<<endl;
    }
    return 0;
}