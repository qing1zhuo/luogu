#include<iostream>
using namespace std;
#define maxn 10005
int param[maxn][4];
int n,m;
class SmallRoot
{
#define ll long long
private:
    ll *arr;
    int point;
public:
    SmallRoot(int n){
        arr=new ll[n+1];
        point=0;
    }
    ~SmallRoot(){
        delete []arr;
    }
    void push(ll x){
        point++;
        arr[point]=x;
        int pt=point;
        while(pt>1&&arr[pt]<arr[pt/2]){
            MySwap(arr[pt],arr[pt/2]);
            pt/=2;
        }
    }
    int top(){
        return arr[1];
    }
    void pop(){
        arr[1]=arr[point];
        point--;
        int pt=1;
        while(2*pt<=point){
            int son=pt*2;
            if(son+1<=point&&arr[son+1]<arr[son]){
                son++;
            }
            if(arr[pt]>arr[son]){
                MySwap(arr[pt],arr[son]);
                pt=son;
            }
            else break;
        }
    }
    void MySwap(ll&a,ll&b){int cur=a;a=b;b=cur;}
};
long long func(int x,int u);
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>param[i][j];
        }
    }
    int x=0;
    SmallRoot sr(m);
    while(x*n<m){
        x++;
        for(int u=1;u<=n;u++){
            sr.push(func(x,u));
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sr.top()<<" ";
        sr.pop();
    }
    return 0;
}

long long func(int x,int u){
    return x*x*param[u][1]+x*param[u][2]+param[u][3];
}
