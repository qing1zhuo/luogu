#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int person[1510]={0};//表示每位居民是否感染，否为0，是为1
int start[1510]={2000};//存储初始病人编号，
int m,n;//总人数，初始病人数量
unsigned long long k;//第k天

void affect(int*,int,unsigned long long);
void print(int,int*);

int main()
{
    int* cur=(int*)malloc(1510*sizeof(int));//存储当前病人编号
    scanf("%llu%d%d",&k,&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&start[i]);
        cur[i]=start[i];
        person[cur[i]]=1;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",cur[i]);
        }
    }
    else
    {
        affect(cur,n,k);
    }
    return 0;
}

void affect(int*cur,int num_now,unsigned long long day)
{
    day--;
    int num=0;//当前感染人数
    int* new_cur=(int*)malloc(1510*4);//中转站
    for(int i=1;i<=num_now;i++)//对每一个当前感染者
    {
        person[cur[i]]=0;
        for(int j=1;j<=n;j++)
        {
            int t=(cur[i]*start[j])%m;
            if(person[t]==0)
            {
                num++;
                person[t]=1;
                new_cur[num]=t;
            }
        }
    }
    free(cur);
    if(day==1)
    {
        print(num,new_cur);
    }
    else
    {
        affect(new_cur,num,day);
    }
}

void print(int num,int*cur)
{
    sort(cur+1,cur+1+num);
    for(int i=1;i<=num;i++)
    {
        printf("%d ",cur[i]);
    }
}
