#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
struct building
{
    long long wide,high;
    long long max_cover=0;
};
building bu[250005];
int l[250005],r[250005];
int father[250005];
int n;
bool cmp(building a,building b){return a.high<b.high;}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>bu[i].wide>>bu[i].high;
    }
    long long ans=0;

    //处理左边第一个高度小于他的
    stack<int>s1;
    for(int i=n;i>=1;i--)
    {
        while(!s1.empty()&&bu[s1.top()].high>bu[i].high)
        {
            l[s1.top()]=i;
            s1.pop();
        }
        s1.push(i);
    }
    while(!s1.empty())
    {
        l[s1.top()]=0;
        s1.pop();
    }


    //处理右边第一个高度小于它的
    stack<int>s2;
    for(int i=1;i<=n;i++)
    {
        while(!s2.empty()&&bu[s2.top()].high>bu[i].high)
        {
            r[s2.top()]=i;
            s2.pop();
        }
        s2.push(i);
    }
    while(!s2.empty())
    {
        r[s2.top()]=n+1;
        s2.pop();
    }


    for(int i=1;i<=n;i++)
    {
        if(bu[i].high>bu[i].max_cover)
        {
            int left=l[i],right=r[i];
            for(int j=left+1;j<right;j++)
            {
                bu[j].max_cover=bu[i].high;
            }
            ans++;
        }
    }

    cout<<ans;
    return 0;
}