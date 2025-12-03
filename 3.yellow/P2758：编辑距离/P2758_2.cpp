#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int a[2005]; int len1;
int b[2005]; int len2;
int dp[2005][2005];//dp[i][j]:a的前i位变为b的前j位的最少步数

int mini(int,int,int);

int main()
{
    char str[2005];
    scanf("%s", str);
    len1 = strlen(str);
    for (int i = 1; i <= len1; i++)a[i] = str[i - 1];

    scanf("%s", str);
    len2 = strlen(str);
    for (int i = 1; i <= len2; i++)b[i] = str[i - 1];

    for(int i=1;i<=len1;i++)dp[i][0]=i;//将a的前i个变为b的前0个，要操作i次

    for(int i=1;i<=len2;i++)dp[0][i]=i;//将a的前0个变为b的前i个，要操作i次

    for (int i = 1; i <= len1; i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1];
                //若相等，则无需增加步数
            }
            else{
                dp[i][j]=mini(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
                //若不等，从a加一个元素、a删一个元素，a变一个元素中选一个最小方案
            }
        }
    }

    cout << dp[len1][len2];
    return 0;
}

int mini(int a,int b,int c)
{
    return (a>b)?(b>c?c:b):(a>c?c:a);
}