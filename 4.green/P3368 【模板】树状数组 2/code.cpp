#include<iostream>
using namespace std;
#define maxn 500005
int a[maxn],c[maxn],low_bit[maxn];
int n,m;
int op,x,y,k;

void init();
void work();
void add(int x,int k);
int sum(int x);

int main()
{
    cin>>n>>m;
    init();
    work();
    return 0;
}

void init()
{
    for(int i=1;i<=n;i++){
        cin>>a[i];
        low_bit[i]=(i&(-i));
    }
    for(int i=1;i<=n;i++){
        c[i]=a[i]-a[i-low_bit[i]];
    }
    return;
}
void work()
{
    while(m--){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            add(x,k),add(y+1,-k);
        }
        if(op==2){
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=low_bit[i]){
        c[i]+=k;
    }
    return;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i>0;i-=low_bit[i]){
        res+=c[i];
    }
    return res;
}