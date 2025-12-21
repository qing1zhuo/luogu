#include<iostream>
#include<algorithm>
using namespace std;
#define MaxNum 200005
namespace me
{
    struct Ore
    {
        int w,v;
    };
    struct Interval
    {
        int l,r;
    };
    Ore ore[MaxNum];Interval inter[MaxNum]; 
    unsigned long long pre1[MaxNum],pre2[MaxNum];
    int n,m;
    unsigned long long min_delta=1e18,s;
    int min_weight=1,max_weight;
}using namespace me;

void read()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>ore[i].w>>ore[i].v;
        max_weight=max(max_weight,ore[i].w);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>inter[i].l>>inter[i].r;
    }
}

unsigned long long interval_sum(int l,int r)
{
    return (pre1[r]-pre1[l-1])*(pre2[r]-pre2[l-1]);
}

void init_pre(int W)
{
    for(int i=1;i<=n;i++)
    {
        pre1[i]=pre1[i-1]+(ore[i].w>=W);
        pre2[i]=pre2[i-1]+(ore[i].w>=W)*ore[i].v;
    }
}

int find_W(int min_W,int max_W)
{
    int mid_W=(min_W+max_W)/2;
    init_pre(mid_W);
    unsigned long long sum=0;
    for(int i=1;i<=m;i++)
    {
        int left=inter[i].l,right=inter[i].r;
        sum+=interval_sum(left,right);
    }

    if(sum>s)
    {
        min_delta=min(min_delta,sum-s);
        if(min_W!=max_W)return find_W(mid_W+1,max_W);
        else return min_W;
    }
    else if(sum<s)
    {
        min_delta=min(min_delta,s-sum);
        if(min_W!=max_W)return find_W(min_W,mid_W);
        else return min_W;
    }
    else
    {
        min_delta=0;
        return mid_W;
    }
}

int main()
{
    read();
    int WW=find_W(min_weight,max_weight);
    cout<<min_delta<<endl;
    return 0;
}