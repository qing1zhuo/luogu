#include<iostream>
using namespace std;
#define ll long long
#define maxn 500010
int n;
ll ans=0;
ll a[maxn],b[maxn];

void my_sort(int left,int right)
{
    if(left==right)return;
    int mid=(left+right)/2;
    my_sort(left,mid),my_sort(mid+1,right);
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
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    my_sort(1,n);
    cout<<ans;
    return 0;
}