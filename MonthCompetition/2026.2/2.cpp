#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
#define MOD (1000000000+7)
char t[1100005];
int s[1100005];
int q;
int len;
int k;char c;

int init(char* t,int* s);
void solve(int* s,int len);

int main()
{
    cin>>t;
    len=init(t,s);
    solve(s,len);
    cin>>q;
    while(q--){
        cin>>k>>c;
        if((char)s[2*k-1]=='*'&&c!='*'){
            s[2*k-1]=c;
            solve(s,len);
        }
    }
    return 0;
}
int init(char* t,int* s)
{
    int pt=-1;
    int slow=0,fast=0;
    int len=strlen(t);
    while(fast<len){
        while(t[fast]<='9'&&t[fast]>='0'){
            fast++;
        }
        int cur=0;
        for(int i=slow;i<fast;i++){
            cur=cur*10+(t[i]-'0');
        }
        s[++pt]=cur;
        s[++pt]=t[fast];
        fast++;slow=fast;
    }
    return pt;
}

void solve(int* s,int len)
{
    queue<long long>num;
    queue<char>ch;
    for(int i=0;i<len;i++){
        if(i%2==0){
            num.push(s[i]);
        }
        else{
            if((char)s[i]=='*'){
                num.back()=(num.back()*(s[i+1]))%MOD;
                i++;
            }
            else{
                ch.push(s[i]);
            }
        }
    }
    while(!ch.empty())
    {
        char cur=ch.front();ch.pop();
        if(cur=='+'){
            int cn=num.front();
            num.pop();
            num.front()=(num.front()+cn)%MOD;
        }
        else{
            int cn=num.front();
            num.pop();
            num.front()=(cn-num.front())%MOD;
        }
    }
    long long ans=num.front();
    cout<<(ans%MOD+MOD)%MOD<<endl;
}