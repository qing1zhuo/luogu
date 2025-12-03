#include<iostream>
#define m 10000
using namespace std;
long long stack[100010];
int top = 0;
int main()
{
    int ans=0;
    char ch; 
    int a, b;
    cin >> a; stack[++top] = a%m;
    while (cin >> ch >> b)
    {
        b%=m;
        if(ch=='*')
        {
            stack[top]=(stack[top]*b)%m;
        }
        else
        {
            top++;
            stack[top]=b;
        }
    }
    for(int i=top;i>=1;i--)
    {
        ans+=stack[i];
    }
    cout<<ans%m;
    return 0;
}