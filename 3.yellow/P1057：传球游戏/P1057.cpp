#include<iostream>
using namespace std;
unsigned long long ans=0;
int n,m;
int dx[3]={0,-1,1};
void dfs(int before,int k)
{
    if(k==m&&(before==2||before==n))ans++;
    else if(k<m){
        for(int i=1;i<=2;i++){
            int tx=before+dx[i];
            if(tx<1)tx=n;
            else if(tx>n)tx=1;
            dfs(tx,k+1);
        }
    }
}
int main()
{
    cin>>n>>m;
    dfs(1,1);
    cout<<ans;
    return 0;
}