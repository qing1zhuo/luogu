#include<stdio.h>
int hole[100010]={0};
int n;
int sum=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&hole[i]);
        int t=hole[i]-hole[i-1];
        if(t>0)
        {
            sum+=t;
        }
    }
    printf("%d",sum);
    return 0;
}