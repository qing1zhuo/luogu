#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//     int a[510]={0};
//     int n,r,s=0;
//     scanf("%d%d",&n,&r);
//     for(int i=1;i<=n;i++)
//     {
//        scanf("%d",&a[i]);
//     }
//     sort(a+1,a+n+1);
//     for(int i=1;i<=n;i++)
//     {
//         if(i>r)
//         {
//             a[i]=a[i]+a[i-r];
//         }
//         s+=a[i];
//     }
//     printf("%d",s);
//     return 0;
// }


typedef struct person
{
    int id;
    int time;
}person;
int cmp_person(const void*a,const void*b)
{
    person *x=(person*)a;
    person *y=(person*)b;
    if(x->time!=y->time)
        return x->time-y->time;
    else
        return x->id-y->id;
}
int main()
{
    person a[1001]={0};
    int n;double sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
        scanf("%d",&a[i].time);
    }
    qsort(a+1,n,sizeof(person),cmp_person);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i].id);
        a[i].time+=a[i-1].time;
        sum+=a[i-1].time;
    }
    printf("\n%.2f",sum/n);
    return 0;
}