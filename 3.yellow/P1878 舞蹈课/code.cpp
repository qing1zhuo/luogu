#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
#define maxn 200005

struct node
{
    int delta;
    int l_pos,r_pos;
    bool operator<(const node&other)const{
        if(delta!=other.delta)return delta>other.delta;
        else return l_pos>other.l_pos;
    }
};
priority_queue<node>pq;

int a[maxn],l[maxn],r[maxn];
bool use[maxn]={0};
int n;string s;

queue<pair<int,int>>q;
int ans=0;

int main()
{
    cin>>n>>s;s+="H";
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[i]=i-1,r[i]=i+1;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            pq.push({abs(a[i+1]-a[i+2]),i+1,i+2});
        }
    }
    use[0]=use[n+1]=true;
    while(!pq.empty()){
        node cur=pq.top();pq.pop();
        int l_pos=cur.l_pos,r_pos=cur.r_pos;
        if(!use[l_pos]&&!use[r_pos]){
            ans++;
            q.push({l_pos,r_pos});
            use[l_pos]=true,use[r_pos]=true;

            int new_l_pos=l[l_pos],new_r_pos=r[r_pos];
            r[new_l_pos]=new_r_pos;
            l[new_r_pos]=new_l_pos;

            if(s[new_l_pos-1]!=s[new_r_pos-1]){
                pq.push({abs(a[new_l_pos]-a[new_r_pos]),new_l_pos,new_r_pos});
            }
        }
    }
    cout<<ans<<endl;
    while(!q.empty()){
        cout<<min(q.front().first,q.front().second)<<" "<<max(q.front().first,q.front().second)<<endl;
        q.pop();
    }
    return 0;
}