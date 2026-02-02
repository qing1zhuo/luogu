#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 20010
#define ull unsigned long long

ull ans=0;
struct Cow{int v,x;}cow[maxn];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cow[i].v>>cow[i].x;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=max(cow[i].v,cow[j].v)*abs(cow[i].x-cow[j].x);
        }
    }
    cout<<ans;
    return 0;
}