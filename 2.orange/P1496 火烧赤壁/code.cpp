#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 40005
struct field
{
    int l,r;
};
field ori[MAXN/2];
int sor[MAXN],dif[MAXN],pre[MAXN];
bool cmp(int a,int b){return a<b;}

int find(int l,int r,int a)
{
    if(l==r)return l;
    int mid=(l+r)/2;
    if(sor[mid]==a)return mid;
    if(sor[mid]>a)return find(l,mid-1,a);
    if(sor[mid]<a)return find(mid+1,r,a);
}
int main()
{
    int n;cin>>n;
    int l,r;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        if(l||r)flag=false;
        ori[i].l=l,ori[i].r=r;
        sor[2*i-1]=l,sor[2*i]=r;
    }

    if(flag){cout<<0;return 0;}
    sort(sor+1,sor+1+2*n,cmp);
    int pt1=1,pt2=1;
    int num=0;//记录把数据去重后的数量
    while(pt1<=2*n)
    {
        while(sor[pt1]==sor[pt2])pt2++;
        sor[++num]=sor[pt1];
        pt1=pt2;
    }

    int sort_l,sort_r;
    for(int i=1;i<=n;i++)
    {
        l=ori[i].l,r=ori[i].r;
        sort_l=find(1,num,l),sort_r=find(1,num,r);
        dif[sort_l]++,dif[sort_r]--;
    }
    for(int i=1;i<=num;i++)
    {
        pre[i]+=dif[i]+pre[i-1];
    }

    long long ans=0;
    for(int i=1;i<=num;i++)
    {
        if(pre[i]!=0)
        {
            ans+=sor[i+1]-sor[i];
        }
    }
    //for(int i=1;i<=num;i++)cout<<pre[i]<<" ";
    //cout<<"***"<<endl;
    cout<<ans<<endl;
    return 0;
}