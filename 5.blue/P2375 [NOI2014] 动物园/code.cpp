#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MOD 1000000007

void work();
void init_next(string&str,int len,vector<int>&next,vector<int>&cnt);
void init_num(string&str,int len,vector<int>&next,vector<int>&num,vector<int>&cnt);

int main()
{
    int T;cin>>T;
    while(T--){
        work();
    }
}

void work()
{
    string str;cin>>str;
    int len=str.size();
    vector<int>next(len+5);
    vector<int>num(len+5);
    vector<int>cnt(len+5);

    init_next(str,len,next,cnt);
    init_num(str,len,next,num,cnt);

    long long ans=1;
    for(int i=1;i<=len;i++){
        ans=(ans*(num[i]+1)%MOD)%MOD;
    }
    ans%=MOD;
    cout<<ans<<endl;
}

void init_next(string&str,int len,vector<int>&next,vector<int>&cnt)
{
    int i=0,j=-1;
    next[0]=j;
    while(i<len){
        if(j==-1||str[i]==str[j]){
            i++,j++;
            next[i]=j;
            cnt[i]=cnt[j]+1;
        }
        else{
            j=next[j];
        }
    }
}
void init_num(string&str,int len,vector<int>&next,vector<int>&num,vector<int>&cnt)
{
    int j=0;
    for(int i=1;i<=len;i++){
        while(j!=0&&str[i-1]!=str[j]){
            j=next[j];
        }
        if(str[i-1]==str[j])j++;
        while(2*j>i)j=next[j];
        num[i]=cnt[j];
    }

}