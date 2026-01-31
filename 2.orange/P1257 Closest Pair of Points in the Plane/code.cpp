#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
#define maxn 10010
#define ll long long

double ans=1e40;
int n;
int afterx[maxn],aftery[maxn];
struct node{ll x,y;}a[maxn]; 
inline ll power(ll a){return a*a;}
bool cmp(node a,node b){return (a.x!=b.x)?a.x<b.x:a.y<b.y;}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+1+n,cmp);
    stack<int>sx,sy;
    for(int i=1;i<=n;i++){
        afterx[i]=i,aftery[i]=i;
        while(!sx.empty()&&a[sx.top()].x<a[i].x){
            afterx[sx.top()]=i;
            sx.pop();
        }
        sx.push(i);
        while(!sy.empty()&&a[sy.top()].y<a[i].y){
            aftery[sy.top()]=i;
            sy.pop();
        }
        sy.push(i);
    }
    for(int i=1;i<=n;i++){
        int nxt1=afterx[i];
        double d1=sqrt(power(a[i].x-a[nxt1].x)+power(a[i].y-a[nxt1].y));
        int nxt2=aftery[i];
        double d2=sqrt(power(a[i].x-a[nxt2].x)+power(a[i].y-a[nxt2].y));
        if(d1==0)d1=1e40;
        if(d2==0)d2=1e40;
        ans=min(ans,min(d1,d2));
    }
    printf("%.4lf",ans);
    return 0;
}