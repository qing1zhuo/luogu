#include<iostream>
#include<algorithm>
using namespace std;
#define ull unsigned long long
ull a,b,p;
ull fast_power(ull base_num,ull exponent_num,ull mod_num)
{
    if(exponent_num==0)return 1;
    if(exponent_num%2==0){
        ull root=fast_power(base_num,exponent_num/2,mod_num);
        return (root*root)%mod_num;
    }
    if(exponent_num%2==1){
        ull root=fast_power(base_num,exponent_num/2,mod_num);
        return (((root*root)%mod_num)*base_num)%mod_num;
    }
}
int main()
{
    cin>>a>>b>>p;
    ull ans=fast_power(a,b,p);
    printf("%llu^%llu mod %llu=%llu",a,b,p,ans);
    return 0;
}