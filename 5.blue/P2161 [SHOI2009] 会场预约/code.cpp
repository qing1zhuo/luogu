#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005

class TreeArray
{
private:
    int size;
    int*arr;
public:
    TreeArray(int n,int*init):size(n){
        arr=new int[n+1];
        for(int i=1;i<=n;i++){
            arr[i]=init[i]-init[i-low_bit(i)];
        }
    }
    ~TreeArray(){
        delete []arr;
    }
    int low_bit(int x){
        return x&(-x);
    }
    void add(int local,int k){
        for(int i=local;i<=size;i+=low_bit(i)){
            arr[i]+=k;
        }
        return;
    }
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=low_bit(i)){
            res+=arr[i];
        }
        return res;
    }
};

int main()
{
    int n;cin>>n;//操作次数
    int cnt=0;//总预约数量
    int init[maxn]={0};//用于初始化ta的数组，无实际意义
    int righ[maxn]={0};//righ_i表示[i,right[i]]的一段预约
    TreeArray ta(maxn,init);//ta_i表示以i为左端点的一个预约
    while(n--){
        char ch;cin>>ch;
        if(ch=='A'){
            int st,ed;cin>>st>>ed;
            int del=0;
            while(1){//查找每一个可能在查询区间的预约
                int l=0,r=ed;//初始化左右指针
                while(l<r){
                    int mid=(l+r)/2;
                    if(ta.sum(mid)<ta.sum(ed)){
                        l=mid+1;
                    }
                    else{
                        r=mid;
                    }
                }
                if(righ[l]>=st){
                    ta.add(l,-1);
                    del++;
                    cnt--;
                }
                else break;
            }
            ta.add(st,1);
            cnt++;
            righ[st]=ed;
            cout<<del<<endl;
        }
        else{
            cout<<cnt<<endl;
        }
    }
    return 0;
}