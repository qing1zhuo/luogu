#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
class Queue
{
private:
    int front,tail;
    int queue[100010];
public:
    Queue()
    {
        front=0,tail=0;
        memset(queue,0,sizeof(queue));
    }
    void push(int x)
    {
        queue[tail]=x;
        tail++;
    }
    void front_pop()
    {
        front++;
    }
    void tail_pop()
    {
        tail--;
    }
    int getfront()
    {
        return queue[front];
    }
    int gettail()
    {
        return queue[tail-1];
    }
    bool empty()
    {
        return front==tail;
    }
};
void print(ull (*arr)[1005],int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int a,b,n;cin>>a>>b>>n;
    ull m[1005][1005]={0};
    ull minn[1005][1005]={0};
    ull maxn[1005][1005]={0};
    ull ans=1e10;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cin>>m[i][j];
        }
    }
    
    //matrix_minn
    for(int i=1;i<=a;i++)
    {
        Queue q;//对每一行都建立一个队列
        for(int j=1;j<=b;j++)
        {
            ull cur=m[i][j];
            if(q.empty())//若q为空，则直接塞进去
            {
                q.push(j);
            }
            else
            {
                while(cur<m[i][q.gettail()])
                {
                    q.tail_pop();
                    if(q.empty())break;
                }
                q.push(j);
            }
            if(q.getfront()<j-n+1)q.front_pop();

            if(j>=n)minn[i][j-n+1]=m[i][q.getfront()];
        }
    }
    for(int j=1;j<=b-n+1;j++)
    {
        Queue q;
        for(int i=1;i<=a;i++)
        {
            ull cur=minn[i][j];
            if(q.empty())//若q为空，则直接塞进去
            {
                q.push(i);
            }
            else//若q不为空，则首先清除队尾比当前元素小的，然后再把当前元素塞进去
            {
                while(cur<minn[q.gettail()][j])
                {
                    q.tail_pop();
                    if(q.empty())break;
                }
                q.push(i);
            }
            if(q.getfront()<i-n+1)q.front_pop();

            if(i>=n)minn[i-n+1][j]=minn[q.getfront()][j];
        }
    }


    //matrix_maxn
    for(int i=1;i<=a;i++)
    {
        Queue q;//对每一行都建立一个队列
        for(int j=1;j<=b;j++)
        {
            ull cur=m[i][j];
            if(q.empty())//若q为空，则直接塞进去
            {
                q.push(j);
            }
            else//若q不为空，则首先清除队尾比当前元素小的，然后再把当前元素塞进去
            {
                while(cur>m[i][q.gettail()])
                {
                    q.tail_pop();
                    if(q.empty())break;
                }
                q.push(j);
            }
            if(q.getfront()<j-n+1)q.front_pop();

            if(j>=n)maxn[i][j-n+1]=m[i][q.getfront()];
        }
    }
    for(int j=1;j<=b-n+1;j++)
    {
        Queue q;
        for(int i=1;i<=a;i++)
        {
            ull cur=maxn[i][j];
            if(q.empty())//若q为空，则直接塞进去
            {
                q.push(i);
            }
            else//若q不为空，则首先清除队尾比当前元素小的，然后再把当前元素塞进去
            {
                while(cur>maxn[q.gettail()][j])
                {
                    q.tail_pop();
                    if(q.empty())break;
                }
                q.push(i);
            }
            if(q.getfront()<i-n+1)q.front_pop();

            if(i>=n)maxn[i-n+1][j]=maxn[q.getfront()][j];
        }
    }

    for(int i=1;i<=a-n+1;i++)
    {
        for(int j=1;j<=b-n+1;j++)
        {
            ans=min(ans,maxn[i][j]-minn[i][j]);
        }
    }


    //print(maxn,a-n+1,b-n+1);
    //print(minn,a-n+1,b-n+1);
    cout<<ans<<endl;
    return 0;
}