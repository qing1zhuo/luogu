#include<iostream>
#include<algorithm>
using namespace std;
struct path
{
    int u,v,w;
};
path p[6001];
int parent[201];
int urank[201];
bool mark[201];

void work();
void init(int n);//初始化每个节点
int find(int x);//寻找每个节点的父节点
bool unionn(int x,int y);//合并
void insert_sort(int left,int right);//插入排序
void my_sort(int left, int right);//排序主体
void swap(path& a,path& b);//交换
void work(int n,int k);
void test(int k);

int main()
{
    int n,w;
    cin>>n>>w;
    int flag=0;
    for(int i=1;i<=w;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        p[i].u=u;p[i].v=v;p[i].w=w;
        if(mark[u]==0)
        {
            mark[u]=1;flag++;
        }
        if(mark[v]==0)
        {
            mark[v]=1;
            flag++;
        }
        if(flag==n)//所有节点都出现后
        {
            work(n,i);
        }
        else cout<<"-1"<<endl;
    }
    
    //test(w);
    return 0;
}

void test(int n)
{
    cout<<"********"<<endl;
    my_sort(1,n);
    for(int i=1;i<=n;i++)
    {
        int u=p[i].u,v=p[i].v,w=p[i].w;
        cout<<u<<" "<<v<<" "<<w<<endl;
    }
}
void work(int n,int k)
{
    init(n);
    my_sort(1,k);
    int num=0;//边的数量
    unsigned long long tot=0;
    for(int i=1;i<=k;i++)
    {
        int u=p[i].u,v=p[i].v,w=p[i].w;
        if(unionn(u,v))
        {
            tot+=w;
            num++;
        }
    }
    if(num==n-1)cout<<tot<<endl;
    else cout<<-1<<endl;
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        urank[i]=0;
        parent[i]=i;
    }
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
    if(urank[fx]==urank[fy])
    {
        parent[fy]=fx;
        urank[fx]=urank[fy]+1;
    }
    else if(urank[fx]<urank[fy])
    {
        parent[fx]=fy;
        urank[fx]=urank[fy]-1;
    }
    else if(urank[fx]>urank[fy])
    {
        parent[fy]=fx;
        urank[fy]=urank[fx]-1;
    }
    return true;
}

void insert_sort(int left,int right)
{
    for(int i=left+1;i<=right;i++)
    {
        path tmp=p[i];
        int j=i-1;
        while(j>=left&&p[j].w>tmp.w)
        {
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=tmp;
    }
}
void my_sort(int left, int right) 
{
    if (right - left + 1 < 10) {
        insert_sort(left, right);
        return;
    }
    int i = left, j = right;
    int key = p[(i+j)/2].w;
    while (true) 
    {
        while (p[i].w < key) i++;
        while (p[j].w > key) j--;
        if (i >= j) break;
        swap(p[i], p[j]);
        i++;
        j--;
    }
    if (left < j) my_sort(left, j);
    if (i < right) my_sort(i, right);
}
void swap(path& a,path& b)
{
    path tmp=a;
    a=b;
    b=tmp;
}