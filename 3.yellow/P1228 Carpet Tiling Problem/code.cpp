#include<iostream>
#include<algorithm>
using namespace std;
#define maxn (1<<10)+5

struct Carpet{int x,y;int t;}carpet[maxn*maxn];//地毯结构体
int num_c=0;//地毯数量
int k,x,y;
int n;

void divide(int x,int y,int hx,int hy,int len)
{
    if(len==1)return;
    int mid=len/2;
    if(hx<x+mid&&hy<y+mid){//特殊点在左上
        cout<<x+mid<<" "<<y+mid<<" "<<1<<endl;
        divide(x,y,hx,hy,mid);//递归左上矩阵
        divide(x+mid,y+mid,x+mid,y+mid,mid);//右下
        divide(x+mid,y,x+mid,y+mid-1,mid);//左下
        divide(x,y+mid,x+mid-1,y+mid,mid);//右上
        return;
    }
    if(hx<x+mid&&hy>=y+mid){//特殊点在右上
        cout<<x+mid<<" "<<y+mid-1<<" "<<2<<endl;
        divide(x,y,x+mid-1,y+mid-1,mid);//左上
        divide(x+mid,y+mid,x+mid,y+mid,mid);//右下
        divide(x+mid,y,x+mid,y+mid-1,mid);//左下
        divide(x,y+mid,hx,hy,mid);//右上
        return;
    }
    if(hx>=x+mid&&hy<y+mid){//特殊点在左下
        cout<<x+mid-1<<" "<<y+mid<<" "<<3<<endl;
        divide(x,y,x+mid-1,y+mid-1,mid);//左上
        divide(x+mid,y+mid,x+mid,y+mid,mid);//右下
        divide(x+mid,y,hx,hy,mid);//左下
        divide(x,y+mid,x+mid-1,y+mid,mid);//右上
        return;
    }
    if(hx>=x+mid&&hy>=y+mid){//特殊点在右下
        cout<<x+mid-1<<" "<<y+mid-1<<" "<<4<<endl;
        divide(x,y,x+mid-1,y+mid-1,mid);//左上
        divide(x+mid,y+mid,hx,hy,mid);//右下
        divide(x+mid,y,x+mid,y+mid-1,mid);//左下
        divide(x,y+mid,x+mid-1,y+mid,mid);//右上
        return;
    }
}

int main()
{
    cin>>k>>x>>y;
    n=1<<k;
    divide(1,1,x,y,n);
    return 0;
}