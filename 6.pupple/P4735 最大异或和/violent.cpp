#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 300005

vector<int>a,prexor;
int n,m;

int main()
{
    cin>>n>>m;
    a.push_back(0);prexor.push_back(0);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back(x);
        prexor.push_back(x^prexor.back());
    }
    for(int i=1;i<=m;i++){
        char op;cin>>op;
        if(op=='A'){
            int x;cin>>x;
            a.push_back(x);
            prexor.push_back(x^prexor.back());
        }
        else{
            int l,r;cin>>l>>r;
            int x;cin>>x;
            int maxa=-1e9;
            for(int j=l;j<=r;j++){
                maxa=max(maxa,x^prexor.back()^prexor[j-1]);
            }
            cout<<maxa<<endl;
        }
    }
    return 0;
}