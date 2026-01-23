#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//宏定义
#define MAXDAY 1000010
#define MAXROOM 1000000010
//变量定义
int days,order_nums;
bool whether_satisfy=true;
int failure_index=0;
long long rooms_per_day[MAXDAY];
long long fraction[MAXDAY];
long long presum[MAXDAY];
long long order[MAXDAY][3];
//函数声明
void fraction_initial();
bool check();
//主函数
int main()
{
    cin>>days>>order_nums;
    for(int i=1;i<=days;i++){
        cin>>rooms_per_day[i];
    }
    for(int i=1;i<=order_nums;i++){
        cin>>order[i][0]>>order[i][1]>>order[i][2];
    }

    int left=1,right=order_nums;
    while(left<=right){
        fraction_initial();
        int mid=(left+right)/2;
        for(int i=1;i<=mid;i++){
            fraction[order[i][1]]-=order[i][0];
            fraction[order[i][2]+1]+=order[i][0];
        }
        if(check()){
            left=mid+1;
        }
        else{
            whether_satisfy=false;
            failure_index=mid;
            right=mid-1;
        }
    }

    if(whether_satisfy)cout<<0;
    else cout<<-1<<endl<<failure_index;
    return 0;
}

bool check(){
    memset(presum,0,sizeof(long long)*(days+5));
    for(int i=1;i<=days;i++){
        presum[i]=presum[i-1]+fraction[i];
        if(presum[i]<0)return false;
    }
    return true;
}
void fraction_initial(){
    for(int i=1;i<=days;i++)fraction[i]=rooms_per_day[i]-rooms_per_day[i-1];
}