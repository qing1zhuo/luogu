#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define maxn 2005
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
bool KMP_find(string&str1,string&str2,vector<int>&next)//主串，模式串
{
    int n=str1.size(),m=str2.size();
    if(m==0||n<m)return false;
    int i=0,j=0;

    while(i<n){
        if(j==-1||str1[i]==str2[j]){
            i++,j++;
        }
        else{
            j=next[j];
        }

        if(j==m&&i==j){
            return true;
        }
    }
    return false;
}
bool cmp(string a,string b){return a.size()<b.size();}
string a[maxn];
vector<int>b[maxn];
int c[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);

    for(int i=1;i<=n;i++){
        b[i].resize(80);
        get_next(a[i],b[i]);
    }

    for(int i=1;i<=n;i++)c[i]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(KMP_find(a[i],a[j],b[j])){
                c[i]=max(c[i],c[j]+1);
            }
        }
    }

    int ans=-1;
    for(int i=1;i<=n;i++)ans=max(ans,c[i]);

    cout<<ans;
}