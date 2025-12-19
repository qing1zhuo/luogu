#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int LOG=18;
int n,m;
int arr[MAXN];
int max_st[LOG][MAXN];
int log_table[MAXN];

void init_log_table();
void init_max_st();
int find(int a,int b);
inline int read();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n=read(),m=read();

    for(int i=1;i<=n;i++)arr[i]=read();

    init_log_table();//初始化对数表
    init_max_st();//初始化ST表

    for(int i=1;i<=m;i++)
    {
        int a,b;a=read(),b=read();
        cout<<find(a,b)<<"\n";
    }

    return 0;
}

void init_log_table()
{
    log_table[1]=0;
    for(int i=2;i<=n;i++)
    {
        log_table[i]=log_table[i/2]+1;
    }
}
void init_max_st()
{
    for(int i=1;i<=n;i++)
    {
        max_st[0][i]=arr[i];
    }

    for(int k=1;k<LOG;k++)
    {
        for(int i=1;i + (1<<k) -1<=n;i++)
        {
            max_st[k][i]=max(max_st[k-1][i],max_st[k-1][i+(1<<(k-1))]);
        }
    }
}
int find(int a,int b)
{
    int len=b-a+1;
    int log_len=log_table[len];
    return max(max_st[log_len][a],max_st[log_len][b-(1<<log_len)+1]);
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
