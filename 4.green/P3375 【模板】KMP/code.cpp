#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define maxn 1000005


void get_next(string&s,vector<int>&next)
{
    int n=s.size();
    int i=0,j=-1;
    next[0]=-1;
    while(i<n){
        if(j==-1||s[i]==s[j]){
            i++,j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}
void KMP_find(string&str1,string&str2,vector<int>&next,vector<int>&ans)//主串，模式串
{
    int n=str1.size(),m=str2.size();
    if(m==0||n<m)return;
    int i=0,j=0;

    while(i<n){
        if(j==-1||str1[i]==str2[j]){
            i++,j++;
        }
        else{
            j=next[j];
        }

        if(j==m){
            ans.push_back(i-j);
            j=next[j];
        }
    }
}
int main()
{
    string str1,str2;
    vector<int>next(maxn);
    vector<int>ans;
    cin>>str1>>str2;

    get_next(str2,next);
    KMP_find(str1,str2,next,ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<endl;
    }
    for(int i=1;i<=str2.size();i++){
        cout<<next[i]<<" ";
    }
    return 0;
}
