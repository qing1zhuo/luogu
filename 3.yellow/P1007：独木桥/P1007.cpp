#include<iostream>
#include<algorithm>
using namespace std;

int a[5005];

int main()
{
    int l,n;cin>>l>>n;
    int maxn=0,minn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];

        int max_n=max(a[i],l-a[i]+1);
        int min_n=min(a[i],l-a[i]+1);

        maxn=max(maxn,max_n);
        minn=max(minn,min_n);
    }
    cout<<minn<<" "<<maxn;
    return 0;
}