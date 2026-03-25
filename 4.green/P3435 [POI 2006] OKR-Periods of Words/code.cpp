#include<iostream>
#include<string>
#include<vector>
using namespace std;
int k;
string str;
vector<int>next_short;//最短共同前后缀
void init_next(vector<int>&next_short,string&str)
{
    int i=0,j=-1;
    vector<int>next_long;
    next_long.push_back(j);
    while(i<k){
        if(j==-1||str[i]==str[j]){
            i++,j++;
            next_long.push_back(j);
        }
        else{
            j=next_long[j];
        }
    }
    next_short.resize(k+1);
    next_short[0]=-1;
    for(int i=1;i<=k;i++){
        int l=next_long[i];
        while(l>0&&next_long[l]>0){
            l=next_long[l];
        }
        next_short[i]=l;
        next_long[i]=next_short[i];
    }
}
int find_time(int k)
{
    int max_len=k-next_short[k];
    if(max_len==k)return 0;
    else return max_len;
}
int main()
{
    long long ans=0;
    cin>>k>>str;
    init_next(next_short,str);
    for(int i=1;i<=k;i++){
        ans+=find_time(i);
    }
    cout<<ans;
    return 0;
}