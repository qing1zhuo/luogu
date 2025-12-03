#include<iostream>
#include<climits>
#include<string.h>
using namespace std;
typedef struct location
{
    int data;
    int parent;
    int lchild;
    int rchild;
}location;
location loc[105];
int n;
int mini=INT_MAX;
int mark[105];
int path[105][3];
int head,tail;
int sum=0;//从i节点开始走到其他节点费用总和
int bfs(int,int);
int back(int);
int main()
{
    cin>>n;
    //存储节点
    for(int i=1;i<=n;i++)
    {
        int data,l,r;
        cin>>data>>l>>r;
        loc[i].data=data;
        loc[i].lchild=l;
        loc[i].rchild=r;
        loc[l].parent=i;
        loc[r].parent=i;
    }

    for(int i=1;i<=n;i++)
    {
        sum=0;
        //从i节点走到j节点
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                memset(mark,0,sizeof(mark));
                memset(path,0,sizeof(path));
                head=1;tail=1;
                path[1][1]=i;mark[i]=1;
                sum+=bfs(i,j);
            }
        }
        if(sum<mini)mini=sum;
    }
    cout<<mini;
    return 0;
}
int bfs(int start,int end)
{
    while(path[head][1]!=end)
    {
        int now=path[head][1];
        int pa=loc[now].parent;
        int left=loc[now].lchild;
        int right=loc[now].rchild;
        if(pa!=0&&mark[pa]==0)
        {
            tail++;
            path[tail][1]=pa;path[tail][2]=head;
            mark[pa]=1;
        }
        if(left!=0&&mark[left]==0)
        {
            tail++;
            path[tail][1]=left;path[tail][2]=head;
            mark[left]=1;
        }
        if(right!=0&&mark[right]==0)
        {
            tail++;
            path[tail][1]=right;path[tail][2]=head;
            mark[right]=1;
        }
        head++;
    }
    int distance=back(head);
    return distance*loc[end].data;
}
int back(int k)
{
    if(path[k][2])
    {
        return 1+back(path[k][2]);
    }
    else return 0;
}