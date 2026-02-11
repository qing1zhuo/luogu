#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005

int n,m;
struct PATH{int id,cost,num;}a[maxn];
bool cmp1(PATH x,PATH y){return x.cost<y.cost;}
struct CAR{int id,ct;}b[maxn];
bool cmp2(CAR x,CAR y){return x.ct>y.ct;}
unsigned long long ans=0;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cost;
        a[i].id=i;a[i].num=0;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].ct;
        b[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+m,cmp2);

    int pt=1;
    for(int i=1;i<=m;i++)
    {
        if(a[pt].num+1<=b[i].ct)
        {

            a[pt].num++;
            ans+=a[pt].cost;
        }
        else
        {
            pt++;
            if(pt>n){
                cout<<-1;
                return 0;
            }
            a[pt].num++;
            ans+=a[pt].cost;
        }
    }
    cout<<ans;
    return 0;
}