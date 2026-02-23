#include<iostream>
using namespace std;
#define maxn 100005
int n;
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
class BigRoot
{
#define ll long long
private:
    ll *arr;
    int point;
public:
    BigRoot(int n){
        arr=new ll[n+1];
        point=0;
    }
    ~BigRoot(){
        delete []arr;
    }
    void push(ll x){
        point++;
        arr[point]=x;
        int pt=point;
        while(pt>1&&arr[pt]>arr[pt/2]){
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
            if(son+1<=point&&arr[son+1]>arr[son]){
                son++;
            }
            if(arr[pt]<arr[son]){
                MySwap(arr[pt],arr[son]);
                pt=son;
            }
            else break;
        }
    }
    void MySwap(ll&a,ll&b){int cur=a;a=b;b=cur;}
};


int main()
{
    cin>>n;
    SmallRoot sr(n);BigRoot br(n);
    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        br.push(x);
        x=br.top();
        br.pop();
        sr.push(x);
        if(i%2==1){
            x=sr.top();
            sr.pop();
            br.push(x);
            cout<<br.top()<<endl;
        }
    }
    return 0;
}