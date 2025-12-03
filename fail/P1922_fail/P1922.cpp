#include<iostream>
using namespace std;
int tree[100005];//tree[i] represents the parent of node i
int son[100005];//son[i] represents the number of children of node i
int table[100005];//table[i] represents the number of table in the son tree of node i
int cafe[100005];//cafe[i] represents the number of cafe in the son tree of node i
int leaf[100005];//leaf[i] represents whether node i is table(1) or cafe(-1)
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        tree[y]=x;
        son[x]++;
    }

    printf("%d\n",table[1]);
    return 0;
}