#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 510

long long presum[MAXN][MAXN];
int r,c,a,b;
int ans=0;

bool check(int x)
{
    int cnt_row=0,last_row=0;
    for(int i=1;i<=r;i++){
        int cnt_col=0,last_col=0;
        for(int j=1;j<=c;j++){
            if(presum[i][j]-presum[last_row][j]-presum[i][last_col]+presum[last_row][last_col]>=x){
                cnt_col++;
                last_col=j;
            }
        }
        if(cnt_col>=b){
            cnt_row++;
            last_row=i;
        }
    }
    return cnt_row>=a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c>>a>>b;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int val;
            cin>>val;
            presum[i][j]=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+val;
        }
    }

    int left=0,right=presum[r][c]/(a*b);

    while(left<=right){
        int mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}