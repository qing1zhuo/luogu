#include<stdio.h>
#include<stdlib.h>

int m,n;
typedef struct task
{
    int ddl;
    int punish;
    int isok;
}task;
task tas[1510]={0};
task* re[1510]={0};

int cmp_task(const void*,const void*);
void replace(int,int);

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&(tas[i].ddl));
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&(tas[i].punish));
        tas[i].isok=0;
    }

    qsort(tas+1,n,sizeof(task),cmp_task);

    for(int i=1;i<=n;i++)
    {
        int index=tas[i].ddl;
        replace(index,i);
    }

    int time=1;
    for(int i=1;i<=n;i++)
    {
        if(re[i]->ddl>=time)
        {
            re[i]->isok=1;
            time++;
        }
        else
        {
            m-=re[i]->punish;
        }
    }
    printf("%d",m);
    return 0;
}

int cmp_task(const void*ptr1,const void*ptr2)
{
    task*p1=(task*)ptr1;
    task*p2=(task*)ptr2;
    if(p1->punish>p2->punish)
    {
        return -1;
    }
    else if(p1->punish==p2->punish)
    {
        return 0;
    }
    else if(p1->punish<p2->punish)
    {
        return 1;
    }
}

void replace(int index,int i)
{
    if(index==0)
    {
        replace(n,i);
    }
    else if(re[index]==0)
    {
        re[index]=&tas[i];
    }
    else
    {
        replace(index-1,i);
    }
}