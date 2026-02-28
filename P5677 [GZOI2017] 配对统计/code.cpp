#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
#define maxn 300005
int n,m;
struct Node
{
    int id;
    int a;
    int cnt=0;
    int neigh[2]={0,0};
}node[maxn];
int b[maxn],pre[maxn];//b_i表示以i为x的好对有b_i个,pre_i表示i前有pre_i个好对
int ans=0;
bool cmp(Node x,Node y){return x.a<y.a;}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>node[i].a;
        node[i].id=i;
    }
    sort(node+1,node+1+n,cmp);
    for(int i=2;i<n;i++){
        int l_delta=abs(node[i-1].a-node[i].a),r_delta=abs(node[i+1].a-node[i].a);
        if(l_delta<r_delta){
            node[i].cnt=1;
            node[i].neigh[0]=node[i-1].id;
        }
        else if(l_delta==r_delta){
            node[i].cnt=2;
            node[i].neigh[0]=node[i-1].id;
            node[i].neigh[1]=node[i+1].id;
        }
        else if(l_delta>r_delta){
            node[i].cnt=1;
            node[i].neigh[0]=node[i+1].id;
        }
    }
    cout<<ans;
    //test();
    return 0;
}