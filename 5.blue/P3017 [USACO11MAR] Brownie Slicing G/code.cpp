#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 510

int cake[MAXN][MAXN];
long long presum[MAXN][MAXN];
int r,c,a,b;
int ans=-1;
bool check(int x);
int main()
{
    cin>>r>>c>>a>>b;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>cake[i][j];
            presum[i][j]+=cake[i][j]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
        }
    }

    int left=0,right=presum[r][c]/(a*b);

    while(left<=right){
        int mid=(left+right)/2;
        if(check(mid)){
            if(ans<mid)ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}

bool check(int x)
{
    int tmp_row=0,last_row=0;
    for(int i=1;i<=r;i++){
        int tmp_col=0,last_col=0;
        for(int j=1;j<=c;j++){
            if(presum[i][j]-presum[last_row][j]-presum[i][last_col]+presum[last_row][last_col]>=x){
                tmp_col++;
                last_col=j;
            }
        }
        if(tmp_col>=b){
            tmp_row++;last_row=i;
        }
    }
    if(tmp_row<a)return false;
    else return true;
}