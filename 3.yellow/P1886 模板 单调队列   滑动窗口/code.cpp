#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int SIZE=1000005;
int n,k;
int a[SIZE];
int min_ans[SIZE],max_ans[SIZE];
int min_pt=0,max_pt=0;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];

    deque<int>minn;deque<int>maxn;

    for(int i=1;i<=n;i++)
    {
        while(!minn.empty()&&a[minn.back()]>a[i])
        {
            minn.pop_back();
        }
        minn.push_back(i);

        while(minn.front()<i-k+1)minn.pop_front();

        if(i>=k)min_ans[++min_pt]=minn.front();
    }

    for(int i=1;i<=n;i++)
    {
        while(!maxn.empty()&&a[maxn.back()]<a[i])
        {
            maxn.pop_back();
        }
        maxn.push_back(i);

        while(maxn.front()<i-k+1)maxn.pop_front();

        if(i>=k)max_ans[++max_pt]=maxn.front();
    }

    for(int i=1;i<=min_pt;i++)cout<<a[min_ans[i]]<<" ";
    cout<<endl;
    for(int i=1;i<=max_pt;i++)cout<<a[max_ans[i]]<<" ";
    return 0;
}