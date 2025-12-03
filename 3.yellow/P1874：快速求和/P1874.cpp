#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
char str[45];
int arr[45];
ull num[45][45];//num[i][j]表示从i到j的数字组成的数
int len;
int goal;
int dp[45][100005];//dp[i][j]表示前i个数字组成j所需的最少部分数
bool z=false;
int main()
{
    scanf("%s",str);
    int len0=strlen(str);
    for(int i=1;i<=len0;i++)
    {
        if(str[i-1]!='0')z=true;
        if(z)arr[++len]=str[i-1]-'0';
    }
    scanf("%d",&goal);
    for(int i=1;i<=len;i++)
    {
        num[i][i]=arr[i];
        for(int j=i+1;j<=i+11&&j<=len;j++)
            num[i][j]=num[i][j-1]*10+arr[j];
    }

    for(int i=0;i<=len;i++){
        for(int j=0;j<=goal;j++)
            dp[i][j]=0x7fffffff-1;
    }
    dp[0][0]=0;

    for(int i=1;i<=len;i++){
        for(int k=1;k<=11;k++){
            if(i>=k)
            {
                ull val=num[i-k+1][i];
                for(ull j=val;j<=goal;j++){
                    dp[i][j]=min(dp[i][j],dp[i-k][j-val]+1);
                }
            }
        }
    }

    if(dp[len][goal] > len) cout<<-1;  // 若最少部分数超过最大可能（tot个数字最多分tot部分），则不可达
    else cout<<dp[len][goal] - 1;  // 加号数 = 部分数 - 1
    return 0;
}