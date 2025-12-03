#include<iostream>
using namespace std;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int tine[505][505];//每个人感染的时间
int mark[505][505];//标记是否被感染
int sour[250005][3];//标记感染源
int lord[250005][3];//标记领主
int path[250005][3];//标记路径
int head,tail;
int n,m,a,b;
void bfs();

int main()
{
    head=1,tail=0;
    cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>sour[i][1]>>sour[i][2];
        mark[sour[i][1]][sour[i][2]]=1;
        path[i][1]=sour[i][1];path[i][2]=sour[i][2];
        tail++;
    }
    for(int i=1;i<=b;i++){
        cin>>lord[i][1]>>lord[i][2];
    }

    bfs();

    for(int i=1;i<=b;i++){
        int x=lord[i][1];int y=lord[i][2];
        cout<<tine[x][y]<<endl;
    }
    return 0;
}

void bfs()
{
    while(head<=tail){
        int x_now=path[head][1];
        int y_now=path[head][2];
        for(int i=1;i<=4;i++)
        {
            int tx=x_now+dx[i];int ty=y_now+dy[i];
            if(tx<=n&&tx>=1&&ty>=1&&ty<=m&&mark[tx][ty]==0)
            {
                tail++;
                path[tail][1]=tx;path[tail][2]=ty;
                mark[tx][ty]=1;
                tine[tx][ty]=tine[x_now][y_now]+1;
            }
        }
        head++;
    }
}