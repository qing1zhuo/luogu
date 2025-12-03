#include<iostream>
#include<cstring>
using namespace std;
int a[1000005];
int p[2005];
int n,m;
int ans1,ans2;
int num;
int main()
{
    cin>>n>>m;ans1=1,ans2=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int l=1,r=1;
    while(r<=n&&l<=r)
    {
        bool flag=false;
        while(num<m&&r<=n)
        {
            int pe=a[r];
            if(p[pe]==0)
            {
                num++;
            }
            p[pe]++;
            r++;
        }
        r--;
        if(num==m)flag=true;
        while(num==m&&l<=r)
        {
            int pe=a[l];
            p[pe]--;
            if(p[pe]==0)num--;
            l++;
        }
        l--;

        if(r-l+1<ans2-ans1+1&&flag){ans1=l,ans2=r;}
        l++,r++;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}