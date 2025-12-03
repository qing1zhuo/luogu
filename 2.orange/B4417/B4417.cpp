#include<iostream>
#include<string.h>
using namespace std;
int n;
char str[1000005];
char stack[1000005];
int top;
void test();
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        test();
    }
    return 0;
}
void test()
{
    int flag=1;//假定初始为合法
    top=0;//栈初始化
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
            top++;
            stack[top]=str[i];
        }
        else if(str[i]==')')
        {
            if(stack[top]=='(')
            {
                stack[top]='\0';
                top--;
            }
            else
            {
                flag=0;break;
            }
        }
        else if(str[i]=='}')
        {
            if(stack[top]=='{')
            {
                stack[top]='\0';
                top--;
            }
            else
            {
                flag=0;break;
            }
        }
        else if(str[i]==']')
        {
            if(stack[top]=='[')
            {
                stack[top]='\0';
                top--;
            }
            else
            {
                flag=0;break;
            }
        }
    }
    if(flag==1&&top==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}