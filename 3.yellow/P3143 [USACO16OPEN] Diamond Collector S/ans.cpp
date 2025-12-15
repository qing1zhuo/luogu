#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 50005

int diamond[MAXN];
int max_len_before_r[MAXN];
int max_len_before;
int n,k;
int ans=0;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>diamond[i];
    sort(diamond+1,diamond+1+n);
    int j=2;
    for(int i=1;i<=n;i++)
    {
        while(diamond[j]<=diamond[i]+k&&j<=n)j++;
        int cur_max_len=j-i;

        if(max_len_before_r[j]<cur_max_len)max_len_before_r[j]=cur_max_len;

        if(max_len_before<max_len_before_r[i])max_len_before=max_len_before_r[i];

        int tot=max_len_before+cur_max_len;

        if(ans<tot)ans=tot;
    }

    cout<<ans;
    return 0;
}