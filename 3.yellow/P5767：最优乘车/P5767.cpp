#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int _v[501][101];
int cnt[501];
int dis[501];
bool mark[501];
void my_scanf()
{
    string s;
	int z = 0;int q[501];
	getline(cin, s);//字符串读入 
	for(int i = 0; i < s.length(); ++i)
	{
		int x = 0;//记录当前答案 
		while(s[i] <= '9' && s[i] >= '0')//转换(遇到空格就退了) 
		{
			x = x * 10 + s[i] - '0';//当前所有位都向前移一位再加上最低位(转成数字) 
			++i;//不停的加 
		}
		q[++z] = x;//存储 
	}
	for(int i = 1; i <z; ++i)
	{
        for(int j=i+1;j<=z;j++){
            //建立无向图
            _v[q[i]][++cnt[q[i]]]=q[j];
        }
	}
}

int main()
{
    int m,n;cin>>m>>n;
    cin.ignore();
    
    for(int i=1;i<=m;i++){
        my_scanf();
    }
    
    for(int i=0;i<=n;i++){
        dis[i]=1e9;
    }
    dis[1]=0;

    for(int k=1;k<=n;k++){
        int u=0;int minn=1e9;
        for(int i=1;i<=n;i++){
            //寻找当前距离起点需要换乘次数最少的点
            if(mark[i]==0&&dis[i]<minn){
                minn=dis[i];
                u=i;
            }
        }

        if(u)mark[u]=1;

        for(int i=1;i<=cnt[u];i++){
            int v=_v[u][i];
            //更新v的距离
            dis[v]=min(dis[v],dis[u]+1);
        }
    }
    if(dis[n]>500)cout<<"NO"<<endl;
    else cout<<dis[n]-1<<endl;
    return 0;
}