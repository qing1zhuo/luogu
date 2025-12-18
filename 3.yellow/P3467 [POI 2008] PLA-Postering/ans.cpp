#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
struct building
{
    long long wide,high;
};
building bu[250005];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>bu[i].wide>>bu[i].high;
    }
    long long ans=0;

    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&bu[s.top()].high>bu[i].high)
        {
            s.pop();
        }
        while(s.empty()||bu[s.top()].high!=bu[i].high)
        {
            ans++;
        }
        s.push(i);
    }
    cout<<ans;
    return 0;
}