#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define maxn 1000005

void get_next(string&s,vector<int>&next)
{
    int n=s.size();
    int i=0,j=-1;
    next[i]=j;
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

int main()
{
    int L;cin>>L;
    string str;cin>>str;
    vector<int>next(maxn);
    get_next(str,next);

    cout<<L-next[L];
    return 0;
}