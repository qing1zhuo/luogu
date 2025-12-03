#include<stdio.h>
int missile[100010];
int n=0;
int list[100010];
int system[100010];

int find1(int left,int right,int goat)
{
    if(left==right)
    {
        return right;
    }
    int mid=(right+left)/2;
    if(list[mid]>=goat)
    {
        return find1(mid+1,right,goat);
    }
    else if(list[mid]<goat)
    {
        return find1(left,mid,goat);
    }
}

int find2(int left,int right,int goat)
{
    if(left==right)
    {
        return right;
    }
    int mid=(left+right)/2;
    if(system[mid]<goat)
    {
        return find2(mid+1,right,goat);
    }
    else if(system[mid]>=goat)
    {
        return find2(left,mid,goat);
    }
}

int main()
{
    while(~scanf("%d",&missile[++n]));
    n--;

    list[1]=missile[1];
    int ans1=1;
    for(int i=2;i<=n;i++)
    {
        if(missile[i]<=list[ans1])
        {
            ans1++;
            list[ans1]=missile[i];
        }
        else
        {
            int index=find1(1,ans1,missile[i]);
            list[index]=missile[i];
        }
    }
    int ans2=1;
    system[1]=missile[1];
    for(int i=2;i<=n;i++)
    {
        if(missile[i]>system[ans2])
        {
            ans2++;
            system[ans2]=missile[i];
        }
        else
        {
            int index=find2(1,ans2,missile[i]);
            system[index]=missile[i];
        }
    }
    printf("%d\n%d",ans1,ans2);
    return 0;
}