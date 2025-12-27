#include<iostream>
using namespace std;
#define MAXN 5000005
int a[MAXN],b[MAXN],c[MAXN];
int main()
{
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++)
    {
        cin>>a[i+1];
        b[i+1]=a[i+1]-a[i];
    }
    int x,y,z;
    for(int i=0;i<p;i++)
    {
        cin>>x>>y>>z;
        b[x]+=z;
        if(y<n)b[y+1]-=z;
    }
    int minn=1e5;
    for(int i=1;i<=n;i++)
    {
        c[i]=b[i]+c[i-1];
        if(c[i]<minn)minn=c[i];
    }
    cout<<minn<<endl;
    return 0;
}