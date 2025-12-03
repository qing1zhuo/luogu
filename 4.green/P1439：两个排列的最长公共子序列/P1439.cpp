#include<iostream>
using namespace std;

int a[100005],b[100005];
int findt[100005];
int c[100005];
int d[100005];
int n;

int up(int,int,int);

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        findt[b[i]]=i;
    }

    //c[i]:a[i]对应的数字在b中的位置
    for(int i=1;i<=n;i++)
    {
        c[i]=findt[a[i]];
    }

    //求c的最长单调上升子序列
    int tail1=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]>d[tail1])
        {
            tail1++;
            d[tail1]=c[i];
        }
        else
        {
            int index=up(1,tail1,c[i]);
            d[index]=c[i];
        }
    }
    cout<<tail1;
    return 0;
}

int up(int left,int right,int goal)
{
    if(left==right)
    {
        return left;
    }
    int mid=(left+right)/2;
    if(d[mid]>goal)
    {
        return up(left,mid,goal);
    }
    else
    {
        return up(mid+1,right,goal);
    }
}