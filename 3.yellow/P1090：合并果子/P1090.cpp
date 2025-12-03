#include<iostream>
using namespace std;
int tree[100005];
int n;
int len=0;
long long ans=0;
int get();
void t(int);
void put(int);
void swap(int*,int*);
void print();

int main()
{
    scanf("%d",&n);
    //建堆
    for(int i=1;i<=n;i++)
    {
        len++;scanf("%d",&tree[len]);
        put(len);
    }
    //print();
    //取数
    for(int i=1;i<n;i++)
    {
        int x=get();len--;
        int y=get();len--;
        ans+=(x+y);
        len++;
        tree[len]=x+y;
        put(len);
    }
    printf("%d",ans);
    return 0;
}
int get()
{
    int res=tree[1];
    tree[1]=tree[len];
    tree[len]=0;
    t(1);
    return res;
}
void t(int k)
{
    if(tree[2*k])//若有孩子
    {
        if(tree[2*k+1])//若两个孩子都有
        {
            if(tree[2*k]<tree[2*k+1]+1&&tree[k]>tree[2*k])//若左孩子小,且父亲大于左孩子
            {
                swap(&tree[k],&tree[2*k]);
                t(2*k);
            }
            else if(tree[2*k]>=tree[2*k+1]+1&&tree[k]>tree[2*k+1])
            {
                swap(&tree[k],&tree[2*k+1]);
                t(2*k+1);
            }
        }
        else if(tree[k]>tree[2*k])
        {
            swap(&tree[k],&tree[2*k]);
            t(2*k);
        }
    }
}
void put(int k)
{
    if(k==1);
    else
    {
        if(tree[k/2]>tree[k])//如果我爹大于我
        {
            swap(&tree[k],&tree[k/2]);
            put(k/2);
        }
    }
}
void swap(int*pa,int*pb)
{
    int s=*pa;
    *pa=*pb;
    *pb=s;
}
void print()
{
    for(int i=1;i<=len;i++)cout<<tree[i]<<" ";
}