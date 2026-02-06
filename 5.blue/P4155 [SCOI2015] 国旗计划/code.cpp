#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 200005
int n,m;
struct soilder{int id,l,r;}a[2*maxn];
int go[25][2*maxn];
int ans[maxn];

bool cmp(soilder x,soilder y){return x.l<y.l;}
int main()
{
    //数据读取处理
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        if(a[i].l>a[i].r){
            a[i].r+=m;
        }
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        a[i+n]=a[i];
        a[i+n].l=a[i].l+m;
        a[i+n].r=a[i].r+m;
    }
    //go数组处理
    for(int i=1;i<=2*n;i++){
        int p=i,l=i,r=2*n;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid].l<=a[i].r){
                p=mid;l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        go[0][i]=p;
    }
    for(int k=1;k<=20;k++){
        for(int i=1;i<=2*n;i++){
            go[k][i]=go[k-1][go[k-1][i]];
        }
    }
    //
    for(int i=1;i<=n;i++){
        int end=a[i].l+m;
        int cur=i;
        int res=1;
        for(int k=20;k>=0;k--){
            int step=1<<k;
            if(a[go[k][cur]].r<end){
                cur=go[k][cur];
                res+=step;
            }
        }
        cur=go[0][cur];
        res+=1;
        ans[a[i].id]=res;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}