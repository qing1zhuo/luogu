#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
#define maxn 300005
struct Node
{
    int id,a;
    vector<int>next;
}node[maxn];
bool cmp(Node x,Node y){return x.a<y.a;}
int n,m;
vector<int>ans;
int main()
{
    cin>>n>>m;
    return 0;
}