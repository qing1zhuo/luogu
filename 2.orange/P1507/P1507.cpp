#include<iostream>
#include<algorithm>
using namespace std;
int volumn,weight,num;
int v[55],w[55],k[55];
int dp[405][405];//前一个数据表示体积，后一个表示重量
int main()
{
    cin>>volumn>>weight>>num;
    for(int i=1;i<=num;i++)
    {
        cin>>v[i]>>w[i]>>k[i];
    }
    for(int i=1;i<=num;i++)
    {
        for(int p=volumn;p>=v[i];p--)
        {
            for(int q=weight;q>=w[i];q--)
            {
                dp[p][q]=max(dp[p][q],dp[p-v[i]][q-w[i]]+k[i]);
            }
        }
    }
    cout<<dp[volumn][weight];
    return 0;
}