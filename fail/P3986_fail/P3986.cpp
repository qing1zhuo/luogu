#include<stdio.h>
int arr[1000000010]={0};
int main()
{
    long long ans=0;
    long long k;scanf("%lld",&k);
    for(long long a=1;a<k;a++)
    {
        for(long long b=1;b<k;b++)
        {
            arr[0]=a;arr[1]=b;
            int count=2;
            while(arr[count-1]+arr[count-2]<k)
            {
                arr[count]=arr[count-1]+arr[count-2];
                count++;
            }
            if(arr[count-1]+arr[count-2]==k) ans++;
        }
    }
    printf("%lld",ans%1000000007);
    return 0;
}
