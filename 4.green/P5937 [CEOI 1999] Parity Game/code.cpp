#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 5010

struct QA
{
    int l,r;
    string s;
};
int n=0,m=0;
QA qa[maxn];
int discrete[2*maxn]={0};int disn=0;
int f[4*maxn];

int discrete_deal();
int binary_search(int x,int left,int right);
void unionn_init(int n);
void unionn(int x,int y);
int find(int x);

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>qa[i].l>>qa[i].r>>qa[i].s;
        qa[i].l--;
        discrete[++disn]=qa[i].l,discrete[++disn]=qa[i].r;
    }
    disn=discrete_deal();
    unionn_init(disn);
    for(int i=1;i<=m;i++){
        int l=binary_search(qa[i].l,1,disn);
        int r=binary_search(qa[i].r,1,disn);
        if(qa[i].s=="even"){
            if(find(l)==find(r+disn)){
                cout<<i-1;
                return 0;
            }
            unionn(l,r);
            unionn(l+disn,r+disn);
        }
        else if(qa[i].s=="odd"){
            if(find(l)==find(r)){
                cout<<i-1;
                return 0;
            }
            unionn(l,r+disn);
            unionn(l+disn,r);
        }
    }
    cout<<m;
    //test();
    return 0;
}

int discrete_deal()
{
    int res=0;
    discrete[0]=-1;
    sort(discrete+1,discrete+1+disn);
    for(int i=1;i<=disn;i++){
        if(discrete[i]!=discrete[i-1]){
            discrete[++res]=discrete[i];
        }
    }
    return res;
}
int binary_search(int x,int left,int right)
{
    int l=left,r=right;
    while(l<=r){
        int mid=(l+r)/2;
        if(discrete[mid]==x)return mid;
        else if(discrete[mid]>x)r=mid-1;
        else if(discrete[mid]<x)l=mid+1;
    }
    return -1;
}
void unionn_init(int n)
{
    for(int i=1;i<=2*n;i++){
        f[i]=i;
    }
}
void unionn(int x,int y)
{
    x=find(x),y=find(y);
    if(x!=y)f[x]=y;
}
int find(int x)
{
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}


/*
s[l~r]=s[r]^s[l-1]
l~r区间的奇偶性等于，1~l-1区间的奇偶性与1~r区间的奇偶性做异或运算，奇数为1，偶数为0
*/