#include<iostream>
#include<vector>
using namespace std;
struct edge
{
    int u,v,w;
};
vector<edge>E;
int parent[101];
int urank[101];

void insertSort(int left,int right);
void my_sort(int left,int right);
void swap(edge& a,edge& b);
void init(int n);
int find(int x);
bool unionn(int x,int y);

int main()
{
    int n,k;
    int tot=0;
    int ans_t=0;
    cin>>n>>k;
    init(n);
    for(int i=0;i<k;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        tot+=w;
        E.push_back({u,v,w});
    }
    my_sort(0,k-1);
    for(int i=0;i<k;i++)
    {
        int u=E[i].u,v=E[i].v,w=E[i].w;
        if(unionn(u,v))
        {
            ans_t+=w;
        }
    }
    int ans=tot-ans_t;
    cout<<ans<<endl;
    return 0;
}
int find(int x)
{
    if(x!=parent[x])parent[x]=find(parent[x]);
    return parent[x];
}
bool unionn(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return false;
    else
    {
        if(urank[fx]>urank[fy])
        {
            parent[fy]=fx;
            urank[fy]=urank[fx]-1;
        }
        else if(urank[fx]<urank[fy])
        {
            parent[fx]=fy;
            urank[fx]=urank[fy]-1;
        }
        else
        {
            parent[fx]=fy;
            urank[fy]=urank[fx]+1;
        }
        return true;
    }
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        urank[i]=0;
    }
}
void insertSort(int left,int right)
{
    for(int i=left+1;i<=right;i++)
    {
        edge tmp=E[i];
        int j=i-1;
        while(j>=left&&E[j].w>tmp.w)
        {
            E[j+1]=E[j];
            j--;
        }
        E[j+1]=tmp;
    }
}
void my_sort(int left,int right)
{
    if(right-left+1<=10)
    {
        insertSort(left,right);
    }
    else
    {
        int i=left;int j=right;
        int key=E[(i+j)/2].w;
        while(E[i].w<key)i++;
        while(E[j].w>key)j--;
        if(i<j)
        {
            swap(E[i],E[j]);
            i++;j--;
        }
        if(i<right)my_sort(i,right);
        if(j>left)my_sort(left,j);
    }
}
void swap(edge& a,edge& b)
{
    edge tmp=a;
    a=b;
    b=tmp;
}