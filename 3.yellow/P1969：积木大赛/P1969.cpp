#include<stdio.h>
#include<algorithm>
int arr[100010]={0};

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            ans+=arr[i]-arr[i-1];
        }
    }
    printf("%d",ans);
}