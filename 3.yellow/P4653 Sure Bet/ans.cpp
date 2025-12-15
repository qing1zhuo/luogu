#include<iostream>
#include<algorithm>
using namespace std;
int n;
double ans;
double a[100005],b[100005];
bool cmp(double x,double y)
{
    return x>y;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    sort(a+1,a+n+1,cmp),sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    int i=1,j=1;
    while(i<=n&&j<=n)
    {
        if(a[i]<b[j])
        {
            ans=max(ans,a[i]-i-j);
            i++;
        }
        else
        {
            ans=max(ans,b[j]-i-j);
            j++;
        }
    }
    printf("%.4lf\n",ans);
    return 0;
}