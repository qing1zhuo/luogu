#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define maxn 100010

long long a[maxn],b[maxn];
int n;
long long positive_sum,negative_sum;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
        if(b[i]>0)positive_sum+=b[i];
        else if(b[i]<0)negative_sum-=b[i];
    }
    long long operation=max(positive_sum,negative_sum);
    long long kind=abs(positive_sum-negative_sum)+1;

    cout<<operation<<endl<<kind;
    
    return 0;
}