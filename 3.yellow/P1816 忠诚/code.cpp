#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100010

int n,m;
int t[maxn];
int minst[25][maxn];
int logtable[maxn];

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>t[i];
        minst[0][i]=t[i];
    }

    logtable[1]=0;
    for(int i=2;i<=m;i++){
        logtable[i]=logtable[i/2]+1;
    }

    for(int k=1;k<=24;k++){
        int step=1<<(k-1);
        for(int i=1;i<=m;i++){
            minst[k][i]=min(minst[k-1][i],minst[k-1][min(i+step,m)]);
        }
    }

    int a,b;
    int len,step;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        len=b-a+1;
        step=1<<logtable[len];
        ans=min(minst[logtable[len]][a],minst[logtable[len]][b-step+1]);
        cout<<ans<<" ";
    }

    return 0;
}