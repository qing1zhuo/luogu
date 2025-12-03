#include<iostream>
using namespace std;
#include<string.h>

int t;
int n,m;
int sum=0;
int maxa=0;
int a[10][10];//存数组
int b[10][10];//0表示没走过，1表示走过了
int dx[9]={0,0,1,1,1,0,-1,-1,-1};
int dy[9]={0,1,1,0,-1,-1,-1,0,1};

void test();
void dsp(int,int);
void conse();

int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        test();
    }
    return 0;
}

void test()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    sum=0;maxa=0;
    cin>>n>>m;
    //存数组
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    dsp(1,1);
    cout<<maxa<<endl;
}

void dsp(int x,int y)
{
    if(x==n+1){
        conse();
        return;
    }
    else if(y==m+1){
        dsp(x+1,1);
        return;
    }
    int flag=1;
    for(int i=1;i<=8;i++)
    {
        int tx=x+dx[i];int ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
        {
            if(b[tx][ty]==1)
            {
                flag=0;break;
            }
        }
    }

    dsp(x,y+1);//不取这个数字

    if(flag)
    {
        b[x][y]=1;sum+=a[x][y];
        dsp(x,y+1);
        b[x][y]=0;sum-=a[x][y];
    }
}

void conse()
{
    if(maxa<sum)
    {
        maxa=sum;
    }
}