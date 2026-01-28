#include<iostream>
#include<algorithm>
using namespace std;
#define MOD 100000000-3
#define maxn 100010

int a[maxn],b[maxn];
int c[maxn],d[maxn];
int f[maxn];
int none[maxn];
int n;
long long ans=0;

int binary_find(int x,int*dic);
void my_sort(int left,int right,int*a,int*b);
void test();

int main()
{
    cin>>n;
    //处理a数组
    for(int i=1;i<=n;i++){
        cin>>a[i];c[i]=a[i];
    }
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++){
        a[i]=binary_find(a[i],c);
    }
    //处理b数组
    for(int i=1;i<=n;i++){
        cin>>b[i];d[i]=b[i];
    }
    sort(d+1,d+1+n);
    for(int i=1;i<=n;i++){
        b[i]=binary_find(b[i],d);
    }
    //f_i表示i在b数组中为第f_i位
    for(int i=1;i<=n;i++){
        f[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        a[i]=f[a[i]];
    }
    my_sort(1,n,a,none);
    cout<<ans;
    return 0;
}

int binary_find(int x,int*dic)
{
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(dic[mid]==x)return mid;
        else if(dic[mid]>x)r=mid-1;
        else l=mid+1;
    }
    return -1;
}
void my_sort(int left,int right,int*a,int*b)
{
    if(left==right)return;
    int mid=(left+right)/2;
    my_sort(left,mid,a,b),my_sort(mid+1,right,a,b);
    int l=left,r=mid+1;
    int s=left-1;
    while(l<=mid&&r<=right){
        if(a[l]<=a[r]){
            b[++s]=a[l];
            l++;
        }
        else{
            b[++s]=a[r];
            r++;
            ans+=mid-l+1;
            ans%=MOD;
        }
    }
    while(l<=mid){
        b[++s]=a[l];
        l++;
    }
    while(r<=right){
        b[++s]=a[r];
        r++;
    }
    for(int i=left;i<=right;i++){
        a[i]=b[i];
    }
}
void test()
{
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    cout<<endl;
}