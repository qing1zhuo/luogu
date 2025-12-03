#include<stdio.h>
#include<math.h>
int n;
int a[3]={0};
void search(int);
int main()
{
    scanf("%d",&n);
    for(int i=4;i<=n;i+=2)
    {
        search(i);
    }
    return 0;
}

int pd(int x)
{
    int k=2;
    while(k<=sqrt(x)&&x%k!=0){k++;}
    if(k>sqrt(x))
    {
        return 1;
    }
    return 0;
}
void print(int x,int i)
{
    printf("%d=%d+%d\n",x,i,x-i);
}

void search(int x)
{
    for(int i=2;i<x-1;i++)
    {
        if(pd(i)&&pd(x-i)&&i<=(x-i))
        {
            print(x,i);
            return;
        }
    }
}