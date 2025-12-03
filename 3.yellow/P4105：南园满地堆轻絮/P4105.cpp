#include<stdio.h>
typedef long long llint;
int n;
llint sa,sb,sc,sd;
llint a[5000010]={0};
llint b[5000010]={0};
llint mod=0;

llint divide(llint,llint);
bool check(llint);
llint func(llint);
void print();

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&sa,&sb,&sc,&sd,&a[1],&mod);
    llint right=a[1];llint left=0;
    for(int i=2;i<=n;i++)
    {
        a[i]=(func(a[i-1])+func(a[i-2])+mod)%mod;
        right=(right>a[i])?right:a[i];//right为a数列最大值
    }
    llint ans=divide(left,right);

    printf("%lld\n",ans);
    //print();
    return 0;
}

llint divide(llint left,llint right)
{
    if(left==right)
    {
        return left;
    }
    llint mid=(left+right)/2ll;
    if(check(mid))
    {
        return divide(left,mid);
    }
    else
    {
        return divide(mid+1,right);
    }
}

bool check(llint x)
{
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    b[1]=(0ll>(b[1]-x))?0ll:b[1]-x;
    for(int i=2;i<=n;i++)
    {
        b[i]=(b[i-1]>(b[i]-x))?b[i-1]:b[i]-x;
        if(a[i]-b[i]>x||b[i]-a[i]>x)return false;
    }
    return true;
}
llint func(llint x)
{
    return ((x * x % mod * x % mod * sa % mod) + (x * x % mod * sb % mod) + (x * sc % mod) + sd) % mod;
}

void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%u ",a[i]);
    }
    printf("\n");
}