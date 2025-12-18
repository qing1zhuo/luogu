#include<iostream>
#include<stack>
using namespace std;
const int MAXN=10005;
int L,W;
int map[MAXN][MAXN];
int h[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN];

int main()
{
    cin>>L>>W;
    int n;cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        map[x][y]=1;
    }
    //处理h数组
    for(int i=0;i<=L;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0)h[i][j]=0;
            else if(map[i][j]==1&&(map[i-1][j]==1||(i-1)==0))h[i][j]=0;
            else if(map[i][j]==1&&map[i-1][j]==0)h[i][j]=h[i-1][j]+1;
            else if(map[i][j]==0&&map[i-1][j]==0)h[i][j]=h[i-1][j]+1;
            else if(map[i][j]==0&&map[i-1][j]==1)h[i][j]=1;
        }
    }
    //处理l数组
    for(int i=0;i<=L;i++)
    {
        stack<int>s;
        for(int j=W;j>=0;j--)
        {
            while(!s.empty()&&h[i][s.top()]>h[i][j])
            {
                l[i][s.top()]=j;
                s.pop();
            }
            s.push(j);
        }
        while(!s.empty())
        {
            l[i][s.top()]=-1;
            s.pop();
        }
    }
    //处理r数组
    for(int i=0;i<=L;i++)
    {
        stack<int>s;
        for(int j=0;j<=W;j++)
        {
            while(!s.empty()&&h[i][s.top()]>h[i][j])
            {
                r[i][s.top()]=j;
                s.pop();
            }
            s.push(j);
        }
        while(!s.empty())
        {
            r[i][s.top()]=W+1;
            s.pop();
        }    
    }
    long long ans=0;
    for(int i=0;i<=L;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(h[i][j]!=0)
            {
                long long width=r[i][j]-l[i][j]-2;
                if(ans<width*h[i][j])
                {
                    ans=width*h[i][j];
                }
            }
        }
    }
    cout<<ans<<endl;
    //printh(),printl(),printr();
    return 0;
}

