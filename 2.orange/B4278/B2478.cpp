#include<iostream>
using namespace std;
int digit[100005];
char str[100005];
int i=0,j=0;//i for digit,j for str;
int num;
char ch;
int main()
{
    cin>>num;digit[++i]=num;
    while(cin>>ch>>num)
    {
        digit[++i]=num;
        if(ch=='*')
        {
            i--;
            digit[i]=digit[i]*digit[i+1];
        }
        else if(ch=='/')
        {
            i--;
            digit[i]=digit[i]/digit[i+1];
        }
        else if(ch=='%')
        {
            i--;
            digit[i]=(int)digit[i]%(int)digit[i+1];
        }
        else
        {
            str[++j]=ch;
        }
    }
    for(int k=1;k<=j;k++)
    {
        if(str[k]=='+')
        {
            digit[k+1]=digit[k]+digit[k+1];
        }
        else if(str[k]=='-')
        {
            digit[k+1]=digit[k]-digit[k+1];
        }
    }
    cout<<int(digit[i]);
    return 0;
}