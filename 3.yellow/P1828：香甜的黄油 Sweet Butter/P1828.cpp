#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf INT_MAX
#define queuesize 2000
int queue[queuesize];//队列
bool inqueue[queuesize];//标记是否在队列
int path[queuesize][queuesize];//标记两点间距离
int cnt[queuesize][queuesize];//标记某点的路径数量与终点,cnt[i][0]表示第i个农场有cnt[i][0]条路径
int mark[queuesize];//标记牧场有多少只奶牛
int dis[queuesize];
int n,p,c;int head=0,tail=0;

void ini()//初始化队列
{
    head=tail=0;
}
void into_queue(int k){
    queue[tail]=k;//元素入队
    inqueue[k]=true;//元素状态改为在队列中
    tail=(tail+1)%queuesize;//尾指针后移
}
int out_queue()
{
    int out=queue[head];//去除头指针元素并返回
    inqueue[out]=false;//头指针元素标记为出队
    head=(head+1)%queuesize;//头指针加一
    return out;
}
void spfa(int start){
    ini();
    for(int i=1;i<=p;i++){
        dis[i]=inf;
    }
    dis[start]=0;

    into_queue(start);
    while(head!=tail)//相等时说明队列为空
    {
        int u=out_queue();
        for(int i=1;i<=cnt[u][0];i++){
            int v=cnt[u][i];
            int w=path[u][v];
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                if(inqueue[v]==false)into_queue(v);
            }
        }
    }
}
int main()
{
    cin>>n>>p>>c;
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            path[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        mark[t]++;
    }
    for(int i=1;i<=c;i++){
        int u,v,w;cin>>u>>v>>w;
        path[u][v]=path[v][u]=w;
        cnt[u][0]++;cnt[u][cnt[u][0]]=v;
        cnt[v][0]++;cnt[v][cnt[v][0]]=u;
    }

    int ans=inf;
    for(int i=1;i<=p;i++){
        spfa(i);
        int sum=0;
        for(int j=1;j<=p;j++){
            sum+=dis[j]*mark[j];
        }
        if(sum<ans)ans=sum;
    }
    cout<<ans;
    return 0;
}