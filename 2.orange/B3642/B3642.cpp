#include<iostream>
using namespace std;
typedef struct tree
{
    int data;
    int left;
    int right;
}tree;
tree t[1000005];
int n;

void find1(int);
void find2(int);
void find3(int);

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;cin>>l>>r;
        t[i].data=i;
        t[i].left=l;
        t[i].right=r;
    }
    find1(1);cout<<endl;
    find2(1);cout<<endl;
    find3(1);cout<<endl;
    return 0;
}

void find1(int k)
{
    if(t[k].data)
    {
        cout<<t[k].data<<" ";
        find1(t[k].left);
        find1(t[k].right);
    }
}
void find2(int k)
{
    if(t[k].data)
    {
        find2(t[k].left);
        cout<<t[k].data<<" ";
        find2(t[k].right);
    }
}
void find3(int k)
{
    if(t[k].data)
    {
        find3(t[k].left);
        find3(t[k].right);
        cout<<t[k].data<<" ";
    }
}