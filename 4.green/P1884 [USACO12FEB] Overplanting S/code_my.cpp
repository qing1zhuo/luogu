#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define MAXN 4010

int n,b_cnt,c_cnt;
int a[MAXN][4],b[MAXN],c[MAXN];
int f[MAXN][MAXN];
map<int,int>Map;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
            b[++b_cnt]=a[i][j];
        }
    }
    sort(b+1,b+b_cnt+1);
    b[0]=-1e9-5;
    for(int i=1;i<=b_cnt;i++){
        if(b[i]!=b[i-1]){
            c[++c_cnt]=b[i];
            Map[b[i]]=c_cnt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            a[i][j]=Map[a[i][j]];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=a[i][0];j<a[i][2];j++){
            f[j][a[i][3]]++,f[j][a[i][1]]--;
        }
    }

    for(int i=1;i<=c_cnt;i++){
        for(int j=1;j<=c_cnt;j++){
            f[i][j]+=f[i][j-1];
        }
    }

    for(int i=1;i<=c_cnt;i++){
        for(int j=1;j<=c_cnt;j++){
            if(f[i][j])ans+=(long long)(c[i+1]-c[i])*(c[j+1]-c[j]);
        }
    }

    cout<<ans;
    return 0;
}