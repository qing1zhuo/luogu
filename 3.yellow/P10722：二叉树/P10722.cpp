#include<iostream>
using namespace std;
int arr[100001];
int tree[100001][3];//tree[i][0]:parent;tree[i][1]:leftchild;tree[i][2]:rightchild;
int mark[100001];//标记这个节点被改变过几次
int markk[100001];//标记这个节点一共被改变几次
int num=0;
int n,q;
int dfs(int k);
void rever(int*a);
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++){
        int pa;cin>>pa;
        tree[i][0]=pa;
        if(tree[pa][1]==0)tree[pa][1]=i;
        else tree[pa][2]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%1d",&arr[i]);
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int node;cin>>node;
        mark[node]++;
    }
    markk[1]=mark[1]+2;
    for(int i=1;i<=n;i++){
        if(markk[i]==0)markk[i]=dfs(i);
    }
    for(int i=1;i<=n;i++){
        if(markk[i]%2==1){
            rever(&arr[i]);
        }
    }
    for(int i=1;i<=n;i++)cout<<arr[i];
    return 0;
}

int dfs(int k)
{
    if(markk[k]==0){
        markk[k]=mark[k]+dfs(tree[k][0]);
    }
    return markk[k];
}
void rever(int*a)
{
    if(*a==0)*a=1;
    else *a=0;
}