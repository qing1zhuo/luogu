#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct person
{
    string name;
    unsigned long long prac;
};
person mu[100005];int n1=0;
person s[100005];int n2=0;

void myswap(person& a,person& b)
{
    string curname=a.name;
    unsigned long long curprac=a.prac;

    a.name=b.name;
    a.prac=b.prac;

    b.name=curname;
    b.prac=curprac;
}
void mysort1(int l,int r)
{
    unsigned long long mid=mu[(l+r)/2].prac;
    int i=l,j=r;
    while(i<=j)
    {
        while(mu[i].prac>mid)i++;
        while(mu[j].prac<mid)j--;

        if(i<=j)
        {
            myswap(mu[i],mu[j]);
            i++,j--;
        }
    }
    if(l<j)mysort1(l,j);
	if(i<r)mysort1(i,r);
}
void mysort2(int l,int r)
{
    unsigned long long mid=s[(l+r)/2].prac;
    int i=l,j=r;
    while(i<=j)
    {
        while(s[i].prac>mid)i++;
        while(s[j].prac<mid)j--;

        if(i<=j)
        {
            myswap(s[i],s[j]);
            i++,j--;
        }
    }
    if(l<j)mysort2(l,j);
	if(i<r)mysort2(i,r);
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n+m;i++)
    {
        string name;
        char type;
        unsigned long long prac;
        cin>>name>>type>>prac;
        if(type=='H')
        {
            n1++;
            mu[n1].name=name;
            mu[n1].prac=prac;
        }
        else
        {
            n2++;
            s[n2].name=name;
            s[n2].prac=prac;
        }
    }
    mysort1(1,n1);
    mysort2(1,n2);
    cout<<mu[3].name<<endl;
    for(int i=1;i<=4;i++)
    {
        cout<<s[5+i].name<<endl;
    }
    return 0;
}