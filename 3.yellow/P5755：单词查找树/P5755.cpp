#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s[8001];
string cur;
int n=0;
int sum=0;

void print();

int main()
{

    while(cin>>s[++n]);n--;
    //for(int i=1;i<=8;i++)cin>>s[i];n=8;

    sort(s+1,s+n+1);
    //print();

    sum=s[1].length();
    for(int i=2;i<=n;i++)
    {
        int j=0;
        while(s[i][j]==s[i-1][j]&&j<s[i-1].length())
        {
            j++;
        }
        sum+=s[i].length()-j;
    }
    cout<<sum+1;
    return 0;
}

void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%s\n",s[i].c_str());
    }
}