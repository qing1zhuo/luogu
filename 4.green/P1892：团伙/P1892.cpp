#include<iostream>
using namespace std;
#define maxn 50001
int pa[maxn];
int enemy[maxn];
bool mark[maxn];
void init(int n){
    for(int i=1;i<=n;i++){
        pa[i]=i;
    }
}
int find(int x){
    if(pa[x]==x)return pa[x];
    else return find(pa[x]);
}
void unionn(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)pa[fy]=fx;
}

int main()
{
    int n,m;
    cin>>n>>m;
    init(n);
    for(int i=1;i<=m;i++){
        char ch;int a,b;
        cin>>ch>>a>>b;
        if(ch=='E'){
            if(enemy[a]==0&&enemy[b]==0){
                enemy[a]=b;enemy[b]=a;
            }
            else if(enemy[a]==0&&enemy[b]!=0){
                enemy[a]=b;
                unionn(enemy[b],a);
            }
            else if(enemy[a]!=0&&enemy[b]==0){
                enemy[b]=a;
                unionn(enemy[a],b);
            }
            else{
                unionn(enemy[a],b);
                unionn(enemy[b],a);
            }
        }
        else if(ch=='F'){
            unionn(a,b);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int root=find(i);
        if(!mark[root]){
            mark[root]=true;
            ans++;
        }
        else{
            continue;
        }
    }
    cout<<ans;
    return 0;
}