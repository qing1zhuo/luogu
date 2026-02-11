#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100

int a[maxn],pre[maxn],len[maxn];
bool use[maxn];
int n,sum;
int ans=1e6;
int d;//要考虑的最短长度能否为d

void dfs(int u,int k,int p);

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        len[a[i]]++;
    }

    sort(a+1,a+1+n);

    a[0]=-1;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1])pre[a[i]]=a[i-1];
    }

    for(d=a[n];2*d<=sum;d++){
        if(sum%d==0){
            dfs(d,sum/d,a[n]);
        }
    }
    cout<<sum;
    return 0;
}

void dfs(int u,int k,int p)//当前长棍还有长度u没有拼，还有k根长棍没拼，当前长棍的最短短棍长度为p
{
    if(u==0){
        dfs(d,k-1,a[n]);
        return;
    }
    if(k==0){
        cout<<d;
        exit(0);
    }
    p=(p<u)?p:u;
    while(p&&!len[p])p--;
    while(p){
        if(len[p]){
            --len[p];
            dfs(u-p,k,p);
            ++len[p];
            if((u==p)||(u==d))return;
            p=pre[p];
        }
        else{
            p=pre[p];
        }
    }
}