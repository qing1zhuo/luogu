#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct State
{
    int x,y;
    int dep;
};
int dx[9]={0,1,1,1,0,0,-1,-1,-1};
int dy[9]={0,1,0,-1,1,-1,1,0,-1};
int x,y,mx,my;
char a[105][105];
int ans=0;
queue<State>q;

int main()
{
    cin>>x>>y>>mx>>my;
    for(int row=y;row>0;row--){
        for(int col=1;col<=x;col++){
            cin>>a[col][row];
        }
    }
    a[mx][my]='m';
    q.push({mx,my,0});
    while(!q.empty()){
        State cur=q.front();q.pop();
        for(int i=1;i<=8;i++){
            int next_x=cur.x+dx[i];
            int next_y=cur.y+dy[i];
            int next_dep=cur.dep+1;
            if(next_x<=x&&next_x>=1&&next_y<=y&&next_y>=1&&a[next_x][next_y]=='.'){
                a[next_x][next_y]='m';
                q.push({next_x,next_y,next_dep});
                ans=max(ans,next_dep);
            }
        }
    }
    cout<<ans;
    return 0;
}