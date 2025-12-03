/*链表方法*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node//创建节点
{
    int data;//节点编号
    int num;//依赖包个数
    struct node* next[5000];//指向依赖包的指针
}node;

node* createnode(int x)//创建节点函数
{
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    for(int i=0;i<5000;i++)
    {
        p->next[i] = NULL;
    }
    return p;
}

// void print(node* p)//打印节点信息
// {
//     while(p!=NULL)
//     {
//         printf("%d->",p->data);
//         p=p->next[0];
//     }
//     printf("NULL\n");
// }
void detect(node*p,int*mark)
{
    if(mark[p->data-1]==1)//如果该节点已经被访问过则返回
        return;
    mark[p->data-1]=1;//标记该节点为已访问
    for(int i=0;i<p->num;i++)//递归访问所有依赖包
    {
        detect(p->next[i],mark);
    }
}
int main()
{
    int n;scanf("%d",&n);
    node* lian[n]; 
    int mark[n]={0};//标记数组，标记每个节点是否被访问过
    for(int i=0;i<n;i++)//创建一个节点数组，每个数组元素是一个节点地址
    {
        lian[i]=createnode(i+1);
    }
    for(int i=0;i<n;i++)
    {
        int m;scanf("%d",&m); //输入共有几个依赖包
        lian[i]->num=m;//将依赖包个数存入节点
        for(int j=0;j<m;j++)
        {
            int x;scanf("%d",&x);//输入依赖包具体编号
            lian[i]->next[j]=lian[x-1];//将依赖包地址存入
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     print(lian[i]);//打印每个节点的信息
    // }
    detect(lian[0],mark);//从节点1开始访问
    int count=0;
    for(int i=0;i<n;i++)    //统计被访问过的节点个数
    {
        if(mark[i]==1)
            count++;
    }       
    printf("%d",count);
    return 0;
}