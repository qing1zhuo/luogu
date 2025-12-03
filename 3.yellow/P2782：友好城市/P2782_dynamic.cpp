#include<stdio.h>
#include<stdlib.h>

typedef struct sealine
{
    int start;
    int end;
    int max;
}sealine;

int n;
sealine line[200010];

int cmp_line(const void*ptr1,const void*ptr2)
{
    sealine*p1=(sealine*)ptr1;sealine*p2=(sealine*)ptr2;
    return (p1->start)-(p2->start);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&line[i].start,&line[i].end);
        line[i].max=1;
    }

    qsort(line+1,n,sizeof(sealine),cmp_line);

    int ans=0;
    for(int i=n-1;i>=1;i--)
    {
        int longest=0;
        for(int j=i+1;j<=n;j++)
        {
            if(line[i].end<line[j].end&&longest<line[j].max)
            {
                longest=line[j].max;
            }
        }
        line[i].max=longest+1;
        if(ans<line[i].max)ans=line[i].max;
    }

    printf("%d",ans);

    return 0;
}