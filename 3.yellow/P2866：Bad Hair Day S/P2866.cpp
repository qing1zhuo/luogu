#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long ans=0;
    stack<int>s;
    while(n--)
    {
        int x=0;cin>>x;
        while(!s.empty()&&s.top()<=x)
        {
            s.pop();
        }
        ans+=s.size();
        s.push(x);
    }
    cout<<ans;
    return 0;
}