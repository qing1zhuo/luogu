#include<iostream>
using namespace std;
int father[10001];
int cost[10001];
int value[10001];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}
int find(int x)
{
    if(father[x]==x)return father[x];
    else return father[x]=find(father[x]);
}
void unionn(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fy!=fx)
    {
        father[fy]=fx;
    }
}
int main()
{
    int n,m,w;
    cin>>n>>m>>w;
    //初始化
    init(n);

    //读取数据
    for(int i=1;i<=n;i++)
    {
        int c,v;cin>>c>>v;
        cost[i]=c;value[i]=v;
    }
    
    //合并
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        unionn(x,y);
    }
    
    //处理每个连通块的总价值和总花费
    for(int i=1;i<=n;i++){
        int f=find(i);
        if(f!=i){
            value[f]+=value[i];
            cost[f]+=cost[i];
        }
    }
    
    //提取每个连通块
    bool used[10001]={false};
    int bag[10001][3]={0};
    int num=0;//表示有多少连通块
    for(int i=1;i<=n;i++)
    {
        int f=find(i);
        if(!used[f]){
            used[f]=true;
            num++;
            bag[num][1]=cost[f];
            bag[num][2]=value[f];
        }
    }
    
    //01背包
    int dp[10001]={0};
    for(int i=1;i<=num;i++){
        for(int j=w;j>=bag[i][1];j--){
            dp[j]=max(dp[j],dp[j-bag[i][1]]+bag[i][2]);
        }
    }
    cout<<dp[w]<<endl;
    return 0;
}