#include<iostream>
#include<climits>
using namespace std;
int d[3]={0,1,-1};
int n,a,b;
int li[205];
int ans=INT_MAX;
int path[205];//记录路径
int mark[205];//标记哪些楼层去过
int flag=0;
void dfs(int k)
{
    if(path[k]==b)//若到达目标楼层
    {
        if(ans>k)ans=k;
        flag=1;
    }
    else
    {
        for(int i=1;i<=2;i++)
        {
            int floor=path[k]+d[i]*li[path[k]];//可以去的楼层
            if(floor>=1&&floor<=n&&mark[floor]==0)
            {
                path[k+1]=floor;mark[floor]=1;
                dfs(k+1);
                path[k+1]=0;mark[floor]=0;
            }
        }
    }
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>li[i];
    path[1]=a;mark[a]=1;
    dfs(1);
    if(flag)cout<<ans-1;
    else cout<<-1;
    return 0;
}