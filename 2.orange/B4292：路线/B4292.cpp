#include<iostream>
using namespace std;
int n,m;
int path[105][105];//存储联通图
int mark[105];//标记该节点是否走过
int walk[105];//存储节点i到n的最短路线
int list[105];
int head=0;int tail=0;
void bfs();
int main()
{
    cin>>n>>m;
    //path[i][0]表示p1开始有多少条路
    int p1,p2;
    for(int i=1;i<=m;i++){
        cin>>p1>>p2;
        path[p1][0]++;
        path[p1][path[p1][0]]=p2;
        path[p2][0]++;
        path[p2][path[p2][0]]=p1;
    }
    head++;tail++;
    mark[n]=1;
    list[head]=n;
    bfs();
    for(int i=1;i<n;i++){
        if(walk[i]==0)walk[i]=-1;
        cout<<walk[i]<<" ";
    }
    return 0;
}
void bfs(){
    while(head<=tail){
        int curNode=list[head];
        for(int i=1;i<=path[curNode][0];i++){
            int nextNode=path[curNode][i];
            if(mark[nextNode]==0){
                mark[nextNode]=1;
                walk[nextNode]=walk[curNode]+1;
                tail++;
                list[tail]=nextNode;
            }
        }
        head++;
    }
}