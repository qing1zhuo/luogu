#include<stdio.h>
int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    long long light[200005]={0};//每个位置星星亮度之和
    int cur=0;//记录当前位置
    int count=0;//记录有星星的位置数量
    int mark[100005]={0};//记录有星星的位置
    for(int i=1;i<=n;i++)
    {
        int x,b;
        scanf("%d%d",&x,&b);
        light[x]+=b;
        if(cur!=x)
        {
            cur=x;
            count++;
            mark[count]=x;
        }
    }
    long long max=0;//记录最大亮度和
    long long sum=0;//记录当前亮度和
    for(int i=1;i<=count;i++)
    {
        sum=0;
        for(int j=0;j<w;j++)
        {
            sum=sum+light[mark[i]+j];
        }
        if(sum>max) max=sum;
    }
    printf("%lld",max);
    return 0;
}