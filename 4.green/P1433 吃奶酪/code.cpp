#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Node{double x,y;}node[20];
double dis[25][25];
bool vis[25]={0};
int n;
double ans=1e20;
double sum=0;
inline double power(double x){return x*x;}

double cur_min_dis(int cur)
{
    vector<int>res;
    for(int i=1;i<=n;i++){
        if(!vis[i])res.push_back(i);
    }
    int m=res.size();
    if(m==0)return 0;

    double next_min=1e20;
    for(int i=0;i<m;i++){
        next_min=min(next_min,dis[cur][res[i]]);
    }

    //prim图算法
    vector<bool>v(m);
    vector<double>d(m,1e20);
    d[0]=0;
    double sum_dis=0;
    for(int i=0;i<m;i++){
        int u=-1;double min_d=1e20;
        for(int j=0;j<m;j++){
            if(!v[j]&&d[j]<min_d){
                min_d=d[j];
                u=j;
            }
        }

        sum_dis+=min_d;
        v[u]=true;

        for(int j=0;j<m;j++){
            if(!v[j]){
                d[j]=min(d[j],dis[res[u]][res[j]]);
            }
        }
    }
    return next_min+sum_dis;
}
void dfs(int cur_index,int num)//当前(x,y),目前经过多少点
{
    if(num==n){
        ans=min(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            sum+=dis[cur_index][i];
            if(sum+cur_min_dis(i)>=ans){//如若当前距离总和已经大于当前答案，则立刻回溯
                sum-=dis[cur_index][i];
                vis[i]=false;
                continue;
            }
            dfs(i,num+1);
            vis[i]=false;
            sum-=dis[cur_index][i];
        }
    }
}
void pre_dis(int n)
{
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=sqrt(power(node[i].x-node[j].x)+power(node[i].y-node[j].y));
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i].x>>node[i].y;
    }
    pre_dis(n);
    dfs(0,0);
    printf("%.2lf",ans);
    return 0;
}
