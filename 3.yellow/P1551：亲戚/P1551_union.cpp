#include<iostream>
using namespace std;
#define maxn 5001
int rant[maxn];
int pa[maxn];
int find(int x)
{
    if(x==pa[x])return x;
    else return find(pa[x]);
}
void unit(int x,int y)
{
    int rx=find(x);
    int ry=find(y);
    if(rant[ry]<rant[rx]){
        pa[ry]=rx;
    }
    else if(rant[ry]>rant[rx]){
        pa[rx]=ry;
    }
    else{
        pa[ry]=rx;
        rant[rx]++;
    }
}
int main()
{
    int n,m,p;cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        pa[i]=i;
        rant[i]=0;
    }
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        unit(x,y);
    }
    for(int i=1;i<=p;i++){
        int x,y;cin>>x>>y;
        if(find(x)==find(y))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}