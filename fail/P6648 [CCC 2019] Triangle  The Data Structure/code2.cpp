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

    
    cout<<ans;
    return 0;
}