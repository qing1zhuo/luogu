#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 3005

long long ans=0;
int t[maxn][maxn];
int n,k;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>t[i][j];
        }
    }

    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=i;j++){
            //(i,j) start
            int maxa=-1;
            for(int p=i;p<i+k;p++){
                for(int q=j;q<j+k;q++){
                    maxa=max(maxa,t[p][q]);
                }
            }
            ans+=(long long)maxa;
        }
    }
    cout<<ans;
    return 0;
}

void solve()
{
    
}