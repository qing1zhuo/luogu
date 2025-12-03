#include<stdio.h>
#include<string.h>
int a[5010][4];
int n;
int main()
{
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i][1]);
        a[i][2]=1;a[i][3]=0;
    }
    for(int i=n-1;i>=1;i--)
    {
        int longest=0;int index=0;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][1]<a[j][1]&&longest<a[j][2])
            {
                longest=a[j][2];
                index=j;
            }
            a[i][2]=longest+1;
            a[i][3]=index;
        }
    }
    int ans=0;int k=0;
    for(int i=1;i<=n;i++)
    {
        if(ans<a[i][2])
        {
            ans=a[i][2];
            k=i;
        }
    }
    printf("%d\n",ans);
    // while(k)
    // {
    //     printf("%d ",a[k][1]);
    //     k=a[k][3];
    // }
    
    return 0;
}