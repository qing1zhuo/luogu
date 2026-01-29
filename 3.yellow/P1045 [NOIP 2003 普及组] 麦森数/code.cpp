#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 3100010
int p;
int a[maxn];
int alen;
int HighPrecisionMultiple(int*a,int len1,int* b,int len2)
{
    int c[1010]={0};int now=0;
    int res=0;
    for(int i=1;i<=min(500,len2);i++){
        for(int j=1;j<=min(500,len1);j++){
            now=i+j-1;
            c[now]+=b[i]*a[j];
            c[now+1]+=c[now]/10;
            c[now]%=10;
        }
    }
    if(c[len1+len2])res=len2+len1;
    else res=len2+len1-1;
    for(int i=1;i<=res;i++){
        a[i]=c[i];
    }
    return min(500,res);
}
void FastPower(int p)
{
    if(p==0)return;
    if(p%2==0){
        FastPower(p/2);
        alen=HighPrecisionMultiple(a,alen,a,alen);
        return;
    }
    if(p%2==1){
        FastPower(p/2);
        alen=HighPrecisionMultiple(a,alen,a,alen);
        int b[2]={0,2};
        alen=HighPrecisionMultiple(a,alen,b,1);
        return;
    }

}
int main()
{
    cin>>p;
    cout<<int(p*log10(2))+1<<endl;

    a[1]=1,alen=1;
    FastPower(p);
    a[1]--;
    int num=0;
    if(alen<500){
        for(int i=1;i<=500-alen;i++){
            cout<<0;
            num++;
            if(num%50==0)cout<<endl;
        }
        for(int i=alen;i>=1;i--){
            cout<<a[i];
            num++;
            if(num%50==0)cout<<endl;
        }
    }
    else{
        for(int i=500;i>=1;i--){
            cout<<a[i];
            num++;
            if(num%50==0)cout<<endl;
        }
    }
    return 0;
}
