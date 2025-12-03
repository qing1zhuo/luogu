#include<stdio.h>
int missile[100010][4];//1导弹本身高度，2从此开始的单调下降序列最长长度，3所在单调下降序列的后继导弹编号
int n=0;
int system[100010];
int k=1;

int main()
{
    /*存数据*/
    while(~scanf("%d",&missile[++n][1]))
    {
        missile[n][2]=1;missile[n][3]=0;
    }
    n--;

    /*标记最长不上升序列*/
    for(int i=n-1;i>=1;i--)
    {
        int l=0,k=0;
        for(int j=i+1;j<=n;j++)
        {
            if(missile[j][1]<=missile[i][1]&&missile[j][2]>l)
            {
                l=missile[j][2];
                k=j;
            }
        }
        if(l)
        {
            missile[i][2]=l+1;
            missile[i][3]=k;
        }
    }
    /*寻找最长不上升序列的起点*/
    int longest=0;
    for(int i=1;i<=n;i++)
    {
        if(missile[i][2]>longest)
        {
            longest=missile[i][2];
        }
    }
    printf("%d\n",longest);

    system[1]=missile[1][1];//第一套系统拦截第一枚导弹
    k=1;//现有1个系统
    for(int i=2;i<=n;i++)
    {
        int p=0;//能拦截这枚的系统且当前拦截高度最低的系统编号
        for(int j=1;j<=k;j++)
        {
            if(system[j]>=missile[i][1])
            {
                if(p==0)
                {
                    p=j;
                }
                else if(system[j]<system[p])
                {
                    p=j;
                }
            }
        }
        if(p==0)
        {
            k++;
            system[k]=missile[i][1];
        }
        else
        {
            system[p]=missile[i][1];
        }
    }
    printf("%d",k);
    return 0;
}