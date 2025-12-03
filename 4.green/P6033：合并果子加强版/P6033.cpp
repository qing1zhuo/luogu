#include<iostream>
#include<queue>
using namespace std;
namespace declaration
{
    long long cnt[100010];
    queue<long long>q1,q2;
    int minn=1000000,maxn=0;
    int n;
    long long ans=0;
}using namespace declaration;
inline long long read() {
    long long x = 0; // 用long long避免数值溢出
    bool f = false;
    char ch = getchar(); // 读取单个字符
    // 跳过非数字字符（如空格、换行）
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = true; // 处理负数（本题数据为正，可省略）
        ch = getchar();
    }
    // 转换数字字符为整数
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48); // 等价于x*10 + (ch-'0')，位运算更快
        ch = getchar();
    }
    return f ? -x : x;
}
int main()
{
    cin>>n;
    if(n==1)
    {
        long long x;cin>>x;
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        long long x=read();
        cnt[x]++;
        if(minn>x)minn=x;
        if(maxn<x)maxn=x;
    }
    for(int i=minn;i<=maxn;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            q1.push(i);
        }
    }
    long long x,y,z;
    while(!(q1.empty()&&q2.size()==1))
    {
        if(q1.empty())//q1为空
        {
            x=q2.front();q2.pop();
            y=q2.front();q2.pop();
        }
        else if(q2.empty())//q2为空
        {
            x=q1.front();q1.pop();
            y=q1.front();q1.pop();
        }
        else//q1，q2都不为空
        {
            //x赋值
            if(q1.front()>q2.front())
            {
                x=q2.front();q2.pop();
                if(q2.empty())
                {
                    y=q1.front();q1.pop();
                }
                else
                {
                    if(q1.front()>q2.front())
                    {
                        y=q2.front();q2.pop();
                    }
                    else
                    {
                        y=q1.front();q1.pop();
                    }
                }
            }
            else
            {
                x=q1.front();q1.pop();
                if(q1.empty())
                {
                    y=q2.front();q2.pop();
                }
                else
                {
                    if(q1.front()>q2.front())
                    {
                        y=q2.front();q2.pop();
                    }
                    else
                    {
                        y=q1.front();q1.pop();
                    }
                }
            }
        }
        z=x+y;
        q2.push(z);
        ans+=z;
    }
    cout<<ans;
    return 0;
}