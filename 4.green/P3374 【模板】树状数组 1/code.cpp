#include<iostream>
using namespace std;

#define maxn 500005

int sum(int x);
void add(int x,int k);
void init();

int a[maxn],pre[maxn],c[maxn],low_bit[maxn];
int n,m;
int op,x,y;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    init();
    while(m--){
        cin>>op>>x>>y;
        if(op==1){
            add(x,y);
        }
        if(op==2){
            cout<<sum(y)-sum(x-1)<<endl;
        }
    }
    return 0;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i>0;i-=low_bit[i])res+=c[i];
    return res;
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=low_bit[i])c[i]+=k;
    return;
}
void init()
{
    for(int i=1;i<=n;i++)low_bit[i]=(i&(-i));
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
        c[i]=pre[i]-pre[i-low_bit[i]];
    }
    return;
}