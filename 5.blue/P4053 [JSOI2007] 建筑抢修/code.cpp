#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 150005
struct node
{
    int t1,t2;
};
bool cmp(node a,node b){
    return a.t2<b.t2;
}
node a[maxn];
int n,ans=0;
long long sum=0;

int main()
{
    cin>>n;
    priority_queue<int>pq;
    for(int i=1;i<=n;i++){
        cin>>a[i].t1>>a[i].t2;
    }
    sort(a+1,a+1+n,cmp);//按照t2升序排列
    for(int i=1;i<=n;i++){
        pq.push(a[i].t1);
        sum+=a[i].t1;
        if(sum<=a[i].t2){
            ans++;
        }
        else{
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<<ans;
    return 0;
}
