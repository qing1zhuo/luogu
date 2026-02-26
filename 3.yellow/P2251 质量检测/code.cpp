#include<iostream>
#include<queue>
using namespace std;
#define maxn 100005
struct node
{
    int id,A;
    bool operator<(const node& other)const{
        return A>other.A;
    }
}a[maxn];
int n,m;
priority_queue<node>pq;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].A;a[i].id=i;
        pq.push(a[i]);
    }
    for(int i=1;i<=n;i++){
        pq.push(a[i]);
        if(i>=m){
            while(pq.top().id<i-m+1)pq.pop();
            cout<<pq.top().A<<endl;
        }
    }
    return 0;
}