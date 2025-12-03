#include<iostream>
using namespace std;
int parent[1000001];
int rant[1000001];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rant[i]=0;
    }
}
int find(int x)
{
    if(parent[x]==x)return parent[x];
    else return parent[x]=find(parent[x]);
}
void unionn(int x,int y)
{
    parent[y]=x;
}
int main()
{
    int n,m;cin>>n>>m;
    init(n);
    for(int i=1;i<=m;i++)
    {
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            int r1=find(x);
            int r2=find(y);
            if(r1!=r2){
                unionn(r1,r2);
            }
        }
        else if(z==2){
            if(find(x)==find(y))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}