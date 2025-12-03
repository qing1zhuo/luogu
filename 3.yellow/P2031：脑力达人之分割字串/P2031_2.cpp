#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char s[303];
char dic[505][303];
int n;
int ans;
int dp[303];
int cmp(const char*ptr1,const char*ptr2);
int main()
{
    scanf("%s",s); 
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%s",dic[i]);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<=n;j++){
            if(s[i]==dic[j][0]){
                if(cmp(&s[i],dic[j])){//若dic[j]在s的从i开始的后续字符串中
                    for(int k=strlen(dic[j])+i-1;k<=len-1;k++){
                        if(i==0)dp[k]=max(dp[k],1);
                        else dp[k]=max(dp[k],dp[i-1]+1);
                    }
                }
            }
        }
    }
    cout<<dp[len-1];
    return 0;
}
int cmp(const char*ptr1,const char*ptr2){
    int len1=strlen(ptr1);
    int len2=strlen(ptr2);
    if(len1<len2)return 0;
    for(int i=0;i<len2;i++)
    {
        if(*(ptr1+i)!=*(ptr2+i))return 0;
    }
    return 1;
}

//动态规划做法