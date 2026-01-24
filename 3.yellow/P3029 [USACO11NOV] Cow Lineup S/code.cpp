#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxn 50010

struct COW{long long position,breed;};//每头奶牛的位置与品种
COW cow[maxn]={0,0};//存储每头奶牛信息
long long breed[maxn]={0};int b_num=0;//离散化品种
int visit[maxn]={0};//标记离散化的某个数字是否查询
int n=0;//奶牛数量
long long ans=1e9;

void my_sort(int left,int right,COW*cow);//给奶牛按照位置大小排序
void swap(COW&a,COW&b);//奶牛交换函数
int breed_deal(long long*breed,int b_num);//给离散化排序去重
int binary_search(int x,long long*breed,int l,int r);//二分查找

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cow[i].position>>cow[i].breed;
        breed[++b_num]=cow[i].breed;
    }
    b_num=breed_deal(breed,b_num);
    my_sort(1,n,cow);
    
    int fast=1,slow=1;
    while(fast<=n){
        int findex=binary_search(cow[fast].breed,breed,1,b_num);
        visit[findex]++;
        if(visit[findex]==1)visit[0]++;
        while(visit[0]==b_num){
            int sindex=binary_search(cow[slow].breed,breed,1,b_num);
            visit[sindex]--;
            if(visit[sindex]==0){
                visit[0]--;
            }
            if(visit[0]!=b_num){
                if(ans>cow[fast].position-cow[slow].position){
                    ans=cow[fast].position-cow[slow].position;
                }
            }
            slow++;
        }
        fast++;
    }
    cout<<ans;
    // cout<<"\n***\n";
    // for(int i=1;i<=n;i++)cout<<cow[i].position<<" "<<cow[i].breed<<endl;
    return 0;
}
void my_sort(int left,int right,COW*cow){
    int l=left,r=right;
    long long mid=cow[(left+right)/2].position;
    while(l<=r){
        while(cow[l].position<mid)l++;
        while(cow[r].position>mid)r--;
        if(l<=r){
            swap(cow[l],cow[r]);
            l++,r--;
        }
    }
    if(l<right)my_sort(l,right,cow);
    if(r>left)my_sort(left,r,cow);
}
void swap(COW&a,COW&b){
    COW cur=a;
    a=b;
    b=cur;
}
int breed_deal(long long*breed,int b_num){
    sort(breed+1,breed+1+b_num);
    int res=0;
    for(int i=1;i<=b_num;i++){
        if(breed[i]!=breed[i-1]){
            breed[++res]=breed[i];
        }
    }
    return res;
}
int binary_search(int x,long long*breed,int l,int r){
    int mid=(l+r)/2;
    if(breed[mid]==x)return mid;
    else if(breed[mid]>x)return binary_search(x,breed,l,mid-1);
    else if(breed[mid]<x)return binary_search(x,breed,mid+1,r);
}