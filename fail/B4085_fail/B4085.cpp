#include<stdio.h>
#include<stdlib.h>
typedef struct group
{
    char name[15];//队伍名字
    char name_pig[3][15];
    bool iswin=false;//是否有资格
}group;

int main()
{
    int n,m,t,k;//n队伍数量，m场比赛，t比赛容量，k晋级名额
    scanf("%d%d%d%d",&n,&m,&t,&k);
    int c=0;//最终可晋级的数量

    return 0;
}