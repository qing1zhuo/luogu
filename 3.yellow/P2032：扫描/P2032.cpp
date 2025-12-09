#include<iostream>
#include<cstring>
using namespace std;
class Queue
{
private:
    int front,tail;
    int queue[2000005];
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
int main()
{
    int n,k;
    cin>>n>>k;
    Queue q;
    int a[2000005]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int cur=a[i];

        if(q.empty())//若q为空，则直接塞进去
        {
            q.push(i);
        }
        else//若q不为空，则首先清除队尾比当前元素小的，然后再把当前元素塞进去
        {
            while(cur>a[q.gettail()])
            {
                q.tail_pop();
                if(q.empty())break;
            }
            q.push(i);
        }

        if(q.getfront()<i-k+1)q.front_pop();

        if(i+1>=k)cout<<a[q.getfront()]<<endl;
    }
    return 0;
}