#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 5010
int n;
int cow[maxn];char ch;
int back_num;
int f[maxn];

int ans_k,ans_m=1e8;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ch;
        if(ch=='F')cow[i]=1;
        else{
            cow[i]=0;
            back_num++;
        }
    }

    for(int k=1;k<=n;k++){//遍历每个可能的k
        int operation=0;int current_flip=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            if(i>k)current_flip-=f[i-k];
            if((cow[i]+current_flip)%2==0){
                if(i>n-k+1){
                    operation=-1;
                    break;
                }
                operation++;
                current_flip++;
                f[i]=1;
            }
        }
        if(operation<ans_m&&operation!=-1){
            ans_m=operation,ans_k=k;
        }
    }

    cout<<ans_k<<" "<<ans_m;
    return 0;
}
