#include<iostream>
#include<climits>
using namespace std;
int d[3]={0,1,-1};
int n,a,b;
int li[205];
int ans=0;
int path[205][2];//记录路径,1为当前楼层，0为来自何处
int mark[205];//标记哪些楼层去过
int flag=0;
int head=1,tail=1;
void back(int k)
{
    if(path[k][0])
    {
        back(path[k][0]);
    }
    ans++;
}
void bfs()
{
    while(head<=tail&&path[head][1]!=b)
    {
        for(int i=1;i<=2;i++)
        {
            int floor=path[head][1]+d[i]*li[path[head][1]];
            if(floor>=1&&floor<=n&&mark[floor]==0)
            {
                tail++;
                path[tail][1]=floor;
                path[tail][0]=head;
                mark[floor]=1;
            }
        }
        head++;
    }
    if(path[head][1]==b)
    {
        flag=1;
        back(head);
    }
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>li[i];
    path[1][1]=a;path[1][0]=0;
    mark[a]=1;
    bfs();
    if(flag)cout<<ans-1;
    else cout<<-1;
    return 0;
}