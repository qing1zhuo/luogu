#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 2*10005
int n,m;
struct Node{unsigned long long x,y;}node[maxn];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>node[i].x>>node[i].y;
    }
    return 0;
}