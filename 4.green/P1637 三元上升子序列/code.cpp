
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 30005
#define maxa 100005

class TreeArray
{
private:
    int b[maxa]={0};
    int low_bit(int u){return u&(-u);}
    int max_val;
public:
    TreeArray(int m):max_val(m){}

    long long sum(int u){
        long long res=0;
        for(int i=u;i;i-=low_bit(i)){
            res+=b[i];
        }
        return res;
    }

    void add(int u,int k){
        for(int i=u;i<=max_val;i+=low_bit(i)){
            b[i]+=k;
        }
    }
};

int smaller[maxn],bigger[maxn]; 
int a[maxn],cur[maxn];

int main()
{
    int n;cin>>n;
    int max_val=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max_val=max(max_val,a[i]);
    }
    
    TreeArray ta1(max_val);
    for(int i=1;i<=n;i++){
        int cur_num=a[i];
        smaller[i]+=ta1.sum(cur_num-1);
        ta1.add(cur_num,1);
    }

    TreeArray ta2(max_val);
    for(int i=n;i>0;i--){
        int cur_num=max_val+1-a[i];
        bigger[i]+=ta2.sum(cur_num-1);
        ta2.add(cur_num,1);
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=smaller[i]*bigger[i];
    }

    cout<<ans;
    return 0;
}