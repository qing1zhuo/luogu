/*
仅采用迭代加深搜索
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
int origin[4][4];
int target[4][4]={{0,0,0,0},{0,1,2,3},{0,8,0,4},{0,7,6,5}};
int x_0,y_0;
ll ans=1e16,cur_ans=1e16;
int dep;

void dfs(int cur_dep,int cur_x,int cur_y);
void swap(int& x,int& y);
bool check();

int main()
{
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            scanf("%1d",&origin[i][j]);
            if(origin[i][j]==0){
                x_0=i;y_0=j;
            }
        }
    }
    for(dep=1;dep<=25;dep++){
        cur_ans=1e16;
        dfs(1,x_0,y_0);
        if(cur_ans!=1e16){
            ans=min(cur_ans,ans);
            break;
        }
    }
    cout<<ans;
    return 0;
}

void dfs(int cur_dep,int cur_x,int cur_y)//当前要移动第cur_dep步,0在(cur_x,xur_y)
{
    if(check()){//如果相同，返回cur_dep-1步，因为当前这步还没移动
        cur_ans=min(cur_ans,(ll)cur_dep-1);
        return;
    }
    if(cur_dep>dep){//如果超了最多能移动的步数，且不相同，则返回
        return;
    }

    for(int i=1;i<=4;i++){
        int nextx=cur_x+dx[i],nexty=cur_y+dy[i];
        if(nextx>=1&&nextx<=3&&nexty>=1&&nexty<=3){
            swap(origin[nextx][nexty],origin[cur_x][cur_y]);
            dfs(cur_dep+1,nextx,nexty);
            swap(origin[nextx][nexty],origin[cur_x][cur_y]);
        }
    }

}
void swap(int& x,int& y)
{
    int cur=x;
    x=y;
    y=cur;
}
bool check()
{
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(origin[i][j]!=target[i][j])return false;
        }
    }
    return true;
}