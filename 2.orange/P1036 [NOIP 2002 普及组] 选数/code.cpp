#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,k;
int a[25];
long long ans=0;

bool is_prime(int x)
{
    if(x==1)return false;
    if(x==2)return true;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int x,int y,int z)//考虑a[x]选不选，当前已经选了y个，总和为z
{
    if(y>k)return;
    if(n-x+1+y<k)return;
    if(x>n&&is_prime(z)){
        ans++;
        return;
    }   
    dfs(x+1,y+1,z+a[x]);
    dfs(x+1,y,z);
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}

