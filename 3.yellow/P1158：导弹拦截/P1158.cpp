#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef unsigned long long llu;
struct system
{
    int x;
    int y;
    llu rr;
};
struct missile
{
    int id;
    llu r1;
    llu r2;
};
struct system sys[3];
struct missile mis[100005];
int num;//导弹数量
int cmp1(const void*a,const void*b)
{
    return ((missile*)a)->r1-((missile*)b)->r1;//按照每一枚导弹到sys1的距离排序
}
llu dis(int x,int y,int k)
{
    return (llu)(x-sys[k].x)*(x-sys[k].x)+(llu)(y-sys[k].y)*(y-sys[k].y);
}
int main()
{
    scanf("%d%d%d%d%d",&sys[1].x,&sys[1].y,&sys[2].x,&sys[2].y,&num);
    for(int i=1;i<=num;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mis[i].id=i;
        mis[i].r1=dis(x,y,1);
        mis[i].r2=dis(x,y,2);
    }
    qsort(mis+1,num,sizeof(missile),cmp1);
    llu minn=0x7fffffff;
    llu maxn=0;
    for(int i=num;i>=0;i--)
    {
        minn=min(minn,mis[i].r1+maxn);
        if(mis[i].r2>maxn) maxn=mis[i].r2;
    }
    printf("%llu",minn);
    return 0;
}