#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100010
#define ll long long

struct node{
    ll val;
    int id;
};
int n=0;
node a[maxn]={0,0},b[maxn]={0,0};
int c[maxn];
ll moo=0;

bool cmp1(node a,node b);
int binary_search(int x,int l,int r);
void test();

int main()
{   
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;a[i].id=i;
        b[i]=a[i];
    }
    sort(b+1,b+n+1,cmp1);
    for(int i=1;i<=n;i++){
        c[i]=binary_search(i,1,n);
    }

    //下面这块学完树状数组回来改
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=1;j<=i;j++){
            if(c[j]>i){
                sum++;
            }
        }
        moo=max(moo,sum);
    }
    //test();
    cout<<max(moo,1LL);
    return 0;
}

int binary_search(int x,int l,int r)//根据a的索引返回在b的索引
{
    int mid=(l+r)/2;
    int mid_val=b[mid].val,mid_id=b[mid].id;
    if(mid_val==a[x].val&&mid_id==a[x].id)return mid;
    else if(mid_val>a[x].val||(mid_val==a[x].val&&mid_id>a[x].id))return binary_search(x,l,mid);
    else if(mid_val<a[x].val||(mid_val==a[x].val&&mid_id<a[x].id))return binary_search(x,mid+1,r);
}
bool cmp1(node a,node b)
{
    if(a.val!=b.val)return a.val<b.val;
    else return a.id<b.id;
}

void test()
{
    for(int i=1;i<=n;i++)cout<<c[i]<<" ";
    //cow_sort();
}