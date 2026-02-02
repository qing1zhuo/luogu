#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 50010
#define ull unsigned long long

ull ans=0;
struct Cow{int v,x;}cow[maxn],tmp[maxn];
int n;
bool cmp(Cow a,Cow b){return a.v<b.v;}
void solve(int left,int right)
{
    if(left>=right)return;
    int mid=(left+right)/2;
    solve(left,mid),solve(mid+1,right);

    int less_sum=0,bigger_sum=0;
    for(int i=left;i<=mid;i++){
        bigger_sum+=cow[i].x;
    }

    int poi=left;
    for(int i=mid+1;i<=right;i++){
        while(poi<=mid&&cow[poi].x<cow[i].x){
            less_sum+=cow[poi].x;
            bigger_sum-=cow[poi].x;
            poi++;
        }
        ans+=cow[i].v*(1LL*(poi-left)*cow[i].x-less_sum)+cow[i].v*(bigger_sum-1LL*(mid-poi+1)*cow[i].x);
    }

    int l=left,r=mid+1;int cnt=left-1;
    while(l<=mid&&r<=right){
        if(cow[l].x<cow[r].x){
            tmp[++cnt]=cow[l];
            l++;
        }
        else{
            tmp[++cnt]=cow[r];
            r++;
        }
    }
    while(l<=mid){
        tmp[++cnt]=cow[l];
        l++;
    }
    while(r<=right){
        tmp[++cnt]=cow[r];
        r++;
    }
    for(int i=left;i<=cnt;i++){
        cow[i]=tmp[i];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cow[i].v>>cow[i].x;
    }
    sort(cow+1,cow+1+n,cmp);
    solve(1,n);
    cout<<ans;
    return 0;
}