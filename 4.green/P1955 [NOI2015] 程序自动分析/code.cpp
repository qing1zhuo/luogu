#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100005
struct condition
{
    int i,j;
    bool flag;
};
condition con[MAXN];
int origin[2*MAXN];
int discrete[2*MAXN];
int parent[2*MAXN];

void work();
bool cmp(int a,int b);
void init(int n);
int find(int x);
void unionn(int x,int y);
int BinarySearch(int l,int r,int g);

int main()
{
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>con[i].i>>con[i].j>>con[i].flag;
        origin[2*i-1]=con[i].i;
        origin[2*i]=con[i].j;
    }
    sort(origin+1,origin+1+2*n,cmp);
    int left=1,right=1;int pt=0;
    while(left<=2*n)
    {
        while(origin[left]==origin[right]&&right<=2*n)right++;
        discrete[++pt]=origin[left];
        left=right;
    }

    init(pt);
    for(int i=1;i<=n;i++)
    {
        if(con[i].flag)
        {
            int i_index=BinarySearch(1,pt,con[i].i);
            int j_index=BinarySearch(1,pt,con[i].j);
            unionn(i_index,j_index);
        }
    }

    bool ans=true;
    for(int i=1;i<=n;i++)
    {
        if(!con[i].flag)
        {
            int i_index=BinarySearch(1,pt,con[i].i);
            int j_index=BinarySearch(1,pt,con[i].j);
            if(find(i_index)==find(j_index))ans=false;
        }
    }

    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int BinarySearch(int l,int r,int g)
{
    if(l==r)return l;
    int mid=(l+r)/2;
    if(discrete[mid]==g)return mid;
    if(discrete[mid]>g)return BinarySearch(l,mid-1,g);
    if(discrete[mid]<g)return BinarySearch(mid+1,r,g);
}
bool cmp(int a,int b){return a<b;}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
}
int find(int x)
{
    if(parent[x]==x)return parent[x];
    else return parent[x]=find(parent[x]);
}
void unionn(int x,int y)
{
    parent[find(y)]=find(x);
}