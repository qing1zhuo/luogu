#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 10005
int a,b,c;
int n,m;
priority_queue<int>q;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        for(int j=1;j<=m;j++){
            long long y=j*j*a+j*b+c;
            if(i==1)q.push(y);
            else{
                if(y<q.top()){
                    q.push(y);
                    q.pop();
                }
                else break;
            }
        }
    }
    int ans[maxn];
    for(int i=1;i<=m;i++){
        ans[i]=q.top();
        q.pop();
    }
    for(int i=m;i;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}