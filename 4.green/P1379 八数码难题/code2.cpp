/*
双向bfs
*/

#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define ll long long

int start,ed=123804765;
int a[10];
map<int,ll>rec[2];//0表示起点方向，1表示终点方向，first表示状态，second表示步数
queue<pair<int,int>>Q;//first表示状态，second表示方向

int change(int x,int op)//1向上，2向下，3向左，4向右
{
    int p;
    for(int i=9;i>0;i--){
        a[i]=x%10;
        x/=10;
        if(a[i]==0)p=i;
    }

    if(op==1){
        if(p<=3)return -1;
        swap(a[p],a[p-3]);
    }
    else if(op==2){
        if(p>=7)return -1;
        swap(a[p],a[p+3]);
    }
    else if(op==3){
        if(p%3==1)return -1;
        swap(a[p],a[p-1]);
    }
    else if(op==4){
        if(p%3==0)return -1;
        swap(a[p],a[p+1]);
    }
    int res=0;
    for(int i=1;i<=9;i++){
        res=res*10+a[i];
    }
    return res;
}

void check(int x,pair<int,int>cur_direct)
{
    int status=cur_direct.first;
    int direct=cur_direct.second;
    int oppsite=direct^1;
    if(x!=-1){//若该状态可以抵达
        //若反向存在该状态
        if(rec[oppsite].count(x)){
            cout<<rec[direct][status]+rec[oppsite][x]+1;
            exit(0);
        }
        //若反向不存在该状态
        else{
            rec[direct][x]=rec[direct][status]+1;
            Q.push({x,direct});
        }
    }
}
int main()
{
    cin>>start;
    if(start==ed){
        cout<<0;
        return 0;
    }
    Q.push({start,0});
    Q.push({ed,1});
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        int x=0;
        x=change(cur.first,1);
        check(x,cur);
        x=change(cur.first,2);
        check(x,cur);
        x=change(cur.first,3);
        check(x,cur);
        x=change(cur.first,4);
        check(x,cur);
    }
    return 0;
}