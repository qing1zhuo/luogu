#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=50005;
const int LOG=18;
int n,q;
int h[MAXN];
int log_table[MAXN];
int max_st[LOG][MAXN],min_st[LOG][MAXN];

void init_log_table();
void init_ST();
int find(int a,int b);
inline int read();

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)h[i]=read();
    init_log_table(),init_ST();
    for(int i=1;i<=q;i++)
    {
        int a=read();int b=read();
        cout<<find(a,b)<<"\n";
    }
    return 0;
}

void init_log_table()
{
    log_table[1]=0;
    for(int i=2;i<=n;i++)log_table[i]=log_table[i/2]+1;
}
void init_ST()
{
    for(int i=1;i<=n;i++)
    {
        max_st[0][i]=min_st[0][i]=h[i];
    }
    for(int k=1;k<LOG;k++)
    {
        for(int i=1;i<=n-(1<<k)+1;i++)
        {
            max_st[k][i]=max(max_st[k-1][i],max_st[k-1][i+(1<<(k-1))]);
            min_st[k][i]=min(min_st[k-1][i],min_st[k-1][i+(1<<(k-1))]);
        }
    }
}
int find(int a,int b)
{
    int len=b-a+1;
    int log=log_table[len];
    int max_h=max(max_st[log][a],max_st[log][b-(1<<log)+1]);
    int min_h=min(min_st[log][a],min_st[log][b-(1<<log)+1]);
    return max_h-min_h;
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}