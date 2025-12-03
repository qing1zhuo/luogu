#include<iostream>
using namespace std;
int stack[55];
int top=0;

int calculate()
{
    char ch;
    int now=0;
    while((ch=getchar())!='@')
    {
        if(ch>='0'&&ch<='9')
        {
            now=now*10+ch-'0';
        }
        else if(ch=='+')
        {
            stack[top-1]=stack[top-1]+stack[top];
            stack[top]=0;
            top--;
        }
        else if(ch=='-')
        {
            stack[top-1]=stack[top-1]-stack[top];
            stack[top]=0;
            top--;
        }
        else if(ch=='/')
        {
            stack[top-1]=stack[top-1]/stack[top];
            stack[top]=0;
            top--;
        }
        else if(ch=='*')
        {
            stack[top-1]=stack[top-1]*stack[top];
            stack[top]=0;
            top--;
        }
        else if(ch=='.')
        {
            top++;
            stack[top]=now;
            now=0;
        }
    }
    return stack[1];
}
int main()
{
    int ans=calculate();
    cout<<ans;
    return 0;
}