#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sealine
{
    int start;
    int end;
}sealine;

int n;
sealine line[200010];
int list[200010];

int cmp_line(const void*ptr1,const void*ptr2)
{
    sealine*p1=(sealine*)ptr1;sealine*p2=(sealine*)ptr2;
    return (p1->start)-(p2->start);
}

int find(int left,int right,int goat)
{
    if(left==right)
    {
        return right;
    }
    int mid=(left+right)/2;
    if(list[mid]>=goat)
    {
        return find(left,mid,goat);
    }
    else if(list[mid]<goat)
    {
        return find(mid+1,right,goat);
    }
}

int main()
{
    memset(list,0,sizeof(list));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&line[i].start,&line[i].end);
    }

    qsort(line+1,n,sizeof(sealine),cmp_line);

    int tail=1;
    list[1]=line[1].end;
    for(int i=2;i<=n;i++)
    {
        if(line[i].end>list[tail])
        {
            tail++;
            list[tail]=line[i].end;
        }
        else
        {
            int index=find(1,tail,line[i].end);
            list[index]=line[i].end;
        }
    }    

    printf("%d",tail);

    return 0;
}