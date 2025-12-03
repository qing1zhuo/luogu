#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int a[2005]; int len1;
int b[2005]; int len2;
int dp[2005][3];

int find(int, int);

int main()
{
    char str[2005];
    scanf("%s", str);
    len1 = strlen(str);
    for (int i = 1; i <= len1; i++)a[i] = str[i - 1];

    scanf("%s", str);
    len2 = strlen(str);
    for (int i = 1; i <= len2; i++)b[i] = str[i - 1];

    int len = (len1 > len2) ? len1 : len2;

    for (int i = 1; i <= len1; i++)
    {
        dp[i][2] = find(dp[i - 1][2], a[i]);
        if (dp[i][2] > dp[i - 1][2])
        {
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
    }

    cout << len - dp[len1][1];
    return 0;
}

int find(int start, int goal)//查找从b[start]开始，使得b[i]==goal的最小的i
{
    if(start==0)start++;
    for (int i = start; i <= len2; i++)
    {
        if (b[i] == goal)
        {
            return i;
        }
    }
    return 0;//若没有，返回0；
}