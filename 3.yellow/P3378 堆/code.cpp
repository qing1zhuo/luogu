#include<iostream>
using namespace std;
#define ll long long
void MySwap(ll&a,ll&b){int cur=a;a=b;b=cur;}
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
    int find(){
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
};

int main()
{
    ios::sync_with_stdio(false); // 加速cin/cout（应对1e6数据）
    cin.tie(0);
    int n;cin>>n;
    SmallRoot sr(n);
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            int x;cin>>x;
            sr.push(x);
        }
        if(op==2){
            int x=sr.find();
            cout<<x<<endl;
        }
        if(op==3){
            sr.pop();
        }
    }
    return 0;
}