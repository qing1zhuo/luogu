#include<iostream>
#include<queue>
using namespace std;
#define maxn 200005
#define ll long long
int n,m;
queue<ll>Add,Get;
int cnt=0;

class SmallRoot
{
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
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        Add.push(x);
    }
    for(int i=1;i<=m;i++){
        ll x;cin>>x;
        Get.push(x);
    }

    SmallRoot sr(n);
    BigRoot br(n);
    for(int i=1;i<=n;i++){
        ll x=Add.front();Add.pop();
        br.push(x);
        x=br.top(),br.pop();
        sr.push(x);
        while(i==Get.front()){
            Get.pop();
            cnt++;
            if(cnt){
                x=sr.top();
                sr.pop();
                br.push(x);
            }
            cout<<br.top()<<endl;
        }
    }

    return 0;
}